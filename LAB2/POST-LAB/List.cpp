//name: Eza Rasheed
//id: er6qt
//date: 1-28-19
//filename: List.cpp
//TA Helpers: Noted Below

#include <iostream>
#include <string>

#include "ListItr.h"
#include "ListNode.h"

List::List() {
    count = 0;
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
}

List::~List() {
    delete head;
    delete tail;
    makeEmpty();
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

bool List::isEmpty() const {
    if (count == 0) 
        return true;
    else {
        return false;
    }
}

void List::makeEmpty(){ //TA Help: bac6vx
    ListItr* iter = new ListItr(head); 
    while (!iter->isPastEnd()) {
        iter->moveForward();
        delete (iter->current);
    }
    tail->previous = head;
    head->next = tail;
    count = 0;
}

ListItr List::first() {
    return ListItr(head->next);
}

ListItr List::last() {
    return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position) { //TA Help:ski5uc
    ListNode* tempNode = new ListNode();
    tempNode->value = x;
    position.current->next->previous = tempNode;
    tempNode->next = position.current->next;
    tempNode->previous = position.current;
    position.current->next = tempNode;
    count++;
}

void List::insertBefore(int x, ListItr position) {
    ListNode* tempNode = new ListNode();
    tempNode->value = x;
    position.current->previous->next = tempNode;
    tempNode->previous = position.current->previous;
    tempNode->next = position.current;
    position.current->previous = tempNode;
    count++;
}

void List::insertAtTail(int x) {  
    ListNode* tempNode = new ListNode();
    tempNode->value = x;
    tail->previous->next = tempNode;
    tempNode->previous = tail->previous;
    tempNode->next = tail;
    tail->previous = tempNode;
    count++;
}

ListItr List::find(int x){ //TA Help:cvt7bm
    ListItr iter = first();
    while (!iter.isPastEnd()) { // taken from deep copy of the list
        if(iter.current->value == x) {
            return iter;
        }
        else {
            iter.moveForward();
        }
    }
    return iter;
}

void List::remove(int x) { //TA Help:bac6vx
   ListItr iter = find(x);
    // ListItr* iter = new ListItr(head); // use parameter constructor 
    // while (!iter->isPastEnd()) { // same algorithm as find but with delete
    //   if(iter->current->value == x) { */
            iter.current->previous->next = iter.current->next;
            iter.current->next->previous = iter.current->previous;
            delete (iter.current);
            count--;
    //   }
    //   else {
    //      iter->moveForward();
    //   } 
//    }  
}

int List::size() const {
    return count;
}

void printList(List& source, bool direction) {
    if (direction == true) {
        ListItr iter = source.first();
        while(!iter.isPastEnd()) {
            cout << " " << iter.retrieve();
            iter.moveForward();
        }
    }
    else { //if direction is false
        ListItr iter = source.last();
        while(!iter.isPastBeginning()) {
            cout << " " << iter.retrieve();
            iter.moveBackward();
        }
    }   
}
