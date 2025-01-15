#include <iostream>
using namespace std;
//using std::vector;
#include<vector>
#include <fstream>
#include <sstream>


class GetNumbersFromFile {
public:
	char* filename;
	vector<double> listOfNumbers;

	bool read_file() {
		//ifstream myfile("file1");
		ifstream myfile(filename);
		string line;

		if(myfile.is_open()) {
			while(getline(myfile,line)) {
				split_sentence(line);
			}
			myfile.close();
		} else {
			cout << "Unable to open file" << endl;
			return false;
		}
		for(string w : words) {
			cout << "|" << w << "|" << endl;
		}
		return true;
	}
private:
	vector<string> words;
	void split_sentence(string sen) {

		// Create a stringstream object
		stringstream ss(sen);

		// Variable to hold each word
		string word;

		// Vector to store the words
		//vector<string> words;

		// Extract words from the sentence
		while(ss >> word) {

			// Add the word to the vector
			words.push_back(word);
		}

	}
};

