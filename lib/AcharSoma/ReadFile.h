#pragma once
using namespace std;
#include<vector>
class GetNumbersFromFile {
public:
	char* filename;
	vector<double> listOfNumbers;
	vector<double>& getListOfNumbers();
	bool read_file();
};

