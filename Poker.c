/**
*File: Poker.c
*Author: August B. Sandoval
**/
/**NOTE: All FUNCTIONALITY IS NO IMPLEMENTED**/

/**This file contains Main and the check methods and logic for poker**/

#include <stdio.h>
#include <stdlib.h>
#include "CARD.H"
#include "DECK.H"



void Deal(Card Hand[], Card *Deck[] ,int *place){  /// Deals the next five cards to the player.
    printf("Place = %d\n",*place );///Debug
    int i;
    for(i = 0; i < HANDLEN; i++, (*place)++ ){
        printf( "i = %d\n", i );
        Hand[i] = *Deck[*place]  ;
    }
}

int CheckForFlush(Card H[]){  /// Checks general Flush
     printf("in Flush\n");///Debug
    int i;
    int same=0;
    Suit suit = H[0].suit;
    for(i = 1; i < HANDLEN; i++){
        if(H[i].suit  != suit)
            return 0;
    }
    return 1;
}

int CheckForRoyalF(Card H[]){ /// Checks for a royal Flush
         printf("in Royal");///Debug
        if( H[0].face == Ace){
            if(H[1].face == Ten){
                if(H[2].face == Jack){
                    if(H[3].face == Queen  ){
                        if(H[4].face == King){
                            return 1;
                        }
                        else
                            return 0;
                    }
                    else
                        return 0;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        else
            return 0;
}



int CheckForStraight(Card H[]){ /// Checks for General Straight
     printf("in Straight\n");///Debug
    int i;
    int sequence = 0;
    for(i = 0; i < HANDLEN-1; i++){
        if( (int)( H[i].face) == ( (int)(H[i+1].face) -1 )  )
            sequence+1;
        else
            return 0;
    }
    return  1;
}


int CheckForPair( Card H[], int *start){  /// Checks for a single pair
         printf("in Pair\n");///Debug
        int i;
        for(i = *start; i < HANDLEN -1 ; i++){
            if(H[*start].face == H[*start+1] .face){
                *start+1;
                return 1;
                }
        }
        return 0;
}

int CheckForThree(Card h[], int *start){ ///Checks for Three of a kind
     printf("in Three\n");///Debug
    int i;
    for(i = *start; i < HANDLEN-2; i++){
        if(  h[*start].face == h[(*start )+1].face == h[(*start) +1].face     ){
            start +2;
            return 1;
            }
    }
    return 0;
}

int CheckForFour(Card h[]){  ///Checks  for Four of a kind
     printf("in Four\n");///Debug
    if( h[0].face == h[1].face == h[2].face == h[3].face ){
        return  1;
    }
    else if( h[1].face == h[2].face == h[3].face == h[4].face ){
        return 1;
    }
    else
        return 0;
}

int CheckForTwoPair(Card h[], int *place){ /// checks for Two pair *This function had a bug and the body is subject to change
     printf("in Two Pair\n"); ///Debug
    int i;
    for(i = *place; i < HANDLEN-1  ;i++){
         printf("place = %d, i = %d\n",*place, i );
        if(h[i].face == h[ i +1 ].face )
            return 1;
    }
    return 0;

}

int CheckForFull(Card h[], int *start){  /// Checks for Full House
     printf("in Full house\n");///Debug
    if (CheckForPair(h, start) )
        if( CheckForThree(h,start) )
            return 1;
    else
        return 0;
}

HandRank Logic(Card hand[]){ /// The check logic for determining what the player has.
    int current = 0;
    int *PCurrent = &current;
    ///check for flush
        if (CheckForFlush(hand) ){
                printf("in Flush - ");
            if(CheckForRoyalF(hand)){
                printf("in Royal");
                return RoyalFlush;
            }
            else if(CheckForStraight(hand)){
                printf("in Straight");
                return StraightFlush;
            }
             else{
                    printf("Flush\n");
                    return Flush;
            }
        }
        else if(CheckForStraight(hand)){
                printf("in Straight\n");
                return Straight;
        }
        else{
            if(CheckForFull(hand, PCurrent) ){
                printf("in Full\n");
                return FullHouse;
            }
            else if(CheckForFour(hand) ){
                printf("in Four\n");
                return FourKind;
            }
            else if( CheckForThree(hand, PCurrent) ){
                    printf("in Three\n");
                    return ThreeKind;
            }
            else if(CheckForTwoPair(hand,PCurrent ) ){
                printf("in Two Pair\n");
                return TwoPair;
            }
            else if(CheckForPair(hand, 0)){
                printf("in Pair\n");
                return Pair;
            }
            else{
                 printf("in abs. Else\n");
                printf("No Set\n");
                return NoSet;
            }
        }
}




int main(){

    int placeInDeck =0, *PtrPlace;
    PtrPlace = &placeInDeck;
    Card Deck[DECKLEN];
    Card *DeckPtr[DECKLEN];
    Player Player1;
    Player1.Rank = NoSet;
    SetHand(Player1.Hand);
    Player Player2;
    SetHand( Player2.Hand );


    assignCards(Deck);
    assignPtr(DeckPtr, Deck);
    printDeck( DeckPtr );
    printf("Shuffling Deck ...\n\n");
    shuffle(DeckPtr);
    printf("Shuffling Done!\n");
    //printDeck( DeckPtr );

    printf("Dealing Player1's hand\n");
    Deal( Player1.Hand, DeckPtr, PtrPlace );
    printf("Dealing Player2's hand\n");
    Deal( Player2.Hand, DeckPtr, PtrPlace );
    printf("Dealing Complete!\n");

    printf( "Printing Player1's Hand:\n" );
    printCards(Player1.Hand, HANDLEN);
    printf("\n\nPrinting Player2's Hand:\n");
    printCards(Player2.Hand, HANDLEN );

    Player1.Rank = Logic( Player1.Hand );
    printf("\nPlayer 1 has a ");
    printRankEnum(Player1.Rank);
    printf("\n");




    return 1;
}












