/*
 * riskmn.cpp
 *
 *  Created on: Nov 20, 2016
 *      Authors: reidr, martineaur, levesques, dossantosl
 */
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
 * available armies in the countries they own. After this, the game finally starts. Players can
 * use the armies in their owned countries to attack or manuever their troops however they like.
 * Once the goal of controlling all countries is achieved by a player, the game announces the
 * winner and terminates.
 */
class GameBoard {

public:
	GameBoard() {
		//default constructor

		initiateCountries();
		createBorders();

		Player player1;
		Player player2;

		while ((player1.countriesControlled.size()
				+ player2.countriesControlled.size()) != riskMap.size()) {
			static int counter = 1;

			if (counter % 2 != 0) {
				distributeCountries(player1);
			}else {
				distributeCountries(player2);
			}

			counter++;
		}

		while ((player1.getArmiesAvailable() + player2.getArmiesAvailable())
				!= 0) {

			static int counter = 1;

			if (counter % 2 != 0) {
				distributeArmies(player1);
			}else {
				distributeArmies(player2);
			}

			counter++;
		}

		printStatus(player1, player2);

		int counter = 1;

		while ((player1.countriesControlled.size() != riskMap.size())
				&& (player2.countriesControlled.size() != riskMap.size())) {

			/*
			 * TODO: when the player can neither attack nor manuever, this output can be a
			 *little confusing, might need to adjust
			 */
			if ((counter % 2) != 0) {
				cout << string(50, '\n');
				takeTurn(player1, player2);
			}else {
				cout << string(50, '\n');
				takeTurn(player2, player1);
			}

			counter++;
		}

		if ((player1.countriesControlled.size() == riskMap.size())) {
			cout << "Player " << player1.getId() << " wins!!!" << endl;
		}else {
			cout << "Player " << player2.getId() << " wins!!!" << endl;
		}
	}

	/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	 * GameBoard Constructor
	 *
	 * The GameBoard Constructor intitially sets up the game by calling the functions:
	 * 		-initiateCountries()
	 * 		-createBorders()
	 *
	 * 	These functions help to set up the countries and their borders, so that every country
	 * 	is connected in the manner shown on the actual Risc++ Map. After the board is set up,
	 * 	two players are instantiated so that the game can begin.
	 *
	 * 	Once the players have entered the game, a function is called that allows the two
	 * 	players to choose the countries they want to own, alternating as they do so. After all
	 * 	countries have been selected, the program alternates calling the takeTurn() function
	 * 	for each player, until the winning conditions of the game have been met. The winning
	 * 	conditions are only met when one player owns all countries on the map. After this, a
	 * 	short message displaying the winner is shown, and the game ends.
	 */

