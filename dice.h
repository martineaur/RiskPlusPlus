
/*
 * dice.h
 *
 *  Created on: Dec 1, 2016
 *      Author: levesques
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>

class dice{
private:
    //Attack dice
    int A_Dice1, A_Dice2, A_Dice3;
    //Defense dice
    int D_Dice1, D_Dice2;
public:
dice(){}
~dice(){

}

/*
 * AttackDice3 rolls three dice in the for loop.  Each die has a random integer (that was seeded in the beginning) that is chosen by the rand function
 * (that was seeded in the beginning to give completely random integers).  A_Dice1 then iterates through the array and searches for the largest integer,
 * and puts that integer front of the array (attackroll[0]).  A_Dice3 then iterates through the array to find the smallest integer, and puts that integer
 * at the end of the array (attackroll[2]). A_Dice2 is then chosen to be the second highest integer by choosing the integer in the middle of the array (attackroll[1]).
 * Only the two highest integers will be chosen to compare against the defensive dice or 1 dice if the defensive country only has 1 army.  This give the attacker
 * a higher probability of winning since three dice are rolled
 */
void AttackDice3(){
    int attackroll[3];
    for (int i = 0; i < 3; i++){
        int A_Roll;
        A_Roll = rand() %6 +1;
        attackroll[i] = A_Roll;
    }
    A_Dice1 = attackroll[0];
	for (int i = 0; i < 3; i++) {
		if (attackroll[i] > A_Dice1) {
			A_Dice1 = attackroll[i];
		}
	}
    A_Dice3 = attackroll[2];
	for (int i = 0; i < 3; i++){
		if (attackroll[i] < A_Dice3){
		     A_Dice3 = attackroll[i];
		}
	}
    A_Dice2 = attackroll[1];
}

/*
 * AttackDice2 rolls two dice in the for loop.  Each die has a random integer (that was seeded in the beginning) that is chosen by the rand function
 * (that was seeded in the beginning to give completely random integers).  A_Dice1 then iterates through the array and searches for the largest integer,
 * and puts that integer front of the array (attackroll[0]). A_Dice2 is then chosen to be the second highest integer by choosing the second integer of the array (attackroll[1]).
 * The two integers will then be compared against the defensive dice or die if.  This give the attacker an equal or greater chance of winning against the defensive country.
 */
void AttackDice2(){
          int attackroll[2];
    for (int i = 0; i < 2; i++){
        int A_Roll;
        A_Roll = rand() %6 +1;
        attackroll[i] = A_Roll;
    }
    A_Dice1 = attackroll[0];
	for (int i = 0; i < 2; i++) {
		if (attackroll[i] > A_Dice1) {
			A_Dice1 = attackroll[i];
		}
	}
    A_Dice2 = attackroll[1];
}

/*
 * AttackDice1 rolls one die. The die is given a random integer (that was seeded in the beginning) that is chosen by the rand function
 * (that was seeded in the beginning to give completely random integers).  The die integer will then be compared against the defensive die.
 * This give the attacker a lesser probability of winning.
 */
void AttackDice1(){
     A_Dice1 = rand() %6 +1;
}

/*
 * If the defense can attack with two troops, then the two dice will be rolled in the for loops. Each die has a random integer (that was
 * seeded in the beginning) that is chosen by the rand function (that was seeded in the beginning to give completely random integers).
 * D_Dice1 then iterates through the array and find the highest interger and puts it in the front of the array (defenseroll[0]).  D_Dice2 is
 * put in second spot of the array (defenseroll[1]).
 */
void DefenseDice2(){
    int defenseroll[2];
    for (int i = 0; i < 2; i++){
        int D_Roll;
        D_Roll = rand() %6 +1;
        defenseroll[i] = D_Roll;
    }
     D_Dice1 = defenseroll[0];
	for (int i = 0; i < 2; i++) {
		if (defenseroll[i] > D_Dice1) {
			D_Dice1 = defenseroll[i];
		}
	}
     D_Dice2 = defenseroll[1];
}

/*
 * DefenseDice1 rolls one die (this only rolls if the attacker is attacking with 1 army or the defense only has 1 army in the country that
 * is under attack). The die is given a random integer (that was seeded in the beginning) that is chosen by the rand function
 * (that was seeded in the beginning to give completely random integers).
 */
