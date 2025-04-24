#include <stdio.h>


void userRegister(){
    
}
void userLogin(){

}


void userPrompt(){
    int selectedOption;
    char selectedOptionChar;
    while (1)
    {
        printf("1.Register\n");
        printf("2.login\n");
        printf("3.exit\n");
        printf("select an option: \n");
    
       
        if (scanf("%i%c", &selectedOption, &selectedOptionChar) != 2 || selectedOptionChar != '\n'){
            printf("please enter a valid option\n");
            while(getchar() != '\n');
            continue;
        }

        switch (selectedOption)
        {
        case 1:
           userRegister();
            break;
        case 2:
            userLogin();
            break;
        case 3:
            return;
            break;
        default:
            printf("please enter a valid number");
            break;
        }

        printf("selected Option: %i\n\n", selectedOption);
    }
    
    
}

int main(){
    userPrompt();
}