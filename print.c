/* 
 * Contains the various print functions to display to screen:
 *   printCard() can be used to print a card's raw values to screen.  Useful for debugging.
 *     printCardFancy() prints a particular card in ASCII
 *   printHand() prints the player's hand to the screen.
 *     printHandRaw() prints the player's hand in raw integers to the screen.
 *     printHandFancy() prints the player's hand in ASCII to the screen.
 *     printHandEval() prints a hand's information after it has been evaluated
 *   printDeck() prints the entire deck, useful for debugging deck order.
 *     printDeckRaw() prints the entire deck in raw integers, useful for debugging deck order.
 *     printDeckFancy() prints all 52 cards in ASCII sequentially left to right, top to bottom.
 *   printScore() prints a hand's score and relevant face values.
 *   
 */
#include "header.h"

/* Prints a card with raw integer values */
void printCard ( Card const wDeck ) {
	printf("%d %2d of %d\n", wDeck.color, wDeck.face, wDeck.suit);
}

/* Prints a card with ASCII formatting */
void printCardFancy ( Card const wDeck,	const char * wFace[],
    const char * wSuit[] ) {
    printf(" ---- \n"
           "|%s   |\n"
           "| %s  |\n"
           "|   %s|\n"
           " ---- \n",
           wFace[wDeck.face],
           wSuit[wDeck.suit],
           wFace[wDeck.face]
    );
}

/* Prints hand for each player */
void printHand( Card ** wDeck, const char * wFace[],
    const char * wSuit[], const char * wColor[] ) {
    int i;
    
    for ( i = 0; i < HAND; i++) {
	printf( "  %-5s %5s of %-8s\n",
            wColor[wDeck[ i ]->color], 
	        wFace[wDeck[ i ]->face], 
            wSuit[wDeck[ i ]->suit]
            );
    }
    //printf("\n");
}

/* Prints hand for each player in raw values */
void printHandRaw( Card ** wDeck ) {
    int i;
    
    printf( "RAW-  Hand[i]:  clr  face  suit\n");
    for ( i = 0; i < HAND; i++) {
	printf( "RAW-  held[%d]:   %d    %2d    %d\n", i, 
        wDeck[ i ]->color, 
	    wDeck[ i ]->face, 
        wDeck[ i ]->suit );
    }
}

/* Prints the hand in ASCII format */
void printHandFancy( Hand * wHand, const char * wFace[], const char * wSuit[]) {
    printf(" ----  ----  ----  ----  ---- \n"
           "|%s   ||%s   ||%s   ||%s   ||%s   |\n"
           "| %s  || %s  || %s  || %s  || %s  |\n"
           "|   %s||   %s||   %s||   %s||   %s|\n"
           " ----  ----  ----  ----  ---- \n",
           wFace[wHand->held[0]->face],
           wFace[wHand->held[1]->face],
           wFace[wHand->held[2]->face],
           wFace[wHand->held[3]->face],
           wFace[wHand->held[4]->face],
           wSuit[wHand->held[0]->suit],
           wSuit[wHand->held[1]->suit],
           wSuit[wHand->held[2]->suit],
           wSuit[wHand->held[3]->suit],
           wSuit[wHand->held[4]->suit],
           wFace[wHand->held[0]->face],
           wFace[wHand->held[1]->face],
           wFace[wHand->held[2]->face],
           wFace[wHand->held[3]->face],
           wFace[wHand->held[4]->face]
           );
}

void printHandEval( Hand * wHand, const char * wFace[], const char * wRank[] ) {
    printf("Hand Evaluation:\n"
           "  Hand Rank:             %s\n"
           "  Highest Multiple:      %s\n"
           "  Next Highest Multiple: %s\n"
           "  Highest Card:          %s\n"
           , wRank[wHand->rank]
           , wFace[wHand->highSet]
           , wFace[wHand->lowSet]
           , wFace[wHand->highCard]
           );
}

/* Prints entire deck in sequential order */
void printDeck(Card * const wDeck, const char * wFace[],
    const char * wSuit[], const char * wColor[] ) {
    int i;
    for ( i=0; i < 52; i++)
    printf("%2d) f: %-5s  s: %-8s  c: %-5s\n", i,
        wFace[wDeck[i].face],
        wSuit[wDeck[i].suit],
        wColor[wDeck[i].color]);
}

