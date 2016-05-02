/*
 * Contains the actual logic for evaluating and comparing hands
 *  evaluateHand() is the main workhorse of the logic portion
 * 
 *  compareHand() determines which hand is the actual winner
 *    Currently supports 2 player ONLY!
 */
#include "header.h"

/* calculates the rank and highest card of a hand */
void evaluateHand( Hand *wHand ) {
    /* integer values */
    int i, j;           /* iterators for loops */ 
    int v;              /* temp variable to store all matches */
    int total;          /* rank value variable */
    int matches;        /* stores total # of adjacent matches */
    int value;          /*  */
    int face_value;     /*  */

    /* boolean flags */
    bool multi;     /* hand contains multiple matching cards */
    bool str;       /* hand contains straight */
    bool flush;     /* hand contains flush */
    
    /* initializing values */
    total = matches = value = v = face_value = 0;
    multi = str = flush = 0;

    /* testing for multiples branch */
    qSort(wHand->held, 0, 4, 1);        /* sort by face value descending*/
    face_value = wHand->held[0]->face;  /* temporary storage of highest card in hand */
    
    /* loop to check for adjacent multiples */
    for (i = 0; i < 4; i++) {
        if (wHand->held[i]->face > 0) {     /* ignore "replaced" zero cards */
            if (wHand->held[i]->face == wHand->held[i+1]->face) {   /* if adjacent cards have matching face values */
                //printf("Muliple %d cards found:\n", wHand->held[i]->face);
                face_value = wHand->held[i]->face;      /* replace high card value with match */
                multi = 1;                              /* set multi flag to true */
	            matches += 1;                           /* increase total adjacent matches */
            }
        }
    }
    
    /* counts total number of matches */
        for (i=0;i<=4;i++)
            for (j=i+1;j<=4;j++) {
                /* debug to screen */
                //printf("%d) Face1: %d  Face2: %d\n",i, wHand->held[i]->face, wHand->held[j]->face);
                if (wHand->held[i]->face == wHand->held[j]->face) { /* if match found */
                    v += 1;                                         /* increase total # of all matches */
                }
            }
        
    /* stores highest match count */
    if (v > value)
        value = v;
    v = 0;
    
    // variables
    int HighestCard = 0;                // highest face card in hand
    int HighestMultipleCount = 0;       // highest # of multiple cards AKA pair, trip, quad
    int NextHighestMultipleCount = 0;   // lower # of multiple cards AKA full house or two pair's lowest pair
    int HighestMultiple = 0;            // face value of HMC
    int NextHighestMultiple = 0;        // face value of NHMC
    bool isMultiple = 0;               // boolean toggles for multiples 
    
    // intermediate vars
    int HMC1, HMC2, HM1, HM2;
    HMC1 = HMC2 = HM1 = HM2 = 0;
    
    //wHand->held[i]->face
    HighestCard = wHand->held[0]->face;
    
    for (i = 1; i < HAND; i++) {
        printf("%d) %d %d\n", i, wHand->held[i-1]->face+1, wHand->held[i]->face+1);
    }
    ///
    for (i = 1; i < HAND; i++) {
        printf("%d) %d %d\n", i, wHand->held[i-1]->face+1, wHand->held[i]->face+1);
        //if (wHand->held[i]->face >= 0) {
            if (wHand->held[i-1]->face == wHand->held[i]->face && wHand->held[i]->face == HighestCard) {
                HMC1 += 1;
                HM1 = wHand->held[i]->face;
            }
            if (wHand->held[i-1]->face == wHand->held[i]->face && wHand->held[i]->face != HighestCard) {
                HMC2 += 1;
                HM2 = wHand->held[i]->face;
            }
        //}
        //printf("%d %d's\n%d %d's\n", HMC1+1, HM1+1, HMC2+1, HM2+1);
    }
    
    if (HMC1 >= HMC2) {
        HighestMultipleCount = HMC1;
        HighestMultiple = HM1;
        NextHighestMultipleCount = HMC2;
        NextHighestMultiple = HM2;
    } else if (HMC2 > HMC1) {
        HighestMultipleCount = HMC2;
        HighestMultiple = HM2;
        NextHighestMultipleCount = HMC1;
        NextHighestMultiple = HM1;
    } else {
        printf("Error with validating multiples!\n");
    }
        
        printf(
            "=====================\n"
            "HMC:  %d\nHM:   %d\nNHMC: %d\nNHM:  %d\nHighCard: %d\n"
            "=====================\n",
            HighestMultipleCount,
            HighestMultiple,
            NextHighestMultipleCount,
            NextHighestMultiple,
            HighestCard
        );
        wHand->highSet = HighestMultiple;
        wHand->lowSet  = NextHighestMultiple;
        
    
    wHand->highCard = HighestCard;
    
        if (matches == 1)
            if (value == 1) {
                total = 1;      // pair
            }
        if (matches == 2) {
            //either 2 pair or three of a kind
            if (value == 2)
                total = 2;      // two pair
            if (value == 3)
                total = 3;      // three-of-a-kind
        }
	    if (matches == 3) {    // full house or four of a kind
            if (value == 4)
                total = 6;      // full house
            if (value == 6)
                total = 7;      // four-of-a-kind
        }
        if (matches == 4)
            total = 10;         // five-of-a-kind
    //printf("Adjacent matches: %d\nHighest value card: %d\nrank: %d\nHigh card value: %d\n",matches, value, total, face_value);
           
    // testing for straight/flush branch
    if (multi == 0) {
        qSort(wHand->held, 0, 4, 0);
        if (wHand->held[0]->suit == wHand->held[4]->suit && wHand->held[0]->suit != 0) {
	        flush = 1;
	        total = 5;         // Flush
        }
        qSort(wHand->held, 0, 4, 1);
        if (wHand->held[0]->face == wHand->held[4]->face + 4 || wHand->held[0]->face == 12 && 
           (( wHand->held[1]->face == 11 || wHand->held[1]->face == 3 ) && 
           (wHand->held[4]->face == wHand->held[1]->face - 3))) {
	        str = 1;
	        total = 4;         // Straight
            if (wHand->held[1]->face == 3)
                wHand->highCard = 3;
        }

        if (str == 1 && flush == 1) {
	        total = 8;
            if (wHand->held[0]->face == 12 && wHand->held[4]->face == 8) {
	            total = 9;
	        }
        }
    }
    wHand->rank = total;
}

