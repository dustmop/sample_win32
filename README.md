Sample Win32 gui application, using subsystem:windows, to demonstrate an issue with jxcore's use of the console.

Created using Visual Studio C++ 2010 Express on Windows 10.

Steps to create:

1) New Project -> Win32 Project. (non-empty)
2) Add source js_engine.cpp, js_engine.h
3) In Source Files -> sample_win32.cpp
    #include "js_engine.h"
    JSEngineRun("sample_win32.exe"); // directly before main loop begins
4) Properties for project ->
    VC++ Directory -> Include Directories
      ..\..\jxcore-dev\src\public
    Linker -> General -> Additional Library Directories
      ..\..\jxcore-dev\Release
    Linker -> Input -> Additional Dependencies
      jx.lib

Running the compiled program creates a file "log.txt". Contents are:

-------------
count 0 msg b

Expected:

--------------
count 0 msg a
count 1 msg b
