# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\buddi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\buddi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\ideal-gas-test.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\ideal-gas-test.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ideal-gas-test.dir\flags.make

CMakeFiles\ideal-gas-test.dir\test\test_main.cpp.obj: CMakeFiles\ideal-gas-test.dir\flags.make
CMakeFiles\ideal-gas-test.dir\test\test_main.cpp.obj: ..\test\test_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ideal-gas-test.dir/test/test_main.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ideal-gas-test.dir\test\test_main.cpp.obj /FdCMakeFiles\ideal-gas-test.dir\ /FS -c C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\test\test_main.cpp
<<

CMakeFiles\ideal-gas-test.dir\test\test_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ideal-gas-test.dir/test/test_main.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\ideal-gas-test.dir\test\test_main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\test\test_main.cpp
<<

CMakeFiles\ideal-gas-test.dir\test\test_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ideal-gas-test.dir/test/test_main.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ideal-gas-test.dir\test\test_main.cpp.s /c C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\test\test_main.cpp
<<

CMakeFiles\ideal-gas-test.dir\src\particle.cpp.obj: CMakeFiles\ideal-gas-test.dir\flags.make
CMakeFiles\ideal-gas-test.dir\src\particle.cpp.obj: ..\src\particle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ideal-gas-test.dir/src/particle.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ideal-gas-test.dir\src\particle.cpp.obj /FdCMakeFiles\ideal-gas-test.dir\ /FS -c C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\src\particle.cpp
<<

CMakeFiles\ideal-gas-test.dir\src\particle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ideal-gas-test.dir/src/particle.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\ideal-gas-test.dir\src\particle.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\src\particle.cpp
<<

CMakeFiles\ideal-gas-test.dir\src\particle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ideal-gas-test.dir/src/particle.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ideal-gas-test.dir\src\particle.cpp.s /c C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\src\particle.cpp
<<

CMakeFiles\ideal-gas-test.dir\src\simulation.cpp.obj: CMakeFiles\ideal-gas-test.dir\flags.make
CMakeFiles\ideal-gas-test.dir\src\simulation.cpp.obj: ..\src\simulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ideal-gas-test.dir/src/simulation.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ideal-gas-test.dir\src\simulation.cpp.obj /FdCMakeFiles\ideal-gas-test.dir\ /FS -c C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\src\simulation.cpp
<<

CMakeFiles\ideal-gas-test.dir\src\simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ideal-gas-test.dir/src/simulation.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\ideal-gas-test.dir\src\simulation.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\src\simulation.cpp
<<

CMakeFiles\ideal-gas-test.dir\src\simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ideal-gas-test.dir/src/simulation.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ideal-gas-test.dir\src\simulation.cpp.s /c C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\src\simulation.cpp
<<

CMakeFiles\ideal-gas-test.dir\src\idealgasapp.cpp.obj: CMakeFiles\ideal-gas-test.dir\flags.make
CMakeFiles\ideal-gas-test.dir\src\idealgasapp.cpp.obj: ..\src\idealgasapp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ideal-gas-test.dir/src/idealgasapp.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ideal-gas-test.dir\src\idealgasapp.cpp.obj /FdCMakeFiles\ideal-gas-test.dir\ /FS -c C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\src\idealgasapp.cpp
<<

CMakeFiles\ideal-gas-test.dir\src\idealgasapp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ideal-gas-test.dir/src/idealgasapp.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\ideal-gas-test.dir\src\idealgasapp.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\src\idealgasapp.cpp
<<

CMakeFiles\ideal-gas-test.dir\src\idealgasapp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ideal-gas-test.dir/src/idealgasapp.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ideal-gas-test.dir\src\idealgasapp.cpp.s /c C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\src\idealgasapp.cpp
<<

# Object files for target ideal-gas-test
ideal__gas__test_OBJECTS = \
"CMakeFiles\ideal-gas-test.dir\test\test_main.cpp.obj" \
"CMakeFiles\ideal-gas-test.dir\src\particle.cpp.obj" \
"CMakeFiles\ideal-gas-test.dir\src\simulation.cpp.obj" \
"CMakeFiles\ideal-gas-test.dir\src\idealgasapp.cpp.obj"

# External object files for target ideal-gas-test
ideal__gas__test_EXTERNAL_OBJECTS =

Debug\ideal-gas-test\ideal-gas-test.exe: CMakeFiles\ideal-gas-test.dir\test\test_main.cpp.obj
Debug\ideal-gas-test\ideal-gas-test.exe: CMakeFiles\ideal-gas-test.dir\src\particle.cpp.obj
Debug\ideal-gas-test\ideal-gas-test.exe: CMakeFiles\ideal-gas-test.dir\src\simulation.cpp.obj
Debug\ideal-gas-test\ideal-gas-test.exe: CMakeFiles\ideal-gas-test.dir\src\idealgasapp.cpp.obj
Debug\ideal-gas-test\ideal-gas-test.exe: CMakeFiles\ideal-gas-test.dir\build.make
Debug\ideal-gas-test\ideal-gas-test.exe: C:\Users\buddi\Cinder\lib\msw\x86\Debug\v140\cinder.lib
Debug\ideal-gas-test\ideal-gas-test.exe: CMakeFiles\ideal-gas-test.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Debug\ideal-gas-test\ideal-gas-test.exe"
	C:\Users\buddi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\ideal-gas-test.dir --rc=rc --mt=C:\PROGRA~2\WI3CF2~1\8.1\bin\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\ideal-gas-test.dir\objects1.rsp @<<
 /out:Debug\ideal-gas-test\ideal-gas-test.exe /implib:ideal-gas-test.lib /pdb:C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug\Debug\ideal-gas-test\ideal-gas-test.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:windows  /SUBSYSTEM:CONSOLE /NODEFAULTLIB:LIBCMT /NODEFAULTLIB:LIBCPMT   -LIBPATH:C:\Users\buddi\Cinder\lib\msw\x86  C:\Users\buddi\Cinder\lib\msw\x86\Debug\v140\cinder.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ideal-gas-test.dir\build: Debug\ideal-gas-test\ideal-gas-test.exe

.PHONY : CMakeFiles\ideal-gas-test.dir\build

CMakeFiles\ideal-gas-test.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ideal-gas-test.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ideal-gas-test.dir\clean

CMakeFiles\ideal-gas-test.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug C:\Users\buddi\Cinder\my-projects\ideal-gas-vinsunkavalli\cmake-build-debug\CMakeFiles\ideal-gas-test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ideal-gas-test.dir\depend

