#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_USERS 50
#define MAX_FRIENDS 10
#define MAX_REQUESTS 10

//Structs
    typedef struct {
        char nickname[MAX_LENGTH];
        char pronouns[MAX_LENGTH];
        char gamertags[2][MAX_LENGTH];
        char platforms[3][MAX_LENGTH];
        char favorite_games[3][MAX_LENGTH];
        char region[MAX_LENGTH];
        char game_types[3][MAX_LENGTH];
    } Profile;
    
    typedef struct {
        char username[MAX_LENGTH];
        char password[MAX_LENGTH];
        char email[MAX_LENGTH];
        char first_name[MAX_LENGTH];
        char last_name[MAX_LENGTH];
        Profile profile;
        int friendCount;
        int friendRequestsCount;
        char friends[MAX_FRIENDS][MAX_LENGTH];
        char friendRequests[MAX_REQUESTS][MAX_LENGTH];
    } User;

//function prototypes
    void displayTitle(void);
    void createAccount(User users[], int *userCount);
    void login(User users[], int userCount);
    void initializeFakeAccounts(User users[], int *userCount);
    int checkUser(User users[], char *username, char *email);
    void customizeProfile(User *user);
    void optionsMenu(User *user, User users[], int userCount);
    void friendsMenu(User *user, User users[], int userCount);
    void profileMenu(User *user, User users[], int userCount);
    void displayFriends(User *user);
    void addFriend(User *user, User users[], int userCount);
    void handleFriendRequests(User *user);

//main start
    int main() {
        User users[MAX_USERS];
        int userCount = 0;
        initializeFakeAccounts(users, &userCount);
    
        int selection;
        do {
            displayTitle();
            printf("\nSelect your choice: ");
            scanf("%d", &selection);
            while (getchar() != '\n'); // Clear the input buffer
            
            switch (selection) {
                case 1:
                    createAccount(users, &userCount);
                    break;
                case 2:
                      login(users, userCount);
                    break;
                case 3:
                    printf("Goodbye!\n");
                    break;
                default:
                    printf("Invalid choice, please enter one of the options above.\n");
            }
        } while (selection != 3);
    
        return 0;
    } //main end

// Function to check if the username or email already exists
    int checkUser(User users[], char *username, char *email) {
        for (int i = 0; i < MAX_USERS; i++) {
            if (username != NULL && strcmp(users[i].username, username) == 0) {
                return 1; //Username already exists
            }
            if (email != NULL && strcmp(users[i].email, email) == 0) {
                return 2; //Email already exists
            }
        }
        return 0; //no conflict
    }

// Title Page
    void displayTitle(void) {
        printf("\n");
        printf(" ███╗   ███╗ █████╗ ████████╗ ██████╗██╗  ██╗██╗   ██╗██████╗ \n");
        printf(" ████╗ ████║██╔══██╗╚══██╔══╝██╔════╝██║  ██║██║   ██║██╔══██╗\n");
        printf(" ██╔████╔██║███████║   ██║   ██║     ███████║██║   ██║██████╔╝\n");
        printf(" ██║╚██╔╝██║██╔══██║   ██║   ██║     ██╔══██║██║   ██║██╔═══╝ \n");
        printf(" ██║ ╚═╝ ██║██║  ██║   ██║   ╚██████╗██║  ██║╚██████╔╝██║     \n");
        printf(" ╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝     \n");
        printf("\n");
        printf("\t A fun way to meet new friends and play video games\n");
        printf("\n");
        printf("Select Login or Sign up to Begin: ");
        printf("\n   1. Sign up");
        printf("\n   2. Login");
        printf("\n   3. Exit\n");
    }

