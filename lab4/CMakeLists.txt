cmake_minimum_required(VERSION 3.10)
project(MAI-OOP-LAB4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск путей к заголовочным файлам (если они в папке include)
include_directories(include)

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
    GIT_CONFIG "safe.directory=*"
    TLS_VERIFY false
)
FetchContent_MakeAvailable(googletest)

# Создаем исполняемый файл (библиотека не нужна, так как всё в хедерах)
add_executable(lab4 main.cpp)

# Настройка тестов
enable_testing()
add_executable(tests test/test.cpp)
target_link_libraries(tests gtest_main)

add_test(NAME Lab4Tests COMMAND tests)