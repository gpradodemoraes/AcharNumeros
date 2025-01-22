#include "AcharSoma.h"
#include <iostream>
//using std::vector;
#include<cmath>
#include<forward_list>
#include<list>
#include "GetNumbersFromFile.h"
#include<utility>

//	vector<double> listOfNumbers;
//	map<double,vector<vector<double>*>*> somasHash;

bool AcharSoma::print_result() {
	if(somasHash.empty()) {
		return false;
	}
	map<double,vector<vector<double>*>*>::iterator soma;
	for(soma = somasHash.begin(); soma != somasHash.end(); soma++) {
		vector<vector<double>*>* array_de_todas_as_somas_que_dao_soma = soma->second;
		for(vector<double>* parcelas : *array_de_todas_as_somas_que_dao_soma) {
			printf("%.2f = ", soma->first);
			for(vector<double>::iterator it = parcelas->begin(); it != parcelas->end(); it++) {
			//for(double d : *parcelas) {
				printf("%.2f", *it);
				if(it == parcelas->end() - 1) {
					printf("\n");
				} else {
					printf(" + ");
				}
			}
		}
		printf("\n");
	}
	return true;
}
map<double,vector<vector<double>*>*> AcharSoma::do_numbers() {
		// for(const double& number : listOfNumbers)
		// 	cout << "hello " << number << '\n';

		const double length = pow(2, listOfNumbers.size()) - 1;
		//cout << "size " << length << '\n';


		for(unsigned n = 1; n <= length; n++) {
			int j = 0;
			double soma = 0.0;


			unsigned p;
			vector<double>* elementos_da_soma = new vector<double>();
			while((p = (unsigned)pow(2,j)) <= n) {
				if(p & n) {
					//cout << listOfNumbers[j] << " ";
					soma += listOfNumbers[j];
					// colocar o número que faz parte da soma na lista de elementos
					elementos_da_soma->push_back(listOfNumbers[j]);
				}
				j++;
			}
			// vamos ter que criar um map que aponta para listas de listas
			//
			// primeiro devemos ver se já temos um map com essa chave
			if(somasHash.find(soma) == somasHash.end()) {
				// a chave soma NÃO existe!
				vector<vector<double>*>* listaDeListas = new vector<vector<double>*>();
				listaDeListas->push_back(elementos_da_soma);
				somasHash.insert(pair<double,vector<vector<double>*>*>(soma,listaDeListas));
				//somasHash.insert(pair<double,std::reference_wrapper<PONTEIROLISTADEPONTEIROS>>(soma,&elementos_da_soma));
				//somasHash.insert(std::pair<double,forward_list<double>*>(soma,&elementos_da_soma));
				//somasHash.insert({soma,&elementos_da_soma});
				//somasHash[soma] = &elementos_da_soma;
				//somasHash.emplace(pair<double,forward_list<forward_list<double>*>*>(soma,&elementos_da_soma));
			} else {
				// a chave soma existe! Basta inserir no fim da lista a referência para a lista de elementos
				//forward_list<double>& referencia_para_lista_de_uma_soma = (*somasHash.find(soma)).second;
				vector<vector<double>*>* referencia_para_lista_de_uma_soma = (*somasHash.find(soma)).second;
				referencia_para_lista_de_uma_soma->push_back(elementos_da_soma);
				//somasHash.find(soma).push_front(&elementos_da_soma);
				//somasHash.find(soma).push_front(&elementos_da_soma);

			}
			//elementos_da_soma.erase(elementos_da_soma.begin(),elementos_da_soma.end());

			//cout << " SOMA: " << soma << endl;
			//cout << "============= " << endl;


		}
	return somasHash;
}
