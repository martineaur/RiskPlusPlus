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

/*
 * The player class describes a player and their role in the game of RiskPlusPlus. For each
 * player, it is important to keep track of their ID, their number of armies, and the
 * countries they control. This class is supposed to handle all of the functionality of a
 * player in the game of Risk
 */

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
				//default constructor
				static int p = 0;
				p++;
				playerId = p;
				setArmiesAvailable();
				cout << "A player has entered the game. His Player ID is " << playerId << endl;
			}
			/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			 * Constructor simply assigns the player an ID number, gives him the game's set
			 * number of armies (8), and tells the user by printing to the console.
			 */

			vector<Country*> countriesControlled;
			/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			 * This is a major component of the Player type. This vector contains all the countries
			 * a player controls at any one time.
			 */

	private:
			//simple attributes for Player type
			int playerId;
			int armiesAvailable;

};

int Player::getId() {
	return playerId;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Returns the value of the player's ID, set at instantiation
 */

void Player::setArmiesAvailable(){
	armiesAvailable = 8;
}

void Player::setArmiesAvailable(int a){
	armiesAvailable += a;
}

int Player::getArmiesAvailable() {
	return armiesAvailable;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Setters and getters for the armiesAvailable attribute. setArmiesAvailable is overloaded because
 * it needs to be set to 8 automatically when the player is instantiated. After that, the function may
 *  need to be called to set a different amount, so it is helpful to overload it.
 */

void Player::giveArmyToCountry(Country* ctry) {
	armiesAvailable--;

	for(vector<Country*>::const_iterator it = countriesControlled.begin(); it != countriesControlled.end(); ++it) {
		if (*it == ctry) {
			(*it)->addOccupiedArmies(1);
		}
	}
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * This function takes one of the armies available to this player, and places it into a country that is
 * owned by the player. The countriedControlled vector is searched by an iterator from beginning to end,
 * looking for a matching country pointer. Once the matching country pointer is found, the
 * addOccupiedArmies() function is called from the Country class on that Country
 */

void Player::becomeOwner(Country* ctry) {

	//check for next available position in vector
	//set this country pointer equal to that position

	countriesControlled.push_back(ctry);
	ctry->setOwner(this->getId());

}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * The becomeOwner() function allows the player to take control of a country by adding a pointer to that
 * country to its controlledCountries vector. This function used the built-in push_back function that is
 * in the vector template class. This function also goes and sets the country's owner attribute to the ID
 * of THIS player
 */

void Player::printControlledCountries() {

	for (vector<Country*>::const_iterator it = countriesControlled.begin(); it != countriesControlled.end(); ++it) {
		cout << (*it)->getName() << ": " << (*it)->getOccupiedArmies() << " armies" << endl;

	}

}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * This function loops through the countriesControlled vector and prints out the name of each country that
 * this player owns, along with the number of armies in those countries
 */

//crying over a bowl of ramen while trying to chug down a redbull

void Player::giveUpCountry(Country* ctry){

	countriesControlled.erase(std::remove(countriesControlled.begin(), countriesControlled.end(), ctry), countriesControlled.end());

}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * This function uses the erase function in combination with the remove function to allow the program to remove
 * a country from the player's countriesControlled vector. It traverses through the vector, looking for a specifc
 * country pointer, and once it is found, it is erased from the player's countriesControlled vector
 */
