cmake_minimum_required(VERSION 3.5)
project(first-yocto-app LANGUAGES CXX VERSION 1.0.0)

find_package(Boost REQUIRED)

add_executable(${PROJECT_NAME}
  src/Main.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  boost_system
  boost_thread
)

target_compile_options(${PROJECT_NAME}
  PRIVATE
  ${GLOBAL_COMPILE_OPTIONS_BASIC}
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

