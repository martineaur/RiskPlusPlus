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

class Player;

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
		//overloading
		void addArmies(int arms);
		int getOccupiedArmies();


		void initializeNeighborsPtr();
		void pairNeighbor(Country *neighbors);
		void printNeighbors();


		bool isOwned();

	private:
		string name;
		//Player* owner; //need to correlate an owner with each country
		int owner;
		int weight;
		int occupiedArmies;
		vector<Country*> neighbors;
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
	occupiedArmies = occupiedArmies + arms;
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


