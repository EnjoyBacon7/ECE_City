# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/camille/Documents/GitHub/ECE_City/ECE_City

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ECE_City.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ECE_City.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ECE_City.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ECE_City.dir/flags.make

CMakeFiles/ECE_City.dir/main.c.o: CMakeFiles/ECE_City.dir/flags.make
CMakeFiles/ECE_City.dir/main.c.o: ../main.c
CMakeFiles/ECE_City.dir/main.c.o: CMakeFiles/ECE_City.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ECE_City.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ECE_City.dir/main.c.o -MF CMakeFiles/ECE_City.dir/main.c.o.d -o CMakeFiles/ECE_City.dir/main.c.o -c /Users/camille/Documents/GitHub/ECE_City/ECE_City/main.c

CMakeFiles/ECE_City.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ECE_City.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/camille/Documents/GitHub/ECE_City/ECE_City/main.c > CMakeFiles/ECE_City.dir/main.c.i

CMakeFiles/ECE_City.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ECE_City.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/camille/Documents/GitHub/ECE_City/ECE_City/main.c -o CMakeFiles/ECE_City.dir/main.c.s

CMakeFiles/ECE_City.dir/extras.c.o: CMakeFiles/ECE_City.dir/flags.make
CMakeFiles/ECE_City.dir/extras.c.o: ../extras.c
CMakeFiles/ECE_City.dir/extras.c.o: CMakeFiles/ECE_City.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ECE_City.dir/extras.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ECE_City.dir/extras.c.o -MF CMakeFiles/ECE_City.dir/extras.c.o.d -o CMakeFiles/ECE_City.dir/extras.c.o -c /Users/camille/Documents/GitHub/ECE_City/ECE_City/extras.c

CMakeFiles/ECE_City.dir/extras.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ECE_City.dir/extras.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/camille/Documents/GitHub/ECE_City/ECE_City/extras.c > CMakeFiles/ECE_City.dir/extras.c.i

CMakeFiles/ECE_City.dir/extras.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ECE_City.dir/extras.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/camille/Documents/GitHub/ECE_City/ECE_City/extras.c -o CMakeFiles/ECE_City.dir/extras.c.s

CMakeFiles/ECE_City.dir/boucleJeu.c.o: CMakeFiles/ECE_City.dir/flags.make
CMakeFiles/ECE_City.dir/boucleJeu.c.o: ../boucleJeu.c
CMakeFiles/ECE_City.dir/boucleJeu.c.o: CMakeFiles/ECE_City.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ECE_City.dir/boucleJeu.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ECE_City.dir/boucleJeu.c.o -MF CMakeFiles/ECE_City.dir/boucleJeu.c.o.d -o CMakeFiles/ECE_City.dir/boucleJeu.c.o -c /Users/camille/Documents/GitHub/ECE_City/ECE_City/boucleJeu.c

CMakeFiles/ECE_City.dir/boucleJeu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ECE_City.dir/boucleJeu.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/camille/Documents/GitHub/ECE_City/ECE_City/boucleJeu.c > CMakeFiles/ECE_City.dir/boucleJeu.c.i

CMakeFiles/ECE_City.dir/boucleJeu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ECE_City.dir/boucleJeu.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/camille/Documents/GitHub/ECE_City/ECE_City/boucleJeu.c -o CMakeFiles/ECE_City.dir/boucleJeu.c.s

CMakeFiles/ECE_City.dir/initPartie.c.o: CMakeFiles/ECE_City.dir/flags.make
CMakeFiles/ECE_City.dir/initPartie.c.o: ../initPartie.c
CMakeFiles/ECE_City.dir/initPartie.c.o: CMakeFiles/ECE_City.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ECE_City.dir/initPartie.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ECE_City.dir/initPartie.c.o -MF CMakeFiles/ECE_City.dir/initPartie.c.o.d -o CMakeFiles/ECE_City.dir/initPartie.c.o -c /Users/camille/Documents/GitHub/ECE_City/ECE_City/initPartie.c

CMakeFiles/ECE_City.dir/initPartie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ECE_City.dir/initPartie.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/camille/Documents/GitHub/ECE_City/ECE_City/initPartie.c > CMakeFiles/ECE_City.dir/initPartie.c.i

