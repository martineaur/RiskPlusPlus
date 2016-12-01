#include <iostream>
#include <string>

using namespace std;

class GameBoard {


	public:
		GameBoard() {//Constructor for setting up the game board
			//default constructor
			initiateCountries();
			createBorders();

/*			for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
				cout << it->first + 1 << ". "<< it->second->getName() << endl;
			}

			for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
				it->second->printNeighbors();
			}*/

			Player player1;
			Player player2;

			Player players[2] = {player1, player2};

			distributeCountries(player1, player2);
			distributeArmies(player1, player2);
		}

		map <int, Country*> riskMap;

	private:



	public:
		void initiateCountries();
		void createBorders();
		void distributeCountries(Player &player1, Player &player2);
		void distributeArmies(Player &player1, Player &player2);
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

/*
 * This function reads 9 files, one for each country. Each file has a list of countries
 * which border that particular country. The file opens and reads through all the country names,
 * adding them to the array of type Country pointers for that country. So each country's array
 * of bordering countries will be filled by this function.
 */
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

	//ADD VENEZUELA


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
				riskMap[0]->pairNeighbor(it->second);
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
				riskMap[1]->pairNeighbor(it->second);
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
				riskMap[2]->pairNeighbor(it->second);
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
				riskMap[3]->pairNeighbor(it->second);
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
				riskMap[4]->pairNeighbor(it->second);
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
				riskMap[5]->pairNeighbor(it->second);
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
				riskMap[6]->pairNeighbor(it->second);
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
				riskMap[7]->pairNeighbor(it->second);
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
				riskMap[8]->pairNeighbor(it->second);
			}
		}
	}
}

void GameBoard::distributeCountries(Player &play1, Player &play2) {
	int choice;
	int counter = 1;

	cout << "Welcome message...." << endl;

	for (int i = 0; i < riskMap.size(); i++) {

		if (counter % 2 != 0) {
			cout << endl << "Player 1 please choose a country" << endl;

			//print out available countries


			for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
				if(!it->second->isOwned()) {
					cout <<"(" << it->first + 1 << ") " <<  it->second->getName() << endl;
				}
			}

			cin >> choice;
			choice--;

			riskMap.find(choice)->second->setOwner(play1.getId());
			play1.becomeOwner(riskMap.find(choice)->second);
			play1.giveArmyToCountry(riskMap.find(choice)->second);
			//play1.printControlledCountries();


		} else {

			cout << endl << "Player 2 please select a country" << endl;
			for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
				if(!it->second->isOwned()) {
					cout <<"(" << it->first + 1 << ") " <<  it->second->getName() << endl;
				}
			}

			cin >> choice;
			choice--;

			riskMap.find(choice)->second->setOwner(play2.getId());
			play2.becomeOwner(riskMap.find(choice)->second);
			play2.giveArmyToCountry(riskMap.find(choice)->second);
		}

		counter++;
	}

	cout << endl << "Player 1 controls: " << endl;
	play1.printControlledCountries();
	cout << "ARMIES AVAILABLE: " << play1.getArmiesAvailable() << endl;
	cout << endl << "Player 2 controls: " << endl;
	play2.printControlledCountries();
	cout << "ARMIES AVAILABLE: " << play2.getArmiesAvailable() << endl;
}

void GameBoard::distributeArmies(Player &play1, Player &play2) {
	int choice;
	int counter = 1;
	while((play1.getArmiesAvailable() + play2.getArmiesAvailable()) != 0) {

			if ((counter % 2 != 0)&&(play1.getArmiesAvailable() != 0)) {
				cout << "Player 1 please choose a country to place one more army in" << endl;
				for (map<int, Country*>::const_iterator it = riskMap.begin(); it != riskMap.end(); ++it) {
								if(it->second->getOwner() == play1.getId()) {
									cout <<"(" << it->first + 1 << ") " <<  it->second->getName() << ": " << it->second->getOccupiedArmies() << endl;
								}
							}
				cin >> choice;
				choice--;

				play1.giveArmyToCountry(riskMap.find(choice)->second);
				play1.printControlledCountries();
			}

			else if((counter % 2 == 0)&&(play2.getArmiesAvailable() != 0)){
				cout << "Player 2 please choose a country to place one more army in"
						<< endl;
				for (map<int, Country*>::const_iterator it = riskMap.begin();
						it != riskMap.end(); ++it) {
					if (it->second->getOwner() == play2.getId()) {
						cout << "(" << it->first + 1 << ") "
								<< it->second->getName() << ": "
								<< it->second->getOccupiedArmies() << endl;
					}
				}
				cin >> choice;
				choice--;

				play2.giveArmyToCountry(riskMap.find(choice)->second);
				play2.printControlledCountries();
			}
		counter++;
	}
}



