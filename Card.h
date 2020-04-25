/**
* File Card.h
*Author: August B. Sandoval
**/

/**This file contains all the Enumerators, Structs and Constants for the poker program**/

#ifndef CARD_H
#define CARD_H

#define HANDLEN 5
#define DECKLEN 52
/// Enumerator that store the data that will be used for the Card Struct
typedef enum Face{
    FNone,Ace,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King
}Face;

typedef enum Suit{
    SNone,Heart,Diamond,Club,Spade
}Suit;

typedef enum HandRank{
    NoSet,Pair,TwoPair, ThreeKind, Straight, Flush, FullHouse, FourKind, StraightFlush, RoyalFlush
}HandRank;


/// The Struct for Card
typedef struct Card{
    Face face;  /// Stores the face value of the card
    Suit suit;  /// Stores the Suit value of the card
}Card;

/// The Struct for Player
typedef struct Player{
    Card Hand[HANDLEN];  /// A Card array of 5 that stores all the card in the player's hand
    HandRank Rank;  /// Stores the value of the hand the player has.  e.i. Pair
    Face RankF;
    Face HighCard;
}Player;

const Card Blank = { FNone, SNone };  /// a constant Card with a blank face and suit.
/**Used in initlizing the deck**/

void printFaceEnum(Face value){  /// prints the Face enum as a string
    switch(value){
        case FNone:
            printf("None");
            break;
        case Ace:
            printf("Ace");
            break;
        case Two:
            printf("Two");
            break;
        case Three:
            printf("Three");
            break;
        case Four:
            printf("Four");
            break;
        case Five:
            printf("Five");
            break;
        case Six:
            printf("Six");
            break;
        case Seven:
            printf("Seven");
            break;
        case Eight:
            printf("Eight");
            break;
        case Nine:
            printf("Nine");
            break;
        case Ten:
            printf("Ten");
            break;
        case Jack:
            printf("Jack");
            break;
        case Queen:
            printf("Queen");
            break;
        case King:
            printf("King");
            break;
        default:
            printf("should not be here\n");
            break;
    }
}


void fprintFaceEnum(Face value, FILE *out){ ///Prints the Face Enum as a string to a file
    switch(value){
        case FNone:
            fprintf(out,"None");
            break;
        case Ace:
            fprintf(out,"Ace");
            break;
        case Two:
            fprintf(out,"Two");
            break;
        case Three:
            fprintf(out,"Three");
            break;
        case Four:
            fprintf(out,"Four");
            break;
        case Five:
            fprintf(out,"Five");
            break;
        case Six:
            fprintf(out,"Six");
            break;
        case Seven:
            fprintf(out,"Seven");
            break;
        case Eight:
            fprintf(out,"Eight");
            break;
        case Nine:
            fprintf(out,"Nine");
            break;
        case Ten:
            fprintf(out,"Ten");
            break;
        case Jack:
            fprintf(out,"Jack");
            break;
        case Queen:
            fprintf(out,"Queen");
            break;
        case King:
            fprintf(out,"King");
            break;
        default:
            printf("should not be here\n");
            break;
    }
}


void printSuitEnum(Suit suit){  /// prints the Suit enum as a string
    switch(suit){
        case FNone:
            printf("None");
            break;
        case Heart:
            printf("Heart");
            break;
        case Diamond:
            printf("Diamond");
            break;
        case Club:
            printf("Club");
            break;
        case Spade:
            printf("Spade");
            break;
        default:
            printf("should not be here\n");
            break;
    }
}

void fprintSuitEnum(Suit suit, FILE *out){ ///Prints the Suit Enum as a string to a file
    switch(suit){
        case FNone:
            fprintf(out,"None");
            break;
        case Heart:
            fprintf(out,"Heart");
            break;
        case Diamond:
            fprintf(out,"Diamond");
            break;
        case Club:
            fprintf(out,"Club");
            break;
        case Spade:
            fprintf(out,"Spade");
            break;
        default:
            printf("should not be here\n");
            break;
    }
}


void printRankEnum(HandRank Rank){ ///Prints the Rank Enum as a string
    switch(Rank){
    case NoSet:
        printf("NoSet");
        break;
    case Pair:
        printf("Pair");
        break;
    case TwoPair:
        printf("Two Pair");
        break;
    case ThreeKind:
        printf("Three kind");
        break;
    case FourKind:
    printf("Four Kind");
        break;
    case Straight:
        printf("Straight");
        break;
    case Flush:
        printf("Flush");
        break;
    case StraightFlush:
        printf("Straight Flush");
        break;
    case FullHouse:
        printf("Full House");
        break;
    case RoyalFlush:
        printf("Royal Flush");
        break;
    default:
        printf("Should not be here!\n");
        break;
    }

}
#endif // Card_H
