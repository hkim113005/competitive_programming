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
CMAKE_SOURCE_DIR = "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\D__Twist_the_Permutation.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\D__Twist_the_Permutation.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\D__Twist_the_Permutation.dir\flags.make

CMakeFiles\D__Twist_the_Permutation.dir\main.cpp.obj: CMakeFiles\D__Twist_the_Permutation.dir\flags.make
CMakeFiles\D__Twist_the_Permutation.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/D__Twist_the_Permutation.dir/main.cpp.obj"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\D__Twist_the_Permutation.dir\main.cpp.obj /FdCMakeFiles\D__Twist_the_Permutation.dir\ /FS -c "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\main.cpp"
<<

CMakeFiles\D__Twist_the_Permutation.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/D__Twist_the_Permutation.dir/main.cpp.i"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx64\x64\cl.exe > CMakeFiles\D__Twist_the_Permutation.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\main.cpp"
<<

CMakeFiles\D__Twist_the_Permutation.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/D__Twist_the_Permutation.dir/main.cpp.s"
	C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\D__Twist_the_Permutation.dir\main.cpp.s /c "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\main.cpp"
<<

# Object files for target D__Twist_the_Permutation
D__Twist_the_Permutation_OBJECTS = \
"CMakeFiles\D__Twist_the_Permutation.dir\main.cpp.obj"

# External object files for target D__Twist_the_Permutation
D__Twist_the_Permutation_EXTERNAL_OBJECTS =

D__Twist_the_Permutation.exe: CMakeFiles\D__Twist_the_Permutation.dir\main.cpp.obj
D__Twist_the_Permutation.exe: CMakeFiles\D__Twist_the_Permutation.dir\build.make
D__Twist_the_Permutation.exe: CMakeFiles\D__Twist_the_Permutation.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D__Twist_the_Permutation.exe"
	"C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\D__Twist_the_Permutation.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x64\mt.exe --manifests  -- C:\PROGRA~1\MICROS~4\2022\COMMUN~1\VC\Tools\MSVC\1431~1.311\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\D__Twist_the_Permutation.dir\objects1.rsp @<<
 /out:D__Twist_the_Permutation.exe /implib:D__Twist_the_Permutation.lib /pdb:"C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\cmake-build-debug\D__Twist_the_Permutation.pdb" /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\D__Twist_the_Permutation.dir\build: D__Twist_the_Permutation.exe

.PHONY : CMakeFiles\D__Twist_the_Permutation.dir\build

CMakeFiles\D__Twist_the_Permutation.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\D__Twist_the_Permutation.dir\cmake_clean.cmake
.PHONY : CMakeFiles\D__Twist_the_Permutation.dir\clean

CMakeFiles\D__Twist_the_Permutation.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation" "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation" "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\cmake-build-debug" "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\cmake-build-debug" "C:\Users\hyung\CLionProjects\Competitive Programming\D. Twist the Permutation\cmake-build-debug\CMakeFiles\D__Twist_the_Permutation.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\D__Twist_the_Permutation.dir\depend

