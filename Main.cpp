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
	map<double,vector<vector<double>*>*> hash = find.do_numbers();

	map<double,vector<vector<double>*>*>::iterator soma;
	for(soma = hash.begin(); soma != hash.end(); soma++){
		vector<vector<double>*>* array_de_todas_as_somas_que_dao_soma = soma->second;
		for(vector<double>* parcelas : *array_de_todas_as_somas_que_dao_soma) {
			//cout << soma->first << " = ";
			printf("%.2f = ", soma->first);
			for(vector<double>::iterator it = parcelas->begin(); it != parcelas->end(); it++) {
			//for(double d : *parcelas) {
				//cout << *it;
				printf("%.2f", *it);
				if(it == parcelas->end() - 1) {
					printf("\n");
				} else {
					printf(" + ");
				}
			}
		}
		cout << '\n';

	}

	//	for (string w : getnumbers.) {
	//        cout << "|" << w << "|" << endl;
	//	}
	return 0;


}

