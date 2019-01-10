#pragma once

//This Node class is fully functional
class Node {
	int data; //Holds the data we're keeping track of
	Node *next;
	public:
	Node() {
		data = 0;
		next = NULL;
	}
	~Node() {
		//You: Write a destructor here if you need one
	}
	Node(int new_data, Node *new_next) {
		data = new_data;
		next = new_next;
	}
	int get_data() const { return data; }
	Node *get_next() const { return next; }
	void set_next(Node *new_next) { next = new_next; }
};
