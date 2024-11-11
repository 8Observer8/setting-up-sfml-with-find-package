cmake_minimum_required(VERSION 3.20)

project(setting-up-sfml-with-find-package)
# USE the WIN32 key to hide the console like this:
# add_executable(app WIN32)
add_executable(app)

# set(SFML_STATIC_LIBRARIES TRUE)

target_sources(app
PRIVATE
    src/main.cpp
)

# This code copies the SFML DLLs to the build directory
# add_custom_command(TARGET app POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     $<TARGET_RUNTIME_DLLS:app> $<TARGET_FILE_DIR:app>
# )

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)
target_link_libraries(app sfml-system sfml-window sfml-graphics)

# target_link_options(app PRIVATE -static)
