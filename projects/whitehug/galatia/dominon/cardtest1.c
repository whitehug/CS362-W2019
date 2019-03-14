#include "dominion.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

//Card test for smithy

int main(){
	struct gameState state;
	int seed = 100;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, cutpurse, embargo, mine, minion, sea_hag, smithy, tribute, village};
	
	initializeGame(numPlayers, k, seed, &state);
	
	int count = numHandCards(&state);
	
	int status = smithyCard(0, 0, &state, 0);
	
	if(count + 3 != numHandCards(&state)){
		printf("Error, incorrect number of cards drawn\n");
	}
	else{
		printf("Passed\n");
	}
	
	return 0;
}