	map<int, Country*> riskMap;
	/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	 * Above is how we managed to replicate an actual map in C++. By having a map of of
	 * pointers that point to the created type Country, we were able to associate an ID
	 * number with each country, allowing us to iterate through the list very easily, and
	 * access the exact data we wanted whenever we needed it. In addition to this, a country
	 * object has a vector of pointers that point to other countries that border them. This
	 * was able to be done because each country pointer in the game was associated with a
	 * unique integer value. This map also needed to be public so that all areas of the
	 * program could access it. Both players, the gameboard, and countries all need access
	 * to the map; the same is true in a real-life game of Risk.
	 */

private:



public:
	//comments below for each function
	void initiateCountries();
	void createBorders();
	void distributeCountries(Player &player/*1, Player &player2*/);
	void distributeArmies(Player &player/*1, Player &player2*/);
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

/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * This function simply creates all of the countries in the game. For simplicity's sake,
 * the number was kept to 10 and only included 9 countries from North America and 1 from
 * South America. However, it would be very simple to add in more countries as well. All
 * this function does is read a text file of all the countries' names and instantiate a
 * new country, passing in the name of the country so that it can be set in the Country
 * class.
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
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Very similar to instantiateCountries(), this function reads in a bunch of text files.
 * Each text file contains its corresponding country's list of bordering countries. For
 * each line of the file, the string is read in, and the name of that country is found in
 * the map. Once the country is found in the map, the function then calls another function
 * inside of the country class to pair the two countries. Each country could have anywhere
 * from one border to any number of borders.
 */

void GameBoard::distributeCountries(Player &player/*1, Player &play2*/) {
	unsigned int choice;

	cout << endl << "Player " << player.getId() << ": please choose a country"
			<< endl;

	//print out available countries

	for (map<int, Country*>::const_iterator it = riskMap.begin();
			it != riskMap.end(); ++it) {
		if (!it->second->isOwned()) {
			cout << "(" << it->first + 1 << ") " << it->second->getName()
					<< endl;
		}
	}
	cout << endl;

	while (true) {
		cin >> choice;
		choice--;

		if ((choice >= 0) && (choice < riskMap.size())) {
			if (!riskMap.find(choice)->second->isOwned()) {
				break;
			}
		}

		else {
			cin.clear();
			cin.ignore();
			cout << "Invalid selection. Please enter a valid value" << endl;
		}
	}
	riskMap.find(choice)->second->setOwner(player.getId());
	player.becomeOwner(riskMap.find(choice)->second);
	player.giveArmyToCountry(riskMap.find(choice)->second);

}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * This function allows players to initially pick countries that they wish to control.
 * The player being passed in to the function is the player actually picking the
 * country. The function starts by creating an unsigned integer that will be used as
 * user input. The integer that this variable represents the country ID of the country
 * that the user wishes to select. The available countries that are not owned are then
 * printed to screen by creating an iterator and traversing the map. The iterator will
 * stop at each element inside the map and will print the country name as well as the
 * ID only if the country's isOwned variable is set to 0 or null. Then the user is asked
 * to enter an ID. Upon entering the ID, the ID the user entered is checked to see that
 * that value is greater than or equal to zero and less than the number of elements in
 * the map. Note that the ID is decremented: countries are displayed with their IDs
 * incremented by 1 for ease of use for the user, so the ID must be decremented in the
 * opposite direction. If the user-entered variable is determined to be valid, then
 * the selected country is added to the user's controlledCountries vector and the
 * function ends. If the value is determined to be invalid, then the user is warned.
 * Note that the user must enter a valid value for the game to continue.
 */

void GameBoard::distributeArmies(Player &player /*Player &play2*/) {
	unsigned int choice;
	//int counter = 1;

	//while ((play1.getArmiesAvailable() + play2.getArmiesAvailable()) != 0) {

	//if ((counter % 2 != 0) && (play1.getArmiesAvailable() != 0)) {
	cout << endl << "Player " << player.getId()
			<< ": please choose a country to place one more army in" << endl;
	for (map<int, Country*>::const_iterator it = riskMap.begin();
			it != riskMap.end(); ++it) {
		if (it->second->getOwner() == player.getId()) {
			cout << "(" << it->first + 1 << ") " << it->second->getName()
					<< ": " << it->second->getOccupiedArmies() << " armies" << endl;
		}
	}
	cout << endl;

	while (true) {
		cin >> choice;
		choice--;

		if ((choice >= 0) && (choice < riskMap.size())
				&& (riskMap.find(choice)->second->getOwner() == player.getId())) {
			player.giveArmyToCountry(riskMap.find(choice)->second);
			player.printControlledCountries();
			break;
		}

		else {
			cin.clear();
			cin.ignore();
			cout << "Invalid selection. Please enter a valid value" << endl;
		}
	}

}

/*		else if ((counter % 2 == 0) && (play2.getArmiesAvailable() != 0)) {
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

	printStatus(play1, play2);*/
//}


void GameBoard::takeTurn(Player &player, Player &player2) {

	//Give player three armies to the player taking the turn.

	//Make the player place their armies into a territory that is theirs
	//if the territory is not theirs, warn the user

	//once all new armies have been placed, allow the user to attack (if they want)

	//once the player is done attacking, allow the user to manuever their armies into postition
	//if they wish to go into a territory that is not in their control, warn the user
	//if the a user makes a move that would not leave any armies in a controlled territory,
	//do not allow
	printStatus(player, player2);

	if (player.countriesControlled.size() == riskMap.size()) {
		return;
	}

	unsigned int placementChoice;
	char attackChoice;
	bool attackMenu = 1;

	player.setArmiesAvailable(3);
	cout << "Player " << player.getId() << ": has been given 3 armies" << endl;

	while (player.getArmiesAvailable() != 0) {
		cout << endl << "Player " << player.getId()
				<< ": please select country you wish to put an army in" << endl
				<< endl;
		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getOwner() == player.getId()) {
				cout << "(" << it->first + 1 << ") " << it->second->getName()
						<< ": " << it->second->getOccupiedArmies() << endl;
			}
		}

