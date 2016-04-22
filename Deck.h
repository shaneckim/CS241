/**
* File: Deck.h
* Author: August B. Sandoval
**/

/**This file contains all the methods for working with the Deck and Player hand Arrays**/

#ifndef DECK_H
#include "CARD.H"
#define DECK_H

void assignCards( Card Deck[]);  /// Assigns all the cards in the deck from Blank to a valid Face and Suit Value
void assignPtr(Card *DeckPtr[], Card Deck[]); /// Assigns all the pointers in the pointer array to point to each element in the deck array
void shuffle(Card *deck[]); /// Shuffles the pointers on the pointer array to pointer by swapping two random pointers addresses
void printDeck(Card *deck[]); /// Prints the pointer array to a the file "deckout.txt"
void printCards(Card deck[], int Len); /// Prints the hand of a player's hand
void SetHand(Card hand[]); /// sets the player's hand to Blank before anything else is done

void assignCards( Card Deck[]){
    int i, j= 1;
    for(i = 0; i < 52; i++){
        //printf("i = %d\tj = %d\n", i,j);  ///Debug
        Deck[i].face = (Face)( (i % 13)+1 );
        if(  i%13 == 0 && i != 0){
            //printf("in if\n"); ///Debug
            ++j;
            //printf("j = %d\n",j); ///Debug
        }
        //printSuitEnum(  (Suit)(j)   ); ///Debug
        Deck[i].suit = (Suit)( j ) ;
    }
}

void assignPtr(Card *DeckPtr[], Card Deck[]){
    int i;
    for(i = 0; i <52; i++){
        DeckPtr[i] = &Deck[i];
    }
}

void shuffle(Card *deck[]){
    unsigned int seed = time(NULL);
    srand(seed);
    int i,R1,R2;
    Card *temp;
    for(i = 0; i< (52 * 2); i++){
        R1 = rand() % 52;
        R2 = rand() % 52;
        if(R1 == R2){
            i--;
            continue;
        }
        else{
            temp = deck[R1];
            deck[R1] = deck[R2];
            deck[R2] = temp;
        }
    }
}

void printDeck(Card *deck[]){
    FILE *outfile;
    outfile = fopen( "deckout.txt","w");
    int i;
    for(i =0;i<DECKLEN;i++){
        fprintf(outfile,"Card %d: ",i+1 );
        fprintFaceEnum(  deck[i]->face ,outfile  );
        fprintf(outfile," of ");
        fprintSuitEnum( deck[i]->suit,outfile );
        fprintf(outfile,"\n");
    }
}

void printCards(Card deck[], int Len){
    int i;
    for(i =0;i<Len;i++){
        printf("Card %d: ",i+1 );
        printFaceEnum(  deck[i].face   );
        printf(" of ");
        printSuitEnum( deck[i].suit );
        printf("\n");
    }
}

void SetHand(Card hand[] ){
    int i;
    for(i = 0; i < HANDLEN; i++){
        hand[i] = Blank;
    }
}

#endif // DECK_H
