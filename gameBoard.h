#include <iostream>
#include <string>
#include "dice.h"
using namespace std;

class GameBoard {

public:
	GameBoard() { //Constructor for setting up the game board
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

		Player players[2] = { player1, player2 };

		distributeCountries(player1, player2);
		distributeArmies(player1, player2);

		takeTurn(player1, player2);
	}

	map<int, Country*> riskMap;

private:

public:
	void initiateCountries();
	void createBorders();
	void distributeCountries(Player &player1, Player &player2);
	void distributeArmies(Player &player1, Player &player2);

	void printStatus();

	void takeTurn(Player &player1, Player &player2);
	void attack(Player &player, Player &player2);
	void manueverTroops(Player &player);
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

	if (listOfCountries.is_open()) {
	} else {
		listOfCountries.open("northAmericaTest.txt");

		if (listOfCountries.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(listOfCountries, countryName)) {

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
	if (alaskaBorders.is_open()) {
	} else {
		alaskaBorders.open("alaskaBorders.txt");

		if (alaskaBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(alaskaBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[0]->pairNeighbor(it->second);
			}
		}
	}

	//NORTH WEST TERRITORY BORDERS
	if (nwtBorders.is_open()) {
	} else {
		nwtBorders.open("nwtBorders.txt");

		if (nwtBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(nwtBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[1]->pairNeighbor(it->second);
			}
		}
	}

	//ALBERTA BORDERS
	if (albertaBorders.is_open()) {
	} else {
		albertaBorders.open("albertaBorders.txt");

		if (albertaBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(albertaBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[2]->pairNeighbor(it->second);
			}
		}
	}

	//ONTARIO BORDERS
	if (ontarioBorders.is_open()) {
	} else {
		ontarioBorders.open("ontarioBorders.txt");

		if (ontarioBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(ontarioBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[3]->pairNeighbor(it->second);
			}
		}
	}

	//QUEBEC BORDERS
	if (quebecBorders.is_open()) {
	} else {
		quebecBorders.open("quebecBorders.txt");

		if (quebecBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(quebecBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[4]->pairNeighbor(it->second);
			}
		}
	}

	//GREENLAND BORDERS
	if (greenlandBorders.is_open()) {
	} else {
		greenlandBorders.open("greenlandBorders.txt");

		if (greenlandBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(greenlandBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[5]->pairNeighbor(it->second);
			}
		}
	}

	//WESTERN UNITED STATES BORDERS
	if (westUSABorders.is_open()) {
	} else {
		westUSABorders.open("westUSABorders.txt");

		if (westUSABorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(westUSABorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[6]->pairNeighbor(it->second);
			}
		}
	}

	//EASTERN UNITED STATES BORDERS
	if (eastUSABorders.is_open()) {
	} else {
		eastUSABorders.open("eastUSABorders.txt");

		if (eastUSABorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(eastUSABorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[7]->pairNeighbor(it->second);
			}
		}
	}

	//CENTRAL AMERICA BORDERS
	if (centralAmericaBorders.is_open()) {
	} else {
		centralAmericaBorders.open("centralAmericaBorders.txt");

		if (centralAmericaBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(centralAmericaBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
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

			for (map<int, Country*>::const_iterator it = riskMap.begin();
					it != riskMap.end(); ++it) {
				if (!it->second->isOwned()) {
					cout << "(" << it->first + 1 << ") "
							<< it->second->getName() << endl;
				}
			}
			cout << endl;
			cin >> choice;
			choice--;

			riskMap.find(choice)->second->setOwner(play1.getId());
			play1.becomeOwner(riskMap.find(choice)->second);
			play1.giveArmyToCountry(riskMap.find(choice)->second);
			//play1.printControlledCountries();

		} else {

			cout << endl << "Player 2 please select a country" << endl;
			for (map<int, Country*>::const_iterator it = riskMap.begin();
					it != riskMap.end(); ++it) {
				if (!it->second->isOwned()) {
					cout << "(" << it->first + 1 << ") "
							<< it->second->getName() << endl;
				}
			}
			cout << endl;
			cin >> choice;
			choice--;

			riskMap.find(choice)->second->setOwner(play2.getId());
			play2.becomeOwner(riskMap.find(choice)->second);
			play2.giveArmyToCountry(riskMap.find(choice)->second);
		}

		counter++;
	}

	cout << endl << "Player 1 controls: " << endl;
	cout << "ARMIES AVAILABLE: " << play1.getArmiesAvailable() << endl;
	play1.printControlledCountries();

	cout << endl << "Player 2 controls: " << endl;
	cout << "ARMIES AVAILABLE: " << play2.getArmiesAvailable() << endl;
	play2.printControlledCountries();

}

void GameBoard::distributeArmies(Player &play1, Player &play2) {
	int choice;
	int counter = 1;
	while ((play1.getArmiesAvailable() + play2.getArmiesAvailable()) != 0) {

		if ((counter % 2 != 0) && (play1.getArmiesAvailable() != 0)) {
			cout << endl
					<< "Player 1 please choose a country to place one more army in"
					<< endl;
			for (map<int, Country*>::const_iterator it = riskMap.begin();
					it != riskMap.end(); ++it) {
				if (it->second->getOwner() == play1.getId()) {
					cout << "(" << it->first + 1 << ") "
							<< it->second->getName() << ": "
							<< it->second->getOccupiedArmies() << endl;
				}
			}
			cout << endl;
			cin >> choice;
			cout << endl;
			choice--;

			play1.giveArmyToCountry(riskMap.find(choice)->second);
			play1.printControlledCountries();
		}

		else if ((counter % 2 == 0) && (play2.getArmiesAvailable() != 0)) {
			cout << endl
					<< "Player 2 please choose a country to place one more army in"
					<< endl;
			for (map<int, Country*>::const_iterator it = riskMap.begin();
					it != riskMap.end(); ++it) {
				if (it->second->getOwner() == play2.getId()) {
					cout << "(" << it->first + 1 << ") "
							<< it->second->getName() << ": "
							<< it->second->getOccupiedArmies() << endl;
				}
			}
			cout << endl;
			cin >> choice;
			cout << endl;
			choice--;

			play2.giveArmyToCountry(riskMap.find(choice)->second);
			play2.printControlledCountries();
		}
		counter++;
	}
}

void GameBoard::printStatus() {
	//function to print the status of the game
	for (map<int, Country*>::const_iterator it = riskMap.begin();
			it != riskMap.end(); ++it) {
	}
}

void GameBoard::takeTurn(Player &player, Player &player2) {

	//Give player three armies to the player taking the turn.

	//Make the player place their armies into a territory that is theirs
	//if the territory is not theirs, warn the user

	//once all new armies have been placed, allow the user to attack (if they want)

	//once the player is done attacking, allow the user to manuever their armies into postition
	//if they wish to go into a territory that is not in their control, warn the user
	//if the a user makes a move that would not leave any armies in a controlled territory,
	//do not allow

	int placementChoice;
	char attackChoice;
	bool attackMenu = 1;

	player.setArmiesAvailable(3);

	while (player.getArmiesAvailable() != 0) {
		cout << "Please select country you wish to put an army in" << endl
				<< endl;
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getOwner() == player.getId()) {
				cout << "(" << it->first + 1 << ") " << it->second->getName()
						<< ": " << it->second->getOccupiedArmies() << endl;
			}
		}

		cin >> placementChoice;
		placementChoice--;

		player.giveArmyToCountry(riskMap.find(placementChoice)->second);
		player.printControlledCountries();
	}

	while (attackMenu) {
		cout << "Do you wish to attack (Y/N)?" << endl << endl;
		cin >> attackChoice;

		switch (attackChoice) {
		case 'Y':
		case 'y':
			attack(player, player2);
			break;

		case 'N':
		case 'n':
			attackMenu = 0;
			break;
		default:
			cin.clear();
			cin.ignore();
			cout << "Invalid selection" << endl;
			break;
		}

	}

	manueverTroops(player);

}

void GameBoard::attack(Player &attacker, Player &defender) {
	int attackFrom;
	int attackTo;
	int attackWith;

	cout << "Please select a country to attack from" << endl << endl;
	for (map<int, Country*>::const_iterator it = riskMap.begin();
			it != riskMap.end(); ++it) {
		if (it->second->getOwner() == attacker.getId()
				&& it->second->getOccupiedArmies() > 1) {
			cout << "(";
			cout << it->first + 1;
			cout << ") ";
			cout << it->second->getName();
			cout << ": ";
			cout << it->second->getOccupiedArmies();
			cout << " armies";
			cout << endl;

		}
	}

	cin >> attackFrom;
	attackFrom--;

	cout << "Please select a country to attack" << endl << endl;
	for (vector<Country*>::const_iterator itNeighbor =
			riskMap.find(attackFrom)->second->neighbors.begin();
			itNeighbor != riskMap.find(attackFrom)->second->neighbors.end();
			++itNeighbor) {
		if ((*itNeighbor)->getOwner() != attacker.getId()) {
			for (map<int, Country*>::const_iterator itMap = riskMap.begin();
					itMap != riskMap.end(); ++itMap) {
				if (itMap->second == (*itNeighbor)) {
					cout << "(" << itMap->first + 1 << ") "
							<< itMap->second->getName() << ": "
							<< itMap->second->getOccupiedArmies() << " Armies"
							<< endl;
				}
			}
		}
	}

	cin >> attackTo;
	attackTo--;

	cout << "How many armies would you like to use in your attack?" << endl;

	if (riskMap.find(attackFrom)->second->getOccupiedArmies() == 2) {
		cout << "You may attack with 1 army" << endl;
	} else if (riskMap.find(attackFrom)->second->getOccupiedArmies() == 3) {
		cout << "You may attack with up to 2 armies" << endl;
	} else {
		cout << "You may attack with up to 3 armies" << endl;
	}

	cin >> attackWith;

	if (attackWith == 2) {
		dice roll;
		roll.AttackDice2();
		if (riskMap.find(attackTo)->second->getOccupiedArmies() >= 2) {
			roll.DefenseDice2();
		} else {
			roll.DefenseDice1();
		}
		char loser;
		int troops;
		loser = roll.Choose_Winners_AD(
				riskMap.find(attackTo)->second->getOccupiedArmies());
		troops = roll.Choose_Winner_Troops(
				riskMap.find(attackTo)->second->getOccupiedArmies());
		if (loser == 'a') {
			cout << "Attacker lost " << troops << " armies... but not the war"
					<< endl;
			riskMap.find(attackFrom)->second->subtractArmies(troops);
		} else if (loser == 'd') {
			cout << "Defense lost " << troops << "armies... but not the war"
					<< endl;
			riskMap.find(attackTo)->second->subtractArmies(troops);
			if (riskMap.find(attackTo)->second->getOccupiedArmies() == 0) {
				//give attacker the territory if the defending territory has zero troops

				riskMap.find(attackTo)->second->setOwner(attacker.getId());
				attacker.becomeOwner(riskMap.find(attackTo)->second);
				defender.giveUpCountry(riskMap.find(attackTo)->second);
				riskMap.find(attackTo)->second->addArmies(attackWith);
				riskMap.find(attackFrom)->second->subtractArmies(attackWith);

			}
		}

	}
	if (attackWith == 1) {
		dice roll;
		roll.AttackDice1();
		if (riskMap.find(attackTo)->second->getOccupiedArmies() >= 2) {
			roll.DefenseDice2();
		} else {
			roll.DefenseDice1();
		}
		char loser;
		int troops;
		loser = roll.Choose_Winners_AD(
				riskMap.find(attackTo)->second->getOccupiedArmies());
		troops = roll.Choose_Winner_Troops(
				riskMap.find(attackTo)->second->getOccupiedArmies());
		if (loser == 'a') {
			cout << "Attacker lost " << troops << " armies... but not the war"
					<< endl;
			riskMap.find(attackFrom)->second->subtractArmies(troops);
		} else if (loser == 'd') {
			cout << "Defense lost " << troops << "armies... but not the war"
					<< endl;
			riskMap.find(attackTo)->second->subtractArmies(troops);

			if (riskMap.find(attackTo)->second->getOccupiedArmies() == 0) {
				//give attacker the territory if the defending territory has zero troops

				riskMap.find(attackTo)->second->setOwner(attacker.getId());
				attacker.becomeOwner(riskMap.find(attackTo)->second);
				defender.giveUpCountry(riskMap.find(attackTo)->second);
				riskMap.find(attackTo)->second->addArmies(attackWith);
				riskMap.find(attackFrom)->second->subtractArmies(attackWith);
			}

		}
	}
		if (attackWith == 3) {
			dice roll;
			roll.AttackDice3();
			if (riskMap.find(attackTo)->second->getOccupiedArmies() >= 2) {
				roll.DefenseDice2();
			} else {
				roll.DefenseDice1();
			}
			char loser;
			int troops;
			loser = roll.Choose_Winners_AD(
					riskMap.find(attackTo)->second->getOccupiedArmies());
			troops = roll.Choose_Winner_Troops(
					riskMap.find(attackTo)->second->getOccupiedArmies());
			if (loser == 'a') {
				cout << "Attacker lost " << troops
						<< " armies... but not the war" << endl;
				riskMap.find(attackFrom)->second->subtractArmies(troops);
			} else if (loser == 'd') {
				cout << "Defense lost " << troops << "armies... but not the war"
						<< endl;
				riskMap.find(attackTo)->second->subtractArmies(troops);

				if (riskMap.find(attackTo)->second->getOccupiedArmies() == 0) {
					//give attacker the territory if the defending territory has zero troops

					riskMap.find(attackTo)->second->setOwner(attacker.getId());
					attacker.becomeOwner(riskMap.find(attackTo)->second);
					defender.giveUpCountry(riskMap.find(attackTo)->second);
					riskMap.find(attackTo)->second->addArmies(attackWith);
					riskMap.find(attackFrom)->second->subtractArmies(
							attackWith);
				}

			}
		}

}

void GameBoard::manueverTroops(Player &player) {

	int moveFrom;
	int moveTo;
	int armiesToMove;
	int proceed = 1;
	char manueverChoice;

	while (proceed == 1) {

		cout
				<< "Would you like to move any armies between countries you own? (Y/N)"
				<< endl;
		cin >> manueverChoice;

		switch (manueverChoice) {
		case 'y':
		case 'Y':
			cout << "Please select a country to move armies from" << endl
					<< endl;
			for (map<int, Country*>::const_iterator it = riskMap.begin();
					it != riskMap.end(); ++it) {
				if (it->second->getOwner() == player.getId()
						&& it->second->getOccupiedArmies() > 1) {
					cout << "(";
					cout << it->first + 1;
					cout << ") ";
					cout << it->second->getName();
					cout << ": ";
					cout << it->second->getOccupiedArmies();
					cout << " armies";
					cout << endl;

				}
			}
			cout << endl;

			cin >> moveFrom;
			moveFrom--;

			cout << "Please select a country to move your armies to" << endl
					<< endl;
			for (vector<Country*>::const_iterator itNeighbor = riskMap.find(
					moveFrom)->second->neighbors.begin();
					itNeighbor
							!= riskMap.find(moveFrom)->second->neighbors.end();
					++itNeighbor) {
				if ((*itNeighbor)->getOwner() == player.getId()) {
					for (map<int, Country*>::const_iterator itMap =
							riskMap.begin(); itMap != riskMap.end(); ++itMap) {
						if (itMap->second == (*itNeighbor)) {
							cout << "(" << itMap->first + 1 << ") "
									<< itMap->second->getName() << endl;
						}
					}
				}

			}
			cout << endl;

			cin >> moveTo;
			moveTo--;

			cout << "How many armies do you want to move?" << endl;
			cout << "You can move up to: "
					<< riskMap.find(moveFrom)->second->getOccupiedArmies() - 1
					<< endl;
			cin >> armiesToMove;

			riskMap.find(moveFrom)->second->subtractArmies(armiesToMove);
			riskMap.find(moveTo)->second->addArmies(armiesToMove);

			for (map<int, Country*>::const_iterator it = riskMap.begin();
					it != riskMap.end(); ++it) {
				if (it->second->getOwner() == player.getId()) {
					cout << "(" << it->first + 1 << ") "
							<< it->second->getName() << ": "
							<< it->second->getOccupiedArmies() << endl;
				}
			}
			break;

		case 'n':
		case 'N':
			proceed = 0;
			break;
		}
	}
}
