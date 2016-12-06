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

void AttackDice1(){
     A_Dice1 = rand() %6 +1;
}

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

void DefenseDice1(){
    D_Dice1 = rand() %6 +1;
}

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



