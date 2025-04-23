#include <stdio.h>
#include <stdlib.h> // this provides the rand() method for random numbers
#include <time.h>

int randNum; //global variables are initialized before the program starts
int userNum;
int totalGuess = 0;
char leftOver; //for checking char in userInput

int numCheck(int computerNum) {
    while (totalGuess < 5)
    {
        printf("Enter a number betn 1 and 10: ");    
        if(scanf("%i%c", &userNum, &leftOver) != 2 || leftOver != '\n'){ //takes user input *before any spaces (leftover var checks enter pressed)
            printf("invalid input! \n\n");
            while(getchar() != '\n'); //discard invalid input (buffer clear)
            continue;
        } 

        if (userNum > 10 || userNum < 1)
        {
            printf("please enter correct number\n\n");
            continue;
        }
        
        if (userNum > computerNum)
        {
            totalGuess++;
            printf("The guessed number is higher \n");
            printf("Total guess: %i \n\n", totalGuess);
            
        }else if (userNum < computerNum)
        {
            totalGuess++;
            printf("The guessed number is lower \n");
            printf("Total guess: %i \n\n", totalGuess);
            
        }else {
            printf("You have guessed the right number!! \n");
            return 0;    
        }
    }  
}

int main() {
    //generating random number
    srand(time(NULL));
    randNum = (rand() % 10 + 1);

    numCheck(randNum);
    printf("random number: %i \n userNum: %i", randNum, userNum);
}
