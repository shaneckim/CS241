/* Holds organization based functions
 * qSort sorts cards by highest to lowest or by suit
 * can also sort by color (not used currently)
 * 
 * swap will do the actual switching of cards
 * used by both the qSort and for shuffling the initial deck
 * 
 */

#include "header.h"

void qSort( Card ** wHand, int left, int right, int option) {
    int i, last;

    if (left >= right)
	return;
    swap(wHand, left, (left + right)/2);
    last = left;
    for ( i=left+1; i <= right; i++) {
	switch (option) {
	    case 0:
		if ( wHand[i]->suit < wHand[left]->suit )	
		    swap(wHand, ++last, i);
		break;
	    case 1:
		if ( wHand[i]->face > wHand[left]->face )	
		    swap(wHand, ++last, i);
		break;
	  /*  case 2:
		if ( wHand[i]->color < wHand[left]->color )
		    swap(wHand, ++last, i);
		break;*/
	}
    }
    swap(wHand, left, last);
    qSort(wHand, left, last-1, option);
    qSort(wHand, last+1, right, option);
}

void swap( Card **wHand, int i, int j) {
    Card *temp;

    temp = wHand[ i ];
    wHand[ i ] = wHand[ j ];
    wHand[ j ] = temp;
}