cmake_minimum_required(VERSION 3.21)

project(setting-up-sfml-with-find-package)

set(SFML_DIR "C:/libs/SFML-2.6.2-mingw/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

# Define the executable
# Use the WIN32 key to hide the console like this: add_executable(app WIN32)
add_executable(app)

target_sources(app
PRIVATE
    src/main.cpp
)

target_link_libraries(app sfml-system sfml-window sfml-graphics)

# This code copies the SFML DLLs to the build directory
add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_RUNTIME_DLLS:app> $<TARGET_FILE_DIR:app>
    COMMAND_EXPAND_LISTS
)

# Copy Assets (ONLY if the folder exists!)
if(EXISTS "${CMAKE_SOURCE_DIR}/assets")
    add_custom_command(TARGET app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:app>/assets"
    )
endif()

# Static link
# set(SFML_STATIC_LIBRARIES TRUE)
# target_link_options(app PRIVATE -static)

target_link_options(app PRIVATE -mconsole)
