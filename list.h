#ifndef LIST_H
#define LIST_H

// A ListItem struct containing year and flow data for
// river measurements.
struct ListItem {
    int year;
    double flow;
};

// A Node struct for a linked list, in which the river measurement
// data is inserted as a ListItem struct.
struct Node {
    ListItem item;
    Node* next;
};

class FlowList {
   public:
    FlowList();                          // Default constructor
    void insert(const ListItem& itemA);  // Inserts Node into list.

   private:
    Node* headM;  // Always points to the first node in the list.
};

#endif