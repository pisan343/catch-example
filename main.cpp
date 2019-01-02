/**
 * @brief CATCH framework example
 * @file main.cpp
 *
 * Catch2 framework example from
 * https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top
 *
 * 1) Add catch.hpp to the same directory as project
 *
 * 2) Create a CLion configuration that knows about CATCH
 *
 * CLion: Run > Edit Configurations > + and choose Catch
 * Name the new configuration main-catch
 * Run > Run 'main-catch'
 * You should see all tests taht passed and failed
 *
 * CATCH provides its own main() function when CATCH_CONFIG_MAIN
 * is defined.
 * if you want to use your own main
 *          Comment out "#define CATCH_CONFIG_MAIN"
 *                   and
 *          Uncomment "#define CATCH_CONFIG_RUNNER"
 *
 * 3) Modify CMakeLists.txt
 * Always use -Wall -Wextra -Wno-sign-compare when compiling
 * set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-sign-compare")
 *
 * 4) Command line compile
 * $ g++ -std=c++14 -Wall -Wextra -Wno-sign-compare main.cpp -o catch-example.exe
 *
 * @author Yusuf Pisan
 * @date 7 Dec 2018
 */


// *** MUST DEFINE ONE OF *** CATCH_CONFIG_MAIN  or CATCH_CONFIG_RUNNER
// CATCH_CONFIG_MAIN -- defines its own main() do this only once
#define CATCH_CONFIG_MAIN
// CATCH_CONFIG_RUNNER -- use CATCH as a module, run your own main
// #define CATCH_CONFIG_RUNNER

#include <iostream>
#include "catch.hpp"


#ifndef CATCH_CONFIG_MAIN

// If not using CATCH framework, call functions directly
int main() {
  // You can use NOLINT to disable cpplint checks on that line if necessary
  std::cout << "This is user-defined main. " << "CATCH_CONFIG_MAIN not defined. "  // NOLINT
            << "Not using CATCH generated main" << std::endl;
  std::cout << "Hello World :-)" << std::endl;
  return 0;
}

#endif  // CATCH_CONFIG_MAIN