		//cin >> placementChoice;
		//placementChoice--;

		while (true) {
			cin >> placementChoice;
			placementChoice--;

			if ((placementChoice >= 0) && (placementChoice < riskMap.size())
					&& (riskMap.find(placementChoice)->second->getOwner()
							== player.getId())) {
				player.giveArmyToCountry(riskMap.find(placementChoice)->second);
				player.printControlledCountries();
				break;
			}

			else {
				cin.clear();
				cin.ignore();
				cout << "Invalid selection. Please enter a valid value" << endl;
			}
		}
	}

	bool attackPossible = isAttackPossible(player, player2);
	if (attackPossible) {
		while (attackMenu) {
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
				//break;
			}
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


void GameBoard::attack(Player &attacker, Player &defender) {
	unsigned int attackFrom;
	unsigned int attackTo;
	int attackWith;
	int counter = 0;
	//bool foundNeighbor = false;

	cout << "Player " << attacker.getId()
			<< ": please select a country to attack from" << endl << endl;
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
		} else {
			counter++;
		}
	}

	while (true) {
		cin >> attackFrom;
		attackFrom--;

		if ((attackFrom >= 0) && (attackFrom < riskMap.size())
				&& (riskMap.find(attackFrom)->second->getOwner()
						== attacker.getId())) {
			break;
		}

		else {
			cin.clear();
			cin.ignore();
			cout << "Invalid selection. Please enter a valid value" << endl;
		}
	}
	cout << "Player " << attacker.getId()
			<< ": please select a country to attack" << endl << endl;

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

	while (true) {
		cin >> attackTo;
		attackTo--;
		bool foundNeighbor = false;

		if ((attackTo >= 0) && (attackTo < riskMap.size())
				&& (riskMap.find(attackTo)->second->getOwner()
						== defender.getId())) {
			/*for (vector<Country*>::const_iterator itNeighbor = riskMap.find(
			 attackFrom)->second->neighbors.begin();
			 itNeighbor
			 != riskMap.find(attackFrom)->second->neighbors.end();
			 ++itNeighbor) {
			 if ((*itNeighbor)->getOwner() != attacker.getId()) {

			 for (map<int, Country*>::const_iterator itMap =
			 riskMap.begin(); itMap != riskMap.end(); ++itMap) {
			 if (itMap->second == (*itNeighbor)) {
			 break;
			 }
			 foundNeighbor = true;
			 break;
			 }

			 }

			 if (foundNeighbor) {
			 break;
			 }*/

			for (vector<Country*>::const_iterator itAttackFromNeighbors =
					riskMap.find(attackFrom)->second->neighbors.begin();
					itAttackFromNeighbors
							!= riskMap.find(attackFrom)->second->neighbors.end();
					++itAttackFromNeighbors) {
				if ((*itAttackFromNeighbors)
						== riskMap.find(attackTo)->second) {
					foundNeighbor = true;
				}
			}
			if (foundNeighbor) {
				break;
			}
		}

		cin.clear();
		cin.ignore();
		cout << "Invalid selection. Please enter a valid value" << endl;

	}
	cout << "How many armies would you like to use in your attack?" << endl;

	bool menu = 1;

	while (menu) {
		if (riskMap.find(attackFrom)->second->getOccupiedArmies() == 2) {
			cout << "You may attack with 1 army" << endl;
		} else if (riskMap.find(attackFrom)->second->getOccupiedArmies() == 3) {
			cout << "You may attack with up to 2 armies" << endl;
		} else {
			cout << "You may attack with up to 3 armies" << endl;
		}

		cin >> attackWith;

		switch (attackWith) {
		case 1:
		case 2:
		case 3:
			menu = 0;
			break;
		default:
			cin.clear();
			cin.ignore();
			cout << "Invalid selection. Please enter a valid value" << endl;
			break;
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
				riskMap.find(attackFrom)->second->subtractOccupiedArmies(
						attackWith - 1);
			}

		}
	}

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
				riskMap.find(attackFrom)->second->subtractOccupiedArmies(
						attackWith - 1);

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
				riskMap.find(attackFrom)->second->subtractOccupiedArmies(
						attackWith - 1);
			}

		}
	}
	printStatus(attacker, defender);
}

