#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"dominion.h"

// Random test for adventurer
void testme(){
	struct gameState* state = newGame()
	int numPlayers = (rand() % (MAX_PLAYERS - 2)) + 2;
	int randomSeed = rand() % 100;
	//Generate Kingdom Cards
	int j;
	int kingdomCards[10];
	for(j = 0; j < 10; j++){
		kingdomCards[j] = 100;
	}
	int k;
	j = 0;
	while(j < 10){
		kingdomCards[j] = rand() % 27;
		for(k = 0; k < j; k++){
			if(kingdomCards[j] == kingdomCards[k]){
				j++;
			}
		}
	}
	
	initializeGame(numPlayers,kingdomCards,randomSeed,state);

	int cCount = numHandCards(state);
	int player = whoseTurn(state);

	//Call adventurerCard(0,state,currentPlayer,handPos,temphand,0)
	
	if(player != whoseTurn(state)){
		printf("Error in player\n");}
	if(cCount + 2 != numHandCards(state)){
		printf("Error in number of cards\n");}

}

int main(){
	srand(time(NULL));

	int i;
	for(i = 0; i < 50; i++){
		testme();
	}

	return 0;
}
