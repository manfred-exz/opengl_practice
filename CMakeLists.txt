cmake_minimum_required(VERSION 3.3)
project(modern_opengl)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



set(SOURCE_FILES main.cpp Display.cpp Display.h)
add_executable(modern_opengl ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

#set(OPENGL_LIBRARIES "/usr/lib/x86_64-linux-gnu/libGL.so")
#set(SDL_LIBRARY "/usr/lib/x86_64-linux-gnu/libSDL2.so")
#set(GLEW_LIBRARY "/usr/lib/x86_64-linux-gnu/libGLEW.so")
#target_link_libraries(modern_opengl ${OPENGL_LIBRARIES} ${SDL_LIBRARY} ${GLEW_LIBRARY})

target_link_libraries (modern_opengl libGL.so libSDL2.so libGLEW.so)