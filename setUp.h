//GAMME SETUP

#include <iostream>
#include <string>

using namespace std;

void setup(){
	string player1, player2, player3, player4; //variables for user input for player namespace
	
	//asks input for each player name
	cout<<"\nEnter name of player one: ";
	cin>>player1;
	cout<<"\nEnter name of player two: ";
	cin>>player2;
	cout<<"\nEnter name of player three: ";
	cin>>player3;
	cout<<"\nEnter name of player four: ";
	cin>>player4;
	
	//initializes four players
	player *p1 = new player;
	player *p2 = new player;
	player *p3 = new player;
	player *p4 = new player;
	
	//sets each player name
	//assumes constructor makes infantry(army) count to 30 for each player
	p1->name = player1;
	p2->name = player2;
	p3->name = player3;
	p4->name = player4;
	
	//decides player turn order
	int p1Roll, p2Roll, p3Roll, p4Roll; //variables to save roll of player
	int chance; //variable to store random roll
	for(int i=1; i<=4; i++){ //loops once for each player; p1 rolls first, p4 last
		int chance = 1 + rand() % 6;
		if(i==1)
			p1Roll=chance;
		else if(i==2)
			p2Roll=chance;
		else if(i==3)
			p3Roll=chance;
		else if(i==4)
			p4Roll=chance;
		
	}
	//what if two players roll same number?
	//player who rolled number first goes first
	//set up players in a singularyly linked circular list
	/*
		In order to be able to go through player turn rotation, this sets up the player objects into a singularyly linked circular list. The first step is to determine where each 
		player will fall in the list based on the roll they made in the previous segment. Once that is determined, a head pointer will point to the player who will go first, and
		the other players will be placed accourdingly. Initially, the player which the head pointer is pointing to goes next. After a player completes there turn, determining who 
		goes next is simply looking at the current player's next pointer
	*/
	
	
	
	
	
	
	//claiming of territories
	
	
	//placing rest of pieces once terrirories are all claimed
	
	
}

