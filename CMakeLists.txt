cmake_minimum_required(VERSION 3.30)
project(calendar)

set(CMAKE_CXX_STANDARD 20)

include_directories(/opt/homebrew/Cellar/catch2/3.8.0/include)

find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(calendar main.cpp
        calendar/calendar.cpp
        calendar/calendar.h
        CalendarManager/CalendarManager.cpp
        CalendarManager/CalendarManager.h
        Event/Event.cpp
        Event/Event.h
        Resource/Resource.cpp
        Resource/Resource.h
        User/User.cpp
        User/User.h

)