// Initialize Fake Accounts
    void initializeFakeAccounts(User users[], int *userCount) {
        const char *fakeUsernames[] = {"player1", "gamerX", "noobmaster", "proPlayer", "casualGamer"};
        const char *fakePasswords[] = {"pass1", "pass2", "pass3", "pass4", "pass5"};
        const char *fakeEmails[] = {"email1@game.com", "email2@game.com", "email3@game.com", "email4@game.com", "email5@game.com"};
        const char *fakeFirstNames[] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
        const char *fakeLastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones"};
        const char *fakeNicknames[] = {"Ace", "Shadow", "Rookie", "Champion", "Legend"};
    
        for (int i = 0; i < 5; i++) {
            strcpy(users[i].username, fakeUsernames[i]);
            strcpy(users[i].password, fakePasswords[i]);
            strcpy(users[i].email, fakeEmails[i]);
            strcpy(users[i].first_name, fakeFirstNames[i]);
            strcpy(users[i].last_name, fakeLastNames[i]);
    
            // Fake profile data
            strcpy(users[i].profile.nickname, fakeNicknames[i]);
            strcpy(users[i].profile.gamertags[0], "Gamertag1");
            strcpy(users[i].profile.gamertags[1], "Gamertag2");
            strcpy(users[i].profile.platforms[0], "PC");
            strcpy(users[i].profile.platforms[1], "Console");
            strcpy(users[i].profile.favorite_games[0], "Game1");
            strcpy(users[i].profile.favorite_games[1], "Game2");
            strcpy(users[i].profile.game_types[0], "RPG");
    
            users[i].friendCount = 0;
            users[i].friendRequestsCount = 0;
        }
        *userCount += 5;
    }

// Create Account
    void createAccount(User users[], int *userCount) {
        User newUser;
        int age, check;
    
        if (*userCount >= MAX_USERS) {
            printf("Sorry, the maximum user allowance has been reached. You cannot create a new account.\n");
            return;
        }
        
        printf("Enter your age: ");
        scanf("%d", &age);
        if (age < 18) {
            printf("You must be 18 or older to create an account.\n");
            return;
        } 
    
    printf("\nAccount Creation:");
    printf("\n - Enter your username: ");
    scanf("%s", newUser.username);
    check = checkUser(users, newUser.username, NULL);
    if (check == 1) {
        printf("This username already exists. Please try a different username.\n");
        return;
    }

    printf("- Enter your password: ");
    scanf("%s", newUser.password);
    
    printf("- Enter your email: ");
    scanf("%s", newUser.email);
    check = checkUser(users, NULL, newUser.email);
    if (check == 2) {
        printf("An account with this email already exists.\n");
        return;
    }

    printf("- Enter your first name: ");
    scanf("%s", newUser.first_name);
    while (getchar() != '\n'); // Clear the input buffer

    printf("- Enter your last name: ");
    scanf("%s", newUser.last_name);
    while (getchar() != '\n'); // Clear the input buffer

    users[*userCount] = newUser;
    (*userCount)++;

    printf("\nAccount created successfully. You must now customize your profile.\n");
    //customizeProfile(&users[*userCount - 1]); 
}

