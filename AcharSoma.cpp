// AcharSoma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//using std::vector;
#include<cmath>
#include<vector>
#include "ReadFile.cpp"
//#include <typeinfo>


class AcharSoma {
public:
	vector<double> listOfNumbers;

	void do_numbers() {
		for(const double& number : listOfNumbers)
			cout << "hello " << number << endl;

		const double length = pow(2,listOfNumbers.size()) - 1;
		cout << "size " << length << endl;

		for(unsigned n = 1; n <= length; n++) {
			int j = 0;
			double soma = 0.0;

			unsigned p;
			while((p = (unsigned)pow(2,j)) <= n) {
				if(p & n) {
					cout << listOfNumbers[j] << " ";
					soma += listOfNumbers[j];
				}
				j++;
			}
			cout << " SOMA: " << soma << endl;
			cout << "============= " << endl;


		}
	}

};

int main(int argc,char *argv[]) {
	GetNumbersFromFile getnumbers;
	int i = 1;
	while(i < argc) {
		cout << argv[i] << endl;
		getnumbers.filename = argv[i];
		getnumbers.read_file();
		i++;
	}	
	//	for (string w : getnumbers.) {
	//        cout << "|" << w << "|" << endl;
	//	}
	//AcharSoma find;
	//find.listOfNumbers = {1.1,2.2,3.3,4.4};
	//find.do_numbers();
	//return 0;


}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
