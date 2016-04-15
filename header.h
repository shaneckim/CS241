#include <stdio.h>
#include <stdbool.h>

#define PLAYERS 2
#define SHUFFLES 2
#define HAND 5

typedef struct bitCard {
    unsigned face : 4;
    unsigned suit : 2;
    unsigned color: 1;
} Card;

typedef struct hand {
    Card *held[HAND];
    int rank;
    int highCard;
} Hand;

/* prototypes */
void fillDeck( Card * const wDeck );
void shuffle( Card * const wDeck );
void reshuffle( Card * const wDeck, int n );

void printHand( const Card ** const wDeck, const char * wFace[],
    const char * wSuit[], const char * wColor[] );
void printHandRaw( const Card ** const wDeck);
void printCard( Card ** const wDeck );
void printScore( Hand *wHand, const char *wFace[] );

void qSort( Card ** wHand, int left, int right, int option );
void swap( Card ** wHand, int i, int j );

void evaluateHand( Hand *wHand );
void compareHand( Hand *wHand );