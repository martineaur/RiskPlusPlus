#include <iostream>
#include <vector>
using namespace std;

class Player {

	public:

			void setArmies(/*int a*/);
			void setPlayer(int d);
			void addCountry();

			int getId();
			void getArmies();
			int getPlayer();

			Player(){
				playerId++;
				setArmies();
				cout << "A player has entered the game. His Player ID is " << getId() << endl;
			}

	private:

			static int playerId = 1;
			int armiesAvailable;
			vector<Country*> coutriesControlled;


};

int Player::getPlayer(){
	return playerId;
}

void Player::setArmies(){
	armiesAvailable = 4;
}
