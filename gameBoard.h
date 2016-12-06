#include <iostream>
#include <string>
#include "dice.h"
using namespace std;

/*
 * The GameBoard class contains most of the functionality for the entire program. Only one
 * GameBoard is instantiated from the main function, but all other objects in the entire program
 * are able to interact with each other through this class.
 *
 * Once the GameBoard is instantiated, all countries are initiated with one large text file, and
 * then each object's borders are set up with a corresponding text file for each country. After
 * this, GameBoard's constructor then instantiates the two players which will play the game. Each
 * player is passed into a function that allows the players to alternate selecting the countries
 * that they wish to control. After this, each player owns half of the countries on the map, and
 * the GameBoard constructor then calls a function that will allow players to place their
 * available armies in the countries they own. After this, the game finally starts...
 */
 //^^^^^^^^^^^^^^^^^^^^^^^^^
 //TODO: FINISH THIS COMMENT after code is complete

class GameBoard {

public:
	GameBoard() {
		//default constructor

		initiateCountries();
		createBorders();

		Player player1;
		Player player2;

		Player players[2] = { player1, player2 };


		distributeCountries(player1, player2);
		distributeArmies(player1, player2);

		int counter = 1;

		while((player1.countriesControlled.size() != riskMap.size()) && (player2.countriesControlled.size() != riskMap.size())){

			if ((counter % 2) != 0) {
				cout << string(50, '\n');
				takeTurn(player1, player2);
			}

			else {
			cout << string(50, '\n');
			takeTurn(player2, player1);
			}

			counter++;

		}

		if((player1.countriesControlled.size() == riskMap.size())){
				cout << "Player " << player1.getId() <<  " wins!!!" << endl;
		}

		else {
			cout << "Player " << player2.getId() <<  " wins!!!" << endl;
		}


	}

	map<int, Country*> riskMap;

private:



public:
	//comments below for each function
	void initiateCountries();
	void createBorders();
	void distributeCountries(Player &player1, Player &player2);
	void distributeArmies(Player &player1, Player &player2);
	void takeTurn(Player &player1, Player &player2);
	bool isAttackPossible(Player &attacker, Player &defender);
	void attack(Player &player, Player &player2);
	void manueverTroops(Player &player);
	void printStatus(Player &player1, Player &player2);
	bool isManueverPossible(Player &attacker, Player &defender);
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

	//TODO:
	//THIS SHOULD BE OPTIMIZED -- THIS IS HORRIBLE

	fstream alaskaBorders;
	fstream albertaBorders;
	fstream centralAmericaBorders;
	fstream eastUSABorders;
	fstream greenlandBorders;
	fstream nwtBorders;
	fstream ontarioBorders;
	fstream quebecBorders;
	fstream westUSABorders;
	fstream venezuelaBorders;

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

	//VENEZUELA BORDERS
	if (venezuelaBorders.is_open()) {
	} else {
		venezuelaBorders.open("venezuelaBorders.txt");

		if (venezuelaBorders.fail()) {
			cerr << "Error Opening File" << endl;
			exit(1);
		}
	}

	while (getline(venezuelaBorders, border)) {
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getName() == border) {
				riskMap[9]->pairNeighbor(it->second);
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

	printStatus(play1, play2);
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
	cout << "Player " << player.getId() << " has been given 3 armies" << endl;

	while (player.getArmiesAvailable() != 0) {
		cout << "Player " << player.getId()
				<< ": please select country you wish to put an army in" << endl
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
		if (player.countriesControlled.size() == riskMap.size()) {
			return;
		}
		bool attackPossible = isAttackPossible(player, player2);
		if (attackPossible) {
			cout << "Player " << player.getId()
					<< ": Do you wish to attack (Y/N)?" << endl << endl;
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
		} else {
			cout << "No attacking options possible..." << endl;
		}

		bool manueverTroopsPossible = isManueverPossible(player, player2);
		if (manueverTroopsPossible) {
			int proceed = 1;
			while (proceed == 1) {
				char manueverChoice;
				cout << "Player " << player.getId()
						<< ": Would you like to move any armies between countries you own? (Y/N)"
						<< endl;
				cin >> manueverChoice;

				switch (manueverChoice) {
				case 'Y':
				case 'y':
					manueverTroops(player);
					break;
				case 'N':
				case 'n':
					attackMenu = 0;
					proceed = 0;
					break;
				default:
					cout << "Invalid selection" << endl;
					break;
				}
			}

		} else {
			cout << "No manuevering options possible..." << endl;
			attackMenu = 0;
		}
	}
}

void GameBoard::attack(Player &attacker, Player &defender) {
	int attackFrom;
	int attackTo;
	int attackWith;
	int counter = 0;

	cout << "Player " << attacker.getId() << ": please select a country to attack from" << endl << endl;
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
		else {
			counter++;
		}
	}

