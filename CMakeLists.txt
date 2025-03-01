cmake_minimum_required(VERSION 3.30)
project(calendar)

set(CMAKE_CXX_STANDARD 20)

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
        User/User.h)
