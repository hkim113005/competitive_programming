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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\CSES_Counting_Divisors.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\CSES_Counting_Divisors.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\CSES_Counting_Divisors.dir\flags.make

CMakeFiles\CSES_Counting_Divisors.dir\main.cpp.obj: CMakeFiles\CSES_Counting_Divisors.dir\flags.make
CMakeFiles\CSES_Counting_Divisors.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CSES_Counting_Divisors.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\CSES_Counting_Divisors.dir\main.cpp.obj /FdCMakeFiles\CSES_Counting_Divisors.dir\ /FS -c "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\main.cpp"
<<

CMakeFiles\CSES_Counting_Divisors.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CSES_Counting_Divisors.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\CSES_Counting_Divisors.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\main.cpp"
<<

CMakeFiles\CSES_Counting_Divisors.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CSES_Counting_Divisors.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\CSES_Counting_Divisors.dir\main.cpp.s /c "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\main.cpp"
<<

# Object files for target CSES_Counting_Divisors
CSES_Counting_Divisors_OBJECTS = \
"CMakeFiles\CSES_Counting_Divisors.dir\main.cpp.obj"

# External object files for target CSES_Counting_Divisors
CSES_Counting_Divisors_EXTERNAL_OBJECTS =

CSES_Counting_Divisors.exe: CMakeFiles\CSES_Counting_Divisors.dir\main.cpp.obj
CSES_Counting_Divisors.exe: CMakeFiles\CSES_Counting_Divisors.dir\build.make
CSES_Counting_Divisors.exe: CMakeFiles\CSES_Counting_Divisors.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CSES_Counting_Divisors.exe"
	"C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\CSES_Counting_Divisors.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\CSES_Counting_Divisors.dir\objects1.rsp @<<
 /out:CSES_Counting_Divisors.exe /implib:CSES_Counting_Divisors.lib /pdb:"C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\cmake-build-debug\CSES_Counting_Divisors.pdb" /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\CSES_Counting_Divisors.dir\build: CSES_Counting_Divisors.exe

.PHONY : CMakeFiles\CSES_Counting_Divisors.dir\build

CMakeFiles\CSES_Counting_Divisors.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CSES_Counting_Divisors.dir\cmake_clean.cmake
.PHONY : CMakeFiles\CSES_Counting_Divisors.dir\clean

CMakeFiles\CSES_Counting_Divisors.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors" "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors" "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\cmake-build-debug" "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\cmake-build-debug" "C:\Users\hyung\CLionProjects\USACO\Gold\CSES Counting Divisors\cmake-build-debug\CMakeFiles\CSES_Counting_Divisors.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\CSES_Counting_Divisors.dir\depend

