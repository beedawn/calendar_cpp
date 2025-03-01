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
    std::chrono::time_point<std::chrono::seconds> created_time;
    std::chrono::time_point<std::chrono::seconds> start_time;
    std::chrono::time_point<std::chrono::seconds> end_time;

};



#endif //EVENT_H
