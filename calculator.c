#include <stdio.h>

//global variables
double userNum1;
double userNum2;

int numOneScan;
int numTwoScan;

char overFlowNum1;
char overFlowNum2;

int operationNum;
char charOperationNum;
//function for operations

//add
void add(double num1, double num2){   
    double result = num1 + num2;
    printf("Addition result: %lf", result);
}

void subtract(double num1, double num2){
    double result = num1 - num2;
    printf("Addition result: %lf", result);
}

void exitFunc(){

}

void userInput(){
    printf("enter the operation to be performed: ");
    int operation = scanf("%i", &charOperationNum);


    printf("enter your first number: ");
    numOneScan = scanf("%lf%c", &userNum1, &overFlowNum1);

    printf("enter your second number: ");
    numTwoScan = scanf("%lf%c", &userNum2, &overFlowNum2);

    
}
int main(){
    userInput();
    if (numOneScan != 2 || overFlowNum1 != '\n')
    {
        printf("please enter a valid number\n");
    }
    if (numTwoScan != 2 || overFlowNum2 != '\n')
    {
        printf("please enter a valid number\n");
    }
    add(userNum1, userNum2);
    return 0;
}