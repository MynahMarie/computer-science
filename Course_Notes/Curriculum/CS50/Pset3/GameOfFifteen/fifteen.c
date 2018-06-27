/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void init(void)
{
    // Initialize the size of the array to (d*d)-1 and the variables used for row and column.
    int arr_len = (d*d)-1;
    int i, j;
    
    while (arr_len >= 0) {
        
        for (i = 0; i < d; i++) {
            for (j = 0; j < d; j++) {
                
            // If size of array is even number, no swaping is necessary.    
                    board[i][j] = arr_len;
                    arr_len--;
            }
        }
    }
    //If arr_len is an odd number, swap the last 2 numbers.
    
    if (d % 2 == 0) {
            
            board[d-1][d-3] = 1;
            board[d-1][d-2] = 2;
        }
    
}

/**
 * Prints the board in its current state.
 */
 
void draw(void)
{
    
    int i, j;
    
    printf("\n\n");
        
        for (i = 0; i < d; i++) {
            for (j = 0; j < d; j++) {
            
                if (board[i][j] == 0)
                    printf("|  * |"); //Chose a star as my symbole representing 0.
                else
                    printf("| %2i |", board[i][j]);
            }
            
            printf("\n");
        } 
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int i, j;
    int temp;
    
    //Find the index of the tile inputed by the user.
    
    for (i = 0; i < d; i++) {
        for (j = 0; j < d; j++) {
            
            if (board[i][j] == tile) {
                
            //Go through each 4 possible cases and swap accordingly.
                
                if (i > 0 && board[i-1][j] == 0) {
                    
                    temp = board[i][j];
                    board[i][j] = board[i-1][j];
                    board[i-1][j] = temp;
                    
                    return true;
                    
                }
                else if (i < d-1 && board[i+1][j] == 0) {
                    
                    temp = board[i][j];
                    board[i][j] = board[i+1][j];
                    board[i+1][j] = temp;
                    
                    return true;
                    
                }
                else if (j > 0 && board[i][j-1] == 0) {
                    
                    temp = board[i][j];
                    board[i][j] = board[i][j-1];
                    board[i][j-1] = temp;
                    
                    return true;
                    
                }
                else if (j < d-1 && board[i][j+1] == 0) {
                    
                    temp = board[i][j];
                    board[i][j] = board[i][j+1];
                    board[i][j+1] = temp;
                    
                    return true;
                }
            }
            
        }
    }
    
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // Iterate through the board with nested for loops and make sure 
    // the numbers are sorted in ascending order.
    // Initialize a variable counter to compare each tile with.
    
    int arr_len = (d*d) - 1;
    int counter = 1;
    int i, j;
        
    for (i = 0; i < d; i++) {
        for (j = 0; j < d; j++) {
            
            //Return false if the counter and the tile don't match.    
            if (board[i][j] != counter && counter != arr_len) {
                   
                return false;
                    
            }
            else
                if (board[i][j] != arr_len) //Continue iteration as long as we don't reach the last value.
                    counter++;
                else
                    break; //If the last tile before the star is reached and the tile is equal to 
                           // the counter, beark out of the loop and declare the game as won.
            }
        }
        
    return true;    
}


