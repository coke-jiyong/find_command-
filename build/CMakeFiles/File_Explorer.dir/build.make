# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/mytmp/find

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/mytmp/find/build

# Include any dependencies generated for this target.
include CMakeFiles/File_Explorer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/File_Explorer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/File_Explorer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/File_Explorer.dir/flags.make

CMakeFiles/File_Explorer.dir/src/find.c.o: CMakeFiles/File_Explorer.dir/flags.make
CMakeFiles/File_Explorer.dir/src/find.c.o: /home/ubuntu/mytmp/find/src/find.c
CMakeFiles/File_Explorer.dir/src/find.c.o: CMakeFiles/File_Explorer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/mytmp/find/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/File_Explorer.dir/src/find.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/File_Explorer.dir/src/find.c.o -MF CMakeFiles/File_Explorer.dir/src/find.c.o.d -o CMakeFiles/File_Explorer.dir/src/find.c.o -c /home/ubuntu/mytmp/find/src/find.c

CMakeFiles/File_Explorer.dir/src/find.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/File_Explorer.dir/src/find.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/mytmp/find/src/find.c > CMakeFiles/File_Explorer.dir/src/find.c.i

CMakeFiles/File_Explorer.dir/src/find.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/File_Explorer.dir/src/find.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/mytmp/find/src/find.c -o CMakeFiles/File_Explorer.dir/src/find.c.s

CMakeFiles/File_Explorer.dir/src/main.c.o: CMakeFiles/File_Explorer.dir/flags.make
CMakeFiles/File_Explorer.dir/src/main.c.o: /home/ubuntu/mytmp/find/src/main.c
CMakeFiles/File_Explorer.dir/src/main.c.o: CMakeFiles/File_Explorer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ubuntu/mytmp/find/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/File_Explorer.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/File_Explorer.dir/src/main.c.o -MF CMakeFiles/File_Explorer.dir/src/main.c.o.d -o CMakeFiles/File_Explorer.dir/src/main.c.o -c /home/ubuntu/mytmp/find/src/main.c

CMakeFiles/File_Explorer.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/File_Explorer.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/mytmp/find/src/main.c > CMakeFiles/File_Explorer.dir/src/main.c.i

CMakeFiles/File_Explorer.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/File_Explorer.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/mytmp/find/src/main.c -o CMakeFiles/File_Explorer.dir/src/main.c.s

# Object files for target File_Explorer
File_Explorer_OBJECTS = \
"CMakeFiles/File_Explorer.dir/src/find.c.o" \
"CMakeFiles/File_Explorer.dir/src/main.c.o"

# External object files for target File_Explorer
File_Explorer_EXTERNAL_OBJECTS =

File_Explorer: CMakeFiles/File_Explorer.dir/src/find.c.o
File_Explorer: CMakeFiles/File_Explorer.dir/src/main.c.o
File_Explorer: CMakeFiles/File_Explorer.dir/build.make
File_Explorer: CMakeFiles/File_Explorer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ubuntu/mytmp/find/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable File_Explorer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/File_Explorer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/File_Explorer.dir/build: File_Explorer
.PHONY : CMakeFiles/File_Explorer.dir/build

CMakeFiles/File_Explorer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/File_Explorer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/File_Explorer.dir/clean

CMakeFiles/File_Explorer.dir/depend:
	cd /home/ubuntu/mytmp/find/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/mytmp/find /home/ubuntu/mytmp/find /home/ubuntu/mytmp/find/build /home/ubuntu/mytmp/find/build /home/ubuntu/mytmp/find/build/CMakeFiles/File_Explorer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/File_Explorer.dir/depend

