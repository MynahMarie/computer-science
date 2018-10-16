#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    printf("How many minutes do you stay in the shower?\n") ;
    int m = GetInt() ;
    
    int w = m*12 ;
    
    printf ("You are using %i bottles of water every time you take a shower!\n" , w) ;
}
