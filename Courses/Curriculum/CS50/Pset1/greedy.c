#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float amount = 0.0 ;
    
    printf("How much change do I owe you?\n") ; 
    amount = GetFloat() ;
    
    while (amount < 0.0)
    {
    printf("Please give me a valid value!\nLet's try again: ") ; 
    amount = GetFloat() ;
    }
    
    int amount_cents = round(amount * 100) ;
    
    /** 
    * working with the new amount in cents we start doing the greedy algorithm calculations
    * initializing a count variable for counting the number of coins used
    * initializing a variable for each value of coins used 
    */
    
    int count = 0 ;
    int quarters = 0 ;
    int dimes = 0 ;
    int nickels = 0 ;
    int pennies = 0 ;
    
    while (amount_cents >= 25)       // using each coin value starting by quarters 
    {
        quarters++ ;
        count++ ;
        amount_cents = amount_cents - 25 ;
    }
    
    while (amount_cents >= 10 && amount_cents < 25)    
    {
        dimes++ ;
        count++ ;
        amount_cents = amount_cents - 10 ;
    }
    
    while (amount_cents >= 5 && amount_cents < 10)    
    {
        nickels++ ;
        count++ ;
        amount_cents = amount_cents - 5 ;
    }
    
    while (amount_cents >= 1)                        
    {
        pennies++ ;
        count++ ;
        amount_cents = amount_cents - 1 ;
    }
    
    printf("%i\n", count) ;     // print variable 'count' which represents amount of coins used
    
    return 0 ;
}