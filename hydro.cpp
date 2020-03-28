#include <stdlib.h>

#include <fstream>
#include <iomanip>
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

// Displays the flow data and statistics to the user.
void Hydro::display(FlowList& flow_list) {
    cout << "\nYear"
         << "\t\tFlow (in billion cubic meters)" << endl;

    flow_list.reset();
    while (flow_list.isOn() == true) {
        cout << flow_list.getItem().year << "\t\t" << flow_list.getItem().flow << endl;
        flow_list.forward();
    }

    //Output the flow statistics.
    flow_list.reset();
    if (flow_list.isOn() == true) {
        cout << "\nThe annual average flow is: " << fixed
             << setprecision(2) << average(flow_list)
             << " million cubic meters." << endl;
        cout << "The median annual flow is: " << fixed
             << setprecision(2) << median(flow_list)
             << " million cubic meters." << endl;
    } else {
        cout << "\nNote: The annual average flow cannot be "
             << "calculated due to lack of data."
             << endl;
        cout << "Note: The median annual flow cannot be "
             << "calculated due to lack of data."
             << endl;
    }
}

// Returns the average flow for the list.
int Hydro::average(FlowList& flow_list) {
    double average_flow = 0.0;

    // Determines if flow data exists, and if so, calculates and returns
    // the average flow.
    flow_list.reset();
    if (flow_list.isOn() == true) {
        int node_count = flow_list.count();
        double flow_sum = 0.0;

        for (int i = 0; i < node_count; i++) {
            flow_sum += flow_list.getItem().flow;
            flow_list.forward();
        }

        average_flow = flow_sum / node_count;
    }

    // Convert the result to million cubic meters.
    return int(average_flow * 1000);
}

// Returns the median flow for the list.
int Hydro::median(FlowList& flow_list) {
    double median_flow = 0.0;
    int median_node_index = flow_list.count() / 2;

    flow_list.reset();

    // Calculates the median value (average of two middle flows) for
    // a flow dataset with an even number of nodes, or if the flow
    // dataset has an odd number of nodes, then the true median is taken
    // (no average is calculated).
    if (flow_list.isOn() == true && flow_list.count() % 2 == 0) {
        for (int i = 0; i <= median_node_index; i++) {
            if ((i == median_node_index - 1) || (i == median_node_index)) {
                median_flow += flow_list.getItem().flow;
            }
            flow_list.forward();
        }

        median_flow = median_flow / 2;
    } else if (flow_list.isOn() == true && flow_list.count() % 2 != 0) {
        for (int i = 0; i <= median_node_index; i++) {
            if (i == median_node_index) {
                median_flow = flow_list.getItem().flow;
            }
            flow_list.forward();
        }
    }

    // Convert the result to million cubic meters.
    return int(median_flow * 1000);
}

// Prompts the user to press enter to continue.
void Hydro::pressEnter() {
    cout << "<<< Press Enter to Continue >>>";
    cin.ignore();
}