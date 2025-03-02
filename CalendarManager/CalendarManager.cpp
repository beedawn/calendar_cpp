//
// Created by Bee Schmersal on 2/28/25.
//

#include "CalendarManager.h"

#include <iostream>
#include <ostream>
#include <vector>


std::vector<Calendar> CalendarManager::readCalendars() {
    return this->calendars;
}

Calendar CalendarManager::newCalendar() {
    Calendar cal;
    if (calendars.empty()) {
        cal.id = 1;
    } else {
        cal.id = calendars.back().id + 1;  // Equivalent to len(cm.Calendars)-1 in Go
    }
    calendars.push_back(cal);  // Equivalent to append in Go
    return cal;
}

Calendar CalendarManager::deleteCalendar(const Calendar& c) {
    int num = -1;
    for (int i =0; i < calendars.size(); i++) {
        if (calendars[i].id == c.id) {
            num = i;
        }
    }
    Calendar deletedCal = calendars[num];
    if (num != -1) {
    calendars.erase(calendars.begin() + num);}
    return deletedCal;
}


Resource CalendarManager::newResource() {
    Resource r;
    r.id = static_cast<int>(resources.size())+1;
    resources.push_back(r);
    return r;
}

Resource CalendarManager::deleteResource(Resource r) {
    int num = -1;
    for (int i =0; i < resources.size(); i++) {
        if (resources[i].id == r.id) {
            num = i;
        }
    }
    if (num == -1) {
        throw std::out_of_range("resource not found");
    }
    Resource deletedResource = resources[num];
    resources.erase(resources.begin() + num);
    return deletedResource;
}
using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
bool CalendarManager::eventOverlap(TimePoint start, TimePoint end, TimePoint start2, TimePoint end2) {
        return (start < end2) && (end < start2);
}

bool CalendarManager::conflictCheck(TimePoint start, TimePoint end, Resource r) {
    int count =0;
    for (auto & calendar : calendars) {
        for (auto & event : calendar.events) {
            for (auto & resource : event.resources) {
                if (resource.id == r.id&& eventOverlap(start, end, event.start_time, event.end_time)) {
                    ++count;
                }
                if (count > calendar.concurrent_events) {
                    // Probably can just return false?
                    // throw std::runtime_error("Times are conflicting!");
                    return false;
                }
            }
        }
  }
    return true;
}

bool CalendarManager::validateTimes(TimePoint start, TimePoint end) {
    if (end < start) {
        return false;
    }
    if (end == start) {
        return false;
    }
    return true;
}



Event CalendarManager::newEvent(TimePoint start, TimePoint end, Calendar& c, Resource r) {
    if (!validateTimes(start, end)) {
        throw std::runtime_error("end time is before start time");
    }
    if (!conflictCheck(start, end, r)) {
        throw std::runtime_error("conflicting event");
    }

    auto new_event =  Event();
    c.events.push_back(new_event);
    return new_event;
}

Event CalendarManager::deleteEvent(Event e, Calendar& c) {
    int num = -1;
    for (int i =0; i < c.events.size(); i++) {
        if (c.events[i].id == e.id) {
            num = i;
        }
    }
    if (num == -1) {
        throw std::out_of_range("event not found");
    }
    c.events.erase(c.events.begin() + c.events[num].id);
    return c.events[num];
}