int compareHand( Hand *wHand ) {
    int i,j, winner;
    
    Card  blankCard;
    
    blankCard.face = 0;
    blankCard.suit = 0;
    blankCard.color = 0;
    
    winner = 1;
    //printf("\n------------------\nstart of comparehand\n------------------\n");
    
    

        if (wHand[0].rank < wHand[1].rank) {
            winner = 2;
        }
        if (wHand[0].rank == wHand[1].rank) {
            if (wHand[0].highCard < wHand[1].highCard) {
                winner = 2;
            }
            if (wHand[0].highCard == wHand[1].highCard) {
                winner = 0;
                // remove tied cards
                    // check which cards match highCard
                    for ( i=0; i < PLAYERS; i++ ) {
                        //printf("(%d) \n",i);
                        //printHandRaw(wHand[i].held);
                        for ( j=0; j < HAND; j++ ) {
                            if (wHand[i].held[j]->face == wHand[i].highCard) {  
                                //wHand[i].held[j] = NULL;    //blankCard;
                                wHand[i].held[j] = &blankCard;
                                //printCard(*wHand[i].held[j]);
                            }
                          
                        }
                        //printf("(%d) \n",i);
                        //printHandRaw(wHand[i].held);
                    
                    
                // recheck highest card
                    
                    }
            }
        }
        
        if (winner != 0) {
            printf("*** Player %d wins! ***\n",winner);
            return 0;
        } else if ( winner == 0 && wHand[0].highCard != 0) {
            printf("Tie break Required!\n");
            sleep(3);
            return 1;
        } else {
            printf("Hands match! Split pot!\n");
            return 2;
        }
}
