#ifndef HYDRO_H
#define HYDRO_H
#include "list.h"

class Hydro {
   public:
    void displayHeader();                  // Displays the welcome header to the user.
    int readData(FlowList& flow_list);     // Reads data from external file.
    int menu();                            // Displays a menu for the user.
    void display(FlowList& flow_list);     // Displays the flow data.
    void addData(FlowList& flow_list);     // Takes input from the user for new flow data.
    void removeData(FlowList& flow_list);  // Removes a Node from the list based on user input.
    int average(FlowList& flow_list);      // Returns the average flow for the list.
    int median(FlowList& flow_list);       // Returns the median flow for the list.
    void saveData(FlowList& flow_list);    // Saves the list data to file.
    void pressEnter();                     // Prompts the user to press enter to continue.
   private:
    // Returns a boolean indicating if the year exists in the list.
    bool doesYearExist(FlowList& flow_list, int year);
    void clearScreen();  // Clears the terminal of text.
};

#endif