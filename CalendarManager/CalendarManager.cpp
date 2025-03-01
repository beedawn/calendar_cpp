//
// Created by Bee Schmersal on 2/28/25.
//

#include "CalendarManager.h"

#include <iostream>
#include <ostream>


Calendar CalendarManager::newCalendar() {
    Calendar cal;

    if (calendars.empty()) {
        std::cout << "cal manager 0" << std::endl;
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
    Resource deletedResource = resources[num];
    resources.erase(resources.begin() + num);

    return deletedResource;
}