#include <stdlib.h>

#include <iostream>
using namespace std;
#include "list.h"

// Default constructor that sets the head of the linked list to NULL (0).
FlowList::FlowList() {
    headM = 0;
}

// Insert Node Function
void FlowList::insert(const ListItem &itemA) {
    // Create a new Node object and assign the ListItem to it.
    Node *new_node = new Node;
    new_node->item = itemA;

    // Checks if there are any items in the list, or if the flow
    // data is lower than the first item in the list. If not, then
    // iterates through the list until the correct insertion point
    // is found. The linked list is ordered by ascending flow rates.
    if (headM == 0 || itemA.flow <= headM->item.flow) {
        new_node->next = headM;
        headM = new_node;
    } else {
        Node *before = headM;
        Node *after = headM->next;

        // Iterate through the list until the correct insertion position
        // is found.
        while (after != 0 && itemA.flow > after->item.flow) {
            before = after;
            after = after->next;
        }

        // Update the pointers in the linked list to accomodate the new Node.
        new_node->next = after;
        before->next = new_node;
    }
}