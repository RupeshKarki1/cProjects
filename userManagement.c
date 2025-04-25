#include <stdio.h>
#include <string.h>
#include <conio.h> //for getch() to hide pass

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

//to hide the password with *
void hidePassword(char *password, int maxLength){
    int index = 0;
    char ch;

    printf("Set a password: ");
    while (1)
    {
        ch = getch(); //gets a single char and doesnot display it
        if (ch == '\r')
        {
            password[index] = '\0';
            printf("\n");
            break;
        }else if (ch == '\b'){
            if(index > 0){
                index--;
                printf("\b \b");
            }
        }else if (index < maxLength - 1)
        {
            password[index++] = ch;
            printf(".");
        }      
    }
}

void saveUserData(){
    FILE *file = fopen("userData.txt", "w"); //opening file in write mode
    if (file == NULL)
    {
        printf("Error opening file \n.");
        return;
    }
    for (int i = 0; i < userCount; i++)
    {
        fprintf(file, "%s %s\n", users[i].userName,users[i].password);
    }
    
    fclose(file);

}

void loadUserData(){
    FILE *file = fopen("userData.txt", "r"); // in read mode
    if (file == NULL)
    {
        printf("No existing user data found. \n");
        return;
    }
    while (fscanf(file, "%s %s", users[userCount].userName, users[userCount].password) == 2)
    {
        userCount++;
        if (userCount >= MAX_USERS)
        {
            printf("Max users reached!!\n");
            break;
        }   
    }
    fclose(file);   
}

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
    hidePassword(users[userCount].password, sizeof(users[userCount].password));

    printf("registration successful for %s\n\n", users[userCount].userName);

    userCount++;   
    saveUserData();
}
void userLogin(){
    //for username
    printf("Enter the userName: ");
    fgets(loginUsername, sizeof(loginUsername), stdin);
    loginUsername[strcspn(loginUsername, "\n")] = '\0';

    //for password
    // printf("Enter the Password: ");
    // fgets(loginPassword, sizeof(loginPassword), stdin);
    // loginPassword[strcspn(loginPassword, "\n")] = '\0';

    hidePassword(loginPassword, sizeof(loginPassword));

    int isAuthenticated = 0;

    for(int i = 0; i < userCount; i++){
        if(strcmp(users[i].userName, loginUsername) == 0 &&
                strcmp( users[i].password, loginPassword) == 0){
                    isAuthenticated = 1;
                    break;
        }
    }
    
    if(isAuthenticated){
        printf("You have logged in successfully, %s!!\n\n", loginUsername);
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
    loadUserData();
    userPrompt();
    return 0;
}