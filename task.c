#include<stdio.h>
#include<conio.h>
#include<conio.h>

int main()
{
    char username[15];
    char password[10];

    printf("\n Enter your username :");
    scanf("%s", &username);
    printf("\n Enter your password :");
    scanf("%s", &password);

    if(strcmp(username,"sohila")==0){
        if(strcmp(password,"1234")==0){
            printf("login successful");
        }
        else{
        printf("\n wrong password");
    }
    }
    else{
        printf("\n user doesn't exist");
    }

    getch();
    return 0 ;


}