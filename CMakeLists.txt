cmake_minimum_required(VERSION 3.0.0)
project(geneticalgorithm)

include(CTest)
enable_testing()

add_compile_options(-std=c++14)
# set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2" FORCE)
# SET(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE STRING "" FORCE)
SET(CMAKE_BUILD_TYPE Release)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/Lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/Bin)


# include_directories("D:\\mingw-w64\\mingw32\\lib\\gcc\\i686-w64-mingw32\\8.1.0\\include\\c++")



# set(CMAKE_C_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/VC/Tools/MSVC/14.23.28105/bin/Hostx64/x64/cl.exe")

if(WIN32)
    set(CMAKE_PREFIX_PATH "C:\\ProgramData\\Anaconda3\\envs\\tf")
endif()

set (DPYBIND11_FINDPYTHON ON)
find_package (Python3 COMPONENTS Interpreter Development REQUIRED)
include_directories(${Python3_INCLUDE_DIRS})
link_libraries(${Python3_LIBRARIES})


include_directories(eigen-3.3.8)
include_directories(include)


add_subdirectory(pybind11-2.6.1)




# add_library(ga src/GeneticAlgorithm.cpp)
# add_library(api src/api.cpp)
# target_link_libraries(api ga)


aux_source_directory(./src SRC)
pybind11_add_module(pyapi ${SRC})


# target_link_libraries(pyapi PUBLIC api)

# add_library(es src/es_utils.cpp)

add_executable(geneticalgorithm src/es_utils_new.cpp src/api_new.cpp src/GeneticAlgorithm_new.cpp src/villa.cpp src/main.cpp)
# target_link_libraries(geneticalgorithm api)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