	cin >> attackFrom;
	attackFrom--;

	cout << "Player " << attacker.getId() << ": please select a country to attack" << endl << endl;

	for (vector<Country*>::const_iterator itNeighbor = riskMap.find(attackFrom)->second->neighbors.begin();itNeighbor != riskMap.find(attackFrom)->second->neighbors.end(); ++itNeighbor) {
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
			riskMap.find(attackFrom)->second->subtractOccupiedArmies(troops);
		} else if (loser == 'd') {
			cout << "Defense lost " << troops << " armies... but not the war"
					<< endl;
			riskMap.find(attackTo)->second->subtractOccupiedArmies(troops);
			if (riskMap.find(attackTo)->second->getOccupiedArmies() == 0) {
				//give attacker the territory if the defending territory has zero troops

				riskMap.find(attackTo)->second->setOwner(attacker.getId());
				attacker.becomeOwner(riskMap.find(attackTo)->second);
				defender.giveUpCountry(riskMap.find(attackTo)->second);
				riskMap.find(attackTo)->second->addOccupiedArmies(attackWith);
				riskMap.find(attackFrom)->second->subtractOccupiedArmies(attackWith - 1);

			}
		}

	}
	if (attackWith == 1) {
		dice roll;
		roll.AttackDice1();
		roll.DefenseDice1();
		char loser;
		int troops;
		loser = roll.Choose_Winners_AD(attackWith);
		troops = roll.Choose_Winner_Troops(attackWith);
		if (loser == 'a') {
			cout << "Attacker lost " << troops << " armies... but not the war"
					<< endl;
			riskMap.find(attackFrom)->second->subtractOccupiedArmies(troops);
		} else if (loser == 'd') {
			cout << "Defense lost " << troops << " armies... but not the war"
					<< endl;
			riskMap.find(attackTo)->second->subtractOccupiedArmies(troops);

			if (riskMap.find(attackTo)->second->getOccupiedArmies() == 0) {
				//give attacker the territory if the defending territory has zero troops

				riskMap.find(attackTo)->second->setOwner(attacker.getId());
				attacker.becomeOwner(riskMap.find(attackTo)->second);
				defender.giveUpCountry(riskMap.find(attackTo)->second);
				riskMap.find(attackTo)->second->addOccupiedArmies(attackWith);
				riskMap.find(attackFrom)->second->subtractOccupiedArmies(attackWith - 1);
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
				riskMap.find(attackFrom)->second->subtractOccupiedArmies(troops);
			} else if (loser == 'd') {
				cout << "Defense lost " << troops << " armies... but not the war"
						<< endl;
				riskMap.find(attackTo)->second->subtractOccupiedArmies(troops);

				if (riskMap.find(attackTo)->second->getOccupiedArmies() == 0) {
					//give attacker the territory if the defending territory has zero troops

					riskMap.find(attackTo)->second->setOwner(attacker.getId());
					attacker.becomeOwner(riskMap.find(attackTo)->second);
					defender.giveUpCountry(riskMap.find(attackTo)->second);
					riskMap.find(attackTo)->second->addOccupiedArmies(attackWith);
					riskMap.find(attackFrom)->second->subtractOccupiedArmies(
							attackWith - 1);
				}

			}
		}
		printStatus(attacker, defender);
}