CMakeFiles/ECE_City.dir/initPartie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ECE_City.dir/initPartie.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/camille/Documents/GitHub/ECE_City/ECE_City/initPartie.c -o CMakeFiles/ECE_City.dir/initPartie.c.s

CMakeFiles/ECE_City.dir/menus.c.o: CMakeFiles/ECE_City.dir/flags.make
CMakeFiles/ECE_City.dir/menus.c.o: ../menus.c
CMakeFiles/ECE_City.dir/menus.c.o: CMakeFiles/ECE_City.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ECE_City.dir/menus.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ECE_City.dir/menus.c.o -MF CMakeFiles/ECE_City.dir/menus.c.o.d -o CMakeFiles/ECE_City.dir/menus.c.o -c /Users/camille/Documents/GitHub/ECE_City/ECE_City/menus.c

CMakeFiles/ECE_City.dir/menus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ECE_City.dir/menus.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/camille/Documents/GitHub/ECE_City/ECE_City/menus.c > CMakeFiles/ECE_City.dir/menus.c.i

CMakeFiles/ECE_City.dir/menus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ECE_City.dir/menus.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/camille/Documents/GitHub/ECE_City/ECE_City/menus.c -o CMakeFiles/ECE_City.dir/menus.c.s

CMakeFiles/ECE_City.dir/affichage.c.o: CMakeFiles/ECE_City.dir/flags.make
CMakeFiles/ECE_City.dir/affichage.c.o: ../affichage.c
CMakeFiles/ECE_City.dir/affichage.c.o: CMakeFiles/ECE_City.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/ECE_City.dir/affichage.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ECE_City.dir/affichage.c.o -MF CMakeFiles/ECE_City.dir/affichage.c.o.d -o CMakeFiles/ECE_City.dir/affichage.c.o -c /Users/camille/Documents/GitHub/ECE_City/ECE_City/affichage.c

CMakeFiles/ECE_City.dir/affichage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ECE_City.dir/affichage.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/camille/Documents/GitHub/ECE_City/ECE_City/affichage.c > CMakeFiles/ECE_City.dir/affichage.c.i

CMakeFiles/ECE_City.dir/affichage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ECE_City.dir/affichage.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/camille/Documents/GitHub/ECE_City/ECE_City/affichage.c -o CMakeFiles/ECE_City.dir/affichage.c.s

# Object files for target ECE_City
ECE_City_OBJECTS = \
"CMakeFiles/ECE_City.dir/main.c.o" \
"CMakeFiles/ECE_City.dir/extras.c.o" \
"CMakeFiles/ECE_City.dir/boucleJeu.c.o" \
"CMakeFiles/ECE_City.dir/initPartie.c.o" \
"CMakeFiles/ECE_City.dir/menus.c.o" \
"CMakeFiles/ECE_City.dir/affichage.c.o"

# External object files for target ECE_City
ECE_City_EXTERNAL_OBJECTS =

ECE_City: CMakeFiles/ECE_City.dir/main.c.o
ECE_City: CMakeFiles/ECE_City.dir/extras.c.o
ECE_City: CMakeFiles/ECE_City.dir/boucleJeu.c.o
ECE_City: CMakeFiles/ECE_City.dir/initPartie.c.o
ECE_City: CMakeFiles/ECE_City.dir/menus.c.o
ECE_City: CMakeFiles/ECE_City.dir/affichage.c.o
ECE_City: CMakeFiles/ECE_City.dir/build.make
ECE_City: CMakeFiles/ECE_City.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable ECE_City"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ECE_City.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ECE_City.dir/build: ECE_City
.PHONY : CMakeFiles/ECE_City.dir/build

CMakeFiles/ECE_City.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ECE_City.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ECE_City.dir/clean

CMakeFiles/ECE_City.dir/depend:
	cd /Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/camille/Documents/GitHub/ECE_City/ECE_City /Users/camille/Documents/GitHub/ECE_City/ECE_City /Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug /Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug /Users/camille/Documents/GitHub/ECE_City/ECE_City/cmake-build-debug/CMakeFiles/ECE_City.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ECE_City.dir/depend

