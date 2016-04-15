#include "header.h"

/* Initializes deck for 52 cards */
void fillDeck( Card * const wDeck ) {
    int i;

    /* Loop to assign a face value and suit to each card */
    for ( i=0; i < 52; i++) {
	wDeck[ i ].face = i % 13;
	wDeck[ i ].suit = i / 13;
	wDeck[ i ].color = i / 26;
    }
}

/* Shuffles an already initialized deck */
void shuffle( Card * const wDeck ) {
    int i;
    int j;


    for ( i = 0; i < 52; i++ ) {
	j = rand() % 52;
	swap(wDeck, i, j);
    }
}

/* Reshuffles a deck n number of times */
void reshuffle( Card * const wDeck, int n ) {
    int i;

    for (i = 0; i < n; i++) 
	shuffle( wDeck );
}
