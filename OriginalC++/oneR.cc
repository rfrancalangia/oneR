// oneR.cc 
// classifies instances in an arff file using the oneR algorithm
// by: Mike Araujo, Rob Francalangia, and Jeff Horne
// 4/4/17

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include "Instance.h"
#include "linked_list.h"

using namespace std;

int main (void){
	ifstream arff; // file to be read
	Instance insts[1000]; // instances
	Instance train[1000]; // training instances
	Instance test[1000]; // testing instances
	LinkedList value_list; // linked list to store attribute values
	LinkedList best_list; // linked list containing information of attribute used for one rule
	int inst_count = 0; // number of instances
	char att[1000]; // attribute
	char val[1000]; // value
	string attributes[1000]; // attributes
	int att_count = 0; // number of attributes
	string values[1000]; // values
	int val_count = 0; // number of values
	char delim[1000]; // char or string to end input from file
	float error_rate; // error rate of each attribute
	float best_rate = 100; // best error rate, 100 to start as this is the best case
	string best_att; // attribute used for one rule
	string test_val; // stores values of attribute used for best rule
	int best_att_loc; // index of best attribute
	int cmp; // comparison int
	float percent; // desired percent user would like to train
	int num_test; // number of test instances
	int num_train; // numbers of training instances
	int rand_num; // random number
	int correct = 0; // number of correctly classified instances
	int wrong = 0; // number of incorrectly classified instances
	string results[1000]; // stores the classification of an instance
    string filename; // name of the file user wants to open

	// prompt the user to open a file
    cout << "Which File do you want to use? ";
    cin >> filename;
    arff.open(filename.c_str(), ios::in);

	// ignore till attributes
    arff.ignore(1);
    arff.ignore(1000, '@'); 
	arff.get(delim, 1000, ' ');
	cmp = strcmp(delim, "attribute");

	// collect attribute values
	while(cmp == 0){
		arff.ignore(1);
		
		arff.get(att, 1000, '{');
		attributes[att_count] = att;
		att_count++;
		arff.ignore(1000, '@');
		
		if(arff.get() == 'a'){
			arff.unget();
			arff.get(delim, 1000, ' ');
		}
		else{
			arff.get(delim, 1000, '\n');
		}
		cmp = strcmp(delim, "attribute");
	}
	arff.ignore(1);
 
	// collect data values
	while(!arff.eof()){
  
		for(int i = 0; i < att_count; i++){
			if(i == att_count-1){
				arff.getline(val, 1000);
			}else{
				arff.getline(val, 1000, ',');
			}
			values[val_count] = val;
			val_count++;
		}
		//initialize the instance
		if(!arff.eof()){
			insts[inst_count].Init_Instance(attributes, values, att_count);
			inst_count++;
			val_count = 0;
		}
	}

	// ask the user what percentage to train on
	cout << "enter a percentage of the list to train on (integers only): " << endl;

	// calculate the number to train on
	cin >> percent;
	percent = percent/100;
	num_train = inst_count * percent;
	if(num_train < 1){
		percent = 1;
	}

	// create training set, using random value for sorting to ensure different results each time
	srand(time(NULL));
	for(int i = 0; i < num_train; i++){
		rand_num = rand() % inst_count;
		while(insts[rand_num].Is_Used()){
			rand_num = rand() % inst_count;
		}
		train[i].Set_Equal(insts[rand_num]);
		insts[rand_num].Use();
	}

	// create test set
	num_test = inst_count - num_train;
	for(int i = 0; i < num_test; i++){
		rand_num = rand() % inst_count;
		while(insts[rand_num].Is_Used()){
			rand_num = rand() % inst_count;
		}
		test[i].Set_Equal(insts[rand_num]);
		insts[rand_num].Use();
	}

	// print out test and training sets
	cout << "Printing Training Set" << endl << endl;	
	for(int i = 0; i < num_train; i++){
		train[i].print_info(att_count);
	}
	cout << endl;
    cout << "Printing Testing Set" << endl << endl;
	if(num_train == inst_count){
		cout << "Testing being performed on training" << endl;
	}else{	
		for(int i = 0; i < num_test; i++){
			test[i].print_info(att_count);
		}
	}
	cout << endl;

	// create linked lists containing attribute values, keep track of each ones classification
	for(int i = 0; i < att_count-1; i++){
		for(int j = 0; j < num_train; j++){
			if(value_list.has_value(train[j].Get_Value(i))){
				value_list.increment_val(train[j].Get_Value(att_count-1), train[j].Get_Value(i));
				}else{
					value_list.addValue(train[j].Get_Value(i));
					value_list.increment_val(train[j].Get_Value(att_count-1), train[j].Get_Value(i));
				}
		}
		//claculate the error rate of the values in the list
		error_rate = value_list.error_rate();
		// determine if this rate is the best rate, if so, delete the old best list and make a new one
		if(error_rate < best_rate){
			best_rate = error_rate;
			best_att = train[i].Get_Att(i);
			best_att_loc = i;
			best_list.delete_list();
			for(int i = 0; i < value_list.length(); i++){
				best_list.initialize(value_list.get_yes_cnt(i), value_list.get_no_cnt(i), value_list.get_classifier1(), value_list.get_classifier2(), value_list.get_value(i));
			}
		}
		value_list.delete_list(); // delete value list so that new list can be made with different attribute values
	}

	// print out the one rule
	cout << "The one rule is " << best_att << endl;
	best_list.print_list();

	// calculate number of correctly classified instances
	if(num_train != inst_count){
		for (int i = 0; i < num_test; i++){
			test_val = test[i].Get_Value(best_att_loc);
			results[i] = best_list.check_class(test_val);
			if(results[i] == "error"){
				return 0;
			}
		}
		for(int i = 0; i < num_test; i++){
			if(results[i] == test[i].Get_Value(att_count-1)){
				correct++;
			}else{
				wrong++;
			}
		}
	}else{
		for (int i = 0; i < num_train; i++){
			test_val = train[i].Get_Value(best_att_loc);
			results[i] = best_list.check_class(test_val);
			if(results[i] == "error"){
				return 0;
			}
		}
		for(int i = 0; i < num_train; i++){
			if(results[i] == train[i].Get_Value(att_count-1)){
				correct++;
			}else{
				wrong++;
			}
		}
	}

	// print out final report
	cout << "Number Correctly Classified: " << correct << endl;
	cout << "Number Incorrectly Classified: " << wrong << endl;
	cout << "Rate Correct: " << ((float)correct/(float)(correct+wrong))*100 << "%" << endl;
		
	return 0;
} // main
