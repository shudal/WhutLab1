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

# Include any dependencies generated for this target.
include CMakeFiles/mytest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mytest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mytest.dir/flags.make

CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o: CMakeFiles/mytest.dir/flags.make
CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o: ../src/test/piczip/piczip_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o -c /mnt/c/Users/perci/CLionProjects/untitled1/src/test/piczip/piczip_test.cpp

CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/perci/CLionProjects/untitled1/src/test/piczip/piczip_test.cpp > CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.i

CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/perci/CLionProjects/untitled1/src/test/piczip/piczip_test.cpp -o CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.s

CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o.requires:

.PHONY : CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o.requires

CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o.provides: CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/mytest.dir/build.make CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o.provides.build
.PHONY : CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o.provides

CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o.provides.build: CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o


# Object files for target mytest
mytest_OBJECTS = \
"CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o"

# External object files for target mytest
mytest_EXTERNAL_OBJECTS =

mytest: CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o
mytest: CMakeFiles/mytest.dir/build.make
mytest: lib/libgtestd.a
mytest: lib/libgtest_maind.a
mytest: lib/libgtestd.a
mytest: CMakeFiles/mytest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mytest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mytest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mytest.dir/build: mytest

.PHONY : CMakeFiles/mytest.dir/build

CMakeFiles/mytest.dir/requires: CMakeFiles/mytest.dir/src/test/piczip/piczip_test.cpp.o.requires

.PHONY : CMakeFiles/mytest.dir/requires

CMakeFiles/mytest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mytest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mytest.dir/clean

CMakeFiles/mytest.dir/depend:
	cd /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/perci/CLionProjects/untitled1 /mnt/c/Users/perci/CLionProjects/untitled1 /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug /mnt/c/Users/perci/CLionProjects/untitled1/cmake-build-debug/CMakeFiles/mytest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mytest.dir/depend

