#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

typedef uint8_t  BYTE;

int main (int argc, char* argv[]) 
{
    //Verify proper number of arguments
    if (argc != 2) {
        
        fprintf(stderr, "Usage: ./recover file\n");
        return 1;
    }
    
    //Remember file names
    char *infile = argv[1];
    char *outfile = malloc(sizeof(BYTE) * 8);
    
    //Open the input file, return error if not found
    FILE *recover = fopen(infile, "r");
    
    if (recover == NULL) {
        
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    //Counts number of jpegs found
    int count = 0;
    //Set a variable to detect if we are already writing an image
    int writing = 0;
    //Create a buffer to read blocks of data
    BYTE buffer[512];
    //Create a file pointer to write the data to.
    FILE *outptr;
    
    //Read card from beginning to end
    while (fread(&buffer, 512, 1, recover) == 1)
    {
        
        //If signature is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Check if we are already writing to a file.
            if (writing == 1)
            {
                //Close the image file.
                fclose(outptr);
                //Increment the count for using it as name of next image.
                count++;
            }  
        
            //Set variable to 1 if this is the first image found.
            writing = 1;
            
            //Create a file with the right name.
            snprintf(outfile, 8, "%003i.jpg", count);
           
            //Open the file we just named so we can write the content of the image
            outptr = fopen(outfile, "w");
           
            //Write from buffer 1 block at the time
            fwrite(&buffer, 512, 1, outptr);
            
        }//end "if"
        
        //Continue writing to the same file if no new signature is found.
        else if (writing == 1)
            fwrite(&buffer, 512, 1, outptr);

    } //end "while"
    
    //Free memory
    free(outfile);
    
    //Close file
    fclose(recover);
    
    //success!
    return 0; 
    
}