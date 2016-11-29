/*
 * country.h
 *
 *  Created on: Nov 20, 2016
 *      Author: reidr
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Player;

class Country {

	public:
		Country(string nm) {
			setName(nm);
			initializeNeighborsPtr();
		}

		~Country() {
			//default destructor
		}
	public:
		void setName(string nm);
		string getName();
		void initializeNeighborsPtr();
		void pairNeighborPtr(Country *neighbors);
		void print();
		void assignCountries();
		void printNeighbors();


		void setOwner(int PlayId);
		int getOwner();

		bool isOwned();

	private:
		string name;
		//Player* owner; //need to correlate an owner with each country
		int owner;
		int weight;
		Country *neighborPtr[6];
};


void Country::setName(string nm) {
	name = nm;
}

string Country::getName() {
	return name;
}

void Country::print() {

}

void Country::pairNeighborPtr(Country *neighbors) {

	for (int i = 0; i < 6; i++) {
		if (this->neighborPtr[i] == 0) {
			neighborPtr[i] = neighbors;
			return;
		}
	}

}

void Country::initializeNeighborsPtr() {
	for (int i = 0; i < 6; i++) {
		neighborPtr[i] = 0;
	}
}

void Country::printNeighbors() {

	cout << endl << this->getName() <<" has the following borders: " << endl;
	for (int i = 0; i < 6; i++) {
		if(neighborPtr[i] != 0) {
			cout << "Neighbor " << i+1 << ": " << neighborPtr[i]->getName() << endl;
		}
	}
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


