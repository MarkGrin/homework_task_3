cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

set(NAMESPACE taskThree)
set(COMPONENT unittest)
project(${NAMESPACE}-${COMPONENT})

add_executable(${PROJECT_NAME} test.cpp)     
add_executable(${NAMESPACE}::${COMPONENT} ALIAS ${PROJECT_NAME})

find_package(taskThree-mdArray)
find_package(Boost 1.65 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${BOOST_LIBRARIES} taskThree::mdArray)

