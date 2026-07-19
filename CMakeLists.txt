cmake_minimum_required(VERSION 3.10)
project(OUT)
add_subdirectory(UFO-Engine) #CMakeLists.txt for engine is in folder called "engine"
set(
    SRC
    main.cpp
    src/tux.cpp
    src/fire_ball.cpp
    src/ice_ball.cpp
    src/key.cpp)
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} UFO)