void GameBoard::manueverTroops(Player &player) {

	int moveFrom;
	int moveTo;
	int armiesToMove;
	int proceed = 1;
	char manueverChoice;

	//while (proceed == 1) {
		cout << "Please select a country to move armies from" << endl << endl;
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

		cout << "Player " << player.getId()
				<< ": Please select a country to move your armies to" << endl
				<< endl;
		//TODO for some reason, the for-loop below no longer works, we need to figure this out ASAP
		for (vector<Country*>::const_iterator itNeighbor = riskMap.find(moveFrom)->second->neighbors.begin(); itNeighbor != riskMap.find(moveFrom)->second->neighbors.end();++itNeighbor) {
			if ((*itNeighbor)->getOwner() == player.getId()) {
				for (map<int, Country*>::const_iterator itMap = riskMap.begin(); itMap != riskMap.end(); ++itMap) {
					if (itMap->second == (*itNeighbor)) {
						cout << "(" << itMap->first + 1 << ") " << itMap->second->getName() << endl;
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

		riskMap.find(moveFrom)->second->subtractOccupiedArmies(armiesToMove);
		riskMap.find(moveTo)->second->addOccupiedArmies(armiesToMove);

		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getOwner() == player.getId()) {
				cout << "(" << it->first + 1 << ") " << it->second->getName()
						<< ": " << it->second->getOccupiedArmies() << endl;
			}
		}
	//}
}

void GameBoard::printStatus(Player &player1, Player &player2) {
	cout << endl << "Player " << player1.getId() << " controls: " << endl;
	cout << "ARMIES AVAILABLE: " << player1.getArmiesAvailable() << endl;
	player1.printControlledCountries();

	cout << endl << "Player " << player2.getId() << " controls: " << endl;
	cout << "ARMIES AVAILABLE: " << player2.getArmiesAvailable() << endl;
	player2.printControlledCountries();
}

bool GameBoard::isAttackPossible(Player &attacker, Player &defender) {
	int countControlledCountriesArmies = 0;
	int countOpponentSurroundingCountries = 0;

	for(vector<Country*>::const_iterator it = attacker.countriesControlled.begin(); it != attacker.countriesControlled.end(); ++it) {
		if((*it)->getOccupiedArmies() > 1) {
			countControlledCountriesArmies++;
		}
	}

	if (countControlledCountriesArmies > 0) {
		for(vector<Country*>::const_iterator itControlled = attacker.countriesControlled.begin(); itControlled != attacker.countriesControlled.end(); ++itControlled) {
			for(vector<Country*>::const_iterator itNeighbors = (*itControlled)->neighbors.begin(); itNeighbors != (*itControlled)->neighbors.end(); ++itNeighbors) {
				if ((*itControlled)->getOccupiedArmies() > 1) {
					if ((*itNeighbors)->getOwner() == defender.getId()) {
						countOpponentSurroundingCountries++;
					}
				}
			}
		}

		if (countOpponentSurroundingCountries > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool GameBoard::isManueverPossible(Player &attacker, Player &defender) {
	int countControlledCountriesArmies = 0;
	int countFriendlySurroundingCountries = 0;

	for(vector<Country*>::const_iterator it = attacker.countriesControlled.begin(); it != attacker.countriesControlled.end(); ++it) {
		if((*it)->getOccupiedArmies() > 1) {
			countControlledCountriesArmies++;
		}
	}

	if (countControlledCountriesArmies > 0) {
		for(vector<Country*>::const_iterator itControlled = attacker.countriesControlled.begin(); itControlled != attacker.countriesControlled.end(); ++itControlled) {
			for(vector<Country*>::const_iterator itNeighbors = (*itControlled)->neighbors.begin(); itNeighbors != (*itControlled)->neighbors.end(); ++itNeighbors) {
				if ((*itNeighbors)->getOwner() == attacker.getId()) {
					countFriendlySurroundingCountries++;
				}
			}
		}

		if (countFriendlySurroundingCountries > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
