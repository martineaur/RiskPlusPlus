/*
 * riskmn.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: reidr
 */

#include <iostream>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <cmath>
//#include "setUp.h"
#include "player.h"
#include "gameBoard.h"
#include <time.h>



using namespace std;

void displayRules();
void startGame();

int main() {

	srand(time(NULL));

	bool mainMenu = 1;
	char option;

	cout << "Welcome to RiscPlusPlus, a version of the board game Risk written in C++" << endl;

	while(mainMenu){
		cout << "Please select an option:" << endl << endl;

		cout << "r: view README" << endl;
		cout << "s: start game" << endl;
		cout << "e: exit" << endl << endl;

		cin >> option;

		switch (option) {

		case 'r':
		case 'R':
			displayRules();
			break;

		case 's':
		case 'S':
			startGame();
			mainMenu = 0;
			break;

		case 'e':
		case 'E':
			mainMenu = 0;
			break;

		default:
			cin.clear();
			cin.ignore();
			cout << "Invalid selection" << endl;
			break;
		}

	}

	cout << "Thank you for playing!" << endl;
	return 0;
}

void displayRules(){

	cout << "This game is a textual adaption of the traditional version of the game Risk, written    " << endl;
	cout << "in C++. Our team tried to make the game as close to the traditional board game as       " << endl;
	cout << "close as possible with a few exceptions. This rule book will outline how to play        " << endl;
	cout << " the game			                                                                     " << endl << endl;

	cout << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "///////////////////////////////////////////SET-UP///////////////////////////////////////" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;

	cout << "The game starts with each player selecting a country from a list of available countries." << endl;
	cout << "Each player is given armies to place into countries of their choosing. The number that  " << endl;
	cout << "appears to the left of country listed is the country ID. If you wish to select a country" << endl;
	cout << ", enter the country ID number of the country you wish to control. Upon selection, an    " << endl;
	cout << "army is placed into the country that was selected by a player and their number of       " << endl;
	cout << "available armies that player was given is decremented. Players will go back and fourth  " << endl;
	cout << "until all countries are owned. Once all available countries are owned, players will     " << endl;
	cout << "then continue to place armies in countries that they own until all of their armies have " << endl;
	cout << "been placed                                                                             " << endl << endl;

	cout << "////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////GAMEPLAY//////////////////////////////////////" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;

	cout << "Once setup is complete, the actual game is can begin. A turn begins with you being given" << endl;
	cout << "3 additional armies to place into territories that the player owns. Once all armies have" << endl;
	cout << "been placed, you are given the option to attack. If you decides to attack, a list of    " << endl;
	cout << "countries that you own, along with the country ID. Select the country you wish to attack" << endl;
	cout << "from by entering the corresponding country ID. Upon selection, you are shown a list of  " << endl;
	cout << "enemy controlled countries that border the selected countries that you can attack.      " << endl;
	cout << "Select the country that that you wish to attack by entering the corresponding country ID" << endl;
	cout << "You are then asked to select the number of armies you wish to attack with. You may      " << endl;
	cout << "attack with up to three armies, provided that you have at least one remaining army in   " << endl;
	cout << "the country you are attacking from. Once the number of attacking armies has been chosen " << endl;
	cout << "the battle is fought and resolved. Depending on who won the battle, a number of armies  " << endl;
	cout << "is subtracted from either your attacking force or the country you are trying to attack. " << endl;
	cout << "Please note that you can either attack as many times as you can if you wish, but you can" << endl;
	cout << "only attack with up to 3 armies at once. If a battle results in zero armies in the      " << endl;
	cout << "country being attacked, then you gain control of that country and your attacking force  " << endl;
	cout << "is put into the country you were attacking. As an added bonus, an extra army is also    " << endl;
	cout << "placed into the country you were attacking from. Please note that you may attack as     " << endl;
	cout << "many times as possible if you wish, but you can only attack with up to 3 armies at once." << endl;
	cout << "When you have finished attacking, you may then maneuver your troops between countries   " << endl;
	cout << "that you own so long as the two countries are bordering each other. Selection and       " << endl;
	cout << "movement of the troops is done in the same fashion as selection for attacking           " << endl << endl;

	cout << "Just like the original Risk game, a player wins then he controls all available countries" << endl << endl;

}

void startGame(){

	cout << string(50, '\n');
	GameBoard g;

}
