#include <stdlib.h>
#include <time.h>
#include "header.h"

int main ( void ) {
    Card deck[ 52 ];
    Hand playerHands[PLAYERS];
    
    //Hand playerHands[1];

    const char *suit [4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *suit2 [4] = {"He", "Di", "Cl", "Sp"};
    
    const char *face[ 13 ] = 
        { "Two", "Three", "Four",
          "Five", "Six", "Seven", "Eight",
          "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
          
    const char *face2[13] = {"2", "3", "4", "5", "6", "7", "8", "9",
                             "10", "J", "Q", "K", "A"};
   
    const char *color[2] = {"Red", "Black"};

    srand( time(NULL) );
    fillDeck( deck );
   
/* Manual testing block

    playerHands->held[0] = deck[10];
    playerHands->held[1] = deck[1];
    playerHands->held[2] = deck[2];
    playerHands->held[3] = deck[10];
    playerHands->held[4] = deck[9];
    
    qSort(playerHands->held, 0, 4, 1 );
    
    printHand( playerHands->held, face, suit, color );
    
   // playerHands->rank = evaluate(playerHands->held);
    
    evaluateHand(playerHands);
    
    printf("Total Score: %d\n", playerHands->rank);
    printScore(playerHands, face);
    
    */
    
//    shuffle( deck );
//    reshuffle( deck, SHUFFLES );
    
    int i,j;
    
    for(i=0;i<PLAYERS;i++){
        printf("Player %d's Hand:\n", i+1);
        playerHands[i].rank = 0;
        playerHands[i].highCard = 0;
//        for (j=0;j<HAND;j++)
//            playerHands[i].held[j] = deck[PLAYERS * j + i];
        
        playerHands[0].held[0] = &deck[12];
        playerHands[0].held[1] = &deck[7];
        playerHands[0].held[2] = &deck[7];
        playerHands[0].held[3] = &deck[2];
        playerHands[0].held[4] = &deck[0];
        
        playerHands[1].held[0] = &deck[8];
        playerHands[1].held[1] = &deck[7];
        playerHands[1].held[2] = &deck[7];
        playerHands[1].held[3] = &deck[6];
        playerHands[1].held[4] = &deck[2];

/*        
        playerHands[0].held[0] = deck[12];
        playerHands[0].held[1] = deck[6+13];
        playerHands[0].held[2] = deck[7];
        playerHands[0].held[3] = deck[2];
        playerHands[0].held[4] = deck[0];
    
        playerHands[1].held[0] = deck[12];
        playerHands[1].held[1] = deck[0+13];
        playerHands[1].held[2] = deck[7];
        playerHands[1].held[3] = deck[5];
        playerHands[1].held[4] = deck[1];
*/
        qSort( playerHands[i].held, 0, 4, 1 );
        
//        printCard ( playerHands[0].held );
//        printHandRaw(playerHands[0].held);
        
        printHand( playerHands[i].held, face2, suit, color );
        evaluateHand(playerHands+i);
        printf("Hand Rank: %d\nHighest Card: %s\n", playerHands[i].rank, face[playerHands[i].highCard]);
        printScore(playerHands+i, face);
        printf("\n");
    }
    
    compareHand(playerHands);
    
    return 0;
}
