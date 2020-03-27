#include <stdlib.h>

#include <fstream>
#include <iostream>
using namespace std;
#include "Hydro.h"
#include "list.h"

// Displays teh welcome header information to the user.
void Hydro::displayHeader() {
    cout << "HEF Hydropower" << endl;
    cout << "Program: Flow Studies" << endl;
    cout << "Version: 1.0" << endl;
    cout << "Produced by: Ryan Lisowski" << endl
         << endl;

    pressEnter();
}

// Reads the flow data in from an external file.
int Hydro::readData(FlowList& flow_list) {
    // Creates an input stream object to read external file.
    ifstream in_obj;
    in_obj.open("flow.txt");

    int year;
    double flow;

    // Reads in the year and flow inside of the file until the
    // end of the file is reached. The year and flow data is inserted
    // into a linked list each time a read is completed.
    while (in_obj >> year) {
        in_obj >> flow;

        ListItem* new_listitem = new ListItem;
        new_listitem->year = year;
        new_listitem->flow = flow;

        // Insert the year and flow data into a linked list.
        flow_list.insert(*new_listitem);

        year = -1;
        flow = -1.0;
    }

    return flow_list.count();
}

// Display the user interface (menu) to the user.
int Hydro::menu() {
    int selection;

    cout << "\n\nPlease select one of the following options:" << endl;
    cout << "   1. Display the flow list, along with average and median values." << endl;
    cout << "   2. Add Data." << endl;
    cout << "   3. Save data into the file." << endl;
    cout << "   4. Remove data." << endl;
    cout << "   5. Quit." << endl;
    cout << "Enter your choice (1, 2, 3, 4, or 5): ";
    cin >> selection;
    cin.ignore();

    return selection;
}

// Displays the flow data to the user.
void Hydro::display(FlowList& flow_list) {
    cout << "Year"
         << "\t\tFlow" << endl;

    flow_list.reset();
    while (flow_list.isOn() == true) {
        cout << flow_list.getItem().year << "\t\t" << flow_list.getItem().flow << endl;
        flow_list.forward();
    }
}

// Prompts the user to press enter to continue.
void Hydro::pressEnter() {
    cout << "<<< Press Enter to Continue >>>";
    cin.ignore();
}