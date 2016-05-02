/* 
 * Contains the basic deck building and handling functions:
 *  fillDeck() fills a blank deck with the standard 52 playing cards
 *  shuffle() takes each card sequentially and picks a random card in
 *    the deck to shuffle it with. Starts with the first card and swaps
 *    each at least once.
 *  reshuffle() runs the shuffle() program n times to further shuffle a deck.
 * 
 */
#include "header.h"

/* Initializes deck with 52 cards */
void fillDeck( Card * const wDeck ) {
    int i;

    /* Loop to assign a face value and suit to each card */
    for ( i=0; i < 52; i++) {
    	wDeck[ i ].face = i % 13 + 1;       /* face value from 1-13 */
        wDeck[ i ].suit = i / 13 + 1;       /* suit value from 1-4 */
        wDeck[ i ].color = i / 26 + 1;      /* color value 1 or 2 */
    }
}

/* Shuffles an already initialized deck */
void shuffle( Card * const wDeck ) {
    int i, j;   /* iterators for card positions to swap */
    Card temp;  /* placeholder for swapping cards */
    
    for ( i = 0; i < 52; i++ ) {    /* swap 1st card, 2nd, ... to last card */
	    j = rand() % 52;   /* picks a random deck position to swap */
    
        /* Swap each element in place */
        temp = wDeck[ i ];          /* save ith card */
        wDeck[ i ] = wDeck[ j ];    /* store jth into ith */
        wDeck[ j ] = temp;          /* store saved to jth */
    }
}

/* Reshuffles a deck n number of times */
void reshuffle( Card * const wDeck, int n ) {
    int i;

    for (i = 0; i < n; i++) 
	    shuffle( wDeck );  /* run shuffle() n times */
}
