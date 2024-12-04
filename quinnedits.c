#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_USERS 50

//structs
    typedef struct {
        char username[MAX_LENGTH];
        char password[MAX_LENGTH];
        char email[MAX_LENGTH];
        char first_name[MAX_LENGTH];
        char last_name[MAX_LENGTH];
    } User;

//function prototypes
    void displayTitle(void);
    void createAccount(User users[], int *userCount);
    void login(User users[], int userCount);
    int checkUser(User users[], char *username, char *email);

//main start
    int main() {
        // to be removed
        User users[MAX_USERS] = {
            {"messycactus", "password1", "email@email.com", "megan", "stone"},
            {"bob", "password2", "email2@email.com", "bob", "thebuilder"},
            {"jenny", "password3", "email3@email.com", "jenny", "fromtheblock"}
        };
        int userCount = 3; //initial user count
    
        int selection;
    
        do {
            displayTitle();
            printf("\t Select your choice: ");
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
    } //main end

// title (complete)
    void displayTitle(void) {
        printf("\n");
        printf(" ███╗   ███╗ █████╗ ████████╗ ██████╗██╗  ██╗██╗   ██╗██████╗ \n");
        printf(" ████╗ ████║██╔══██╗╚══██╔══╝██╔════╝██║  ██║██║   ██║██╔══██╗\n");
        printf(" ██╔████╔██║███████║   ██║   ██║     ███████║██║   ██║██████╔╝\n");
        printf(" ██║╚██╔╝██║██╔══██║   ██║   ██║     ██╔══██║██║   ██║██╔═══╝ \n");
        printf(" ██║ ╚═╝ ██║██║  ██║   ██║   ╚██████╗██║  ██║╚██████╔╝██║     \n");
        printf(" ╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝     \n");
        printf("\n");
        printf("\t A fun way to meet new friends and play video games  \n");
        printf("\n");
        printf("\t Select login or sign up to Begin:\n");
        printf("\t 1. Sign up\n");
        printf("\t 2. Login\n");
        printf("\t 3. Exit\n");
    }

//check if user is created
    int checkUser(User users[], char *username, char *email) {
        for (int i = 0; i < MAX_USERS; i++) {
            if (username && strcmp(users[i].username, username) == 0) {
                return 1; //username exists
            }
            if (email && strcmp(users[i].email, email) == 0) {
                return 2; //email exists
            }
        }
        return 0; //neither exists
    }

//create new account
void createAccount(User users[], int *userCount) {
    User newUser;
    int check;
    
    //if max user limit hit
    if (*userCount >= MAX_USERS) {
        printf("\t Sorry, the maximum user allowance has been reached. You cannot create a new account.\n");
        return;
    }
    
    //create username
    printf("\t Enter your username: ");
    scanf("%s", newUser.username);
    check = checkUser(users, newUser.username, NULL);
    if (check == 1) {
        printf("\t This username already exists. Please log in with your username and password or try a different username.\n");
        return;
    }
    
    //create password
    printf("\t Enter your password: ");
    scanf("%s", newUser.password);
    
    //enter email
    printf("\t Enter your email address: ");
    scanf("%s", newUser.email);
    check = checkUser(users, NULL, newUser.email);
    if (check == 2) {
        printf("\t There is an account already associated with this email. Please use your username and password to login or use a different email.\n");
        return;
    }
    
    //enter first and last name
    printf("\t Enter your first name: ");
    scanf("%s", newUser.first_name);

    printf("\t Enter your last name: ");
    scanf("%s", newUser.last_name);

    users[*userCount] = newUser; //add new user to array
    (*userCount)++; //increase user counter

    printf("\t Account created successfully. Welcome to MatchUP!\n");
}

//login
    void login(User users[], int userCount) {
        char username[MAX_LENGTH], password[MAX_LENGTH];
        int found = 0;
    
        printf("\t Enter your username: ");
        scanf("%s", username);
    
        printf("\t Enter your password: ");
        scanf("%s", password);
    
    //logging in
        for (int i = 0; i < userCount; i++) {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                printf("\t Login successful. Welcome back, %s!\n", users[i].first_name);
                found = 1;
                break;
            }
        }
    
    //if not found
        if (!found) {
            printf("\t Invalid username or password. Please try again.\n");
        }
}
