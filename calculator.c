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
    printf("Addition result: %.2lf\n\n", result);
}

void subtract(double num1, double num2){
    double result = num1 - num2;
    printf("Subtraction result: %.2lf\n\n", result);
}


void userInput(){
    //run till exit encountered ( exit now: 3) ===> update with future addition of functionsz`
    while(1){
        
        printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
        printf("enter the operation to be performed: \n");
        printf("1.ADD\n");
        printf("2.Subtract\n");
        printf("3.exit\n");
      
        if(scanf("%i%c",&operationNum, &charOperationNum) != 2 || charOperationNum != '\n' ){
            printf("please enter a valid number");
            while (getchar() != '\n');
            continue;       
        }

        if(operationNum == 3){
            break;
        }
     
        //userPromt
        printf("enter your first number: ");
        numOneScan = scanf("%lf%c", &userNum1, &overFlowNum1);
    
        printf("enter your second number: ");
        numTwoScan = scanf("%lf%c", &userNum2, &overFlowNum2);
    
        //checking for values other than integer
        if (numOneScan != 2 || overFlowNum1 != '\n')
        {
            printf("please enter a valid number\n");
            while(getchar() != '\n');
            continue;
        }
        if (numTwoScan != 2 || overFlowNum2 != '\n')
        {
            printf("please enter a valid number\n");
            while(getchar()!='\n');
            continue;
        }
    
        //switch case for calc menu
        switch (operationNum)
        {
        case 1:
            add(userNum1, userNum2);
          
            break;
    
        case 2:
            subtract(userNum1, userNum2);
          
            break;
        default:
            break;
        }
    }
    
}
int main(){
    userInput();  
    return 0;
}