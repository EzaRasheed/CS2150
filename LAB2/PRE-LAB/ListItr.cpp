//name: Eza Rasheed
//id: er6qt
//date: 1-26-19
//filename: ListItr.cpp

#include <iostream>
#include <string>

#include "ListItr.h"
#include "List.h"

using namespace std;

ListItr::ListItr() {
    current = NULL;
}
  
ListItr::ListItr(ListNode* theNode) {
    current = theNode;
}

bool ListItr::isPastEnd() const {
    if (current->next == NULL) 
        return true;
    else {
        return false;
    }
}

bool ListItr::isPastBeginning() const {
    if (current->previous == NULL)
        return true;
    else {
        return false;
    }
}

void ListItr::moveForward() {
    if (!(isPastEnd()))
        current = current->next;
}

void ListItr::moveBackward() {
    if (!(isPastBeginning()))
        current = current->previous;
}

int ListItr::retrieve() const {
   return current->value;
}





