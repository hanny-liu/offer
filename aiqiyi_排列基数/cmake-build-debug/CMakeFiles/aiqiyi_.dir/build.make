# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/lhw/Downloads/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lhw/Downloads/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lhw/workspace/c++/aiqiyi_排列基数

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lhw/workspace/c++/aiqiyi_排列基数/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/aiqiyi_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aiqiyi_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aiqiyi_.dir/flags.make

CMakeFiles/aiqiyi_.dir/main.cpp.o: CMakeFiles/aiqiyi_.dir/flags.make
CMakeFiles/aiqiyi_.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lhw/workspace/c++/aiqiyi_排列基数/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aiqiyi_.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/aiqiyi_.dir/main.cpp.o -c /home/lhw/workspace/c++/aiqiyi_排列基数/main.cpp

CMakeFiles/aiqiyi_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aiqiyi_.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lhw/workspace/c++/aiqiyi_排列基数/main.cpp > CMakeFiles/aiqiyi_.dir/main.cpp.i

CMakeFiles/aiqiyi_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aiqiyi_.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lhw/workspace/c++/aiqiyi_排列基数/main.cpp -o CMakeFiles/aiqiyi_.dir/main.cpp.s

# Object files for target aiqiyi_
aiqiyi__OBJECTS = \
"CMakeFiles/aiqiyi_.dir/main.cpp.o"

# External object files for target aiqiyi_
aiqiyi__EXTERNAL_OBJECTS =

aiqiyi_: CMakeFiles/aiqiyi_.dir/main.cpp.o
aiqiyi_: CMakeFiles/aiqiyi_.dir/build.make
aiqiyi_: CMakeFiles/aiqiyi_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lhw/workspace/c++/aiqiyi_排列基数/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aiqiyi_"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aiqiyi_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aiqiyi_.dir/build: aiqiyi_

.PHONY : CMakeFiles/aiqiyi_.dir/build

CMakeFiles/aiqiyi_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aiqiyi_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aiqiyi_.dir/clean

CMakeFiles/aiqiyi_.dir/depend:
	cd /home/lhw/workspace/c++/aiqiyi_排列基数/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lhw/workspace/c++/aiqiyi_排列基数 /home/lhw/workspace/c++/aiqiyi_排列基数 /home/lhw/workspace/c++/aiqiyi_排列基数/cmake-build-debug /home/lhw/workspace/c++/aiqiyi_排列基数/cmake-build-debug /home/lhw/workspace/c++/aiqiyi_排列基数/cmake-build-debug/CMakeFiles/aiqiyi_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aiqiyi_.dir/depend

