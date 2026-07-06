cmake_minimum_required (VERSION 4.0.0)

project ("Wigi")

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.2
)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE WIGI_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable (Wigi ${WIGI_SOURCES})

target_include_directories(Wigi PRIVATE "${CMAKE_SOURCE_DIR}/include")

set_property(TARGET Wigi PROPERTY CXX_STANDARD 23)

target_link_libraries(Wigi PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

if (WIN32)
    add_custom_command(TARGET Wigi POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-graphics> $<TARGET_FILE:sfml-window>
            $<TARGET_FILE:sfml-system> $<TARGET_FILE:sfml-audio>
            $<TARGET_FILE:sfml-network>
            $<TARGET_FILE_DIR:Wigi>
    )
endif()