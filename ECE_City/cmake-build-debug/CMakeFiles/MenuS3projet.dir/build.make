# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MenuS3projet.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MenuS3projet.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MenuS3projet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MenuS3projet.dir/flags.make

CMakeFiles/MenuS3projet.dir/main.c.obj: CMakeFiles/MenuS3projet.dir/flags.make
CMakeFiles/MenuS3projet.dir/main.c.obj: ../main.c
CMakeFiles/MenuS3projet.dir/main.c.obj: CMakeFiles/MenuS3projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MenuS3projet.dir/main.c.obj"
	C:\Users\codos\Downloads\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MenuS3projet.dir/main.c.obj -MF CMakeFiles\MenuS3projet.dir\main.c.obj.d -o CMakeFiles\MenuS3projet.dir\main.c.obj -c C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\main.c

CMakeFiles/MenuS3projet.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MenuS3projet.dir/main.c.i"
	C:\Users\codos\Downloads\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\main.c > CMakeFiles\MenuS3projet.dir\main.c.i

CMakeFiles/MenuS3projet.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MenuS3projet.dir/main.c.s"
	C:\Users\codos\Downloads\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\main.c -o CMakeFiles\MenuS3projet.dir\main.c.s

CMakeFiles/MenuS3projet.dir/Menu.c.obj: CMakeFiles/MenuS3projet.dir/flags.make
CMakeFiles/MenuS3projet.dir/Menu.c.obj: ../Menu.c
CMakeFiles/MenuS3projet.dir/Menu.c.obj: CMakeFiles/MenuS3projet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MenuS3projet.dir/Menu.c.obj"
	C:\Users\codos\Downloads\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MenuS3projet.dir/Menu.c.obj -MF CMakeFiles\MenuS3projet.dir\Menu.c.obj.d -o CMakeFiles\MenuS3projet.dir\Menu.c.obj -c C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\Menu.c

CMakeFiles/MenuS3projet.dir/Menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MenuS3projet.dir/Menu.c.i"
	C:\Users\codos\Downloads\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\Menu.c > CMakeFiles\MenuS3projet.dir\Menu.c.i

CMakeFiles/MenuS3projet.dir/Menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MenuS3projet.dir/Menu.c.s"
	C:\Users\codos\Downloads\MinGW\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\Menu.c -o CMakeFiles\MenuS3projet.dir\Menu.c.s

# Object files for target MenuS3projet
MenuS3projet_OBJECTS = \
"CMakeFiles/MenuS3projet.dir/main.c.obj" \
"CMakeFiles/MenuS3projet.dir/Menu.c.obj"

# External object files for target MenuS3projet
MenuS3projet_EXTERNAL_OBJECTS =

MenuS3projet.exe: CMakeFiles/MenuS3projet.dir/main.c.obj
MenuS3projet.exe: CMakeFiles/MenuS3projet.dir/Menu.c.obj
MenuS3projet.exe: CMakeFiles/MenuS3projet.dir/build.make
MenuS3projet.exe: CMakeFiles/MenuS3projet.dir/linklibs.rsp
MenuS3projet.exe: CMakeFiles/MenuS3projet.dir/objects1.rsp
MenuS3projet.exe: CMakeFiles/MenuS3projet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable MenuS3projet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MenuS3projet.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MenuS3projet.dir/build: MenuS3projet.exe
.PHONY : CMakeFiles/MenuS3projet.dir/build

CMakeFiles/MenuS3projet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MenuS3projet.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MenuS3projet.dir/clean

CMakeFiles/MenuS3projet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\cmake-build-debug C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\cmake-build-debug C:\Users\codos\OneDrive\Documents\GitHub\ECE_City\ECE_City\cmake-build-debug\CMakeFiles\MenuS3projet.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MenuS3projet.dir/depend
