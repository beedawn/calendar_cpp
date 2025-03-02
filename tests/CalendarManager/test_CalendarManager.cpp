//
// Created by Bee Schmersal on 3/1/25.
//

#include <catch2/catch_all.hpp>
#include "../../CalendarManager/CalendarManager.h"
#include "../../Calendar/Calendar.h"
#include "../../Event/Event.h"
#include "../../Resource/Resource.h"
#include <iostream>

TEST_CASE("Calendar Test") {
    CalendarManager cm;
    Calendar c = cm.newCalendar();
    REQUIRE(1 == cm.calendars.size());
}

TEST_CASE("Calendar Delete Test") {
    CalendarManager cm;
    Calendar c = cm.newCalendar();
    cm.deleteCalendar(c);
    REQUIRE(cm.calendars.empty());
}

TEST_CASE("Resource Test") {
    CalendarManager cm;
    Resource r = cm.newResource();
    REQUIRE(1 == cm.resources.size());
}

TEST_CASE("Resource Delete Test") {
    CalendarManager cm;
    const Resource r = cm.newResource();
    cm.deleteResource(r);
    REQUIRE(cm.resources.empty());
}

TEST_CASE("Event Test") {
    CalendarManager cm;
    Calendar c = cm.newCalendar();
    Resource r = cm.newResource();
    auto now = std::chrono::system_clock::now();
    auto later = now + std::chrono::seconds(1);
    Event e = cm.newEvent(now, later, cm.calendars[0], r);
    REQUIRE(1 == cm.calendars[0].events.size());
}

TEST_CASE("Event Delete Test") {
    CalendarManager cm;
    Calendar c = cm.newCalendar();
    Resource r = cm.newResource();
    auto now = std::chrono::system_clock::now();
    auto later = now + std::chrono::seconds(1);
    Event e = cm.newEvent(now, later, cm.calendars[0], r);
    cm.deleteEvent(e, cm.calendars[0]);
    REQUIRE(cm.calendars[0].events.empty());
}
