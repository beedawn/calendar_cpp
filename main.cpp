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

void calendarTests() {
    CalendarManager cm;
    Calendar c = cm.newCalendar();
    Calendar x = cm.newCalendar();
    Calendar y = cm.newCalendar();
    const Resource r = cm.newResource();
    auto now = std::chrono::system_clock::now();
    auto later = now + std::chrono::seconds(1);

    cm.newEvent(now, later, c, r);
    for (const auto& calendar : cm.readCalendars()) {
        cout << calendar.id << "\n";
    }
}


int main() {

    auto login_result = login();
    if (login_result != 0) {
        return 1;
    }

    calendarTests();
    return 0;
}

