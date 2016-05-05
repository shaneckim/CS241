#include <stdio.h>
#include <stdbool.h>

#define PLAYERS 2   /* total # of players */
#define SHUFFLES 2  /* # of reshuffles */
#define HAND 5      /* size of each hand */

/* defines card structure */
typedef struct bitCard {
    unsigned face : 4;  /* # of bits to store face value */
    unsigned suit : 4;  /* # of bits to store suit (increased to fit a 0 suit) */
    unsigned color: 2;  /* # of bits to store color (increased to fit a 0 color) */
} Card;

/* defines hand structure */
typedef struct hand {
    Card *held[HAND];   /* array of pointers to each card in the hand */
    int rank;           /* stores the rank of each hand */
    int highCard;       /* stores a critical value (high value or pair value) */
    int highSet;        /* highest multiple value */
    int lowSet;         /* lowest multiple value */
} Hand;

/* prototypes */
void fillDeck( Card * const wDeck );
void shuffle( Card * const wDeck );
void reshuffle( Card * const wDeck, int n );

void printDeckRaw(Card * const wDeck);
void printDeck(Card * const wDeck, const char * wFace[],
    const char * wSuit[], const char * wColor[] );
void printDeckFancy(Card * const wDeck, const char * wFace[],
    const char * wSuit[] );
void printHand( Card ** wDeck, const char * wFace[],
    const char * wSuit[], const char * wColor[] );
void printHandRaw( Card ** wDeck);
void printHandFancy( Hand * wHand, const char * wFace[], const char * wSuit[] );
void printHandEval( Hand * wHand, const char * wFace[], const char * wRank[] );
void printCard( Card const wDeck );
void printCardFancy ( Card const wDeck,	const char * wFace[],
    const char * wSuit[] );
void printScore( Hand *wHand, const char *wFace[], const char * wRank[] );

void qSort( Card ** wHand, int left, int right, int option );
void swap( Card ** wHand, int i, int j );

void evaluateHand( Hand *wHand );
int compareHand( Hand *wHand );
int getLine(char *prmpt, char * buff, size_t sz);