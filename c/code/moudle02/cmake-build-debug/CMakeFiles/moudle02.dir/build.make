# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/flycba/clion-2016.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/flycba/clion-2016.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/flycba/code/moudle02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/flycba/code/moudle02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/moudle02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/moudle02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/moudle02.dir/flags.make

CMakeFiles/moudle02.dir/hello.c.o: CMakeFiles/moudle02.dir/flags.make
CMakeFiles/moudle02.dir/hello.c.o: ../hello.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/flycba/code/moudle02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/moudle02.dir/hello.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/moudle02.dir/hello.c.o   -c /home/flycba/code/moudle02/hello.c

CMakeFiles/moudle02.dir/hello.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/moudle02.dir/hello.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/flycba/code/moudle02/hello.c > CMakeFiles/moudle02.dir/hello.c.i

CMakeFiles/moudle02.dir/hello.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/moudle02.dir/hello.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/flycba/code/moudle02/hello.c -o CMakeFiles/moudle02.dir/hello.c.s

CMakeFiles/moudle02.dir/hello.c.o.requires:

.PHONY : CMakeFiles/moudle02.dir/hello.c.o.requires

CMakeFiles/moudle02.dir/hello.c.o.provides: CMakeFiles/moudle02.dir/hello.c.o.requires
	$(MAKE) -f CMakeFiles/moudle02.dir/build.make CMakeFiles/moudle02.dir/hello.c.o.provides.build
.PHONY : CMakeFiles/moudle02.dir/hello.c.o.provides

CMakeFiles/moudle02.dir/hello.c.o.provides.build: CMakeFiles/moudle02.dir/hello.c.o


# Object files for target moudle02
moudle02_OBJECTS = \
"CMakeFiles/moudle02.dir/hello.c.o"

# External object files for target moudle02
moudle02_EXTERNAL_OBJECTS =

moudle02: CMakeFiles/moudle02.dir/hello.c.o
moudle02: CMakeFiles/moudle02.dir/build.make
moudle02: CMakeFiles/moudle02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/flycba/code/moudle02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable moudle02"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/moudle02.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/moudle02.dir/build: moudle02

.PHONY : CMakeFiles/moudle02.dir/build

CMakeFiles/moudle02.dir/requires: CMakeFiles/moudle02.dir/hello.c.o.requires

.PHONY : CMakeFiles/moudle02.dir/requires

CMakeFiles/moudle02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/moudle02.dir/cmake_clean.cmake
.PHONY : CMakeFiles/moudle02.dir/clean

CMakeFiles/moudle02.dir/depend:
	cd /home/flycba/code/moudle02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/flycba/code/moudle02 /home/flycba/code/moudle02 /home/flycba/code/moudle02/cmake-build-debug /home/flycba/code/moudle02/cmake-build-debug /home/flycba/code/moudle02/cmake-build-debug/CMakeFiles/moudle02.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/moudle02.dir/depend

