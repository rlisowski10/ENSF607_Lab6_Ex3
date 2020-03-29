#include <stdlib.h>

#include <iostream>
using namespace std;
#include "hydro.h"
#include "list.h"

int main() {
    Hydro hydro;
    FlowList flow_list;
    int numRecords;
    hydro.displayHeader();
    numRecords = hydro.readData(flow_list);

    int quit = 0;

    while (1) {
        switch (hydro.menu()) {
            case 1:
                hydro.display(flow_list);
                hydro.pressEnter();
                break;
            case 2:
                hydro.addData(flow_list);
                hydro.pressEnter();
                break;
            case 3:
                hydro.saveData(flow_list);
                hydro.pressEnter();
                break;
            case 4:
                hydro.removeData(flow_list);
                hydro.pressEnter();
                break;
            case 5:
                cout << "\nProgram terminated successfully.\n\n";
                quit = 1;
                break;
            default:
                cout << "\nNot a valid input.\n";
                hydro.pressEnter();
        }
        if (quit == 1) break;
    }

    // Creating a copy of FlowList x called copy1
    FlowList copy1;
    copy1 = flow_list;
    // In the following section call addData to add
    // following records (year, flow) to copy1:
    // 2012  459.99
    // 2013  2000.34
    ListItem record_1;
    record_1.year = 2012;
    record_1.flow = 459.99;
    copy1.insert(record_1);

    ListItem record_2;
    record_2.year = 2013;
    record_2.flow = 2000.34;
    copy1.insert(record_2);

    // Use the following code to create a copy of copy1 called copy2
    FlowList copy2 = copy1;

    // Removing three records from copy2
    copy2.remove(1922);
    copy2.remove(2003);
    copy2.remove(2001);

    // Display the values in three list copy 2, copy1, and x
    cout << "\n values in copy2 are: " << endl;
    hydro.display(copy2);

    cout << "\n values in copy1 are: " << endl;
    hydro.display(copy1);

    cout << "\n values in x are: " << endl;
    hydro.display(flow_list);
    return 0;
}