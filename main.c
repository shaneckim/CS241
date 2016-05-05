#include <stdlib.h>
#include <time.h>
#include "header.h"

/* used to choose suit for manual card assignment (debugging) */
#define D 13
#define C 26
#define S 39

//prototype
void tester( Card * wDeck );

/* char arrays for each card's members */
    const char *suit [5] = {"None", "Hearts", "Diamonds", "Clubs", "Spades"};
    const char *suit2 [5] = {"_","♥", "♦", "♣", "♠"};
    
    const char *face[ 14 ] = 
        { "Zero", "Two", "Three", "Four", "Five", 
          "Six", "Seven", "Eight", "Nine", "Ten",
          "Jack", "Queen", "King", "Ace"};
          
    const char *face2[14] = {"0", "2", "3", "4", "5", "6", "7",
                             "8", "9", "T", "J", "Q", "K", "A"};
   
    const char *color[3] = {"None", "Red", "Black"};
    
    const char *rank[10] = {"High Card", "Pair", "Two-Pair", "Three-of-a-Kind",
                            "Straight", "Flush", "Full-House", "Four-of-a-Kind",
                            "Straight-Flush", "Royal-Flush"};

//int main ( void ) {
    
    
/* Manual hand assignment testing block
    playerHands[0].held[0] = &deck[11+D];
    playerHands[0].held[1] = &deck[9+D];
    playerHands[0].held[2] = &deck[3+D];
    playerHands[0].held[3] = &deck[4+D];
    playerHands[0].held[4] = &deck[4+S];
        
    playerHands[1].held[0] = &deck[11+S];
    playerHands[1].held[1] = &deck[9+S];
    playerHands[1].held[2] = &deck[8+S];
    playerHands[1].held[3] = &deck[4+S];
    playerHands[1].held[4] = &deck[4];
*/
/*
    playerHands[0].held[0] = &deck[3+D];
    playerHands[0].held[1] = &deck[3];
    playerHands[0].held[2] = &deck[3+S];
    playerHands[0].held[3] = &deck[1+D];
    playerHands[0].held[4] = &deck[6+D];
        
    playerHands[1].held[0] = &deck[6+D];
    playerHands[1].held[1] = &deck[4+D];
    playerHands[1].held[2] = &deck[4+C];
    playerHands[1].held[3] = &deck[6+C];
    playerHands[1].held[4] = &deck[9+S];
*/
    
//    return 0;}

int main(void) {
    
    /* Initialize */
    Card deck[ 52 ];            /* allocate a 52 card deck */
    
    /* initialize randomizer */
    srand( time(NULL) );
    
    /* assign values to each card in the deck */
    fillDeck( deck );
    
    while (1==1) {
    int rc;
    int choice;
    char buff[2];
    
    printf("Choose a test option:\n"
           "1) test hand evaluation\n"
           "2) print deck\n"
           "3) shuffle deck\n"
           "4) reset deck\n"
           "5) run main prog\n"
           "0) quit\n"
           );
           
    rc = getLine("Enter Option: ", buff, sizeof(buff));
    
    if (rc == 1) {
		// Extra NL since system may not output for EOF.
		printf("\nNo Input\n");
		return 1;
	}
	
	if (rc == 2) {
		printf("Input too long [%s]\n", buff);
		return 1;
	}
    
    choice = buff[0] - '0';
    
    switch (choice) {
        case 1:
            fillDeck(deck);
            tester(deck);
            break;
        case 2:
            //printDeckRaw(deck);
            //printDeck(deck, face, suit, color);
            printDeckFancy(deck, face2, suit2 );
            break;
        case 3:
            shuffle(deck);
            printDeckFancy(deck, face2, suit2 );
            break;
        case 4:
            fillDeck(deck);
            printDeckFancy(deck, face2, suit2);
            break;
        case 5:
            run(deck);
            break;
        case 0:
            return 0;
        default:
            printf("choose an option 1-5!\n");
            break;
    };
    }
    
    return 0;
}

