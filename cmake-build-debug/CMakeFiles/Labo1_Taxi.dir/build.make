# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\guill\projet_HEIG_1\labo_taxi_update

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\guill\projet_HEIG_1\labo_taxi_update\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Labo1_Taxi.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Labo1_Taxi.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Labo1_Taxi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Labo1_Taxi.dir/flags.make

CMakeFiles/Labo1_Taxi.dir/main.cpp.obj: CMakeFiles/Labo1_Taxi.dir/flags.make
CMakeFiles/Labo1_Taxi.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Labo1_Taxi.dir/main.cpp.obj: CMakeFiles/Labo1_Taxi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\guill\projet_HEIG_1\labo_taxi_update\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Labo1_Taxi.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Labo1_Taxi.dir/main.cpp.obj -MF CMakeFiles\Labo1_Taxi.dir\main.cpp.obj.d -o CMakeFiles\Labo1_Taxi.dir\main.cpp.obj -c C:\Users\guill\projet_HEIG_1\labo_taxi_update\main.cpp

CMakeFiles/Labo1_Taxi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Labo1_Taxi.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\guill\projet_HEIG_1\labo_taxi_update\main.cpp > CMakeFiles\Labo1_Taxi.dir\main.cpp.i

CMakeFiles/Labo1_Taxi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Labo1_Taxi.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\guill\projet_HEIG_1\labo_taxi_update\main.cpp -o CMakeFiles\Labo1_Taxi.dir\main.cpp.s

# Object files for target Labo1_Taxi
Labo1_Taxi_OBJECTS = \
"CMakeFiles/Labo1_Taxi.dir/main.cpp.obj"

# External object files for target Labo1_Taxi
Labo1_Taxi_EXTERNAL_OBJECTS =

Labo1_Taxi.exe: CMakeFiles/Labo1_Taxi.dir/main.cpp.obj
Labo1_Taxi.exe: CMakeFiles/Labo1_Taxi.dir/build.make
Labo1_Taxi.exe: CMakeFiles/Labo1_Taxi.dir/linklibs.rsp
Labo1_Taxi.exe: CMakeFiles/Labo1_Taxi.dir/objects1.rsp
Labo1_Taxi.exe: CMakeFiles/Labo1_Taxi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\guill\projet_HEIG_1\labo_taxi_update\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Labo1_Taxi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Labo1_Taxi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Labo1_Taxi.dir/build: Labo1_Taxi.exe
.PHONY : CMakeFiles/Labo1_Taxi.dir/build

CMakeFiles/Labo1_Taxi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Labo1_Taxi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Labo1_Taxi.dir/clean

CMakeFiles/Labo1_Taxi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\guill\projet_HEIG_1\labo_taxi_update C:\Users\guill\projet_HEIG_1\labo_taxi_update C:\Users\guill\projet_HEIG_1\labo_taxi_update\cmake-build-debug C:\Users\guill\projet_HEIG_1\labo_taxi_update\cmake-build-debug C:\Users\guill\projet_HEIG_1\labo_taxi_update\cmake-build-debug\CMakeFiles\Labo1_Taxi.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Labo1_Taxi.dir/depend

