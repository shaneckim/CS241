#include "header.h"

/* prototypes */
void print_deck( int wDeck[][ 13 ], const char *wSuit[]);
void shuffle( int wDeck[][ 13 ]);
void shuffle2( int wDeck[][ 13 ]);
void reshuffle( int wDeck[][ 13 ], int number);
void deal( int wDeck[][ 13 ], const char *wFace[], const char *wSuit[], int players, int hand_size);
void deal_deck( int wDeck[][ 13 ], const char *wFace[], const char *wSuit[], int players);


int main ( void ) {
    
	srand( time(0) );
    printf("Starting shuffle...\n");
    shuffle(deck);
    reshuffle(deck,SHUFFLES);
    print_deck(deck, suit2);
    printf("Shuffle done.\nStarting Deal...\n");
    deal( deck, face2, suit, PLAYERS, HAND);
    printf("Dealing done.\n");
    
    return 0;
}

/* used to initialize and initially shuffle a deck */
void shuffle( int wDeck[][ 13 ]) {
    int row;
    int column;
    int card;
    
    for (card = 1; card <= 52; card++) {
        do {
            row = rand() % 4;			// pick a random row
            column = rand() % 13;		// pick a random column
        } while (wDeck[row][column] != 0);	// do this until a 0 slot is found
        wDeck[ row ][ column ] = card;		// assign card order to deck array
    }
}

/* used to shuffle an already initialized deck */
void shuffle2( int wDeck[][ 13 ]) {
    int row, row2;
    int col, col2;
    int tmp;
    
    for (col = 0; col < 13; col++){
	for (row = 0; row < 4; row++){
            row2 = rand() % 4;		// assign a random row
	    col2 = rand() % 13;		// assign a random column
	    
	    /* swap the two values in the deck array */
        tmp=wDeck[row][col];
	    wDeck[row][col]=wDeck[row2][col2];
	    wDeck[row2][col2]=tmp;
	}
    }
}

/* uses shuffle2 to reshuffle a deck n times */
void reshuffle( int wDeck[][ 13 ], int n) {
    int i;
    for (i = 1; i<= n; i++) {
	//printf("shuffle %d\n", i);
	shuffle2(wDeck);
	//print_deck(wDeck);
    }
}

void deal( int wDeck[][ 13 ], const char *wFace[], const char *wSuit[], int players, int hand_size ) {
    int card;
    int row;
    int column;
    
    /* searches for a card in the deck array, prints when match found */
    for (card = 1; card <= 52; card++){
        for (row = 0; row < 4; row++){
            for (column = 0; column < 13; column++){
                if (wDeck[row][column] == card){	// is card a match?
                    printf("%5s of %-8s\t%c", 		// print face and suit of card
                //    printf("%5s%c",
                    wFace[ column ],
                    wSuit[ row ],
                    card % players == 0 ? '\n' : '\t');
                    if (card == (hand_size*PLAYERS))
                //    sleep(3/2);
		            return;
                } 
            }
        }
    }
}

/* prints out a deck with nice formating */
void deal_deck( int wDeck[][ 13 ], const char *wFace[], const char *wSuit[], int players ) {
    int card;
    int row;
    int column;
    
    /* searches for a card in the deck array, prints when match found */
    for (card = 1; card <= 52; card++){
        for (row = 0; row < 4; row++){
            for (column = 0; column < 13; column++){
                if (wDeck[row][column] == card){	// is card a match?
                    printf("%5s of %-8s\t%c", 		// print face and suit of card
                //    printf("%5s%c",
                    wFace[ column ],
                    wSuit[ row ],
                    card % players == 0 ? '\n' : '\t');
                    if (card == (5*PLAYERS) )  printf("\n");
                //    sleep(3/2);
		            break;
                } 
            }
        }
    }
}

/* prints the deck array, showing card order */
void print_deck( int wDeck[][ 13 ], const char *wSuit[]) {
    int row, col;
    
    printf("     A  2  3  4  5  6  7  8  9 10  J  Q  K\n");
    for (row=0;row<4;row++){
	printf("%s: ",wSuit[row]);
        for (col=0;col<13;col++) {
            printf("%2d ", wDeck[row][col]);	// prints the order of a card in the deck array
        }
	printf("\n");
    }
}

void sort() {
    
}