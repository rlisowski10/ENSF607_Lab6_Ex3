#ifndef HYDRO_H
#define HYDRO_H
#include "list.h"

class Hydro {
   public:
    void displayHeader();               // Displays the welcome header to the user.
    int readData(FlowList& flow_list);  // Reads data from ext. file.
};

#endif