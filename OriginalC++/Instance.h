#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#ifndef INSTANCE_H
#define INSTANCE_H
class Instance {

public:	
	Instance();
	void Init_Instance(string attributes[], string values[], int att_count);
	void print_info(int att_count);
	void Set_Equal(Instance equal);
	void Use();
	bool Is_Used();
	string Get_Value(int val);
	string Get_Att(int val);

private:
	string attributes[100];
	string values[100];
	int num_vals;
	bool used;
};

#endif
