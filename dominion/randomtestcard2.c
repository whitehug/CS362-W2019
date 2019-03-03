#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"dominion.h"

// Random test for great hall
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

	int player = whoseTurn(state);
	int cCount = numHandCards(state);
	int action = state->numActions;

	//call cardEffect(great_hall,0,0,0,state,handPos,bonus)
	
	if(player != whoseTurn(state)){
		printf("error in current player\n");}
	if(cCount != numHandCards(state)){
		printf("error in number of cards\n");}
	if(action != state->numActions){
		printf("error in number of player actions\n");}

}

int main(){
	srand(time(NULL));

	int i;
	for(i = 0; i < 50; i++){
		testme();
	}

	return 0;
}
