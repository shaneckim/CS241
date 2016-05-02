#include <stdlib.h>
#include <time.h>
#include "header.h"

/* used to choose suit for manual card assignment (debugging) */
#define D 13
#define C 26
#define S 39

int main ( void ) {
    /* Initialize */
    Card deck[ 52 ];            /* allocate a 52 card deck */
    Hand playerHands[PLAYERS];  /* allocate player hands */
    
    /* char arrays for each card's members */
    const char *suit [5] = {"None", "Hearts", "Diamonds", "Clubs", "Spades"};
    const char *suit2 [5] = {" ","♥", "♦", "♣", "♠"};
    
    const char *face[ 14 ] = 
        { "Zero", "Two", "Three", "Four", "Five", 
          "Six", "Seven", "Eight", "Nine", "Ten",
          "Jack", "Queen", "King", "Ace"};
          
    const char *face2[14] = {" ", "2", "3", "4", "5", "6", "7",
                             "8", "9", "T", "J", "Q", "K", "A"};
   
    const char *color[3] = {"None", "Red", "Black"};

    /* initialize randomizer */
    srand( time(NULL) );
    
    /* assign values to each card in the deck */
    fillDeck( deck );
   
/* Manual hand assignment testing block
    playerHands[0].held[0] = &deck[11+D];
    playerHands[0].held[1] = &deck[9+D];
    playerHands[0].held[2] = &deck[3+D];
    playerHands[0].held[3] = &deck[1+D];
    playerHands[0].held[4] = &deck[0+D];
        
    playerHands[1].held[0] = &deck[11+S];
    playerHands[1].held[1] = &deck[9+S];
    playerHands[1].held[2] = &deck[8+S];
    playerHands[1].held[3] = &deck[4+S];
    playerHands[1].held[4] = &deck[0+S];
*/
//* full house / two pair testing
    playerHands[0].held[0] = &deck[1+C];
    playerHands[0].held[1] = &deck[6+D];
    playerHands[0].held[2] = &deck[6];
    playerHands[0].held[3] = &deck[2+D];
    playerHands[0].held[4] = &deck[2];
        
    playerHands[1].held[0] = &deck[0+S];
    playerHands[1].held[1] = &deck[2+C];
    playerHands[1].held[2] = &deck[6+S];
    playerHands[1].held[3] = &deck[6+C];
    playerHands[1].held[4] = &deck[2+S];

    /* debug prints to check deck is built properly */
//    printDeckRaw ( deck );
//    printDeck( deck, face, suit, color );
    
    /* shuffling of actual deck */
//    shuffle( deck );
//    reshuffle( deck, SHUFFLES );

    /* Another set of debug prints */
//    printDeckRaw ( deck );
//    printDeck( deck, face, suit, color );

    int i,j,k;      /* loop iterators */
    int status;     /* status of tiebreaking */
    
    status = 1;     /* used to note tiebreaks */
    k = 0;          /* used to print hands once */
    
    /* Do while loop to handle tiebreaking */
    do {
        for( i = 0; i < PLAYERS ; i++ ) {   /* assigns cards to each player's hand */
            //if ( k == 0 ) 
                printf("Player %d's Hand:\n", i + 1);
            playerHands[i].rank = 0;        /* clears hand rank */
            playerHands[i].highCard = 0;    /* clears highest card */
            //if ( k == 0 ) 
//                for (j=0;j<HAND;j++)        /* loop to assign each card from shuffled deck to each hand */
//                    playerHands[i].held[j] = &deck[PLAYERS * j + i];    /* assigns pointer to card into held[] */
        
            qSort( playerHands[i].held, 0, 4, 1 );  /* sorts cards by highest face value */
            
            /* debug for hand assignment */
            //if ( k == 0 ) 
                printHand( playerHands[i].held, face, suit, color );
            //printHandRaw(playerHands[i].held);
            //printHand( playerHands[i].held, face, suit, color );
            /* evaluate rank and high card of each hand */
            evaluateHand(playerHands+i);
            
            /* prints evaluation to screen */
            printf("Hand Rank: %d\n"
                   "Highest Card: %s\n"
                   , playerHands[i].rank
                   , face[playerHands[i].highCard]
                   );
            printScore(playerHands+i, face);
        }
        
        /* prints a "graphical" hand */
        printHandFancy(playerHands, face2, suit2);
    
        //k = 1;
        
        /* compare each hand for the winner */
        status = compareHand(playerHands);  /* returns 0, 1, or 2 */
        if (status == 2) {      /* both hands match exactly */
            return 0;           /* end program */
        }
    } while (status != 0);      /* loops until status is 0 (tie is broken) */
    
    return 0;
}
