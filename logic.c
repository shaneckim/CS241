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
    int total;          /* rank value variable */
    
    /* boolean flags */
    bool multi;     /* hand contains multiple matching cards */
    bool str;       /* hand contains straight */
    bool flush;     /* hand contains flush */
    
    /* initializing values */
    total = 0;
    multi = str = flush = 0;

    /* testing for multiples branch */
    qSort(wHand->held, 0, 4, 1);        /* sort by face value descending */
     
    // variables
    int HighestCard = 0;                // highest face card in hand
    int HighestMultipleCount = 0;       // highest # of multiple cards AKA pair, trip, quad
    int NextHighestMultipleCount = 0;   // lower # of multiple cards AKA full house or two pair's lowest pair
    int HighestMultiple = 0;            // face value of HMC
    int NextHighestMultiple = 0;        // face value of NHMC
    bool isMultiple = 0;                // boolean toggles for multiples 
    
    // intermediate vars
    int HMC1, HMC2, HM1, HM2;
    HMC1 = HMC2 = HM1 = HM2 = 0;
    
    //wHand->held[i]->face
    HighestCard = wHand->held[0]->face;
    
    ///
    for (i = 1; i < HAND; i++) {
        //printf("%d) %d %d\n", i, wHand->held[i-1]->face+1, wHand->held[i]->face+1);
        if (wHand->held[i]->face > 0) {
            if (wHand->held[i-1]->face == wHand->held[i]->face) {
                multi = 1;                              /* set multi flag to true */
                if (HM1 == 0 || HM1 == wHand->held[i]->face) {
                    HMC1 += 1;
                    HM1 = wHand->held[i]->face;
                }
                if ( HM1 != wHand->held[i]->face) {
                    HMC2 += 1;
                    HM2 = wHand->held[i]->face;
                }
            }
        //printf("%d %d's, %d %d's\n", HMC1+1, HM1+1, HMC2+1, HM2+1);
        }
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
        /*
        printf(
            "=====================\n"
            "HMC:  %d\nHM:   %d\nNHMC: %d\nNHM:  %d\nHighCard: %d\n"
            "=====================\n",
            HighestMultipleCount,
            HighestMultiple,
            NextHighestMultipleCount,
            NextHighestMultiple,
            HighestCard
        );//*/
        if (HighestMultiple == 0) {
            wHand->highSet = HighestCard;
        } else {
            wHand->highSet = HighestMultiple;
        }
        wHand->lowSet  = NextHighestMultiple;
        
    
        wHand->highCard = HighestCard;
    
        switch (HighestMultipleCount) {
            case 1:
                // pair or two pair
                if (NextHighestMultipleCount == 1)
                    total = 2;
                else
                    total = 1;
                break;
            case 2:
                // three of a kind or full house
                if (NextHighestMultipleCount == 1)
                    total = 6;
                else
                    total = 3;
                break;
            case 3:
                // four of a kind
                total = 7;
                break;
            case 4:
                // five of a kind
                total = 10;
                break;
        }
           
    // testing for straight/flush branch
    if (multi == 0) {
        qSort(wHand->held, 0, 4, 0);
        if (wHand->held[0]->suit == wHand->held[4]->suit && wHand->held[0]->suit != 0) {
	        flush = 1;
	        total = 5;         // Flush
        }
        qSort(wHand->held, 0, 4, 1);
        if ((wHand->held[0]->face == wHand->held[4]->face + 4 && wHand->held[4]->face != 0) || wHand->held[0]->face == 12 && 
           (( wHand->held[1]->face == 11 || wHand->held[1]->face == 3 ) && 
           (wHand->held[4]->face == wHand->held[1]->face - 3))) {
	        str = 1;
	        total = 4;         // Straight
            if (wHand->held[1]->face == 3)
                wHand->highCard = 3;
        }

        if (str == 1 && flush == 1) {
	        total = 8;         // Straight Flush
            if (wHand->held[0]->face == 13 && wHand->held[4]->face == 9) {
                total = 9;     // Royal Flush
	        }
        }
    }
    wHand->rank = total;
}

int compareHand( Hand *wHand ) {
    int i,j, winner;
    
    static Card blankCard;
    
    blankCard.face = 0;
    blankCard.suit = 0;
    blankCard.color = 0;
    
    //printf("\n------------------\nstart of comparehand\n------------------\n");
    
    if (PLAYERS > 2) {
    for (i = 0; i < PLAYERS; i++) {
        winner = i+1;
        for (j = i + 1; j < PLAYERS; j++) {
            if (wHand[i].rank < wHand[j].rank) {
                winner = j+1;
            }
            if (wHand[i].rank == wHand[j].rank) {
                if (wHand[i].highSet < wHand[j].highSet) {
                    winner = j+1;
                } else if (wHand[i].highSet == wHand[j].highSet) {
                    winner = 0;
                }
            }
        printf("--- %d v %d: Winner: %d\n", i+1, j+1, winner);
        }
    }
    
    return 0;
    }
    
    /*
    for (i = 0; i < PLAYERS; i++) {
        winner = i+1;
        for (j = i+1; j < PLAYERS; j++) { 
            if (wHand[i].rank == wHand[j].rank) {
                if (wHand[i].highSet < wHand[j].highSet) {
                    winner = j+1;
                }
                if (wHand[i].highSet == wHand[j].highSet) {
                    winner = 0;
                    // remove tied cards
                    // check which cards match highCard
                    for ( i=0; i < PLAYERS; i++ ) {
                        //printf("(%d) \n",i);
                        //printHandRaw(wHand[i].held);
                        for ( j=0; j < HAND; j++ ) {
                            if (wHand[i].held[j]->face == wHand[i].highSet) {  
                                //wHand[i].held[j] = NULL;    //blankCard;
                                wHand[i].held[j] = &blankCard;
                                //printCard(*wHand[i].held[j]);
                            }
                        }
                        //printf("(%d) \n",i);
                        //printHandRaw(wHand[i].held);
                    }
                }
            }
        }
    }*/
//*
        winner = 1;
        if (wHand[0].rank < wHand[1].rank) {
            winner = 2;
        }
        if (wHand[0].rank == wHand[1].rank) {
            if (wHand[0].highSet < wHand[1].highSet) {
                winner = 2;
            }
            if (wHand[0].highSet == wHand[1].highSet) {
                winner = 0;
                // remove tied cards
                    // check which cards match highCard
                    for ( i=0; i < PLAYERS; i++ ) {
                        //printf("(%d) \n",i);
                        //printHandRaw(wHand[i].held);
                        for ( j=0; j < HAND; j++ ) {
                            if (wHand[i].held[j]->face == wHand[i].highSet) {  
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
    //*/    
        if (winner != 0) {
            printf("*** Player %d wins! ***\n",winner);
            return 0;
        } else if ( winner == 0 && wHand[0].highCard != 0) {
            printf("Tie break Required!\n");
            //sleep(1);
            return 1;
        } else {
            printf("Hands match! Split pot!\n");
            return 2;
        }
}
