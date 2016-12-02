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

//class Player;

class Country {

	public:
		Country(string nm) {
			setName(nm);
			//initializeNeighborsPtr();
			setOccupiedArmies();
		}

		~Country() {
			//default destructor
		}
	public:
		void setName(string nm);
		string getName();
		void setOwner(int PlayId);
		int getOwner();
		void setOccupiedArmies();
		void addArmies(int arms);
		void subtractArmies(int arms);

		int getOccupiedArmies();


		void initializeNeighborsPtr();
		void pairNeighbor(Country *neighbors);
		void printNeighbors();
		bool isOwned();
		vector<Country*> neighbors;

	private:
		string name;
		//Player* owner; //need to correlate an owner with each country
		//Add a country identifier to help print controlled countries for each player
		int owner;
		int weight;
		int occupiedArmies;
		//Country *neighborPtr[6];
};


void Country::setName(string nm) {
	name = nm;
}

string Country::getName() {
	return name;
}

void Country::setOccupiedArmies() {
	occupiedArmies = 0;
}

//overload setOccupiedArmies function
void Country::addArmies(int arms) {
	occupiedArmies += arms;
}

void Country::subtractArmies(int arms) {
	occupiedArmies -= arms;
}

int Country::getOccupiedArmies() {
	return occupiedArmies;
}

void Country::pairNeighbor(Country *ctry) {
	neighbors.push_back(ctry);
}

void Country::setOwner(int playId) {
	owner = playId;
}

int Country::getOwner() {
	return owner;
}

bool Country::isOwned() {
	if (owner == 1 || owner == 2) {
		return true;
	}
	else {
		return false;
	}
}


