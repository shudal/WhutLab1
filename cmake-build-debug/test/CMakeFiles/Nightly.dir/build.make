# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/perci/CLionProjects/untitled1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug

# Utility rule file for Nightly.

# Include the progress variables for this target.
include test/CMakeFiles/Nightly.dir/progress.make

test/CMakeFiles/Nightly:
	cd /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug/test && /usr/bin/ctest -D Nightly

Nightly: test/CMakeFiles/Nightly
Nightly: test/CMakeFiles/Nightly.dir/build.make

.PHONY : Nightly

# Rule to build all files generated by this target.
test/CMakeFiles/Nightly.dir/build: Nightly

.PHONY : test/CMakeFiles/Nightly.dir/build

test/CMakeFiles/Nightly.dir/clean:
	cd /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/Nightly.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/Nightly.dir/clean

test/CMakeFiles/Nightly.dir/depend:
	cd /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/perci/CLionProjects/untitled1 /mnt/c/Users/perci/CLionProjects/untitled1/test /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug/test /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug/test/CMakeFiles/Nightly.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/Nightly.dir/depend

