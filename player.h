/*
 * riskmn.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: dossantosl
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "country.h"
using namespace std;


class Player {

	public:

			void setArmies(int a);
			void addCountry();

			int getId();
			void setArmiesAvailable();
			void setArmiesAvailable(int a);
			int getArmiesAvailable();
			int getPlayer();
			void becomeOwner(Country* ctry);
			void giveUpCountry(Country* ctry);
			void printControlledCountries();

			void giveArmyToCountry(Country* ctry);

			//armies/troops

			Player(){
				static int p = 0;
				p++;
				playerId = p;
				setArmiesAvailable();
				cout << "A player has entered the game. His Player ID is " << playerId << endl;
			}

			vector<Country*> countriesControlled;

	private:
			int playerId;
			int armiesAvailable;
			//an integer between 0 and 8 that uses riskMap to find the country


};

int Player::getId() {
	return playerId;
}

void Player::setArmiesAvailable(){
	armiesAvailable = 8;
}

void Player::setArmiesAvailable(int a){
	armiesAvailable += a;
}

int Player::getArmiesAvailable() {
	return armiesAvailable;
}

void Player::giveArmyToCountry(Country* ctry) {
	armiesAvailable--;

	for(vector<Country*>::const_iterator it = countriesControlled.begin(); it != countriesControlled.end(); ++it) {
		if (*it == ctry) {
			(*it)->addOccupiedArmies(1);
		}
	}
}

void Player::becomeOwner(Country* ctry) {

	//check for next available position in vector
	//set this country pointer equal to that position

	countriesControlled.push_back(ctry);
	ctry->setOwner(this->getId());

}

void Player::printControlledCountries() {

	for (vector<Country*>::const_iterator it = countriesControlled.begin(); it != countriesControlled.end(); ++it) {
		cout << (*it)->getName() << ": " << (*it)->getOccupiedArmies() << " armies" << endl;

	}

}

//crying over a bowl of ramen while trying to chug down a redbull

void Player::giveUpCountry(Country* ctry){
	/*for(vector<Country*>::const_iterator it = countriesControlled.begin(); it != countriesControlled.end(); ++it){
		if((*it)->getName() == ctry->getName()){
			countriesControlled.remove((*it));
		}
	}*/

	countriesControlled.erase(std::remove(countriesControlled.begin(), countriesControlled.end(), ctry), countriesControlled.end());

}
