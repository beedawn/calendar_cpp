cmake_minimum_required(VERSION 3.30)
project(src/Calendar)

set(CMAKE_CXX_STANDARD 20)

include_directories(/opt/homebrew/Cellar/catch2/3.8.0/include)

find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)


add_executable(test_CalendarManager
        tests/CalendarManager/test_CalendarManager.cpp
        src/CalendarManager/CalendarManager.cpp  # Add this file
)
target_link_libraries(test_CalendarManager PRIVATE Catch2::Catch2WithMain)

add_executable(calendar src/main.cpp
        src/Calendar/calendar.cpp
        src/Calendar/calendar.h
        src/CalendarManager/CalendarManager.cpp
        src/CalendarManager/CalendarManager.h
        src/Event/Event.cpp
        src/Event/Event.h
        src/Resource/Resource.cpp
        src/Resource/Resource.h
        User/User.cpp
        User/User.h


)
