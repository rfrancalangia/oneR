#include <iostream>
#include <string>
#include "Instance.h"

using namespace std;

// constructor, intialize instance
Instance::Instance(){
	num_vals = 0;
	used = false;
	for(int i = 0; i < 100; i++){
		attributes[i] = "empty";
		values[i] = "empty";
	}
}		
// initialize instance with values
void Instance::Init_Instance(string atts[], string vals[], int att_count){
	num_vals = att_count;
	for(int i = 0; i < att_count; i++){
		attributes[i] = atts[i];
	    values[i] = vals[i];
	}
}

// print information about the instance
void Instance::print_info(int att_count){
	for(int i = 0; i < att_count; i++){
		cout << attributes[i] << endl << values[i] << endl; 
	}
	cout << endl;
}

// set this instance equal to another
void Instance::Set_Equal(Instance equal){
	num_vals = equal.num_vals;
	for(int i = 0; i < num_vals; i++){
		attributes[i] = equal.attributes[i];
	    values[i] = equal.values[i];
	}
}

// instance has been added to  testing 
void Instance::Use(){
	used = true;
}

// returns value of used
bool Instance::Is_Used(){
	return used;
}

// returns value at given index
string Instance::Get_Value(int val){
	return values[val];
}	

// returns attribute at given index
string Instance::Get_Att(int val){
	return attributes[val];
}
