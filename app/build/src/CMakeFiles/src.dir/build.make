# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /Users/msavytskyi/.brew/Cellar/cmake/3.18.1/bin/cmake

# The command to remove a file.
RM = /Users/msavytskyi/.brew/Cellar/cmake/3.18.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/msavytskyi/Desktop/CPP-Snake/app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/msavytskyi/Desktop/CPP-Snake/app/build

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/Food.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Food.cpp.o: ../src/Food.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/msavytskyi/Desktop/CPP-Snake/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/Food.cpp.o"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/Food.cpp.o -c /Users/msavytskyi/Desktop/CPP-Snake/app/src/Food.cpp

src/CMakeFiles/src.dir/Food.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Food.cpp.i"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/msavytskyi/Desktop/CPP-Snake/app/src/Food.cpp > CMakeFiles/src.dir/Food.cpp.i

src/CMakeFiles/src.dir/Food.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Food.cpp.s"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/msavytskyi/Desktop/CPP-Snake/app/src/Food.cpp -o CMakeFiles/src.dir/Food.cpp.s

src/CMakeFiles/src.dir/Snake.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Snake.cpp.o: ../src/Snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/msavytskyi/Desktop/CPP-Snake/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/Snake.cpp.o"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/Snake.cpp.o -c /Users/msavytskyi/Desktop/CPP-Snake/app/src/Snake.cpp

src/CMakeFiles/src.dir/Snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Snake.cpp.i"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/msavytskyi/Desktop/CPP-Snake/app/src/Snake.cpp > CMakeFiles/src.dir/Snake.cpp.i

src/CMakeFiles/src.dir/Snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Snake.cpp.s"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/msavytskyi/Desktop/CPP-Snake/app/src/Snake.cpp -o CMakeFiles/src.dir/Snake.cpp.s

src/CMakeFiles/src.dir/SnakeBlocks.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/SnakeBlocks.cpp.o: ../src/SnakeBlocks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/msavytskyi/Desktop/CPP-Snake/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/SnakeBlocks.cpp.o"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/SnakeBlocks.cpp.o -c /Users/msavytskyi/Desktop/CPP-Snake/app/src/SnakeBlocks.cpp

src/CMakeFiles/src.dir/SnakeBlocks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/SnakeBlocks.cpp.i"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/msavytskyi/Desktop/CPP-Snake/app/src/SnakeBlocks.cpp > CMakeFiles/src.dir/SnakeBlocks.cpp.i

src/CMakeFiles/src.dir/SnakeBlocks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/SnakeBlocks.cpp.s"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/msavytskyi/Desktop/CPP-Snake/app/src/SnakeBlocks.cpp -o CMakeFiles/src.dir/SnakeBlocks.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/Food.cpp.o" \
"CMakeFiles/src.dir/Snake.cpp.o" \
"CMakeFiles/src.dir/SnakeBlocks.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/Food.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/Snake.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/SnakeBlocks.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/msavytskyi/Desktop/CPP-Snake/app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libsrc.a"
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a

.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /Users/msavytskyi/Desktop/CPP-Snake/app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/msavytskyi/Desktop/CPP-Snake/app /Users/msavytskyi/Desktop/CPP-Snake/app/src /Users/msavytskyi/Desktop/CPP-Snake/app/build /Users/msavytskyi/Desktop/CPP-Snake/app/build/src /Users/msavytskyi/Desktop/CPP-Snake/app/build/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

