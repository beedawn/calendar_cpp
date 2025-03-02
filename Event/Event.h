//
// Created by Bee Schmersal on 2/28/25.
//

#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include "../Resource/Resource.h"

class Event {
public:
    int id = 0;
    std::vector<Resource> resources;
    std::string user;
    std::string duration;
    std::chrono::time_point<std::chrono::system_clock> created_time;
    std::chrono::time_point<std::chrono::system_clock>start_time;
    std::chrono::time_point<std::chrono::system_clock> end_time;
    Event(int eventId, std::vector<Resource> eventResources, std::string eventUser,
           std::string eventDuration, std::chrono::time_point<std::chrono::system_clock> eventCreatedTime,
           std::chrono::time_point<std::chrono::system_clock> eventStartTime,
           std::chrono::time_point<std::chrono::system_clock> eventEndTime)
         : id(eventId), resources(eventResources), user(eventUser), duration(eventDuration),
           created_time(eventCreatedTime), start_time(eventStartTime), end_time(eventEndTime) {
    }
    Event()
    : id(0), resources({}), user(""), duration(""),
      created_time(std::chrono::system_clock::now()),
      start_time(std::chrono::system_clock::now()),
      end_time(std::chrono::system_clock::now()) {}


};

#endif //EVENT_H
