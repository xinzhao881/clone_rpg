# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/iseungmin/CLionProjects/clone_rpg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/iseungmin/CLionProjects/clone_rpg/build

# Include any dependencies generated for this target.
include CMakeFiles/clone_rpg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/clone_rpg.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clone_rpg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clone_rpg.dir/flags.make

CMakeFiles/clone_rpg.dir/codegen:
.PHONY : CMakeFiles/clone_rpg.dir/codegen

CMakeFiles/clone_rpg.dir/src/main.cpp.o: CMakeFiles/clone_rpg.dir/flags.make
CMakeFiles/clone_rpg.dir/src/main.cpp.o: /Users/iseungmin/CLionProjects/clone_rpg/src/main.cpp
CMakeFiles/clone_rpg.dir/src/main.cpp.o: CMakeFiles/clone_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iseungmin/CLionProjects/clone_rpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clone_rpg.dir/src/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clone_rpg.dir/src/main.cpp.o -MF CMakeFiles/clone_rpg.dir/src/main.cpp.o.d -o CMakeFiles/clone_rpg.dir/src/main.cpp.o -c /Users/iseungmin/CLionProjects/clone_rpg/src/main.cpp

CMakeFiles/clone_rpg.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clone_rpg.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/iseungmin/CLionProjects/clone_rpg/src/main.cpp > CMakeFiles/clone_rpg.dir/src/main.cpp.i

CMakeFiles/clone_rpg.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clone_rpg.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/iseungmin/CLionProjects/clone_rpg/src/main.cpp -o CMakeFiles/clone_rpg.dir/src/main.cpp.s

CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.o: CMakeFiles/clone_rpg.dir/flags.make
CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.o: /Users/iseungmin/CLionProjects/clone_rpg/src/stats/hp.cpp
CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.o: CMakeFiles/clone_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iseungmin/CLionProjects/clone_rpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.o -MF CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.o.d -o CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.o -c /Users/iseungmin/CLionProjects/clone_rpg/src/stats/hp.cpp

CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/iseungmin/CLionProjects/clone_rpg/src/stats/hp.cpp > CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.i

CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/iseungmin/CLionProjects/clone_rpg/src/stats/hp.cpp -o CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.s

CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.o: CMakeFiles/clone_rpg.dir/flags.make
CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.o: /Users/iseungmin/CLionProjects/clone_rpg/src/character/warrior.cpp
CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.o: CMakeFiles/clone_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iseungmin/CLionProjects/clone_rpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.o -MF CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.o.d -o CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.o -c /Users/iseungmin/CLionProjects/clone_rpg/src/character/warrior.cpp

CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/iseungmin/CLionProjects/clone_rpg/src/character/warrior.cpp > CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.i

CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/iseungmin/CLionProjects/clone_rpg/src/character/warrior.cpp -o CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.s

CMakeFiles/clone_rpg.dir/src/character/mage.cpp.o: CMakeFiles/clone_rpg.dir/flags.make
CMakeFiles/clone_rpg.dir/src/character/mage.cpp.o: /Users/iseungmin/CLionProjects/clone_rpg/src/character/mage.cpp
CMakeFiles/clone_rpg.dir/src/character/mage.cpp.o: CMakeFiles/clone_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iseungmin/CLionProjects/clone_rpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/clone_rpg.dir/src/character/mage.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clone_rpg.dir/src/character/mage.cpp.o -MF CMakeFiles/clone_rpg.dir/src/character/mage.cpp.o.d -o CMakeFiles/clone_rpg.dir/src/character/mage.cpp.o -c /Users/iseungmin/CLionProjects/clone_rpg/src/character/mage.cpp

CMakeFiles/clone_rpg.dir/src/character/mage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clone_rpg.dir/src/character/mage.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/iseungmin/CLionProjects/clone_rpg/src/character/mage.cpp > CMakeFiles/clone_rpg.dir/src/character/mage.cpp.i

CMakeFiles/clone_rpg.dir/src/character/mage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clone_rpg.dir/src/character/mage.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/iseungmin/CLionProjects/clone_rpg/src/character/mage.cpp -o CMakeFiles/clone_rpg.dir/src/character/mage.cpp.s

CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.o: CMakeFiles/clone_rpg.dir/flags.make
CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.o: /Users/iseungmin/CLionProjects/clone_rpg/src/game\ manager/gameManager.cpp
CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.o: CMakeFiles/clone_rpg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/iseungmin/CLionProjects/clone_rpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.o -MF CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.o.d -o CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.o -c "/Users/iseungmin/CLionProjects/clone_rpg/src/game manager/gameManager.cpp"

CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/iseungmin/CLionProjects/clone_rpg/src/game manager/gameManager.cpp" > CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.i

CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/iseungmin/CLionProjects/clone_rpg/src/game manager/gameManager.cpp" -o CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.s

# Object files for target clone_rpg
clone_rpg_OBJECTS = \
"CMakeFiles/clone_rpg.dir/src/main.cpp.o" \
"CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.o" \
"CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.o" \
"CMakeFiles/clone_rpg.dir/src/character/mage.cpp.o" \
"CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.o"

# External object files for target clone_rpg
clone_rpg_EXTERNAL_OBJECTS =

clone_rpg: CMakeFiles/clone_rpg.dir/src/main.cpp.o
clone_rpg: CMakeFiles/clone_rpg.dir/src/stats/hp.cpp.o
clone_rpg: CMakeFiles/clone_rpg.dir/src/character/warrior.cpp.o
clone_rpg: CMakeFiles/clone_rpg.dir/src/character/mage.cpp.o
clone_rpg: CMakeFiles/clone_rpg.dir/src/game_manager/gameManager.cpp.o
clone_rpg: CMakeFiles/clone_rpg.dir/build.make
clone_rpg: CMakeFiles/clone_rpg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/iseungmin/CLionProjects/clone_rpg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable clone_rpg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clone_rpg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clone_rpg.dir/build: clone_rpg
.PHONY : CMakeFiles/clone_rpg.dir/build

CMakeFiles/clone_rpg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clone_rpg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clone_rpg.dir/clean

CMakeFiles/clone_rpg.dir/depend:
	cd /Users/iseungmin/CLionProjects/clone_rpg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/iseungmin/CLionProjects/clone_rpg /Users/iseungmin/CLionProjects/clone_rpg /Users/iseungmin/CLionProjects/clone_rpg/build /Users/iseungmin/CLionProjects/clone_rpg/build /Users/iseungmin/CLionProjects/clone_rpg/build/CMakeFiles/clone_rpg.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/clone_rpg.dir/depend

