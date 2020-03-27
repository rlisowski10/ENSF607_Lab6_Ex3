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

    cout << "<<< Press Enter to Continue >>>";
    cin.ignore();
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

    return 1;
}