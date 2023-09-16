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

This has been developed from the cpp-best-practices [cmake_template](https://github.com/cpp-best-practices/cmake_template) and modified for the simpler requirements of completing the [Advent of Code](https://adventofcode.com) yearly problems using CPP.


## Original Details

From the original cmake_template I have deleted the docker functionality as it isn't something I use.  It should be relatively simple to reinstate it if required. The following two files have been kept which give basic instructions. 

 * [Dependency Setup](README_dependencies.md)
    This file lists how to configure the dependencies used in this template.  At the moment these are the same as the original cmake_template.
 * [Building Details](README_building.md) These give instructions on how to configure CMake to build the project. 

 ## More Details

 As stated above this repository was generated from the [cmake_template](https://github.com/cpp-best-practices/cmake_template) and when generated changed the base name to AofCode_Cpp which is used in throughout this repository.  If you require a different base name then I'm afraid you will have to do a search and replace in all the files and directory names in the repository.

 The following is the my interpretation of what the various files that are important for configuring your project.  It is not an exhaustive list of all the files but there are plenty of comments in the files for those who know what they are doing!  If you see anything that is wrong or needs further clarification please let me know and I will change these notes.

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
| Doxygen.cmake                           	| This sets the options for generating API documentation for your code. I have added extra to this file so that the the doxygen-awsone sidebar theme also has a darkmode toggle switch. Note: doxygen is not enabled as a default in the original template and extra lines have been added to the root CmakeLists.txt file to enable doxygen. 	|
| Linker.cmake                            	| This allows the selection of the linker used. It defaults to “lld”                                                                                                                                                                                                                                                                          	|

| Configured_files directory              	|                                                                                                                                                                                                                                                                                                                                             	|
|-----------------------------------------	|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| CmakeLists.txt                          	| An example of using an configure file.                                                                                                                                                                                                                                                                                                      	|
| config.hpp.in                           	| The configuration file that the above CmakeLists.txt copies to the required destination. It sets project makes project information available to libraries.                                                                                                                                                                                  	|
| day_details.hpp.in                      	| This creates a header file with details of the current campaign year and day no.                                                                                                                                                                                                                                                            	|
| day_main.cpp.in                         	| This creates a basic main function that just displays the current campaing year and day.                                                                                                                                                                                                                                                    	|
| delete_me.css, delete_me.hpp & header.html | Files that are used by doxygen to format the page style and provide the dark mode toggle.                                                                                                                                                                                                                                                   	|                                                                                                                                 	

