/* 
 * Holds organization based functions
 *  qSort() sorts cards by highest to lowest or by suit
 *    can also sort by color (not used currently)
 * 
 *  swap() switches two cards in a hand in place
 *    used by qSort()
 * 
 */

#include "header.h"

/* qSort: sorts each hand by either suit, face or color
 * option: 
 *   0 for suit ascending
 *   1 for face descending
 *   2 for color ascending (not used)
 */
void qSort( Card ** wHand, int left, int right, int option) {
    int i, last;

    if (left >= right) 
        return;
    swap(wHand, left, (left + right)/2);
    last = left;
    for ( i=left+1; i <= right; i++) {
        switch (option) {
            case 0:
                if ( wHand[i]->suit < wHand[left]->suit)
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
            default:
                printf("qSort may not have sorted your data!\n");
                break;
        }
    }
    swap(wHand, left, last);
    qSort(wHand, left, last-1, option);
    qSort(wHand, last+1, right, option);
}

/* used to switch two cards in a hand */
void swap( Card **wHand, int i, int j) {
    Card *temp;
    
    temp = wHand[ i ];
    wHand[ i ] = wHand[ j ];
    wHand[ j ] = temp;
    
}