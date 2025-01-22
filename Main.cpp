#include "AcharSoma.h"
#include "GetNumbersFromFile.h"
#include <vector>
#include <stdio.h>

using namespace std;


int main(int argc,char *argv[]) {
	GetNumbersFromFile getnumbers;
	int i = 1;
	while(i < argc) {
		getnumbers.filename = argv[i];
		getnumbers.read_file();
		i++;
	}
	AcharSoma find;
	find.listOfNumbers = getnumbers.listOfNumbers;

	//for(const double& number : getnumbers.listOfNumbers)
	//	find.listOfNumbers.push_back(number);
	map<double,vector<vector<double>*>*> hash = find.do_numbers();


	if(!find.print_result()) {
		printf("não foi possível printar as somas!\n");
		return 1;
	}
	return 0;
}

