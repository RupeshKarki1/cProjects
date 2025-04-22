#include <stdio.h>
#include <stdlib.h> // this provides the rand() method for random numbers
#include <time.h>

int randNum; //global variables are initialized before the program starts
int userNum;

int main() {
    srand(time(NULL));
    randNum = (rand() % 10 + 1);
    printf("Enter a number betn 1 and 10: ");
    scanf("%i", &userNum);
    printf("random number: %i \n userNum: %i", randNum, userNum);
}

int numCheck(guessNum, computerNum) {
    
}