void DefenseDice1(){
    D_Dice1 = rand() %6 +1;
}

/*
 * Compares all the possible outcomes for the dice rolls and returns a looser to the game board class.  If a country loses, they will lose troops
 * in that country they were either attack or defending from.  If there is a draw or the dice rolls break-even (meaning attack could win the first comparison
 * but defense won the second or vice versa), then defense is favored and the attacker will lose 1 army.
 */
int Choose_Winner_Troops(int dTroops) {
	if (dTroops >= 2) {

		if ((A_Dice1 == D_Dice1) && (A_Dice2 == D_Dice2)) {
			// Attack loose 1
			return 1;
		} else if ((A_Dice1 > D_Dice1) && (A_Dice2 > D_Dice2)) {
			// Defense loose 2
			return 2;
		}

		//Break even favor defense
		else if ((A_Dice1 > D_Dice1) && (A_Dice2 < D_Dice2)) {
			// attack lose 1
			return 1;
		} else if ((A_Dice1 < D_Dice1) && (A_Dice2 > D_Dice2)) {
			//attack lose 1
			return 1;
		}

		else if ((A_Dice1 > D_Dice1) && (A_Dice2 == D_Dice2)) {
			// Defence loose 1
			return 1;
		} else if ((A_Dice1 == D_Dice1) && (A_Dice2 > D_Dice2)) {
			// Defence loose 1
			return 1;
		} else if ((A_Dice1 == D_Dice1) && (A_Dice2 > D_Dice2)) {
			// Defence loose 1
			return 1;
		} else if ((D_Dice1 > A_Dice1) && (D_Dice2 > A_Dice2)) {
			// Attack loose 2
			return 2;
		} else if ((D_Dice1 > A_Dice1) && (D_Dice2 == A_Dice2)) {
			// Attack loose 1
			return 1;
		} else if ((D_Dice1 == A_Dice1) && (D_Dice2 > A_Dice2)) {
			// Attack loose 1
			return 1;
		}
	} else {
		if (A_Dice1 == D_Dice1) {
			// Attack loose 1
			return 1;
		} else if (A_Dice1 > D_Dice1) {
			// Defense loose 1
			return 1;
		} else if (D_Dice1 > A_Dice1) {
			// Attack loose 1
			return 1;
		}
	}
	return 1;
}

char Choose_Winners_AD(int dTroops) {
	if (dTroops >=2) {
		if ((A_Dice1 == D_Dice1) && (A_Dice2 == D_Dice2)) {
			// Attack loose 1
			return 'a';
		} else if ((A_Dice1 > D_Dice1) && (A_Dice2 > D_Dice2)) {
			// Defense loose 2
			return 'd';
		} else if ((A_Dice1 > D_Dice1) && (A_Dice2 == D_Dice2)) {
			// Defence loose 1
			return 'd';
		} else if ((A_Dice1 == D_Dice1) && (A_Dice2 > D_Dice2)) {
			// Defence loose 1
			return 'd';
		} else if ((A_Dice1 == D_Dice1) && (A_Dice2 > D_Dice2)) {
			// Defence loose 1
			return 'd';
		} else if ((D_Dice1 > A_Dice1) && (D_Dice2 > A_Dice2)) {
			// Attack loose 2
			return 'a';
		} else if ((D_Dice1 > A_Dice1) && (D_Dice2 == A_Dice2)) {
			// Attack loose 1
			return 'a';
		} else if ((D_Dice1 == A_Dice1) && (D_Dice2 > A_Dice2)) {
			// Attack loose 1
			return 'a';
		}
//Break even favor defense
		else if ((A_Dice1 > D_Dice1) && (A_Dice2 < D_Dice2)) {
			// attack lose 1
			return 'a';
		} else if ((A_Dice1 < D_Dice1) && (A_Dice2 > D_Dice2)) {
			//attack lose 1
			return 'a';
		}
	}else {

		if (A_Dice1 == D_Dice1) {
			// Attack loose 1
			return 'a';
		} else if (A_Dice1 > D_Dice1) {
			// Defense loose 1
			return 'd';
		} else if (D_Dice1 > A_Dice1) {
			// Attack loose 1
			return 'a';
		}
	}
	return 'a';
}
};
