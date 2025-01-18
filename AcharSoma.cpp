// AcharSoma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//using std::vector;
#include<cmath>
#include<vector>
#include<map>
#include<forward_list>
#include<list>
#include "ReadFile.cpp"
#include<utility>
//#include <typeinfo>

//typedef forward_list<double>* PONTEIROLISTADOUBLE;
//typedef forward_list<PONTEIROLISTADOUBLE>* PONTEIROLISTADEPONTEIROS;


class AcharSoma {
public:
	vector<double> listOfNumbers;
	map<double,list<list<double>>> somasHash;

	void do_numbers() {
		for(const double& number : listOfNumbers)
			cout << "hello " << number << endl;

		const double length = pow(2, listOfNumbers.size()) - 1;
		cout << "size " << length << endl;

		for(unsigned n = 1; n <= length; n++) {
			int j = 0;
			double soma = 0.0;

			list<double> elementos_da_soma;
			unsigned p;
			while((p = (unsigned)pow(2,j)) <= n) {
				if(p & n) {
					cout << listOfNumbers[j] << " ";
					soma += listOfNumbers[j];
					// colocar o número que faz parte da soma na lista de elementos
					elementos_da_soma.push_front(listOfNumbers[j]);
				}
				j++;
			}
			// vamos ter que criar um map que aponta para listas de listas
			//
			// primeiro devemos ver se já temos um map com essa chave
			if(somasHash.find(soma) == somasHash.end()) {
				// a chave soma NÃO existe!
				list<list<double>> listaDeListas;
				listaDeListas.push_back(elementos_da_soma);
				somasHash.insert(pair<double,list<list<double>>>(soma,listaDeListas));
				//somasHash.insert(pair<double,std::reference_wrapper<PONTEIROLISTADEPONTEIROS>>(soma,&elementos_da_soma));
				//somasHash.insert(std::pair<double,forward_list<double>*>(soma,&elementos_da_soma));
				//somasHash.insert({soma,&elementos_da_soma});
				//somasHash[soma] = &elementos_da_soma;
				//somasHash.emplace(pair<double,forward_list<forward_list<double>*>*>(soma,&elementos_da_soma));
			} else {
				// a chave soma existe! Basta inserir no fim da lista a referência para a lista de elementos
				//forward_list<double>& referencia_para_lista_de_uma_soma = (*somasHash.find(soma)).second;
				list<list<double>> referencia_para_lista_de_uma_soma = (*somasHash.find(soma)).second;
				referencia_para_lista_de_uma_soma.push_front(elementos_da_soma);
				//somasHash.find(soma).push_front(&elementos_da_soma);
				//somasHash.find(soma).push_front(&elementos_da_soma);

			}

			cout << " SOMA: " << soma << endl;
			//cout << "============= " << endl;


		}
	}

};

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

	// nesse momento getnumbers.listOfNumbers está zerado pois eu ainda preciso converter as strings para double!

	//for(const double& number : getnumbers.listOfNumbers)
	//	find.listOfNumbers.push_back(number);
	find.do_numbers();

	//	for (string w : getnumbers.) {
	//        cout << "|" << w << "|" << endl;
	//	}
	return 0;


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
