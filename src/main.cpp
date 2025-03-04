#include <iostream>
#include "CalendarManager/CalendarManager.h"
#include "Resource/Resource.h"
#include "Calendar/Calendar.h"
using namespace std;


int login() {
    cout << "Hello and welcome to the calendar_cpp app!\n";
    string username, password;
    cout << "Please enter your user name:\n";
    cin >> username;
    cout << "Please enter your password:\n";
    cin >> password;

    if (username != "test" && password != "test") {
        cout << "You entered an invalid username or password.\n";
        return 1;
    }
    return 0;
}

void calendarTests(CalendarManager cm) {

    Calendar c = cm.newCalendar();
    Calendar x = cm.newCalendar();
    Calendar y = cm.newCalendar();
    const Resource r = cm.newResource();
    auto now = std::chrono::system_clock::now();
    auto later = now + std::chrono::seconds(1);

    cm.newEvent(now, later, c, r);
    cm.newEvent(now, later, c, r);
    for (auto event : cm.calendars[0].events) {
        cout<<event.id<<" ";
    }

    cout<<"etsts";
}

void userInterface(CalendarManager& cm) {
    string input;

    while (input != "q") {
        cout << "Hello what would you like to do?\n";
        cout << "1. View Calendars\n";
        cout << "2. View Resources\n";
        cout << "3. Add Calendar\n";
        cout << "4. Delete Calendar\n";
        cout << "5. Add Resource\n";
        cout << "6. Delete Resource\n";
        cout << "7. Add Events\n";
        cout << "8. View Events\n";
        cout << "9. Exit\n";
        cin >> input;


        if (input == "1") {
            for (const auto& calendar : cm.calendars) {
                cout << calendar.id << " \n";
            }
        }
        else if (input == "2") {
            for (const auto& resource : cm.resources) {
                cout << resource.id << " \n";
            }
        } else if (input == "3") {
            cm.newCalendar();
        } else if (input == "4") {
            string input2;
            cout << "Enter the ID of the Calendar you'd like to delete: \n";
            cin >> input2;
            for (int i = 0; i < cm.calendars.size(); i++) {
                if (to_string(cm.calendars[i].id)==input2) {
                    cm.deleteCalendar(cm.calendars[i]);
                }
            }

        } else if (input == "5") {
            cm.newResource();
        } else if (input == "6") {
            string input2;
            cout << "Enter the ID of the Resource you want to delete: \n";
            cin >> input2;
            for (int i = 0; i < cm.resources.size(); i++) {
                if (to_string(cm.resources[i].id)==input2) {
                    cm.deleteResource(cm.resources[i]);
                }
            }
        } else if (input == "7") {
            string input2, input3;
            cout << "Enter the ID of the Calendar you want to add an event to: \n";
            cin >> input2;
            for (int i = 0; i < cm.calendars.size(); i++) {
                if (to_string(cm.calendars[i].id)==input2) {
                    cout << "Calendar ID: " <<cm.calendars[i].id << " found!" << " \n";
                    cout << "Which resouce would you like to use?\n";
                    cin >> input3;
                    for (int j = 0; j < cm.resources.size(); j++) {
                        if (to_string(cm.resources[j].id)==input3) {
                            cout << "Resource ID: " <<cm.resources[j].id << " found!" << " \n";
                            auto now = std::chrono::system_clock::now();
                            auto later = now + std::chrono::seconds(1);
                            cm.newEvent(now, later, cm.calendars[i], cm.resources[j]);
                        }
                    }
                }
            }
        } else if (input == "8") {
            string input2;
            cout << "Which calendar would you like to view events for?\n";
            cin >> input2;
            for (int i = 0; i < cm.calendars.size(); i++) {
                if (to_string(cm.calendars[i].id)==input2) {
                    for (auto event : cm.calendars[i].events) {
                        cout << "Event ID: " << event.id << " \n";
                    }
                }
            }
        }
    }


}



int main() {

    auto login_result = login();
    if (login_result != 0) {
        return 1;
    }
    CalendarManager cm;
    calendarTests(cm);
    userInterface(cm);
    return 0;
}

