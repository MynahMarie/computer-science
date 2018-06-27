#include <stdio.h>
#include <cs50.h>

int main(void)

{
    int x = 0 ;
    
    printf("Lets make a pyramid!\nPlease give me a number between 0 and 23 inclusively:\n") ;
    
    x = GetInt() ; 
    
    while (x > 23 || x < 0) 
    {
       printf("This is an invalid number!\nTry again:") ;
       x = GetInt() ;
    }
    
    int row_num = 1 ;
    int count = 1 ;
    
    for (row_num = 1 ; row_num <= x ; row_num++) 
    {
        for (count = 1 ; count <= x - row_num ; count++)
        printf(" ") ;
        
        for (count = 1 ; count <= row_num + 1 ; count++)
        printf("#") ;
        
        printf("\n") ;
    }
    
    return 0 ;
}