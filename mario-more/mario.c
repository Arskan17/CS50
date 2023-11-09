#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size;

    //gets the size of the pyramid to be printed..
    //in case the user enters anything other than integers ranging from 1 to 8, they get prompted to reenter.
    do
    {
        size = get_int ("Height? ");
    }
    while((size < 1) || (size > 8));

    //Prins each row
    for (int i = 1; i <= size; i++)
        {
            //Prints the spaces, Bricks, two spaces and then the last brick(s)

            for (int i1 = 1; i1 <= (size - i); i1++)
            {
                printf(" ");
            }

            for (int j = 1; j <= i; j++)
            {
                printf("#");
            }

            printf("  ");

            for (int k = 1; k <= i; k++)
            {
                printf("#");
            }

            printf("\n");
        }
        //stops the program at the end of the printing
        return 1;
}