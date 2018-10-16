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
    
    string key = argv[1];
    
    int key_length = strlen(key);
    
    for (int k = 0; k < key_length; k++) {
        if (isalpha(key[k]) == false) {
            printf("Error 2: Only alphabetical characters are allowed.\n");
            return 1;
        }
    }
    

    // Store the value of each character in string
    
    string text = GetString();
    int n = strlen(text);
    char cypher;

    
    // Encrypt each alphabetical character and print the result.
    
    for (int i = 0, k = 0; i<n; i++)
    {   
        char letter = tolower(key[k % key_length]) - 'a'; // Adjust the value of key
        
        if (isalpha(text[i]))  // Detects if plain text is a letter
        {
            if (isupper(text[i]))  // Detects if plain text is upper case
            {   
                
                cypher = 'A' + (text[i] - 'A' + letter) % 26;
                k++;
                printf("%c", cypher);
            }
            
            else if (islower(text[i])) // Detects if plain text is lower case
            {    
                cypher = 'a' + (text[i] - 'a' + letter) % 26;
                k++;
                printf("%c", cypher);
            }
        }
        else                        
            printf("%c", text[i]);  // Other characters are printed as is
    }   
    
    printf("\n");
    
    return 0;
    
}
