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
CMAKE_SOURCE_DIR = /home/lhw/workspace/c++/offer_9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lhw/workspace/c++/offer_9/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/offer_9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/offer_9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/offer_9.dir/flags.make

CMakeFiles/offer_9.dir/main.cpp.o: CMakeFiles/offer_9.dir/flags.make
CMakeFiles/offer_9.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lhw/workspace/c++/offer_9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/offer_9.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/offer_9.dir/main.cpp.o -c /home/lhw/workspace/c++/offer_9/main.cpp

CMakeFiles/offer_9.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/offer_9.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lhw/workspace/c++/offer_9/main.cpp > CMakeFiles/offer_9.dir/main.cpp.i

CMakeFiles/offer_9.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/offer_9.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lhw/workspace/c++/offer_9/main.cpp -o CMakeFiles/offer_9.dir/main.cpp.s

# Object files for target offer_9
offer_9_OBJECTS = \
"CMakeFiles/offer_9.dir/main.cpp.o"

# External object files for target offer_9
offer_9_EXTERNAL_OBJECTS =

offer_9: CMakeFiles/offer_9.dir/main.cpp.o
offer_9: CMakeFiles/offer_9.dir/build.make
offer_9: CMakeFiles/offer_9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lhw/workspace/c++/offer_9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable offer_9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/offer_9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/offer_9.dir/build: offer_9

.PHONY : CMakeFiles/offer_9.dir/build

CMakeFiles/offer_9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/offer_9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/offer_9.dir/clean

CMakeFiles/offer_9.dir/depend:
	cd /home/lhw/workspace/c++/offer_9/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lhw/workspace/c++/offer_9 /home/lhw/workspace/c++/offer_9 /home/lhw/workspace/c++/offer_9/cmake-build-debug /home/lhw/workspace/c++/offer_9/cmake-build-debug /home/lhw/workspace/c++/offer_9/cmake-build-debug/CMakeFiles/offer_9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/offer_9.dir/depend

