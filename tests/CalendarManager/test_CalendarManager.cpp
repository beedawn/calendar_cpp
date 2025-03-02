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

 TEST_CASE("Resource Delete Test No Resource") {
     CalendarManager cm;
     const Resource r = Resource();
     REQUIRE_THROWS_AS(cm.deleteResource(r), std::out_of_range);
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

TEST_CASE("Event Test start after end Time same") {
    CalendarManager cm;
    Calendar c = cm.newCalendar();
    Resource r = cm.newResource();
    auto now = std::chrono::system_clock::now();
    auto later = now + std::chrono::seconds(1);
    REQUIRE_THROWS_AS(cm.newEvent(later, now, c, r), std::runtime_error);
}

TEST_CASE("Event Test start equal end Time same") {
    CalendarManager cm;
    Calendar c = cm.newCalendar();
    Resource r = cm.newResource();
    auto now = std::chrono::system_clock::now();
    REQUIRE_THROWS_AS(cm.newEvent(now, now, c, r), std::runtime_error);
}

TEST_CASE("Event Test Conflicting Times") {
    CalendarManager cm;
    Calendar c = cm.newCalendar();
    Resource r = cm.newResource();
    auto now = std::chrono::system_clock::now();
    auto later = now + std::chrono::seconds(1);
    Event e = cm.newEvent(now, later, cm.calendars[0], r);
    REQUIRE_THROWS_AS(cm.newEvent(later, now, c, r), std::runtime_error);
}

//test delete event not there
TEST_CASE("Event Delete Test No Event") {
    CalendarManager cm;
    Calendar c = cm.newCalendar();
    const Event e = Event();
    REQUIRE_THROWS_AS(cm.deleteEvent(e, c), std::out_of_range);
}
//test delete event when events are empty