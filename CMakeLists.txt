cmake_minimum_required(VERSION 3.5)
project(catch_example)

set(CMAKE_CXX_STANDARD 14)

# have compiler give warnings, but not for signed/unsigned
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-sign-compare")

# Use CATCH (Comment out to disable)
set(USE_CATCH 1)

if (DEFINED USE_CATCH)
    add_definitions(-DUSE_CATCH)
endif (DEFINED USE_CATCH)

add_executable(catch_example main.cpp rational.cpp rational.h factorialcatch.cpp vectorcatch.cpp rationalcatch.cpp maincatch.cpp)