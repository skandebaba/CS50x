/*
 *  A simple program which asks the user how much change is owed
 *  and then spits out the minimum number of coins with which said 
 *  change can be made
 *
 *	Full specifications can be found at:
 *  http://d2o9nyf4hwsci4.cloudfront.net/2013/fall/psets/1/pset1/pset1.html
 *
 *  Written by Johann Nel
 */
 
#include <cs50.h>
#include <math.h>
#include <stdio.h>
 
int main(void)
{
    float   change_req;
    int     cents;
    int     min_coins = 0;
    
    printf("Oh hai! How much change is owed? ");
    
    /*
     *  Keep on prompting the user how much change is required
     *  Will break out of loop once an amount greater than 0 is specified
     */
    for (;;)
    {
        change_req = GetFloat();
            
        if (change_req > 0)
            break;
        
        printf("How much change is owed?\n");
    }
    
    // Convert the change required to cents and round
    change_req *= 100;
    cents = (int)round(change_req);
    
    /*  
     *  A loop to determine the minimum amount of coins required 
     *  It will first keep on deducting 25c from amount before moving 
     *  on the next amount
     *  Each time a certain amount is deducted it will increment min_coins
     */
    while (cents > 0)
    {
        while (cents >= 25)
        {
            cents -= 25;
            min_coins++;
        }
        
        while (cents >= 10)
        {
            cents -= 10;
            min_coins++;
        }
        
        while (cents >= 5)
        {
            cents -= 5;
            min_coins++;
        }
        
        while (cents >= 1)
        {
            cents -= 1;
            min_coins++;
        }
    }
    
    printf("%d\n", min_coins);
}