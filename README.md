# AofCode_Cpp

**MAIN BRANCH:**

[![ci](https://github.com/DouglasWebster/AofCode_Cpp/actions/workflows/ci.yml/badge.svg)](https://github.com/DouglasWebster/AofCode_Cpp/actions/workflows/ci.yml)
[![codecov](https://codecov.io/gh/DouglasWebster/AofCode_Cpp/branch/main/graph/badge.svg?token=2TCQB6B52P)](https://codecov.io/gh/DouglasWebster/AofCode_Cpp)
[![CodeQL](https://github.com/DouglasWebster/AofCode_Cpp/actions/workflows/codeql-analysis.yml/badge.svg)](https://github.com/DouglasWebster/AofCode_Cpp/actions/workflows/codeql-analysis.yml)

**DEVELOP BRANCH**


[![ci](https://github.com/DouglasWebster/AofCode_Cpp/actions/workflows/ci.yml/badge.svg?branch=develop)](https://github.com/DouglasWebster/AofCode_Cpp/actions/workflows/ci.yml)
[![codecov](https://codecov.io/gh/DouglasWebster/AofCode_Cpp/branch/develop/graph/badge.svg?token=2TCQB6B52P)](https://codecov.io/gh/DouglasWebster/AofCode_Cpp)
[![CodeQL](https://github.com/DouglasWebster/AofCode_Cpp/actions/workflows/codeql-analysis.yml/badge.svg?branch=develop)](https://github.com/DouglasWebster/AofCode_Cpp/actions/workflows/codeql-analysis.yml)



## About AofCode_Cpp

This has been developed from the [cpp-best-practices](https://github.com/cpp-best-practices/cmake_template) and modified for the simpler requirements of completing the [Advent of Code](https://adventofcode.com) yearly problems using C++.


## Original Details

From the original cmake_template I have deleted the docker functionality as it isn't something I use.  It should be relatively simple to reinstate it if required. The following two files have been kept which give basic instructions. 

 * [Dependency Setup](README_dependencies.md)
    This file lists how to configure the dependencies used in this template.  At the moment these are the same as the original cmake_template.
 * [Building Details](README_building.md) These give instructions on how to configure CMake to build the project. 

 ## More Details

 As stated above this repository was generated from the [cpp-best-practices](https://github.com/cpp-best-practices/cmake_template) and when generated changed the base name to AofCode_Cpp which is used in throughout this repository.  If you require a different base name then I'm afraid you will have to do a search and replace in all the files and directory names in the repository.

 The following is the my interpretation of the various files that are important for configuring your project.  It is not an exhaustive list of all the files but there are plenty of comments in the files for those who know what they are doing!  If you see anything that is wrong or needs further clarification please let me know and I will change these notes.

| Root Directory                          	|                                                                                                                                                                                                                                                                                                                                             	|
|-----------------------------------------	|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| CmakePresets.json                       	| These allow you to chose the required toolchain for your development. These should be picked up by your IDE so that only relevant options are available.                                                                                                                                                                                    	|
| Dependencies.cmake                      	| The list of packages that the project requires. If the packages cannot be found on the system then CPM will download and add the packages within the build directory.                                                                                                                                                                       	|
| ProjectOptions.cmake                    	| This sets all the options for the project build including all the level of error reporting by the compiler and linker. Settings can be adjusted to suit your requirements.                                                                                                                                                                  	|

| cmake Directory                         	|                                                                                                                                                                                                                                                                                                                                             	|
|-----------------------------------------	|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| _FORTIFY_SOURCE.hpp                     	| This sets the level for the the FORTIFY_SOURCE option of the compiler which is a protection against hackers forcing buffer overruns.                                                                                                                                                                                                        	|
| Cache.cmake                             	| Configures the compiler cache if available or informs the user is not available.                                                                                                                                                                                                                                                            	|
| CompilerWarnings.cmake                  	| A function to set the compiler warning levels based on the choices made in the ProjectOptions.cmake file.                                                                                                                                                                                                                                   	|
| CPM.cmake                               	| This sets the download location for dependencies installed with CPM. It also downloads and installs CPM itself if not already on the system.                                                                                                                                                                                                	|
| Doxygen.cmake                           	| This sets the options for generating API documentation for your code. I have added extra to this file so that the the doxygen-awesome sidebar theme also has a darkmode toggle switch. Note: doxygen is not enabled as a default in the original template and extra lines have been added to the root CmakeLists.txt file to enable doxygen. 	|
| Linker.cmake                            	| This allows the selection of the linker used. It defaults to “lld”                                                                                                                                                                                                                                                                          	|

| Configured_files directory              	|                                                                                                                                                                                                                                                                                                                                             	|
|-----------------------------------------	|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| CmakeLists.txt                          	| An example of using a configure file.                                                                                                                                                                                                                                                                                                      	|
| CmakeLists.txt.in                         	| This is copied into a new campaign day if it does not already contain a CMakeLists.txt. file.                                                                                                                                                                                       	|
| config.hpp.in                           	| The configuration file that the above CmakeLists.txt copies to the required destination. It sets project makes project information available to libraries.                                                                                                                                                                                  	|
| day_details.hpp.in                      	| This creates a header file with details of the current campaign year and day no.                                                                                                                                                                                                                                                            	|
| day_main.cpp.in                         	| This creates a basic main function that just displays the current campaign year and day.                                                                                                                                                                                                                                                    	|
| delete_me.css, delete_me.hpp & header.html | Files that are used by doxygen to format the page style and provide the dark mode toggle.                                                                                                                                                                                                                                                   	|                                                                                                                                 	

## Using this template

#### *src* folder


The source folder is set up with the three sub folders:

 * **cli_test** - This is a small program that the template uses to ensure that Catch2 testing is functioning correctly.
 * **aoc_library** - This holds the code for generating library files.
 * **campaigns** - This is the base directory for the yearly campaigns.  The campaign year folders are simply named by the four digits of the year. To add a new campaign create a new folder with the year and copy a previous years *CMakeLists.txt* file into the new directory then add a new *add_subdirectory(xxxx)* (substituting the year for xxxx) command to the campaigns CMakeLists.txt file.

 The CMakeLists.txt file in the campaign year folder does the following if CMake configuration is triggered:

1. Scans for any folders with the pattern **dayxx** where the xx is the 2 digit day number.
2. For every folder found it checks for the existence of a CMakeLists.txt file in that folder.
3. If the folder does not contain a CMakeLists.txt file then it copies the starter CMakeLists.txt file from *configured_files* into that folder.
4. The discovered folders are added to the list of add_subdirectories.

 The CMakeLists.txt file in the day folders do the following if CMake configuration is triggered:

 1. checks if the folder has a header file named *day_xx.hpp* where *xx* is the day no. If not it creates the header file from the day_details.hpp.in file in the configured_files folder.
 2. checks if the folder has a header file named *day_xx.cpp* where *xx* is the day no. If not it creates the header file from the day_details.cpp.in file in the configured_files folder.
 3. checks if there is a main.cpp file.  If not it creates it from day_main.cpp.in in the configured_files folder, setting the include header file to day_xx.hpp.
 4.  sets the executable to **yyyy**-day**dd** where *yyyy* is the campaign year and *dd* is the day no and sets main.cpp as the initial source file.

 #### *test* folder

 The test folder has just the one sub folder - campaigns.  Like the src folder it holds the yearly campaigns daily test files.  As with the src folder if you start a new campaign year folder then copy the CMakeLists.txt file from a previous year into the new folder.  When triggered it will create any a CMakeLists.txt file in any dayXX folder that doesn't already have one.  This will then create a Catch2 test file with reference to the relevant puzzle day.  The test file has a single test that fails.
 
 ----
The above sequence means that, once a campaign year folder has been set up in both the src and test directories and the default CMakeLists.txt files copied into them, all that is necessary to start a new problem day is to create that days folder in the campaign years.  If it follows the naming convention then doing a CMake clean reconfigure will populate the new folders with the basic starting files and have the executable registered with CMake.

Of course, once the CMakeLists.txt files are created then the user is free to re-configure them to their individual needs.

I realise that this is probably overkill for coding Advent of Code problems and a simple command line instruction would probably be sufficient. But maybe for some of you, like me, it may help a little way in understanding how the [cpp-best-practices](https://github.com/cpp-best-practices/cmake_template) template works.

In order to give an example of the final use of the template I have included a 2022 campaign day 1 puzzle solution (sorry if this is a spoiler!) along with some library code.  Both the library code and the day 1 solution have test suites in the testing folder.  

Again, this solution along with the tests are probably overkill for the task they solve.  I did find, however, when putting it together that I could not just paste in my old solution as clang-tidy really didn't like my cavalier coding!  If you leave the default setting for the compiler then you will at least be encouraged to write modern c++! 

> [!NOTE]
> The project expects to find the relevant days puzzle data file in the same directory as the days code.  The path to this file is generated in the CMakeLists.txt file.  If you do not want to put it there then you may need to
correct the CMakeLists.txt.in file in the configured_files directory.

Happy coding and I hope this at least takes away some of the burden of setting up the build system.
