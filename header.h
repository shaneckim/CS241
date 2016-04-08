#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYERS 2
#define SHUFFLES 5
#define HAND 5

const char *suit [4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *suit2 [4] = {"He", "Di", "Cl", "Sp"};
    
    const char *face[ 13 ] = 
        { "Ace", "Two", "Three", "Four",
          "Five", "Six", "Seven", "Eight",
          "Nine", "Ten", "Jack", "Queen", "King"};
          
    const char *face2[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9",
                             "10", "J", "Q", "K"};
//    const int *count[13] = {-1,1,1,1,1,1,0,0,0,-1,-1,-1,-1};
//    const int *count2[13] = {-2,1,2,2,3,2,1,0,-1,-2,-2,-2,-2};
    
    int deck [ 4 ][ 13 ] = {0};
    int deck2 [ 4 ][ 13 ] = {1,2,3,4,5,6,7,8,9,10,11,12,13,
			     14,15,16,17,18,19,20,21,22,23,24,25,26,
			     27,28,29,30,31,32,33,34,35,36,37,38,39,
			     40,41,42,43,44,45,46,47,48,49,50,51,52};
    
    
	
#endif