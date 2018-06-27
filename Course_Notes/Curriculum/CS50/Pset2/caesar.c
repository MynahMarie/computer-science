#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Make sure that the number of command-line arguments and their value
    // are valid. If not, return appropriate error.
    
    if (argc != 2)
    {   
        printf("Error 1: One command-line argument needed.\n");
        return 1;
    }
    
    int k = atoi(argv[1]);
    
    if (k < 1)
    {
        printf("Error 2: Only positive integers are allowed.\n");
        return 2;
    }
    
    // Get the plain text to encrypt and define the key.
    
    string text = GetString();
    int n = strlen(text);
    char cypher;
    
    // Encrypt each alphabetical character and print the result.
    
    for (int i = 0; i<n; i++)
    {   
        if (isalpha(text[i]))  // Detects if it's a letter
        {
            if (isupper(text[i]))  // Detects if upper case
            {    
                cypher = ((text[i] - 'A' + k )% 26) + 'A' ;
                printf("%c", cypher);
            }
            
            else if (islower(text[i])) // Detects if lower case
            {    
                cypher = ((text[i] - 'a' + k )% 26) + 'a';
                printf("%c", cypher);
            }
        }
        else                        
            printf("%c", text[i]);  // Other characters are printed as is
    }   
    
    printf("\n");
    
    return 0;
    
}