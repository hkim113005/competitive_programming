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
CMAKE_SOURCE_DIR = "C:\Users\hyung\CLionProjects\Where Am I"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\hyung\CLionProjects\Where Am I\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Where_Am_I.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Where_Am_I.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Where_Am_I.dir\flags.make

CMakeFiles\Where_Am_I.dir\main.cpp.obj: CMakeFiles\Where_Am_I.dir\flags.make
CMakeFiles\Where_Am_I.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hyung\CLionProjects\Where Am I\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Where_Am_I.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Where_Am_I.dir\main.cpp.obj /FdCMakeFiles\Where_Am_I.dir\ /FS -c "C:\Users\hyung\CLionProjects\Where Am I\main.cpp"
<<

CMakeFiles\Where_Am_I.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Where_Am_I.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\Where_Am_I.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\hyung\CLionProjects\Where Am I\main.cpp"
<<

CMakeFiles\Where_Am_I.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Where_Am_I.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Where_Am_I.dir\main.cpp.s /c "C:\Users\hyung\CLionProjects\Where Am I\main.cpp"
<<

# Object files for target Where_Am_I
Where_Am_I_OBJECTS = \
"CMakeFiles\Where_Am_I.dir\main.cpp.obj"

# External object files for target Where_Am_I
Where_Am_I_EXTERNAL_OBJECTS =

Where_Am_I.exe: CMakeFiles\Where_Am_I.dir\main.cpp.obj
Where_Am_I.exe: CMakeFiles\Where_Am_I.dir\build.make
Where_Am_I.exe: CMakeFiles\Where_Am_I.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\hyung\CLionProjects\Where Am I\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Where_Am_I.exe"
	"C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Where_Am_I.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\Where_Am_I.dir\objects1.rsp @<<
 /out:Where_Am_I.exe /implib:Where_Am_I.lib /pdb:"C:\Users\hyung\CLionProjects\Where Am I\cmake-build-debug\Where_Am_I.pdb" /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Where_Am_I.dir\build: Where_Am_I.exe

.PHONY : CMakeFiles\Where_Am_I.dir\build

CMakeFiles\Where_Am_I.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Where_Am_I.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Where_Am_I.dir\clean

CMakeFiles\Where_Am_I.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\hyung\CLionProjects\Where Am I" "C:\Users\hyung\CLionProjects\Where Am I" "C:\Users\hyung\CLionProjects\Where Am I\cmake-build-debug" "C:\Users\hyung\CLionProjects\Where Am I\cmake-build-debug" "C:\Users\hyung\CLionProjects\Where Am I\cmake-build-debug\CMakeFiles\Where_Am_I.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Where_Am_I.dir\depend
