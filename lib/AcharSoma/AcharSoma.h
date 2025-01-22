#pragma once

using namespace std;
#include<vector>
#include<map>
class AcharSoma {
public:
	vector<double> listOfNumbers;
	map<double,vector<vector<double>*>*> somasHash;
	map<double,vector<vector<double>*>*> do_numbers();
	bool print_result();
};

