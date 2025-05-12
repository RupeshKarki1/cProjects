#include <stdio.h>
#include <stdlib.h>

//defined at line 20->(change this as code updates) or "ctrl + click" the function name
void userPrompt();

int main(){
    
    // const char *str = "abc13";
    // char *end;

    // long result = strtol(str, &end, 0);
    // printf(" converted: %ld", result);
    // printf(" converted: %s", end);

    userPrompt();
    return 0;
}

void userPrompt(){
    long userInputLong;
    char *endPtrUserIn;
    char userInput[10];

    int userInputInt;
    printf("Please enter a number: ");

    //checking if userinput is int or not
    if (fgets(userInput, sizeof(userInput), stdin)) // returns 0 if no number
    {
        //storing the long return from strtol into userInputLong var
        userInputLong = strtol(userInput, &endPtrUserIn, 0); //0 is the base

        //if no conversion happens the endptr and userInput is same
        if(userInput == endPtrUserIn || *endPtrUserIn != '\n'){ /* userInput is treated as pointer because of 
                                                  decay to first element for arrays(search more if confused later on)*/
            printf("Not a valid number. \n");
            return;
        }
        userInputInt = (int) userInputLong;

        printf("you have entered number: %d", userInputInt);
    }
}