int run ( Card * deck ) {
    Hand playerHands[PLAYERS];  /* allocate player hands */
    
    int i,j,k;          /* loop iterators */
    int status;         /* status of tiebreaking */
    
    int rc;             /* used for input checking */
    char dealAgain[2];  /* stores user input for playing again */
    
    do {

    /* debug prints to check deck is built properly */
//    printDeckRaw ( deck );
//    printDeck( deck, face, suit, color );
    
    /* shuffling of actual deck */
    //shuffle( deck );
    reshuffle( deck, SHUFFLES );

    /* Another set of debug prints */
//    printDeckRaw ( deck );
//    printDeck( deck, face, suit, color );

    status = 1;     /* used to note tiebreaks */
    k = 0;          /* used to print hands once */
    
    /* Do while loop to handle tiebreaking */
    do {
        for( i = 0; i < PLAYERS ; i++ ) {   /* assigns cards to each player's hand */
            if (k == 0)     // print player tag for first pass
                printf("Player %d's Hand:\n", i + 1);
            playerHands[i].rank = 0;        /* clears hand rank */
            playerHands[i].highCard = 0;    /* clears highest card */
            playerHands[i].highSet = 0;     /* clears highest multiple */
            playerHands[i].lowSet = 0;      /* clears next highest multiple */
            if ( k == 0 )   // assign cards from deck to hand only once
                for (j=0;j<HAND;j++)        /* loop to assign each card from shuffled deck to each hand */
                    playerHands[i].held[j] = &deck[PLAYERS * j + i];    /* assigns pointer to card into held[] */
            
            /* prints a particular card from the deck */
            //printCard ( *(deck+5) );    // prints the 6th card (not 5th!) from top of deck
            //printCardFancy ( *(deck+5), face2, suit2 );    // prints the 6th card (not 5th!) from top of deck
            
            qSort( playerHands[i].held, 0, 4, 1 );  /* sorts cards by highest face value */
            
            /* debug for printing hand assignment */
            if ( k == 0 ) {     // print hand only for first pass
                //printHand( playerHands[i].held, face, suit, color );  // prints text version
                //printHandRaw( playerHands[i].held );                  // prints raw int values
                printHandFancy(playerHands+i, face2, suit2);            // prints ASCII cards
            }
            
            /* evaluate rank, high card, etc for each hand */
            evaluateHand( playerHands+i );
            
            /* prints full hand evaluation to screen */
            //printHandEval( playerHands+i, face, rank );
            
            /* print hand's score for player */
            printScore( playerHands+i, face, rank );
        }
        
        k = 1;  // first pass done, tiebreaks print limited info
        
        /* compare each hand for the winner */
        status = compareHand(playerHands);  /* returns 0, 1, or 2 */
        if (status == 2) {      /* both hands match exactly */
            //return 0;           /* end program */
            break;              /* exit while loop */
        }
    } while (status != 0);      /* loops until status is 0 (tie is broken) */
    
    /* prompt user to play again */
    //printf("Deal again? (Y or N): ");
    //scanf("%1s", dealAgain);
    
    rc = getLine("Deal Again? (Y or N): ", dealAgain, sizeof(dealAgain));
    
    if (rc == 1) {
		// Extra NL since system may not output for EOF.
		printf("\nNo Input\n");
		break;
	}
	
	if (rc == 2) {
		printf("Input too long [%s]\n", dealAgain);
		break;
	}
    
    } while (*dealAgain == 'Y' || *dealAgain == 'y');
    
    return 0;
}

void tester( Card * wDeck ) {
    int i;
    Hand testHand[9];
    
    // Manual hand assignment testing block
    testHand[0].held[0] = &wDeck[11+D];
    testHand[0].held[1] = &wDeck[9+D];
    testHand[0].held[2] = &wDeck[3+D];
    testHand[0].held[3] = &wDeck[4+D];
    testHand[0].held[4] = &wDeck[2+S];
        
    testHand[1].held[0] = &wDeck[11+S];
    testHand[1].held[1] = &wDeck[9+S];
    testHand[1].held[2] = &wDeck[8+S];
    testHand[1].held[3] = &wDeck[4+S];
    testHand[1].held[4] = &wDeck[4];
    
    testHand[2].held[0] = &wDeck[1];
    testHand[2].held[1] = &wDeck[1];
    testHand[2].held[2] = &wDeck[2];
    testHand[2].held[3] = &wDeck[2];
    testHand[2].held[4] = &wDeck[3+C];
    
    testHand[3].held[0] = &wDeck[6];
    testHand[3].held[1] = &wDeck[6];
    testHand[3].held[2] = &wDeck[6];
    testHand[3].held[3] = &wDeck[3];
    testHand[3].held[4] = &wDeck[4+D];
    
    testHand[4].held[0] = &wDeck[2];
    testHand[4].held[1] = &wDeck[3];
    testHand[4].held[2] = &wDeck[4];
    testHand[4].held[3] = &wDeck[5];
    testHand[4].held[4] = &wDeck[6+C];
    
    testHand[5].held[0] = &wDeck[2];
    testHand[5].held[1] = &wDeck[12];
    testHand[5].held[2] = &wDeck[11];
    testHand[5].held[3] = &wDeck[10];
    testHand[5].held[4] = &wDeck[8];
    
    testHand[6].held[0] = &wDeck[5];
    testHand[6].held[1] = &wDeck[5];
    testHand[6].held[2] = &wDeck[5];
    testHand[6].held[3] = &wDeck[5];
    testHand[6].held[4] = &wDeck[8+D];
    
    testHand[7].held[0] = &wDeck[8];
    testHand[7].held[1] = &wDeck[7];
    testHand[7].held[2] = &wDeck[6];
    testHand[7].held[3] = &wDeck[5];
    testHand[7].held[4] = &wDeck[4];
    
    testHand[8].held[0] = &wDeck[8];
    testHand[8].held[1] = &wDeck[12];
    testHand[8].held[2] = &wDeck[11];
    testHand[8].held[3] = &wDeck[10];
    testHand[8].held[4] = &wDeck[9];
    
    for (i = 0; i < 9; i++) {
        qSort(testHand[i].held, 0, 4, 1 );
        printHandFancy( testHand+i, face2, suit2);
        evaluateHand( testHand+i );
        //printHandEval( testHand+i, face, rank );
        printScore( testHand+i, face, rank );
    }
}