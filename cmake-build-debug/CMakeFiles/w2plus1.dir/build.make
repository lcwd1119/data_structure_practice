# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\d4050\Documents\program\data structure"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\d4050\Documents\program\data structure\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/w2plus1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/w2plus1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/w2plus1.dir/flags.make

CMakeFiles/w2plus1.dir/w2/w2plus1.cpp.obj: CMakeFiles/w2plus1.dir/flags.make
CMakeFiles/w2plus1.dir/w2/w2plus1.cpp.obj: ../w2/w2plus1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\d4050\Documents\program\data structure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/w2plus1.dir/w2/w2plus1.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\w2plus1.dir\w2\w2plus1.cpp.obj -c "C:\Users\d4050\Documents\program\data structure\w2\w2plus1.cpp"

CMakeFiles/w2plus1.dir/w2/w2plus1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/w2plus1.dir/w2/w2plus1.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\d4050\Documents\program\data structure\w2\w2plus1.cpp" > CMakeFiles\w2plus1.dir\w2\w2plus1.cpp.i

CMakeFiles/w2plus1.dir/w2/w2plus1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/w2plus1.dir/w2/w2plus1.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\d4050\Documents\program\data structure\w2\w2plus1.cpp" -o CMakeFiles\w2plus1.dir\w2\w2plus1.cpp.s

# Object files for target w2plus1
w2plus1_OBJECTS = \
"CMakeFiles/w2plus1.dir/w2/w2plus1.cpp.obj"

# External object files for target w2plus1
w2plus1_EXTERNAL_OBJECTS =

w2plus1.exe: CMakeFiles/w2plus1.dir/w2/w2plus1.cpp.obj
w2plus1.exe: CMakeFiles/w2plus1.dir/build.make
w2plus1.exe: CMakeFiles/w2plus1.dir/linklibs.rsp
w2plus1.exe: CMakeFiles/w2plus1.dir/objects1.rsp
w2plus1.exe: CMakeFiles/w2plus1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\d4050\Documents\program\data structure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable w2plus1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\w2plus1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/w2plus1.dir/build: w2plus1.exe

.PHONY : CMakeFiles/w2plus1.dir/build

CMakeFiles/w2plus1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\w2plus1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/w2plus1.dir/clean

CMakeFiles/w2plus1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\d4050\Documents\program\data structure" "C:\Users\d4050\Documents\program\data structure" "C:\Users\d4050\Documents\program\data structure\cmake-build-debug" "C:\Users\d4050\Documents\program\data structure\cmake-build-debug" "C:\Users\d4050\Documents\program\data structure\cmake-build-debug\CMakeFiles\w2plus1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/w2plus1.dir/depend

