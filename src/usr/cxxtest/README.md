# TestInject

This infrastructure provides a simple class object to do software injects.

1. The test code sets an inject enum in the global class object
2. The functional code uses that global object to detect the inject enum
3. if the test enum is active, the functional code performs the injection operation

**Files**

- src/include/usr/cxxtest/TestInject.H
- src/include/usr/cxxtest/TestInject_defs.H
- src/usr/cxxtest/TestInject.C
- src/usr/initservice/extinitsvc/makefile
- src/usr/util/runtime/makefile

## Usage

**Search** MMIO_INJECT for an example.

- In TestInject_defs.H, add new enum(s) for inject.

 ```
    enum CxxTestInjects : uint8_t
    {
        INJECT_CLEAR              = 0,
        MMIO_INJECT_IN_PROGRESS   = 1,
        MMIO_INJECT_UE            = 2,
        MMIO_INJECT_FIFO_HANG     = 3,
        MMIO_INJECT_FIFO_BREAKAGE = 4,
        NEW_INJECT_SOMETHING      = 5,    <<<< like this

        MAX_CXX_TEST_INJECTS      = 63, // This can be expanded up to 255 as needed
                                        // There is no need to consume the extra space
    };
```

- In your test driver

```
#include <cxxtest/TestInject.H>        << add include file

  // clear the inject at the beginning of your testcases
  g_cxxTestInject.clear(NEW_INJECT_SOMETHING);

  ... other test code ...

  // activate the test inject
  g_cxxTestInject.set(NEW_INJECT_SOMETHING);

  // call the functional code, which will detect the inject
```

- In your functional code, detect the inject and create the error  

   (The idea is for the macro to do all the injection work and be completely  
    compiled out if CONFIG_COMPILE_CXXTEST_HOOKS is not defined)

```
#include <cxxtest/TestInject.H>        << add include file

// Define a macro which is compiled out by default
#if defined(CONFIG_COMPILE_CXXTEST_HOOKS)
#define CI_NEW_INJECT(_g_inject, _i_target, _enum, _msg, _l_addr)  \
    if (_g_inject.isSet(_enum))                                    \
    {                                                              \
      _g_inject.clear(_enum);                                      \
        TRACFCOMP(g_trac_xxxx, _msg                                \
                  " OCMB 0x%08x", TARGETING::get_huid(_i_target)); \
        _l_addr = NEW_ERROR_INJECTION; // *do inject here*         \
    }
#else
#define CI_NEW_INJECT(_g_inject, _i_target, _enum, _msg, _l_addr)
#endif

  void functionalCode(...)
  {
    ... some code ...

    // This spot in the function code is injected with the error
    //  if g_cxxTestInject has NEW_INJECT_SOMETHING set
    CI_NEW_INJECT(CxxTest::g_cxxTestInject,               << global object
                  i_ocmbTarget,                           << target for trace in macro
                  CxxTest::NEW_INJECT_SOMETHING,          << enum inject to detect
                  "functionalCode: NEW_INJECT_SOMETHING", << msg for trace in macro
                  addr_to_inject);                        << input data for inject

    ... some code ...
  }
```

