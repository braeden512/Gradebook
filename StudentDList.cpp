#include "StudentDList.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//Constructor
StudentDList::StudentDList() : head(nullptr), tail(nullptr){};

//Destructor
StudentDList::~StudentDList() {
  ListNode *current;
  ListNode *next;

  current = head;
  while (current != nullptr) {
    next = current->next;
    delete current;
    current = next;
  }
}
//find function to find a student in the linked list given their last name
Student StudentDList::find(string lname){
	ListNode *curr;
	curr = head;
	while (curr != nullptr){
		if (lname == (curr->person.lname)){
			return curr->person;
		}
		curr = curr->next;
	}
	cout << lname << " is not in the list" << endl;
	Student blank;
	return blank;
}

//Function to insert a node into the linked list
void StudentDList::insert_node(Student st) {
	ListNode *newNode; // New node we are adding
    ListNode *curr;    //Current space we are comparing
    ListNode *prev;    //Points to the space behind curr
    
    //Create new node and assign it
    newNode = new ListNode;
    newNode->person = st;
    newNode->next = nullptr;
    
    // Ensure that our newNode isn't the only item in the list
    if (!head)
        head = newNode;
    else{
        // 1) Have current be looking at the same place as head
        //    and the previous spot is nullptr
        curr = head;
        prev = nullptr;
        // 2) as long as the current node hasn't reached the nullptr at the end
        //    and the current value is less than the num I want to insert
        while(curr != nullptr && curr->person.lname < st.lname){
            prev = curr; // have previous look where curr is
            curr = curr->next; // then move curr to the next Node
        }
        // If the new node is less than the first node in the list
        // insert it to the front
        if(prev == nullptr){
            head = newNode; // by making it the head
            newNode->next = curr; // and having the new head point to the old one
        }
        else { // otherwise insert it after the previous node
            prev->next = newNode; // by pointing the previous node to it
            newNode->next = curr; // then pointint it to the "curr" node
        }
    }    
}
//Function to delete a node from the linked list
void StudentDList::delete_node(Student st) {
	// Similar to insert we need 2 pointers to traverse
    // and update the list properly
    ListNode *curr;
    ListNode *prev;
    
    // If our list is empty we should do nothing
    if(!head){
        cout << "List is empty...cannot delete " << st.lname << endl;
        return;
    }
    // Otherwise Find the node to delete
    // If the first node is the one to be removed
    if(head->person.lname == st.lname){
        // 1) assign curr to head->next
        curr = head->next;
        // 2) delete head to free up the memory
        delete head;
        // 3) assign head to curr so we don't lose the list
        head = curr;
    }
    else { // Otherwise Traverse the list until we find the value
        curr = head; // look at the beginning
        // shift current and previous down the list one at a time
        // until either we hit the end or we find the value
        while(curr != nullptr && curr->person.lname != st.lname){
            prev = curr;
            curr = curr->next;
        }
        // If the curr node is not a nullptr
        if (curr){
            // have previous point to where it was pointing
            prev->next = curr->next;
            // then delete curr
            delete curr;
        
        }
        else {
        
        }
        
    }
}
//Function that prints the list forwards
void StudentDList::print_list_forward() {
  ListNode *curr; // create a new pointer to walk along the list
    curr = head;    // and set it to the head
    
    // If our list is empty (print a nice empty message)'
    // and return
    if(!head){
        cout << "List is currently empty!!" << endl;
        return;
    }
    while(curr){     // as long as it isn't a nullptr address
        // 1) we can print the data in it
        //cout << curr->number << endl;
			cout << curr->person.lname << ", " << curr->person.fname
			<< " GPA " << curr->person.gpa << endl;
        // 2) we then shift it along the list
        curr = curr->next;
    }
}

//Overloaded functions that use recursion to print the linked list backwards

void StudentDList::print_list_reverse() {
  print_list_reverse(head);
}

void StudentDList::print_list_reverse(ListNode *curr) {
	if(curr) {
    print_list_reverse(curr->next);
  	cout << curr->person.lname << ", " << curr->person.fname
			<< " GPA " << curr->person.gpa << endl;
  }
}
