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

char loginUsername[20];
char loginPassword[10];

void userRegister(){
   
    if (userCount > MAX_USERS)
    {
        printf("Users limit reached!");
        return;
    }
    
    //for username
    printf("Set a userName: ");
    fgets(users[userCount].userName, sizeof(users[userCount].userName), stdin);
    users[userCount].userName[(strcspn(users[userCount].userName, "\n"))] = '\0';
    printf("\nusername: %s\n", users[userCount].userName);

    //for password
    printf("Set a Password: ");
    fgets(users[userCount].password, sizeof(users[userCount].password), stdin);
    users[userCount].password[(strcspn(users[userCount].password, "\n"))] = '\0';
    printf("\nPassword: %s\n", users[userCount].password);

    userCount++;

   
}
void userLogin(){
    //for username
    printf("Enter the userName: ");
    fgets(loginUsername, sizeof(loginUsername), stdin);
    loginUsername[strcspn(loginUsername, "\n")] = '\0';

    //for password
    printf("Enter the Password: ");
    fgets(loginPassword, sizeof(loginPassword), stdin);
    loginPassword[strcspn(loginPassword, "\n")] = '\0';

    int isAuthenticated = 0;

    for(int i = 0; i < userCount; i++){
        if(strcmp(users[i].userName, loginUsername) == 0 &&
                strcmp( users[i].password, loginPassword) == 0){
                    isAuthenticated = 1;
                    break;
        }
    }
    
    if(isAuthenticated){
        printf("You have logged in successfully!!\n\n");
    }else{
        printf("Wrong username or password\n\n");
    }

    // if (users[userCount].userName == loginUsername & users[userCount].password == loginPassword)
    // {
    //     
    // }else{
    //   
    // }
    
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
    }   
}

int main(){
    userPrompt();
}