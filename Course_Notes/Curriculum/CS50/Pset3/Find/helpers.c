/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    
    int index;
    int max = n;
    int min = 0;
    
    if (value < 1) // Exit if the value is a non-positive int.
        return false;
    
    //Implement binary search.
    
    while (min <= max) {
            
        index = (max + min) / 2;
            
        if (value == values[index]) 
            return true;
                
        else if (value < values[index]) 
            max = index - 1;

        else 
            min = index + 1;
    
    }
    
    return false; //return false if value is not found.

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    //Bubble sort
    
    int counter; //Variable to count swaps at each iteration through the loop.
    
    do {
        
        counter = 0;
        
        for (int i = 0; i < n; i++) {
            if (values[i] > values[i+1]) {
            
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                counter++;
            }
        }
    } while (counter > 0);
    
    return;
}
