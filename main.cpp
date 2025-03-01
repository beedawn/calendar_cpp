#include <iostream>
#include "Calendar/Calendar.h"

using namespace std;


int login() {

    Calendar calendar;

    cout <<calendar.id<<"\n";
    cout << "Hello and welcome to the calendar app!\n";
    string username, password;
    cout << "Please enter your user name:\n";
    cin >> username;
    cout << "Please enter your password:\n";
    cin >> password;

    if (username != "test" && password != "test") {
        cout << "You entered an invalid username or password.\n";
        return 1;
    } else {
        return 0;
    }
}


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.

    auto login_result = login();
    if (login_result != 0) {
        return 1;
    }


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.
