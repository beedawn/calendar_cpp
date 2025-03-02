//
// Created by Bee Schmersal on 2/28/25.
//

#ifndef CALENDAR_H
#define CALENDAR_H
#include <string>
#include "../Event/Event.h"

class Calendar {
public:
    int id = 0;
    std::string name;
    std::vector<Event> events;
    int concurrent_events = 0;
};

#endif //CALENDAR_H
