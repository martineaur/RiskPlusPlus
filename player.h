#include <iostream>
#include <vector>
#include "country.h"
using namespace std;


class Player {

	public:

			void setArmies(int a);
			void addCountry();

			int getId();
			void setArmies();
			void getArmies();
			int getPlayer();
//			void givePlayerControl();
			void becomeOwner(Country* ctry);
			void printControlledCountries();

			Player(){
				static int p = 0;
				p++;
				playerId = p;
				setArmies();
				cout << "A player has entered the game. His Player ID is " << playerId << endl;
			}

	private:
			int playerId;
			int armiesAvailable;
			vector<Country*> countriesControlled;
			//an integer between 0 and 8 that uses riskMap to find the country


};

int Player::getId() {
	return playerId;
}

void Player::setArmies(){
	armiesAvailable = 4;
}

void Player::becomeOwner(Country* ctry) {

	//check for next available position in vector
	//set this country pointer equal to that position

	countriesControlled.push_back(ctry);

}

/*void Player::givePlayerControl() {
	int cid;
	cout << "Please select the number that corresponds to the country you wish to control" << endl;
	cin >> cid;
}*/

void Player::printControlledCountries() {
/*	vector<Country*>::iterator it;
		for (it == countriesControlled.begin(); it<countriesControlled.end(); ++it) {

		}*/

		for (vector<Country*>::const_iterator it = countriesControlled.begin(); it != countriesControlled.end(); ++it) {
			cout << (*it)->getName() << endl;
		}

	}
