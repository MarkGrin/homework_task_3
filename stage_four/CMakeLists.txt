cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(taskThree)

set(SUBPROJECTS
    ${PROJECT_NAME}-mdArray
    ${PROJECT_NAME}-acme
    ${PROJECT_NAME}-unittest
   )

macro(find_package)
    if(NOT "${ARGV0}" IN_LIST SUBPROJECTS)
        _find_package(${ARGV})
    endif()
endmacro()

foreach(subproj IN LISTS SUBPROJECTS)
    add_subdirectory(${subproj})
endforeach()

