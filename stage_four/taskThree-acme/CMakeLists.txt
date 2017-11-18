cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(NAMESPACE taskThree)
set(COMPONENT acme)
project(${NAMESPACE}-${COMPONENT})

add_executable(${PROJECT_NAME} main.cpp acme.cpp)     
add_executable(${NAMESPACE}::${COMPONENT} ALIAS ${PROJECT_NAME})

find_package(taskThree-mdArray)
target_link_libraries(${PROJECT_NAME} PRIVATE taskThree::mdArray)
