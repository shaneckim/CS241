#include "header.h"

/* Prints hand for each player */
void printHand( const Card ** const wDeck, const char * wFace[],
    const char * wSuit[], const char * wColor[] ) {
    int i;
    
    for ( i = 0; i < HAND; i++) {
	printf( "  %-5s %5s of %-8s\n", wColor[wDeck[ i ]->color], 
	    wFace[wDeck[ i ]->face], wSuit[wDeck[ i ]->suit] );
    }
}

/* Prints hand for each player in raw values */
void printHandRaw( const Card ** const wDeck ) {
    int i;
    
    for ( i = 0; i < HAND; i++) {
	printf( "  held[%d]:  %-5d %5d of %-8d\n", i, wDeck[ i ]->color, 
	    wDeck[ i ]->face, wDeck[ i ]->suit );
    }
}

/* Prints cards with integer values */
void printCard ( Card ** const wDeck ) {
    int i;

    for ( i = 0; i < 5; i++) {
	printf("%d %2d of %d\n", wDeck[ i ]->color, wDeck[ i ]->face, wDeck[ i ]->suit);
    }
}

void printScore( Hand *wHand, const char * wFace[]) {
    switch (wHand->rank) {
	case 0:
	    printf(" * High Card: %s\n",wFace[wHand->highCard]);
	    break;
	case 1:
	    printf(" * Pair of %s's\n",wFace[wHand->highCard]);
	    break;
    case 2:
	    printf(" * Two Pair\n");
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
	    printf(" * Full House\n");
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
}