#include "header.h"

void evaluateHand( Hand *wHand ) {
    int i, j, v, total, matches, value, face_value;

    bool multi, str, flush;
    total = matches = value = v = face_value = 0;
    multi = str = flush = 0;

    
    // testing for multiples branch
    qSort(wHand->held, 0, 4, 1);
    face_value = wHand->held[0]->face;
    /* loop to check for adjacent multiples */
    for (i = 0; i < 4; i++)
        if (wHand->held[i]->face == wHand->held[i+1]->face) {
            face_value = wHand->held[i]->face;
            multi = 1;
	        matches += 1;
        }
    /* counts total number of matches */
    for (i=0;i<=4;i++)
        for (j=i+1;j<=4;j++) {
        //printf("%d) Face1: %d  Face2: %d\n",i, wHand[i]->face, wHand[j]->face);
        if (wHand->held[i]->face == wHand->held[j]->face){
            v += 1;
        }
    }
    printf("\n");
    /* stores highest match count */
    if (v > value)
        value = v;
    v = 0;
    
    wHand->highCard = face_value;
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
        if (wHand->held[0]->suit == wHand->held[4]->suit) {
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

void compareHand( Hand *wHand ) {
    int i,j, winner;
    int tempRank = 0;
    int tempHighCard = 0;
    
    winner = 1;
    for (i=0; i<PLAYERS; i++){
        if (tempRank < wHand[i].rank) {
            winner = i+1;
            tempRank = wHand[i].rank;
            //tempHighCard = wHand[i].highCard;
        }
        if (tempRank == wHand[i].rank) {
            if (tempHighCard <= wHand[i].highCard) {
                winner = i+1;
                tempHighCard = wHand[i].highCard;
            }
            if (tempHighCard == wHand[i].highCard) {
                //printf("...uhh, well shit.\n");
            }
        }
        
    }
    printf("Player %d wins!\n",winner);
}