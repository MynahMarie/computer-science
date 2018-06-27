#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    
    printf("%c", toupper(name[0]));
    
    for (int i = 0; i<strlen(name); i++)
    {
        if (name[i]==' ')
        {
            char n = name[i+1];
            
            if (islower(n))
                printf("%c", toupper(n));
            
            else
                printf("%c", n);
        }
    }
    printf("\n");
    
    return 0; 
        
}