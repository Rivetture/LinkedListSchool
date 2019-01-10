#include <iostream>
#include "list.h"
using namespace std;

//YOU: Write these five functions
//Make sure you handle empty Lists cleanly!

//Destructor. Free all memory in the list
List::~List() {
	Node *temp1 = head_ptr;
	while(temp1 != NULL){
		Node *temp2 = temp1 -> get_next();
		delete(temp1);
		temp1 = temp2;

	}
}

//Deletes the oldest Node inserted, and returns its data value
//The oldest Node inserted should be tail_ptr

int List::pop() {
	int x = 0;
	if(list_size == 0){
		return 0;
	}
	else if(list_size == 1){
		x = tail_ptr -> get_data();
		delete tail_ptr;
		head_ptr = NULL;
		tail_ptr = NULL;
		list_size--;
		return x;	
	}
	else{
		Node *temp3 = head_ptr;
		while(temp3 != NULL)
		{
		if(temp3 -> get_next() == tail_ptr){
		
		x = tail_ptr -> get_data();
		delete tail_ptr;
		tail_ptr = temp3;
		tail_ptr -> set_next(NULL);
		list_size--;
		return x;
		}
	temp3 = temp3 -> get_next();

	}
		return 0;
}

}
//Adds a new Node to the end of the list
//The newest Node will be held in head_ptr
void List::push(int new_data) {
		//Node *head = nullptr;
		Node *temp = new Node(new_data,head_ptr);
		head_ptr = temp;
		if(list_size ==0) tail_ptr = head_ptr;
		list_size++;
	
}

//Returns if a Node containing the passed-in integer is in the list
//True if such a Node exists, false otherwise
bool List::search(int test_data) {
	if(list_size ==0) return false;
	Node *tmp5_ptr = head_ptr;
		while(tmp5_ptr != NULL){
		//	if(head_ptr -> get_next() -> get_data() == NULL) break;
			if(tmp5_ptr -> get_data() == test_data) return true;
			
				tmp5_ptr = tmp5_ptr -> get_next();
				
			}
	return false;
}

//Removes the newest node containing the passed in integer
//Only remove one Node. Not all of them.
//Return true if any elements removed, false otherwise
bool List::remove (int old_data) {
	if(list_size ==0) return false;
	Node *temp_ptr = head_ptr;
	Node *conf = NULL;
	
		if(head_ptr -> get_data() == old_data){
			head_ptr = temp_ptr -> get_next();
			delete temp_ptr;
			list_size--;
			return true;
		}
		temp_ptr = head_ptr -> get_next();
		conf = head_ptr;
		while(temp_ptr != NULL){
			if(temp_ptr -> get_data() == old_data){
				conf -> set_next(temp_ptr -> get_next());
				if(temp_ptr == tail_ptr){
					tail_ptr = conf;
				}
				delete temp_ptr;
				list_size -- ;
				return true;
			}
			conf = temp_ptr;
			temp_ptr = temp_ptr -> get_next();
		}
		return false;
}

