#include "ReadFile.h"
#include <iostream>
#include <fstream>
#include <sstream>

static vector<string> words;
ReadFile::vector<double>& getListOfNumbers() {
		return listOfNumbers;
}
ReadFile::bool read_file() {
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
		// transferir todos os 'words' para listOfNumbers
		//for(string w : words) {
		while(!words.empty()) {
			//cout << "|" << w << "|" << endl;
			listOfNumbers.push_back(
					stod(
						words.back()
						));
			words.pop_back();
		}
		for(double d : listOfNumbers) {
			cout << "|" << d << "|" << endl;
		}

		return true;
	}
}
ReadFile::void split_sentence(string sen) {

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

