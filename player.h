#include <iostream>
#include <vector>
using namespace std;


class Player {

	public:

			void setArmies(int a);
			void addCountry();

			int getId();
			void setArmies();
			void getArmies();
			int getPlayer();
			void givePlayerControl()

			Player(){
				static int playerId = 0;
				playerId++;
				setArmies();
				cout << "A player has entered the game. His Player ID is " << playerId << endl;
			}

	private:

			int armiesAvailable;
			vector<int> coutriesControlled;
			//an integer between 0 and 9 that uses riskMap to find the country


};

void Player::setArmies(){
	armiesAvailable = 4;
}

void Player::givePlayerControl() {

}