/* prints entire deck with raw integer values */
void printDeckRaw(Card * const wDeck ) {
    int i;
    for ( i=0; i < 52; i++)
    printf("%2d) f: %2d  s: %d  c: %d\n", i,
        wDeck[i].face,
        wDeck[i].suit,
        wDeck[i].color);
}

/* Prints entire deck in ASCII and sequential order */
void printDeckFancy(Card * const wDeck, const char * wFace[],
    const char * wSuit[] ) {
    int i;
    for ( i=0; i < 52; i += 13)
    printf(" ----  ----  ----  ----  ----  ----  ----  ----  ----  ----  ----  ----  ---- \n"
           "|%s   ||%s   ||%s   ||%s   ||%s   ||%s   ||%s   ||%s   ||%s   ||%s   ||%s   ||%s   ||%s   |\n"
           "| %s  || %s  || %s  || %s  || %s  || %s  || %s  || %s  || %s  || %s  || %s  || %s  || %s  |\n"
           "|   %s||   %s||   %s||   %s||   %s||   %s||   %s||   %s||   %s||   %s||   %s||   %s||   %s|\n"
           " ----  ----  ----  ----  ----  ----  ----  ----  ----  ----  ----  ----  ---- \n",
          wFace[wDeck[i].face],
          wFace[wDeck[i+1].face],
          wFace[wDeck[i+2].face],
          wFace[wDeck[i+3].face],
          wFace[wDeck[i+4].face],
          wFace[wDeck[i+5].face],
          wFace[wDeck[i+6].face],
          wFace[wDeck[i+7].face],
          wFace[wDeck[i+8].face],
          wFace[wDeck[i+9].face],
          wFace[wDeck[i+10].face],
          wFace[wDeck[i+11].face],
          wFace[wDeck[i+12].face],
          wSuit[wDeck[i].suit],
          wSuit[wDeck[i+1].suit],
          wSuit[wDeck[i+2].suit],
          wSuit[wDeck[i+3].suit],
          wSuit[wDeck[i+4].suit],
          wSuit[wDeck[i+5].suit],
          wSuit[wDeck[i+6].suit],
          wSuit[wDeck[i+7].suit],
          wSuit[wDeck[i+8].suit],
          wSuit[wDeck[i+9].suit],
          wSuit[wDeck[i+10].suit],
          wSuit[wDeck[i+11].suit],
          wSuit[wDeck[i+12].suit],
          wFace[wDeck[i].face],
          wFace[wDeck[i+1].face],
          wFace[wDeck[i+2].face],
          wFace[wDeck[i+3].face],
          wFace[wDeck[i+4].face],
          wFace[wDeck[i+5].face],
          wFace[wDeck[i+6].face],
          wFace[wDeck[i+7].face],
          wFace[wDeck[i+8].face],
          wFace[wDeck[i+9].face],
          wFace[wDeck[i+10].face],
          wFace[wDeck[i+11].face],
          wFace[wDeck[i+12].face]
          );
}

/* Prints the hand type based on the given hand */
void printScore( Hand *wHand, const char * wFace[], const char * wRank[] ) {
    printf(" * %s: ",wRank[wHand->rank]);
    switch (wHand->rank) {
	case 0:    // High Card
	    printf("%s\n",wFace[wHand->highCard]);
	    break;
	case 1:    // Pair
	    printf("%s's\n",wFace[wHand->highSet]);
	    break;
    case 2:    // Two Pair
	    printf("%s's & %s's\n", wFace[wHand->highSet], wFace[wHand->lowSet]);
	    break;
    case 3:    // Three of a Kind
	    printf("%s's\n",wFace[wHand->highSet]);
	    break;
    case 4:    // Straight
	    printf("%s High\n",wFace[wHand->highCard]);
	    break;
    case 5:    // Flush
	    printf("%s High\n",wFace[wHand->highCard]);
	    break;
    case 6:    // Full House
	    printf("%s's & %s's\n", wFace[wHand->highSet], wFace[wHand->lowSet]);
	    break;
	case 7:    // Four of a Kind
	    printf("%s's\n",wFace[wHand->highSet]);
	    break;
	case 8:    // Straight Flush
	    printf("%s high\n",wFace[wHand->highCard]);
	    break;
	case 9:    // Royal Flush
	    printf("\n");
	    break;
    case 10:   // Cheater Territory
        printf(" * Five of a Kind! %s's <you filthy cheater ;)>\n",wFace[wHand->highSet]);
        break;
    }
    printf("\n");
}