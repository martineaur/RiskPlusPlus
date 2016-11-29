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
			void givePlayerControl();

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
			vector<Country*> coutriesControlled;
			//an integer between 0 and 8 that uses riskMap to find the country


};

void Player::setArmies(){
	armiesAvailable = 4;
}

void Player::givePlayerControl() {
	int cid;
	cout << "Please select the number that corresponds to the country you wish to control" << endl;
	cin >> cid;
}
