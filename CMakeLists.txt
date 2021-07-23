cmake_minimum_required(VERSION 3.14)
project(AntSimulation)

# Default to release builds
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

#path to SFMLConfig.cmake
set(SFML_DIR C:/Users/ghj/Downloads/SFML-2.5.1/build)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2 REQUIRED COMPONENTS graphics system window)
find_package(Threads REQUIRED)

if(WIN32)
    set(WIN32_GUI WIN32 src/main.cpp)
endif()

set(SFML_LIBS sfml-graphics sfml-system sfml-window)

set(SOURCES src/main.cpp
            src/Ant.cpp
            src/Ant.h
            src/World.cpp
            src/World.h
            src/DisplayManager.cpp
            src/DisplayManager.h
            src/Config.cpp
            src/Config.h
            src/Random.h
            src/Random.cpp
        )

add_executable(${PROJECT_NAME} ${WIN32_GUI} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include lib)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBS} Threads::Threads)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
add_library(${PROJECT_NAME}_lib ${SOURCES})
target_link_libraries(${PROJECT_NAME}_lib ${SFML_LIBS} Threads::Threads)

if(MSVC)
    foreach(lib ${SFML_LIBS})
        get_target_property(lib_path ${lib} LOCATION)
        file(COPY ${lib_path} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    endforeach()
endif()

###Google Test
enable_testing()

include_directories(tests)
include_directories(src)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FetchContent_GetProperties(googletest)

include_directories(${googletest_SOURCE_DIR})
include_directories(${googletest_BINARY_DIR})

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

set(SOURCES_TST tests/main.cpp
                tests/Ant-Test.cpp
                tests/World-test.cpp
                tests/Config-test.cpp
        )

add_executable(${PROJECT_NAME}_tst ${SOURCES_TST})

target_include_directories(${PROJECT_NAME}_tst PRIVATE include ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}_tst PRIVATE include lib)
target_link_libraries(${PROJECT_NAME}_tst gtest_main)
target_link_libraries(${PROJECT_NAME}_tst ${PROJECT_NAME}_lib)

add_test(NAME ${PROJECT_NAME}_tst COMMAND ${PROJECT_NAME}_tst)