// Profile Customization
    void customizeProfile(User *user) {
        printf("\nCustomize your profile:\n");
        
        //Enter nickname/display name
        printf("- Enter your nickname/display name: ");
        scanf("%s", user->profile.nickname);
        while (getchar() != '\n'); // Clear the input buffer
    
        //Enter pronouns (optional)
        printf("- Enter your pronouns (optional, press enter to skip): ");
        getchar(); // Consume leftover newline
        fgets(user->profile.pronouns, MAX_LENGTH, stdin);
        if (user->profile.pronouns[strlen(user->profile.pronouns) - 1] == '\n') {
            user->profile.pronouns[strlen(user->profile.pronouns) - 1] = '\0'; // Remove newline
        }
    
        //Enter gamertags (at least 1 required, up to 2)
        printf("- Enter how many gamertags you wish to display (1-2): ");
        int gamertag_count;
        scanf("%d", &gamertag_count);
        while (getchar() != '\n'); // Clear the input buffer
        gamertag_count = gamertag_count < 1 ? 1 : (gamertag_count > 2 ? 2 : gamertag_count); // Ensure 1-2
        
            //For 1
            if (gamertag_count >= 1) {
                printf("    Gamertag 1: ");
                fgets(user->profile.gamertags[0], MAX_LENGTH, stdin);
                if (user->profile.gamertags[0][strlen(user->profile.gamertags[0]) - 1] == '\n') {
                    user->profile.gamertags[0][strlen(user->profile.gamertags[0]) - 1] = '\0'; // Remove newline
                }
            
                //If the first gamertag is empty, prompt again
                if (strlen(user->profile.gamertags[0]) == 0) {
                    printf("    At least one gamertag is required.\n");
                    printf("    Gamertag 1: ");
                    fgets(user->profile.gamertags[0], MAX_LENGTH, stdin);
                    if (user->profile.gamertags[0][strlen(user->profile.gamertags[0]) - 1] == '\n') {
                        user->profile.gamertags[0][strlen(user->profile.gamertags[0]) - 1] = '\0'; // Remove newline
                    }
                }
            }
    
            //For 2
            if (gamertag_count == 2) {
                printf("Gamertag 2: ");
                fgets(user->profile.gamertags[1], MAX_LENGTH, stdin);
            
                // Remove newline character if present
                if (user->profile.gamertags[1][strlen(user->profile.gamertags[1]) - 1] == '\n') {
                    user->profile.gamertags[1][strlen(user->profile.gamertags[1]) - 1] = '\0'; // Remove newline
                }
            
                // If the second gamertag is empty, allow it to be skipped
                if (strlen(user->profile.gamertags[1]) == 0) {
                    // No need to prompt again, simply leave it empty.
                    printf("Gamertag 2 is optional and has been skipped.\n");
                }
            } 
    
        // Enter platforms (up to 3)
        printf("\r- Enter how many platforms you wish to display (1-3): ");
        int platform_count;
        scanf("%d", &platform_count);
        while (getchar() != '\n'); // Clear the input buffer
        platform_count = platform_count < 1 ? 1 : (platform_count > 3 ? 3 : platform_count); // Ensure 1-3
        
        // For Platform 1
        if (platform_count >= 1) {
            printf("    Platform 1: ");
            fgets(user->profile.platforms[0], MAX_LENGTH, stdin);
            if (user->profile.platforms[0][strlen(user->profile.platforms[0]) - 1] == '\n') {
                user->profile.platforms[0][strlen(user->profile.platforms[0]) - 1] = '\0'; // Remove newline
            }
        
            // If the first platform is empty, prompt again
            if (strlen(user->profile.platforms[0]) == 0) {
                printf("\rAt least one platform is required.\n");
                printf("    Platform 1: ");
                fgets(user->profile.platforms[0], MAX_LENGTH, stdin);
                if (user->profile.platforms[0][strlen(user->profile.platforms[0]) - 1] == '\n') {
                    user->profile.platforms[0][strlen(user->profile.platforms[0]) - 1] = '\0'; // Remove newline
                }
            }
        }
        
        // For Platform 2
        if (platform_count >= 2) {
            printf("Platform 2: ");
            fgets(user->profile.platforms[1], MAX_LENGTH, stdin);
            if (user->profile.platforms[1][strlen(user->profile.platforms[1]) - 1] == '\n') {
                user->profile.platforms[1][strlen(user->profile.platforms[1]) - 1] = '\0'; // Remove newline
            }
        
            // If the second platform is empty, allow it to be skipped
            if (strlen(user->profile.platforms[1]) == 0) {
                // No need to prompt again, simply leave it empty
            }
        }
        
        // For Platform 3
        if (platform_count == 3) {
            
            printf("Platform 3: ");
            fgets(user->profile.platforms[2], MAX_LENGTH, stdin);
            if (user->profile.platforms[2][strlen(user->profile.platforms[2]) - 1] == '\n') {
                user->profile.platforms[2][strlen(user->profile.platforms[2]) - 1] = '\0'; // Remove newline
            }
            
            if (strlen(user->profile.platforms[2]) == 0) {
                // No need to prompt again, simply leave it empty
            }
        }
            
        // Enter favorite games (up to 3)
        printf("\r- Enter how many favorite games you wish to display (1-3): ");
        int favorite_game_count;
        scanf("%d", &favorite_game_count);
        while (getchar() != '\n'); // Clear the input buffer
        favorite_game_count = favorite_game_count < 1 ? 1 : (favorite_game_count > 3 ? 3 : favorite_game_count); // Ensure 1-3
        
        // For Favorite Game 1
        if (favorite_game_count >= 1) {
            printf("    Favorite game 1: ");
            fgets(user->profile.favorite_games[0], MAX_LENGTH, stdin);
            if (user->profile.favorite_games[0][strlen(user->profile.favorite_games[0]) - 1] == '\n') {
                user->profile.favorite_games[0][strlen(user->profile.favorite_games[0]) - 1] = '\0'; // Remove newline
            }
        
            // If the first favorite game is empty, prompt again
            if (strlen(user->profile.favorite_games[0]) == 0) {
                printf("\rAt least one favorite game is required.\n");
                printf("    Favorite game 1: ");
                fgets(user->profile.favorite_games[0], MAX_LENGTH, stdin);
                if (user->profile.favorite_games[0][strlen(user->profile.favorite_games[0]) - 1] == '\n') {
                    user->profile.favorite_games[0][strlen(user->profile.favorite_games[0]) - 1] = '\0'; // Remove newline
                }
            }
        }
        
        // For Favorite Game 2
        if (favorite_game_count >= 2) {
            printf("Favorite game 2: ");
            fgets(user->profile.favorite_games[1], MAX_LENGTH, stdin);
            if (user->profile.favorite_games[1][strlen(user->profile.favorite_games[1]) - 1] == '\n') {
                user->profile.favorite_games[1][strlen(user->profile.favorite_games[1]) - 1] = '\0'; // Remove newline
            }
        
            // If the second favorite game is empty, allow it to be skipped
            if (strlen(user->profile.favorite_games[1]) == 0) {
                // No need to prompt again, simply leave it empty
            }
        }
        
        // For Favorite Game 3
        if (favorite_game_count == 3) {
            printf("Favorite game 3: ");
            fgets(user->profile.favorite_games[2], MAX_LENGTH, stdin);
            if (user->profile.favorite_games[2][strlen(user->profile.favorite_games[2]) - 1] == '\n') {
                user->profile.favorite_games[2][strlen(user->profile.favorite_games[2]) - 1] = '\0'; // Remove newline
            }
        
            // If the third favorite game is empty, allow it to be skipped
            if (strlen(user->profile.favorite_games[2]) == 0) {
                // No need to prompt again, simply leave it empty
            }
        }
            
        // Enter game types (up to 3)
        printf("\r- Enter how many types of games you enjoy (1-3): ");
        int game_type_count;
        scanf("%d", &game_type_count);
        while (getchar() != '\n'); // Clear the input buffer
        game_type_count = game_type_count < 1 ? 1 : (game_type_count > 3 ? 3 : game_type_count); // Ensure 1-3
        
        //For Game Type 1
        if (game_type_count >= 1) {
            printf("    Game type 1: ");
            fgets(user->profile.game_types[0], MAX_LENGTH, stdin);
            if (user->profile.game_types[0][strlen(user->profile.game_types[0]) - 1] == '\n') {
                user->profile.game_types[0][strlen(user->profile.game_types[0]) - 1] = '\0'; // Remove newline
            }
        
            // If the first game type is empty, prompt again
            if (strlen(user->profile.game_types[0]) == 0) {
                printf("\rAt least one game type is required.\n");
                printf("    Game type 1: ");
                fgets(user->profile.game_types[0], MAX_LENGTH, stdin);
                if (user->profile.game_types[0][strlen(user->profile.game_types[0]) - 1] == '\n') {
                    user->profile.game_types[0][strlen(user->profile.game_types[0]) - 1] = '\0'; // Remove newline
                }
            }
        }
        
        // For Game Type 2
        if (game_type_count >= 2) {
            printf("Game type 2: ");
            fgets(user->profile.game_types[1], MAX_LENGTH, stdin);
            if (user->profile.game_types[1][strlen(user->profile.game_types[1]) - 1] == '\n') {
                user->profile.game_types[1][strlen(user->profile.game_types[1]) - 1] = '\0'; // Remove newline
            }
        
            // If the second game type is empty, allow it to be skipped
            if (strlen(user->profile.game_types[1]) == 0) {}
        }
        
        // For Game Type 3
        if (game_type_count == 3) {
            printf("Game type 3: ");
            fgets(user->profile.game_types[2], MAX_LENGTH, stdin);
            if (user->profile.game_types[2][strlen(user->profile.game_types[2]) - 1] == '\n') {
                user->profile.game_types[2][strlen(user->profile.game_types[2]) - 1] = '\0'; // Remove newline
            }
        
            // If the third game type is empty, allow it to be skipped
            if (strlen(user->profile.game_types[2]) == 0) {}
        }
                
        // Enter region (optional)
        printf("\r- Enter your region (optional, press enter to skip): ");
        fgets(user->profile.region, MAX_LENGTH, stdin);
        if (user->profile.region[strlen(user->profile.region) - 1] == '\n') {
            user->profile.region[strlen(user->profile.region) - 1] = '\0'; // Remove newline
        }
    
        printf("Profile setup complete!\n");
    }

