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
    const ListItem& getItem() const;     // Returns the item to which cursorM is attached to.
    void reset();                        // Reset the cursorM node to the start of the list.
    bool isOn() const;                   // Returns true if cursorM is not pointing to NULL (0).
    const Node* cursor() const;          // Returns the Node cursorM points to.
    void forward();                      // Moves cursorM to the next Node (if cursorM is not null).
    void insert(const ListItem& itemA);  // Inserts Node into list.
    void remove(int target_year);        // Removes a Node from the list.
    int count() const;                   // Returns the number of nodes in the list.

   private:
    Node* headM;    // Always points to the first node in the list.
    Node* cursorM;  // Cursor node pointer.
};

#endif