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
CMAKE_SOURCE_DIR = "C:\Users\hyung\CLionProjects\1020 buildings"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\hyung\CLionProjects\1020 buildings\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\1020_buildings.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\1020_buildings.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\1020_buildings.dir\flags.make

CMakeFiles\1020_buildings.dir\main.cpp.obj: CMakeFiles\1020_buildings.dir\flags.make
CMakeFiles\1020_buildings.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hyung\CLionProjects\1020 buildings\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1020_buildings.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1020_buildings.dir\main.cpp.obj /FdCMakeFiles\1020_buildings.dir\ /FS -c "C:\Users\hyung\CLionProjects\1020 buildings\main.cpp"
<<

CMakeFiles\1020_buildings.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1020_buildings.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx64\x64\cl.exe > CMakeFiles\1020_buildings.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\hyung\CLionProjects\1020 buildings\main.cpp"
<<

CMakeFiles\1020_buildings.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1020_buildings.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1020_buildings.dir\main.cpp.s /c "C:\Users\hyung\CLionProjects\1020 buildings\main.cpp"
<<

# Object files for target 1020_buildings
1020_buildings_OBJECTS = \
"CMakeFiles\1020_buildings.dir\main.cpp.obj"

# External object files for target 1020_buildings
1020_buildings_EXTERNAL_OBJECTS =

1020_buildings.exe: CMakeFiles\1020_buildings.dir\main.cpp.obj
1020_buildings.exe: CMakeFiles\1020_buildings.dir\build.make
1020_buildings.exe: CMakeFiles\1020_buildings.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\hyung\CLionProjects\1020 buildings\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1020_buildings.exe"
	"C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\1020_buildings.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\1020_buildings.dir\objects1.rsp @<<
 /out:1020_buildings.exe /implib:1020_buildings.lib /pdb:"C:\Users\hyung\CLionProjects\1020 buildings\cmake-build-debug\1020_buildings.pdb" /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\1020_buildings.dir\build: 1020_buildings.exe

.PHONY : CMakeFiles\1020_buildings.dir\build

CMakeFiles\1020_buildings.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1020_buildings.dir\cmake_clean.cmake
.PHONY : CMakeFiles\1020_buildings.dir\clean

CMakeFiles\1020_buildings.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\hyung\CLionProjects\1020 buildings" "C:\Users\hyung\CLionProjects\1020 buildings" "C:\Users\hyung\CLionProjects\1020 buildings\cmake-build-debug" "C:\Users\hyung\CLionProjects\1020 buildings\cmake-build-debug" "C:\Users\hyung\CLionProjects\1020 buildings\cmake-build-debug\CMakeFiles\1020_buildings.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\1020_buildings.dir\depend
