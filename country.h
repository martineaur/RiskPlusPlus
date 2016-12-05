/*
 * country.h
 *
 *  Created on: Nov 20, 2016
 *      Author: reidr
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

/*
 * Class defines the type country in Risc++. Each player is given an even distribution of
 * countries upon the set-up of the game.
 */
class Country {

	public:
		/*
		 * in the initial set-up of the game, strings are passed in from text files, which
		 * are then used to instantiate each country, as shown below. Each country is
		 * immediately given its name, and its occupiedArmies attribute is initialized to 0
		 */
		Country(string nm) {
			setName(nm);
			setOccupiedArmies();
		}

		~Country() {
			//default destructor
		}
	public:
		//commments below for each function
		void setName(string nm);
		string getName();
		void setOwner(int PlayId);
		int getOwner();
		void setOccupiedArmies();
		int getOccupiedArmies();
		void addOccupiedArmies(int arms);
		void subtractOccupiedArmies(int arms);
		int getOccupiedArmies();
		void initializeNeighborsPtr();
		void pairNeighbor(Country *neighbors);
		void printNeighbors();
		bool isOwned();

		//need all areas of the gameBoard to be able to access the country's neighbors
		vector<Country*> neighbors;

	private:

		string name;
		int owner; //correspond each country with an owner (ie. PlayerID)
		int occupiedArmies;


		//TODO: PROBABLY NEED TO REMOVE WEIGHT, UNLESS ITS IMPORTANT
		int weight;
};


void Country::setName(string nm) {
	name = nm;
}

string Country::getName() {
	return name;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * setters and getters for the country's name as a String
 */


void Country::setOccupiedArmies() {
	occupiedArmies = 0;
}

int Country::getOccupiedArmies() {
	return occupiedArmies;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Setters and getters for the number of occupiedArmies in each country
 */

void Country::addOccupiedArmies(int arms) {
	occupiedArmies += arms;
}

void Country::subtractOccupiedArmies(int arms) {
	occupiedArmies -= arms;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Also needed functions to add/subtract armies to a country after the a battle, so each one of
 * these functions either adds or subtracts a certain number of armies from the occupiedArmies
 * attribute
 */


void Country::pairNeighbor(Country *ctry) {
	neighbors.push_back(ctry);
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * This function sets adds a pointer to another country to this country's vector of neighbors
 * Allows each country to keep track of which other countries it borders...which was very
 * helpful when writing the functions that moved troops from one country to another, or allowed
 * one player to attack only a country that bordered the country they were attacking from.
 */


void Country::setOwner(int playId) {
	owner = playId;
}

int Country::getOwner() {
	return owner;
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Setters and getters for an integer that corresponds to the owner of this particular country
 * Helpful for keeping track of which player owns which country, since each player is
 * instantiated with its own unique playerID
 */

bool Country::isOwned() {
	if (owner == 1 || owner == 2) {
		return true;
	}
	else {
		return false;
	}
}
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Checks to see if the function is currently owned by anyone. Helpful in the set-up of the game
 */