void GameBoard::manueverTroops(Player &player) {

	unsigned int moveFrom;
	unsigned int moveTo;
	int armiesToMove;

	bool foundNeighbor = false;
	//int proceed = 1;
	//char manueverChoice;

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

		while (true) {
		cin >> moveFrom;
		moveFrom--;

		if ((moveFrom >= 0) && (moveFrom < riskMap.size())
				&& (riskMap.find(moveFrom)->second->getOwner() == player.getId())
				&& (riskMap.find(moveFrom)->second->getOccupiedArmies() > 1)) {
			break;
		} else {
			cin.clear();
			cin.ignore();
			cout << "Invalid selection. Please enter a valid value" << endl;
		}
	}
		cout << "Player " << player.getId()
				<< ": Please select a country to move your armies to" << endl
				<< endl;
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

	while (true) {
		cin >> moveTo;
		moveTo--;

		if ((moveTo >= 0) && (moveTo < riskMap.size())
				&& (riskMap.find(moveTo)->second->getOwner() == player.getId())) {
			for (vector<Country*>::const_iterator itAttackFromNeighbors =
					riskMap.find(moveFrom)->second->neighbors.begin();
					itAttackFromNeighbors
							!= riskMap.find(moveFrom)->second->neighbors.end();
					++itAttackFromNeighbors) {
				if ((*itAttackFromNeighbors) == riskMap.find(moveTo)->second) {
					foundNeighbor = true;
					break;
				}
			}

		}
		if(foundNeighbor){
						break;
					}
		cin.clear();
		cin.ignore();
		cout << "Invalid selection. Please enter a valid value" << endl;
	}




		cout << "How many armies do you want to move?" << endl;

	while (true) {
		cout << "You can move up to: "
				<< riskMap.find(moveFrom)->second->getOccupiedArmies() - 1
				<< endl;
		cin >> armiesToMove;

		if ((armiesToMove >= 1) && (armiesToMove <= riskMap.find(moveFrom)->second->getOccupiedArmies()- 1)) {
			break;
		} else {
			cout << "Invalid selection. Please enter a valid value" << endl;
		}
	}
		riskMap.find(moveFrom)->second->subtractOccupiedArmies(armiesToMove);
		riskMap.find(moveTo)->second->addOccupiedArmies(armiesToMove);

		for (map<int, Country*>::const_iterator it = riskMap.begin();
				it != riskMap.end(); ++it) {
			if (it->second->getOwner() == player.getId()) {
				cout << "(" << it->first + 1 << ") " << it->second->getName()
						<< ": " << it->second->getOccupiedArmies() << endl;
			}
		}
}


void GameBoard::printStatus(Player &player1, Player &player2) {
	cout << endl << "Player " << player1.getId() << " controls: " << endl;
	cout << "ARMIES AVAILABLE: " << player1.getArmiesAvailable() << endl;
	player1.printControlledCountries();

	cout << endl << "Player " << player2.getId() << " controls: " << endl;
	cout << "ARMIES AVAILABLE: " << player2.getArmiesAvailable() << endl;
	player2.printControlledCountries();
	cout << endl;
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
