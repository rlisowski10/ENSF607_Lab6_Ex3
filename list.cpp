#include <stdlib.h>

#include <iostream>
using namespace std;
#include "list.h"

// Default constructor that sets the head of the linked list to NULL (0).
FlowList::FlowList() {
    headM = 0;
    cursorM = 0;
}

// Gets the item for the Node that cursorM currently points to.
const ListItem &FlowList::getItem() const {
    return cursorM->item;
}

// Reset the cursorM node to the start of the list.
void FlowList::reset() {
    if (headM != 0) {
        cursorM = headM;
    } else {
        cursorM = 0;
    }
}

// Returns true if cursorM is not pointing to NULL (0).
bool FlowList::isOn() const {
    if (cursorM != 0) {
        return true;
    } else {
        return false;
    }
}

// Returns the Node cursorM points to.
const Node *FlowList::cursor() const {
    return cursorM;
}

// Moves cursorM to the next Node (if cursorM is not null).
void FlowList::forward() {
    if (cursorM != 0 && cursorM->next != 0) {
        cursorM = cursorM->next;
    } else {
        cursorM = 0;
    }
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

    cursorM = 0;
}

// Returns the number of nodes in the list.
int FlowList::count() const {
    int count = 0;
    Node *current_node = headM;

    // Iterates through each node until the node is NULL (0), which
    // means that the end of the list has been reached.
    while (current_node != 0) {
        count++;
        current_node = current_node->next;
    }

    return count;
}