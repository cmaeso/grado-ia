# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2023.1.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2023.1.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = R:\Desktop\ED1Hospital

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = R:\Desktop\ED1Hospital\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ED1Hospital.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ED1Hospital.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ED1Hospital.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ED1Hospital.dir/flags.make

CMakeFiles/ED1Hospital.dir/main.c.obj: CMakeFiles/ED1Hospital.dir/flags.make
CMakeFiles/ED1Hospital.dir/main.c.obj: R:/Desktop/ED1Hospital/main.c
CMakeFiles/ED1Hospital.dir/main.c.obj: CMakeFiles/ED1Hospital.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=R:\Desktop\ED1Hospital\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ED1Hospital.dir/main.c.obj"
	C:\PROGRA~2\JETBRA~1\CLION2~2.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ED1Hospital.dir/main.c.obj -MF CMakeFiles\ED1Hospital.dir\main.c.obj.d -o CMakeFiles\ED1Hospital.dir\main.c.obj -c R:\Desktop\ED1Hospital\main.c

CMakeFiles/ED1Hospital.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ED1Hospital.dir/main.c.i"
	C:\PROGRA~2\JETBRA~1\CLION2~2.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E R:\Desktop\ED1Hospital\main.c > CMakeFiles\ED1Hospital.dir\main.c.i

CMakeFiles/ED1Hospital.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ED1Hospital.dir/main.c.s"
	C:\PROGRA~2\JETBRA~1\CLION2~2.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S R:\Desktop\ED1Hospital\main.c -o CMakeFiles\ED1Hospital.dir\main.c.s

CMakeFiles/ED1Hospital.dir/hospital.c.obj: CMakeFiles/ED1Hospital.dir/flags.make
CMakeFiles/ED1Hospital.dir/hospital.c.obj: R:/Desktop/ED1Hospital/hospital.c
CMakeFiles/ED1Hospital.dir/hospital.c.obj: CMakeFiles/ED1Hospital.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=R:\Desktop\ED1Hospital\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ED1Hospital.dir/hospital.c.obj"
	C:\PROGRA~2\JETBRA~1\CLION2~2.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ED1Hospital.dir/hospital.c.obj -MF CMakeFiles\ED1Hospital.dir\hospital.c.obj.d -o CMakeFiles\ED1Hospital.dir\hospital.c.obj -c R:\Desktop\ED1Hospital\hospital.c

CMakeFiles/ED1Hospital.dir/hospital.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ED1Hospital.dir/hospital.c.i"
	C:\PROGRA~2\JETBRA~1\CLION2~2.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E R:\Desktop\ED1Hospital\hospital.c > CMakeFiles\ED1Hospital.dir\hospital.c.i

CMakeFiles/ED1Hospital.dir/hospital.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ED1Hospital.dir/hospital.c.s"
	C:\PROGRA~2\JETBRA~1\CLION2~2.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S R:\Desktop\ED1Hospital\hospital.c -o CMakeFiles\ED1Hospital.dir\hospital.c.s

# Object files for target ED1Hospital
ED1Hospital_OBJECTS = \
"CMakeFiles/ED1Hospital.dir/main.c.obj" \
"CMakeFiles/ED1Hospital.dir/hospital.c.obj"

# External object files for target ED1Hospital
ED1Hospital_EXTERNAL_OBJECTS =

ED1Hospital.exe: CMakeFiles/ED1Hospital.dir/main.c.obj
ED1Hospital.exe: CMakeFiles/ED1Hospital.dir/hospital.c.obj
ED1Hospital.exe: CMakeFiles/ED1Hospital.dir/build.make
ED1Hospital.exe: CMakeFiles/ED1Hospital.dir/linkLibs.rsp
ED1Hospital.exe: CMakeFiles/ED1Hospital.dir/objects1
ED1Hospital.exe: CMakeFiles/ED1Hospital.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=R:\Desktop\ED1Hospital\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ED1Hospital.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ED1Hospital.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ED1Hospital.dir/build: ED1Hospital.exe
.PHONY : CMakeFiles/ED1Hospital.dir/build

CMakeFiles/ED1Hospital.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ED1Hospital.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ED1Hospital.dir/clean

CMakeFiles/ED1Hospital.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" R:\Desktop\ED1Hospital R:\Desktop\ED1Hospital R:\Desktop\ED1Hospital\cmake-build-debug R:\Desktop\ED1Hospital\cmake-build-debug R:\Desktop\ED1Hospital\cmake-build-debug\CMakeFiles\ED1Hospital.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ED1Hospital.dir/depend

