// #include<stdio.h>
// #include<conio.h>
// #include<conio.h>

// int main()
// {
//     char username[15];
//     char password[10];

//     printf("\n Enter your username :");
//     scanf("%s", &username);
//     printf("\n Enter your password :");
//     scanf("%s", &password);

//     if(strcmp(username,"sohila")==0){
//         if(strcmp(password,"1234")==0){
//             printf("login successful");
//         }
//         else{
//         printf("\n wrong password");
//     }
//     }
//     else{
//         printf("\n user doesn't exist");
//     }

//     getch();
//     return 0 ;


// }

#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef union {
    int activeFlag;
} UserFlag;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    UserFlag flag;
} User;

User users[MAX_USERS];
int numUsers = 0;

void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;

    printf("Enter a username: ");
    scanf("%s", newUser.username);

    printf("Enter a password: ");
    scanf("%s", newUser.password);

    printf("Enter the active flag (true/1 or false/0): ");
    char flagStr[10];
    scanf("%s", flagStr);

    if (strcmp(flagStr, "true") == 0 || strcmp(flagStr, "1") == 0) {
        newUser.flag.activeFlag = 1;
    } else if (strcmp(flagStr, "false") == 0 || strcmp(flagStr, "0") == 0) {
        newUser.flag.activeFlag = 0;
    } else {
        printf("Invalid flag value. Setting the flag to false.\n");
        newUser.flag.activeFlag = 0;
    }

    users[numUsers++] = newUser;

    printf("Registration successful.\n");
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].flag.activeFlag) {
                printf("Login successful.\n");
            } else {
                printf("User is inactive. Login not allowed.\n");
            }
            return;
        }
    }

    printf("Invalid username or password.\n");
}

int main() {
    int choice;

    do {
        printf("\n1. Register\n");
        printf("2. Login\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}