#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

void uppercaseify(string& mystr);

int main() {
	List *mylist = new List;
	string operation;
	int data;
	while (cin) {
		cin >> operation;
		uppercaseify(operation);
		if (!cin || cin.eof() || operation == "QUIT") {
			delete mylist;
			exit(EXIT_SUCCESS);
		}
		if (operation == "STATUS") {
			cout << mylist->get_list_size() << endl;
		}
		if (operation == "PRINT") {
			mylist->print_list();
		}
		if (operation == "PUSH") {
			cin >> data;
			mylist->push(data);
		}
		if (operation == "POP") {
			data = mylist->pop();
			cout << data << endl;
		}
		if (operation == "SEARCH") {
			cin >> data;
			if (mylist->search(data))
				cout << "IN LIST\n";
			else
				cout << "NOT IN LIST\n";
		}
		if (operation == "REMOVE") {
			cin >> data;
			if (mylist->remove(data))
				cout << "REMOVED\n";
			else
				cout << "NOT REMOVED\n";
		}
	}
	delete mylist;
	return 0;
}

void uppercaseify(string& mystr) {
	for (auto& c: mystr)
		c = toupper(c);
}
