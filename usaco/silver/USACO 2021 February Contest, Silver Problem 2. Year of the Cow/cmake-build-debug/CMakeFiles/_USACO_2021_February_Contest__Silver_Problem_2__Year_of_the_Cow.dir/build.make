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
CMAKE_SOURCE_DIR = "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\flags.make

CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\main.cpp.obj: CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\flags.make
CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\main.cpp.obj /FdCMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\ /FS -c "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\main.cpp"
<<

CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe > CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\main.cpp"
<<

CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\main.cpp.s /c "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\main.cpp"
<<

# Object files for target _USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow
_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow_OBJECTS = \
"CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\main.cpp.obj"

# External object files for target _USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow
_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow_EXTERNAL_OBJECTS =

_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.exe: CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\main.cpp.obj
_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.exe: CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\build.make
_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.exe: CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.exe"
	"C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x64\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\objects1.rsp @<<
 /out:_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.exe /implib:_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.lib /pdb:"C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\cmake-build-debug\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.pdb" /version:0.0  /machine:x64 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\build: _USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.exe

.PHONY : CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\build

CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\cmake_clean.cmake
.PHONY : CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\clean

CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow" "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow" "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\cmake-build-debug" "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\cmake-build-debug" "C:\Users\hyung\CLionProjects\USACO\Silver\ USACO 2021 February Contest, Silver Problem 2. Year of the Cow\cmake-build-debug\CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\_USACO_2021_February_Contest__Silver_Problem_2__Year_of_the_Cow.dir\depend

