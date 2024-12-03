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
    char email[MAX_LENGTH];
    char first_name[MAX_LENGTH];
    char last_name[MAX_LENGTH];
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
      {"messycactus", "password1", "email@email.com", "megan", "stone"},
      {"bob", "password2", "email2@email.com", "bob", "thebuilder"},
      {"jenny", "password3", "email3@email.com", "jenny", "fromtheblock"}
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

int checkUser(User users[], char* username, char* email) { //error
  for (int i = 0; i < MAX_USERS; i++) {
      if (strcmp(users[i].username, username) == 0) {
          return 1;
      }
      if (strcmp(users[i].email, email) == 0) {
          return 2;
      }
      return 0; 
      }
  }

void createAccount(userCount) { //error
  User newuser;
  int check;

  if (userCount >= MAX_USERS) {
    printf("\tSorry, the maximum user allowance has been reached. You cannot create a new account.\n");
    return;
  }

  printf("\tEnter your username: \n");
  scanf("%s", newuser.username);
  check = checkUser(userCount, newuser.username, NULL);
  if (check == 1) {
      printf("This username already exists. Please log in with your username and password or try a different username.\n");
      return;
  }

  printf("\tEnter your password: \n");
  scanf("%s", newuser.password);

  printf("\tEnter your email address: \n");
  scanf("%s", newuser.email);
  check = checkUser(userCount,NULL, newuser.email);
  if (check == 2) {
    printf("There is an account already associated with this email. Please use your username and password to login or use a different email.\n");
    return; 
  }

  printf("\tEnter your first name: \n");
  scanf("%s", newuser.first_name);
  printf("\tEnter your last name: \n");
  scanf("%s", newuser.last_name);


  printf("Account created successfully. Welcome to MatchUP!\n");
}