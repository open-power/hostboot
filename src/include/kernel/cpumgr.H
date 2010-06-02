#ifndef __KERNEL_CPUMGR_H
#define __KERNEL_CPUMGR_H

#include <kernel/types.h>

class CpuManager
{
    public:
	enum { MAXCPUS = 8 };
	
	/** @fn getCurrentCPU 
	 *  Returns a pointer to the current CPU structure by using the
	 *  task structure in SPRG3.
	 */
	cpu_t* getCurrentCPU();

	static void init();

    protected:
	CpuManager();
	~CpuManager() {};

	/** @fn startCPU
	 *  Starts the requested CPU. Default of -1 implies current CPU.
	 */
	void startCPU(ssize_t i = -1);

    private:
	cpu_t* iv_cpus[MAXCPUS];
};

#endif