// Options Menu
void optionsMenu(User *user, User users[], int userCount) {
    int choice;
    do {
        printf("\n\tOptions:\n");
        printf("\t1. Friends\n");
        printf("\t2. Profile\n");
        printf("\t3. Logout\n");
        printf("\tSelect an option: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the input buffer
        switch (choice) {
            case 1:
                friendsMenu(user, users, userCount);
                break;
            case 2:
                profileMenu(user, users, userCount);
                break;
            case 3:
                printf("\tLogging out...\n");
                break;
            default:
                printf("\tInvalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

// Friends Menu
void friendsMenu(User *user, User users[], int userCount) {
    int choice;
    do {
        printf("\n\tFriends:\n");
        printf("\t1. Display Friends\n");
        printf("\t2. Add Friend\n");
        printf("\t3. Friend Requests\n");
        printf("\t4. Go Back\n");
        printf("\tSelect an option: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the input buffer
        switch (choice) {
            case 1:
                displayFriends(user);
                break;
            case 2:
                addFriend(user, users, userCount);
                break;
            case 3:
                handleFriendRequests(user);
                break;
            case 4:
                return;
            default:
                printf("\tInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

// Display Friends
void displayFriends(User *user) {
    if (user->friendCount == 0) {
        printf("\tNo friends found.\n");
    } else {
        printf("\tYour friends:\n");
        for (int i = 0; i < user->friendCount; i++) {
            printf("\t- %s\n", user->friends[i]);
        }
    }
}

// Add Friend
void addFriend(User *user, User users[], int userCount) {
    char username[MAX_LENGTH];
    printf("\tEnter the username of the person you'd like to add: ");
    scanf("%s", username);
    while (getchar() != '\n'); // Clear the input buffer
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (user->friendRequestsCount < MAX_REQUESTS) {
                strcpy(users[i].friendRequests[users[i].friendRequestsCount], user->username);
                users[i].friendRequestsCount++;
                printf("\tFriend request sent to %s.\n", username);
                return;
            } else {
                printf("\t%s's friend request list is full. Unable to send request.\n", username);
                return;
            }
        }
    }
    printf("\tUser not found.\n");
}

// Handle Friend Requests
void handleFriendRequests(User *user) {
    if (user->friendRequestsCount == 0) {
        printf("\tNo friend requests.\n");
        return;
    }

    printf("\tFriend Requests:\n");
    for (int i = 0; i < user->friendRequestsCount; i++) {
        printf("\t%d. %s\n", i + 1, user->friendRequests[i]);
    }

    int choice;
    printf("\tSelect a friend request to respond to (or 0 to go back): ");
    scanf("%d", &choice);
    while (getchar() != '\n'); // Clear the input buffer
    if (choice > 0 && choice <= user->friendRequestsCount) {
        printf("\t%s wants to be friends with you.\n", user->friendRequests[choice - 1]);
        printf("\t1. Accept\n\t2. Deny\n\tSelect an option: ");
        int response;
        scanf("%d", &response);
        while (getchar() != '\n'); // Clear the input buffer
        if (response == 1) {
            if (user->friendCount < MAX_FRIENDS) {
                strcpy(user->friends[user->friendCount], user->friendRequests[choice - 1]);
                user->friendCount++;
                printf("\tFriend request accepted.\n");
            } else {
                printf("\tFriend list is full. Cannot accept new friends.\n");
            }
        } else {
            printf("\tFriend request denied.\n");
        }

        // Remove handled request
        for (int i = choice - 1; i < user->friendRequestsCount - 1; i++) {
            strcpy(user->friendRequests[i], user->friendRequests[i + 1]);
        }
        user->friendRequestsCount--;
    }
}

// Profile Menu
void profileMenu(User *user, User users[], int userCount) {
    int choice;
    do {
        printf("\n\tProfile:\n");
        printf("\t1. View My Profile\n");
        printf("\t2. Edit My Profile\n");
        printf("\t3. Delete My Account\n");
        printf("\t4. Go Back\n");
        printf("\tSelect an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\tUsername: %s\n", user->username);
                printf("\tNickname: %s\n", user->profile.nickname);
                printf("\tPronouns: %s\n", user->profile.pronouns);
                printf("\tRegion: %s\n", user->profile.region);
                // Add more fields as needed
                break;
            case 2:
                customizeProfile(user);
                break;
            case 3:
                printf("\tAccount deletion is not implemented yet.\n");
                break;
            case 4:
                return;
            default:
                printf("\tInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
}
