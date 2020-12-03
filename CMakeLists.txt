cmake_minimum_required(VERSION 3.16)
project(aoc2020 VERSION 0.1.0)

# Only do these if this is the main project, and not if it is included through
# add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Optionally set things like CMAKE_CXX_STANDARD,
  # CMAKE_POSITION_INDEPENDENT_CODE here

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDE's
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Testing only available if this is the main app. Note this needs to be done
  # in the main CMakeLists since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)

  # Docs only available if this is the main app
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

include_directories(utils)

# # Testing only available if this is the main app
# if(BUILD_TESTING)
#   add_subdirectory(tests)
# endif()

# Utils for all days
add_subdirectory(utils)

# day1
add_subdirectory(day1)

# day2
add_subdirectory(day2)

# day3
add_subdirectory(day3)