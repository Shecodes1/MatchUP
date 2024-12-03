#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_USERS 50

//function prototypes
void displaytitle();
void createAccount(User users[], int* userCount);
void login(User users[], int userCount);

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;
    //login or create profile
    
        //login

        //create profile

        //once logged in
          //delete profile
          //edit preferences

          //view profiles
          //displays profiles
          //click "next"
          //send friend request 

    //create struct to store profiles - perhaps make dummy data of profiles
    //struct:
      //username
      //gaming platform 1
      //gaming platform 2
      //region (what country they live in)
      //types of games
      //favorite game
      
        

    //delete friend


int main() {
  //locally scope variables 

  //will be removed once hashing/login is added by Kailen
  User users[MAX_USERS] = {
      {"messycactus", "password1"},
      {"bob", "password2"},
      {"jenny", "password3"}
  };
  int userCount = 3;
  //will be removed 


  int selection; 

  do {
      displaytitle();
      printf("\tSelect your choice: ");
      scanf("%d", &selection);

      switch (selection) {
          case 1:
            createAccount(users, &userCount);
            break;
          case 2: 
            login(users, userCount);
            break;
          case 3:
            printf("\tGoodbye!\n");
            break;
          default: 
            printf("\tInvalid choice, please enter one of the options above.\n");
      }
  } while (selection != 3);
  

  return 0;  
}

void displaytitle(void) {
    printf("\t************************************************************************\n");
    printf("\t*                               MatchUP                                *\n");
    printf("\t*          A fun way to meet new friends and play video games          *\n");
    printf("\t************************************************************************\n");
    printf("\n");
    printf("\n");
    printf("\tSelect login or sign up to Begin:");
    printf("\n");
    printf("\t1. Sign up");
    printf("\t2. Login");
    printf("\t3. Exit");
    printf("\n");
}