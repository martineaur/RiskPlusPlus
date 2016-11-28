#include <iostream>
#include <vector>
using namespace std;

class Player {

	public:

			void setArmies(int a);
			void setPlayer(int d);
			void addCountry();

			int getId();
			int getArmies();

			Player(){
				PlayerId++;
				setarmies();
				cout << "A player has entered the game. His Player ID is " << getId() << endl;
			}

	private:

			static int playerId = 1;
			int armiesAvailable;
			vector<Country*> coutriesControlled;


};

Player::getPlayer(){
	return playerId;
}

Player::setArmies(){
	armiesAvailable = 4;
}
