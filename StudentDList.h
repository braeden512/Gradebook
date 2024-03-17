#ifndef STUDENTDLIST_H
#define STUDENTDLIST_H

#include <iostream>
using std::string;

//Student struct (data)
struct Student{
	string fname;
	string lname;
	double gpa;
};

//Linked List Node struct
struct ListNode{
	Student person;
	ListNode *next;
	ListNode *previous;
};

//StudentDList class that uses the other structs 
class StudentDList{

//private members
private:
ListNode* head;
ListNode* tail;

//public functions and constructors/destructors
public:
StudentDList();
~StudentDList();
Student find(string lname);
void insert_node(Student st);
void delete_node(Student st);
void print_list_forward();
void print_list_reverse();
void print_list_reverse(ListNode *curr);
};

#endif
