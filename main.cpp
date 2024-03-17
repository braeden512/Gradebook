/*
Braeden Treutel
Linked List Gradebook
*/

#include <iostream>
#include <fstream>
#include "StudentDList.h"

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

int main() {
	//Creating the student list object
	StudentDList slist;
	//Opening the file
  cout << "Enter student file to process: ";
	string file;
	cin >> file;
	cout << endl;

	//Processing/reading the file in
	ifstream infile(file);
	char letter;
	while (infile){
		letter = ' ';
		infile >> letter;
		if (letter == 'a'){
			string first;
			infile >> first;
			string last;
			infile >> last;
			float gpa;
			infile >> gpa;
			Student s;
			s.fname = first;
			s.lname = last;
			s.gpa = gpa;

			slist.insert_node(s);
		}
		else if (letter == 'd'){
			string last;
			infile >> last;
			Student s = slist.find(last);
			slist.delete_node(s);
		}
		
	}
	//Closing the file
	infile.close();

	//Printing out the final lists
	cout << "The list of Students in order is: " << endl;
	slist.print_list_forward();
	cout << endl;
	cout << "The list of Students in reverse is: " << endl;
	slist.print_list_reverse();
}
