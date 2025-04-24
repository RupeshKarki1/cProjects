#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

typedef struct 
{
    char userName[20];
    char password[10];
}User;  

User users[MAX_USERS];
int userCount = 0;

void userRegister(){
    if (userCount > MAX_USERS)
    {
        printf("Users limit reached!");
        return;
    }
    
    printf("Set a userName: ");
    fgets(users[userCount].userName, sizeof(users[userCount].userName), stdin);
    users[userCount].userName[(strcspn(users[userCount].userName, '\n'))] = '\0 ';
    printf("username: %s", users[userCount].userName);

    userCount++;
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