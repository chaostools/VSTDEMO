cmake_minimum_required(VERSION 3.4.1)
add_library(internal_loader SHARED internal_loader.cpp)
target_link_libraries(internal_loader log EGL GLESv3)