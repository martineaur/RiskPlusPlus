#include <iostream>
#include <string>

using namespace std;

class GameBoard {


	public:
		GameBoard() {
			//default constructor
			initiateCountries();
			createBorders();

			for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
				cout << it->first + 1 << ". "<< it->second->getName() << endl;
			}

			for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
				it->second->printNeighbors();
			}

		}

		map <int, Country*> riskMap;

	private:



	public:
		void initiateCountries();
		void createBorders();
	//making a second change
	//I made a change
	//change made on github

	//Ryan Reid change

	//leo Dos Santosss
	//Martineau's change
};

void GameBoard::initiateCountries() {
	//text file:
		fstream listOfCountries;
		string countryName;
		int count = 0;

		if (listOfCountries.is_open()) {}
		else {
			listOfCountries.open("northAmericaTest.txt");

			if (listOfCountries.fail()) {
				cerr << "Error Opening File" << endl;
				exit(1);
			}
		}

		while(getline(listOfCountries, countryName)) {

			riskMap[count] = new Country(countryName);
			count++;
		}

}

void GameBoard::createBorders() {

	//THIS NEEDS TO BE OPTIMIZED -- THIS IS HORRIBLE
	fstream alaskaBorders;
	fstream albertaBorders;
	fstream centralAmericaBorders;
	fstream eastUSABorders;
	fstream greenlandBorders;
	fstream nwtBorders;
	fstream ontarioBorders;
	fstream quebecBorders;
	fstream westUSABorders;

	string border;


	//ALASKA BORDERS
	if (alaskaBorders.is_open()) {}
	else {
		alaskaBorders.open("alaskaBorders.txt");

		if (alaskaBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while(getline(alaskaBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[0]->pairNeighborPtr(it->second);
			}
		}
	}


	//NORTH WEST TERRITORY BORDERS
	if (nwtBorders.is_open()) {}
	else {
		nwtBorders.open("nwtBorders.txt");

		if (nwtBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while(getline(nwtBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[1]->pairNeighborPtr(it->second);
			}
		}
	}

	//ALBERTA BORDERS
	if (albertaBorders.is_open()) {}
	else {
		albertaBorders.open("albertaBorders.txt");

		if (albertaBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while(getline(albertaBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[2]->pairNeighborPtr(it->second);
			}
		}
	}

	//ONTARIO BORDERS
	if (ontarioBorders.is_open()) {}
	else {
		ontarioBorders.open("ontarioBorders.txt");

		if (ontarioBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while(getline(ontarioBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[3]->pairNeighborPtr(it->second);
			}
		}
	}

	//QUEBEC BORDERS
	if (quebecBorders.is_open()) {}
	else {
		quebecBorders.open("quebecBorders.txt");

		if (quebecBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while(getline(quebecBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[4]->pairNeighborPtr(it->second);
			}
		}
	}

	//GREENLAND BORDERS
	if (greenlandBorders.is_open()) {}
	else {
		greenlandBorders.open("greenlandBorders.txt");

		if (greenlandBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while(getline(greenlandBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[5]->pairNeighborPtr(it->second);
			}
		}
	}

	//WESTERN UNITED STATES BORDERS
	if (westUSABorders.is_open()) {}
	else {
		westUSABorders.open("westUSABorders.txt");

		if (westUSABorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while(getline(westUSABorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[6]->pairNeighborPtr(it->second);
			}
		}
	}

	//EASTERN UNITED STATES BORDERS
	if (eastUSABorders.is_open()) {}
		else {
			eastUSABorders.open("eastUSABorders.txt");

			if (eastUSABorders.fail()) {
				cerr << "Error Opening File" << endl;
				exit(1);
			}
		}

	while(getline(eastUSABorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[7]->pairNeighborPtr(it->second);
			}
		}
	}

	//CENTRAL AMERICA BORDERS
	if (centralAmericaBorders.is_open()) {}
		else {
			centralAmericaBorders.open("centralAmericaBorders.txt");

			if (centralAmericaBorders.fail()) {
				cerr << "Error Opening File" << endl;
				exit(1);
			}
		}

	while(getline(centralAmericaBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[8]->pairNeighborPtr(it->second);
			}
		}
	}




}
