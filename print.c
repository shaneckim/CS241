/* 
 * Contains the various print functions to display to screen
 *   printCard() can be used to print a card to screen.  Useful for debugging.
 *   printHand() prints the player's hand to the screen.
 *   printDeck() prints the entire deck, useful for debugging deck order.
 *   printScore() prints a hand's score and highest card.
 *   
 *   
 */
#include "header.h"

/* Prints a card with raw integer values */
void printCard ( Card const wDeck ) {
	printf("%d %2d of %d\n", wDeck.color, wDeck.face, wDeck.suit);
}

/* Prints hand for each player */
void printHand( Card ** wDeck, const char * wFace[],
    const char * wSuit[], const char * wColor[] ) {
    int i;
    
    for ( i = 0; i < HAND; i++) {
	printf( "  %-5s %5s of %-8s\n"
            //" %2d %2d %2d\n"
            ,wColor[wDeck[ i ]->color], 
	        wFace[wDeck[ i ]->face], 
            wSuit[wDeck[ i ]->suit]
            //,wDeck[ i ]->color, 
	        //wDeck[ i ]->face, 
            //wDeck[ i ]->suit 
            );
    }
    printf("\n");
}

/* Prints the hand fancily */
void printHandFancy( Hand * wHand, const char * wFace[], const char * wSuit[]) {
    int i;
    
    for (i = 0; i < PLAYERS; i++)
    printf(" ----  ----  ----  ----  ---- \n"
           "|%s   ||%s   ||%s   ||%s   ||%s   |\n"
           "| %s  || %s  || %s  || %s  || %s  |\n"
           "|   %s||   %s||   %s||   %s||   %s|\n"
           " ----  ----  ----  ----  ---- \n\n",
           wFace[wHand[i].held[0]->face],
           wFace[wHand[i].held[1]->face],
           wFace[wHand[i].held[2]->face],
           wFace[wHand[i].held[3]->face],
           wFace[wHand[i].held[4]->face],
           wSuit[wHand[i].held[0]->suit],
           wSuit[wHand[i].held[1]->suit],
           wSuit[wHand[i].held[2]->suit],
           wSuit[wHand[i].held[3]->suit],
           wSuit[wHand[i].held[4]->suit],
           wFace[wHand[i].held[0]->face],
           wFace[wHand[i].held[1]->face],
           wFace[wHand[i].held[2]->face],
           wFace[wHand[i].held[3]->face],
           wFace[wHand[i].held[4]->face]
           );
}

/* Prints hand for each player in raw values */
void printHandRaw( Card ** wDeck ) {
    int i;
    
    for ( i = 0; i < HAND; i++) {
	printf( "RAW-  held[%d]:  %-5d %5d of %-8d\n", i, 
        wDeck[ i ]->color, 
	    wDeck[ i ]->face, 
        wDeck[ i ]->suit );
    }
    printf("-----\n");
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

/* Prints the hand type based on the given hand */
void printScore( Hand *wHand, const char * wFace[]) {
    switch (wHand->rank) {
	case 0:
	    printf(" * High Card: %s\n",wFace[wHand->highCard]);
	    break;
	case 1:
	    printf(" * Pair of %s's\n",wFace[wHand->highCard]);
	    break;
    case 2:
	    printf(" * Two Pair: %s's & %s's\n", wFace[wHand->highSet], wFace[wHand->lowSet]);
	    break;
    case 3:
	    printf(" * Three of a Kind: %s's\n",wFace[wHand->highCard]);
	    break;
    case 4:
	    printf(" * Straight: %s high\n",wFace[wHand->highCard]);
	    break;
    case 5:
	    printf(" * Flush: %s high\n",wFace[wHand->highCard]);
	    break;
    case 6:
	    printf(" * Full House: %s's & %s's\n", wFace[wHand->highSet], wFace[wHand->lowSet]);
	    break;
	case 7:
	    printf(" * Four of a Kind: %s's\n",wFace[wHand->highCard]);
	    break;
	case 8:
	    printf(" * Straight Flush: %s high\n",wFace[wHand->highCard]);
	    break;
	case 9:
	    printf(" * Royal Flush\n");
	    break;
    case 10:
        printf(" * Five of a Kind! %s's <you filthy cheater ;)>\n",wFace[wHand->highCard]);
        break;
    }
    printf("\n");
}