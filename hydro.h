#ifndef HYDRO_H
#define HYDRO_H
#include "list.h"

class Hydro {
   public:
    void displayHeader();               // Displays the welcome header to the user.
    int readData(FlowList& flow_list);  // Reads data from external file.
    int menu();                         // Displays a menu for the user.
    void display(FlowList& flow_list);  // Displays the flow data.
    void pressEnter();                  // Prompts the user to press enter to continue.
};

#endif