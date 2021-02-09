# Hostboot Kernel
Hostboot runs a custom microkernel that endeavors to provide only the basic services to user-space.  As much functionality as possible exists in user-space.


The primary functions of the kernel are:
- Memory Management
- Task scheduling
- Interprocess Communication
- Library loading/unloading
- Exception Handling
- Interrupt Processing


## Memory Management
Hostboot memory management is based on a hierarchy of page fault handlers that exist inside both kernel and user-space.  


- HPT = Hardware Page Table, this maps virtual page addresses into physical page addresses, note that this only applies to user-space accesses
- ShadowPTE = Our in-kernel copy of the PTE metadata for every page that we have allocated.  The HPT only contains a subset of pages at any given time so we have to keep our own copy to handle PTE misses.
- PTE = Page Table Entry, contains the virtual-to-physical page mapping plus metadata about access, e.g. permissions
- VMM = Virtual Memory Management, refers to all aspects of the virtual page fault handling infrastructure


When a cpu accesses a memory address, the following flow takes place.
- Hardware checks the Hardware Page Table (HPT) for an exact match of the desired page
- If page is in the HPT
  -  Request is serviced and execution resumes
- Else 
  - Kernel gets a page table miss exception
  - VmmManager::pteMiss() executes and starts the handlePageFault() flow from SegmentMgr->SegmentXX->Block
    - At each layer, if the address is not owned by that instance it will simply return
    - SegmentManager::handlePageFault() loops through the different segments of memory
      - DeviceSegment for Memory Mapped I/O (MMIO)
        - PageTableManager::addEntry() called to add a Cache-Inhibited entry into the HPT
      - StackSegment for stack memory
        - Block::handlePageFault() is called (see below, same behavior as BaseSegment)
      - BaseSegment for everything else
        - Block::handlePageFault() checks to see if we have a ShadowPTE entry for this page
        - If ShadowPTE is not present
          - If there is a resource provider queue associated with this Block
            - Allocate a physical page to back the virtual page if one isn't already there
            - Send MSG_MM_RP_READ/MSG_MM_RP_WRITE message to the queue
              - User-space Resource Provider logic runs (see below)
            - return from handlePageFault
          - Else (no queue)
            - Allocate a physical page to back the virtual page
        - PageTableManager::addEntry() called to add an entry into the HPT


#### Resource Providers
Hostboot is full of user-space daemons that act as backends for a range of virtual addresses.  The most obvious examples are the PNOR Resource Provider (PnorRP) and the Attribute Resource Provider (AttrRP).  Each of these daemons allocates a block of virtual address space and registers a message queue with it to respond to MSG_MM_RP_READ/MSG_MM_RP_WRITE messages from the VMM page fault handling flow.  A resource provider can do whatever it needs to do in order to fulfill the page request.  For example, the PnorRP will physically read PNOR, remove ECC, and put the result into the requested page.
