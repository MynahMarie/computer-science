/**
 * Resizes a bmp image piece by piece
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // Make sure the value of argv[1] is valid.
    
    int n = atoi(argv[1]);
    
    if (n <= 0 || n > 100) 
    {
        
        fprintf(stderr, "Invalid resize value.\n");
        return 2;
    }
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER 
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    // Adjust info in headers for resizing 
        
        bi.biHeight = bi.biHeight * n;
        bi.biWidth = bi.biWidth * n;
        
        int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        
        bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
        bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
        
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    //Old values
    int oldHeight = abs(bi.biHeight) / n;
    int oldWidth = bi.biWidth / n;
    int oldPad  = (4 - (oldWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    RGBTRIPLE triple;
    int line = sizeof(triple) * oldWidth + oldPad;
    
    // iterate over infile's scanlines
    for (int i = 0; i < oldHeight; i++)
    {
        //Repeat each pixel vertically
        for( int x = 0; x < n; x++) 
        {
            // iterate over pixels in scanline
            for (int j = 0; j < oldWidth; j++)
            {
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
                    //Repeat each pixel horizontally
                    for (int y = 0; y < n; y++)
                    {
                         // write RGB triple n amount of times to outfile
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        
                    }//end for "y" 
            }//end for "j"
            
                //skip over padding, if any
                fseek(inptr, oldPad, SEEK_CUR);
                
                //Add the padding
                for (int k = 0; k < padding; k++) 
                {
                    fputc(0x00, outptr);
                }
                
                if (x < n - 1)
                    fseek(inptr, -line, SEEK_CUR);
                
        }//end for "x"
    }//end for "i"

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
