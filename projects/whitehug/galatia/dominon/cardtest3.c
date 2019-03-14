#include "dominion.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Card test for village

int main(){
	struct gameState state;
	int seed = 100;
	int numPlayers = 2;
	int k[10] = {adventurer, council_room, cutpurse, embargo, mine, minion, sea_hag, smithy, tribute, village};
	
	initializeGame(numPlayers, k, seed, &state);
	
	return 0;
}
