#include <stdbool.h>
#include <stdio.h> /* load i/o routines */
#include <string.h>
#include <stdlib.h>
#include <ctype.h> /* load character test routines */
#include <iostream>

using namespace std;

class LinkedList{
    struct Node {
        string value;
		int yes_cnt; // count of first classification
		int no_cnt; // count of second classification
        Node *next;
    };
 public:
 
	// constructor
    LinkedList(){
        head = NULL;
		class1 = "blank";
		class2 = "blank";
		classified1 = false;
		classified2 = false;
    }

	// add a node to the list
    void addValue(string val){
        Node *n = new Node();  
        n->value = val;
		n->yes_cnt = 0;
		n->no_cnt = 0;
        n->next = head;
        head = n;             
    }

	// add a node to the list with given values
	void initialize(int yes, int no, string classifier1, string classifier2, string val){
        Node *n = new Node();  
		class1 = classifier1;
		class2 = classifier2;
        n->value = val;
		n->yes_cnt = yes;
		n->no_cnt = no;
        n->next = head;
        head = n;             
    }

	// delete the list
	void delete_list(){
        head = NULL;
    }

	// print the list
	void print_list(){
		Node * current = head;

		while (current != NULL) {
			cout << current->value << ": ";
			if(current->yes_cnt >= current->no_cnt){
				cout << class1 << endl;
			}else{
				cout << class2 << endl;
			}
			current = current->next;
		}
		cout << endl;
	}

	// determines whether the given value is in the list
	bool has_value(string val){
		Node * current = head;

		while (current != NULL) {
			if(current->value == val){
				
				return true;
			}
			current = current->next;
		}
		return false;
	}
	
	// increments the classification counters based upon the value of the attribute
	void increment_val(string classifier, string val){
		Node * current = head;
		if(class1 == "blank" && classified1 == false){
			class1 = classifier;
			classified1 = true;
		}
        if(classifier != class1 && classified2 == false){
			class2 = classifier;
			classified2 = true;
		}
		while(current->value != val){
			current = current->next;
		}
		if(classifier == class1){
			current->yes_cnt++;
		}else{
			current->no_cnt++;
		}
	}
	
	// calculates the error rate of a given attribute
	float error_rate(){
		Node* current = head;
		float error_rate;
		int  error_num = 0;
		int  error_denom = 0;
		while(current != NULL){
			if(current->yes_cnt <= current->no_cnt){
				error_num += current->yes_cnt;
				error_denom += current->no_cnt;
			}else{
				error_num += current->no_cnt;
				error_denom += current->yes_cnt;
			}
			current = current->next;
		}
		error_denom += error_num;
		error_rate = (float)error_num / (float)error_denom;
		return error_rate;
	}

	// returns the length of the list
	int length(){
		Node * current = head;
		int count = 0;
		while(current != NULL){
			current = current ->next;
			count++;
		}
		return count;
	}

	// calculates given number of first classification at given value
	int get_yes_cnt(int count){
		Node* current = head;
		for(int i = 0; i < count; i++){
			current = current -> next;
		}	
		return current->yes_cnt;
	}

	// calculates given number of second classification at given value
	int get_no_cnt(int count){
		Node* current = head;
		for(int i = 0; i < count; i++){
			current = current -> next;
		}	
		return current->no_cnt;
	}

	// gets the value at given location in list
	string get_value(int count){
		Node* current = head;
		for(int i = 0; i < count; i++){
			current = current -> next;
		}	
		return current->value;
	}

	// returns the first classifier
	string get_classifier1(){
		return class1;
	}
	
	// returns the second classifier
	string get_classifier2(){
		return class2;
	}

	// checks the classification of a given value
	string check_class(string val){
		Node* current = head;
		while(current != NULL && current->value != val){
			current = current->next;
		}
		if(current == NULL){
			cout << "Error, did not collect data on all attribute values, train on more instances!" << endl; // print error if not enough information was collected
			return "error";
		}
		if(current->yes_cnt >= current->no_cnt){
			return class1;
		}else{
			return class2;
		}
	}

 private:
    Node *head;
	string class1; // first classification encountered in data
	string class2; // second classification encountered in data
	bool classified1; // has the first classification been encountered
	bool classified2; // has the second classification been encountered
};

