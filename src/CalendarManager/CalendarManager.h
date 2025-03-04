//
// Created by Bee Schmersal on 2/28/25.
//

#ifndef CALENDARMANAGER_H
#define CALENDARMANAGER_H

#include "../Calendar/Calendar.h"
#include "../Resource/Resource.h"
#include "../Event/Event.h"
#include <vector>
class CalendarManager {
    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;
public:
    int id = 0;
    std::vector<Calendar> calendars;
    std::vector<Resource> resources;
    std::vector<Calendar> readCalendars();
    Calendar newCalendar();
    Calendar deleteCalendar(const Calendar& c);
    Resource newResource();
    Resource deleteResource(Resource r);
    Event newEvent(TimePoint start, TimePoint end, Calendar& c, Resource r);
    Event deleteEvent(Event e, Calendar& c);
private:
    static bool eventOverlap(TimePoint start, TimePoint end, TimePoint start2, TimePoint end2);
    bool conflictCheck(TimePoint start, TimePoint end, Resource r);

    static bool validateTimes(TimePoint start, TimePoint end);
};



#endif //CALENDARMANAGER_H
