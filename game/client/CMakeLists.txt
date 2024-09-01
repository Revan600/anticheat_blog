add_executable(client main.cpp
        Game.cpp
        Game.h
        entities/local_player.cpp
        entities/local_player.h
        entities/pickup.cpp
        entities/pickup.h
        entities/pickup_controller.cpp
        entities/pickup_controller.h
        anticheat_handler.cpp
        anticheat_handler.h
)

target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(raylib CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(client PRIVATE Winmm.lib)

target_link_libraries(client PRIVATE raylib)
target_link_libraries(client PRIVATE ${OPENGL_LIBRARIES})
target_link_libraries(client PRIVATE glfw)

target_link_libraries(client PRIVATE client_ac)