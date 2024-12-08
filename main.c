#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

// gcc needs both -lcjson and -lcurl flags to compile as well as their associated libraries which can be installed with the following commands in linux:
//sudo apt install libcurl4-openssl-dev
//sudo apt install libcjson1 libcjson-dev


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

// API functions and variables

int createUser(char username, char password, char firstname, char lastname, char email); // User creation

size_t write_callback(void *ptr, size_t size, size_t nmemb, char *data); // Assisting function to user and profile reading
void extract_values_user(const char *response_data); // Assisting function to user reading
int readUser(char username); // User reading

int createProfile(char username, char favoritegame, char gamertag, char platform, char region); // Profile creation

void extract_values_profile(const char *response_data); // Assisting function to user reading
int readProfile(char username); // Profile reading

// Variables to store response values from user read
char response_username_val[256] = {0};
char response_password_val[256] = {0};
char response_firstname_val[256] = {0};
char response_lastname_val[256] = {0};
char response_email_val[256] = {0};

// Variables to store response values from profile read
char response_favoritegame_val[256] = {0};
char response_gamertag_val[256] = {0};
char response_platform_val[256] = {0};
char response_region_val[256] = {0};

// Variables for user creation with example inputs
const char *username = "tester24";
const char *password = "password";
const char *firstname = "tester";
const char *lastname = "testington";
const char *email = "email@testing";

// Variables for profile creation
const char *favoritegame = "favoritegame";
const char *gamertag = "besttester";
const char *platform = "PC";
const char *region = "NA";

// End of API functions and variables

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
    printf("\n");
        printf(" ███╗   ███╗ █████╗ ████████╗ ██████╗██╗  ██╗██╗   ██╗██████╗ \n");
        printf(" ████╗ ████║██╔══██╗╚══██╔══╝██╔════╝██║  ██║██║   ██║██╔══██╗\n");
        printf(" ██╔████╔██║███████║   ██║   ██║     ███████║██║   ██║██████╔╝\n");
        printf(" ██║╚██╔╝██║██╔══██║   ██║   ██║     ██╔══██║██║   ██║██╔═══╝ \n");
        printf(" ██║ ╚═╝ ██║██║  ██║   ██║   ╚██████╗██║  ██║╚██████╔╝██║     \n");
        printf(" ╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝     \n");
        printf("\n");
    printf("\t         A fun way to meet new friends and play video games          \n");
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




// API functions:
int createUser(char username, char password, char firstname, char lastname, char email) { // This function is to create a user using the inputs of username, password, firstname, lastname, and email
    CURL *curl;
    CURLcode res;

    char json_data[1024]; // Allocate memory for the JSON string (enough to hold the entire structure)

    // Create the JSON data to be sent with the username
    snprintf(json_data, sizeof(json_data),
             "{\"operation\": \"create\", \"payload\": {\"Item\": {\"username\": \"%s\", \"password\": \"%s\", \"firstname\": \"%s\", \"lastname\": \"%s\", \"email\": \"%s\"}}}",
             username, password, firstname, lastname, email);

  
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init(); // Initialize libcurl

    if (curl) {
       curl_easy_setopt(curl, CURLOPT_URL, "https://1mr9ktlyv9.execute-api.us-east-2.amazonaws.com/test2/user"); // Set URL of the API

        curl_easy_setopt(curl, CURLOPT_POST, 1L); // Set type to POST
        
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data); // Set the data to send with the JSON block created above

        // Set the content type header for JSON data
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            
        res = curl_easy_perform(curl); // Perform the request

        // Errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Clean up the data
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    // Global cleanup
    curl_global_cleanup();

    return 0;
}

int readUser(char username) { // This function takes in a username input and stores the  assoicated username, password, firstname, lastname, and email in the associated response variables
    CURL *curl;
    CURLcode res;

    
    char json_data[1024]; // Allocate memory for the JSON string (enough to hold the entire structure)

    // Create the JSON data to be sent with the username
    snprintf(json_data, sizeof(json_data),
            "{\"operation\": \"read\", \"payload\": {\"Key\": {\"username\": \"%s\"}}}",
            username);
                
    // Allocate memory for the response data
    char response_data[2048] = {0}; // Make the buffer empty by default

    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init(); // Initialize libcurl

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://1mr9ktlyv9.execute-api.us-east-2.amazonaws.com/test2/user"); // Set URL of the API

        curl_easy_setopt(curl, CURLOPT_POST, 1L); // Set type to POST
        
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data); // Set the data to send with the JSON block created above

        // Set the content type header for JSON data
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            
        // Set the callback function to handle the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_data); // Specify where the response will go

        res = curl_easy_perform(curl); // Perform the request

        // Errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else { 
            printf("Response data: %s\n", response_data); // Print the response for error tracking, can be commented out
                        
            extract_values_user(response_data); // Extract the values in the response from the "Item" section of the response
        }

        // Clean up the data
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup(); // Global cleanup

    return 0;
}

size_t write_callback(void *ptr, size_t size, size_t nmemb, char *data) {
    size_t total_size = size * nmemb;
    strncat(data, ptr, total_size); // Put the response data in the buffer
    return total_size;
}

void extract_values_user(const char *response_data) {

    // Parse the response data as JSON
    cJSON *root = cJSON_Parse(response_data);
    if (root == NULL) { // Error handling
        printf("Error parsing JSON\n");
        return;
    }

    cJSON *item = cJSON_GetObjectItem(root, "Item"); // Extract the "Item" object
    if (item == NULL) { // Error handling
        printf("No 'Item' found in JSON\n");
        cJSON_Delete(root); // Data cleanup
        return;
    }

    // Extract and store values from the "Item" section into variables
    cJSON *current_item = NULL; // Make a pointer for the current item
    cJSON_ArrayForEach(current_item, item) {
        const char *key = current_item->string;  // The key of the current item
        
        if (strcmp(key, "username") == 0 && cJSON_IsString(current_item)) { // Extract username
            strcpy(response_username_val, current_item->valuestring);
        } else if (strcmp(key, "password") == 0 && cJSON_IsString(current_item)) { // Extract password
            strcpy(response_password_val, current_item->valuestring);
        } else if (strcmp(key, "firstname") == 0 && cJSON_IsString(current_item)) { // Extract first name
            strcpy(response_firstname_val, current_item->valuestring);
        } else if (strcmp(key, "lastname") == 0 && cJSON_IsString(current_item)) { // Extract last name
            strcpy(response_lastname_val, current_item->valuestring);
        } else if (strcmp(key, "email") == 0 && cJSON_IsString(current_item)) { // Extract email
            strcpy(response_email_val, current_item->valuestring);
        }
    }

    /* Print values of response for error checking
    printf("username: %s\n", response_username_val[0] != '\0' ? response_username_val : "Not available");
    printf("password: %s\n", response_password_val[0] != '\0' ? response_password_val : "Not available");
    printf("firstname: %s\n", response_firstname_val[0] != '\0' ? response_firstname_val : "Not available");
    printf("lastname: %s\n", response_lastname_val[0] != '\0' ? response_lastname_val : "Not available");
    printf("email: %s\n", response_email_val[0] != '\0' ? response_email_val : "Not available");
    */
    
    cJSON_Delete(root); // Clean up data
}

int createProfile(char username, char favoritegame, char gamertag, char platform, char region) {
    CURL *curl;
    CURLcode res;

    char json_data[1024]; // Allocate memory for the JSON string (enough to hold the entire structure)

    // Create the JSON data to be sent with the username
    snprintf(json_data, sizeof(json_data),
             "{\"operation\": \"create\", \"payload\": {\"Item\": {\"username\": \"%s\", \"favoritegame\": \"%s\", \"gamertag\": \"%s\", \"platform\": \"%s\", \"region\": \"%s\"}}}",
             username, favoritegame, gamertag, platform, region);

  
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init(); // Initialize libcurl

    if (curl) {
       curl_easy_setopt(curl, CURLOPT_URL, "https://1mr9ktlyv9.execute-api.us-east-2.amazonaws.com/test2/profile"); // Set URL of the API

        curl_easy_setopt(curl, CURLOPT_POST, 1L); // Set type to POST
        
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data); // Set the data to send with the JSON block created above

        // Set the content type header for JSON data
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            
        res = curl_easy_perform(curl); // Perform the request

        // Errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Clean up the data
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    // Global cleanup
    curl_global_cleanup();

    return 0;
}

int readProfile(char username) { // This function takes in a username input and stores the assoicated username, favoritegame, gamertag, platform, and region in the associated response variables
    CURL *curl;
    CURLcode res;
    
    char json_data[1024]; // Allocate memory for the JSON string (enough to hold the entire structure)

    // Create the JSON data to be sent with the username
    snprintf(json_data, sizeof(json_data),
            "{\"operation\": \"read\", \"payload\": {\"Key\": {\"username\": \"%s\"}}}",
            username);
                
    // Allocate memory for the response data
    char response_data[2048] = {0}; // Make the buffer empty by default

    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init(); // Initialize libcurl

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://1mr9ktlyv9.execute-api.us-east-2.amazonaws.com/test2/profile"); // Set URL of the API

        curl_easy_setopt(curl, CURLOPT_POST, 1L); // Set type to POST
        
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data); // Set the data to send with the JSON block created above

        // Set the content type header for JSON data
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            
        // Set the callback function to handle the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_data); // Specify where the response will go

        res = curl_easy_perform(curl); // Perform the request

        // Errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else { 
            printf("Response data: %s\n", response_data); // Print the response for error tracking, can be commented out
                        
            extract_values_user(response_data); // Extract the values in the response from the "Item" section of the response
        }

        // Clean up the data
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup(); // Global cleanup

    return 0;
}

void extract_values_profile(const char *response_data) {

    // Parse the response data as JSON
    cJSON *root = cJSON_Parse(response_data);
    if (root == NULL) { // Error handling
        printf("Error parsing JSON\n");
        return;
    }

    cJSON *item = cJSON_GetObjectItem(root, "Item"); // Extract the "Item" object
    if (item == NULL) { // Error handling
        printf("No 'Item' found in JSON\n");
        cJSON_Delete(root); // Data cleanup
        return;
    }

    // Extract and store values from the "Item" section into variables
    cJSON *current_item = NULL; // Make a pointer for the current item
    cJSON_ArrayForEach(current_item, item) {
        const char *key = current_item->string;  // The key of the current item
        
        if (strcmp(key, "username") == 0 && cJSON_IsString(current_item)) { // Extract username
            strcpy(response_username_val, current_item->valuestring);
        } else if (strcmp(key, "favoritegame") == 0 && cJSON_IsString(current_item)) { // Extract favoritegame
            strcpy(response_favoritegame_val, current_item->valuestring);
        } else if (strcmp(key, "gamertag") == 0 && cJSON_IsString(current_item)) { // Extract first name
            strcpy(response_gamertag_val, current_item->valuestring);
        } else if (strcmp(key, "platform") == 0 && cJSON_IsString(current_item)) { // Extract last name
            strcpy(response_platform_val, current_item->valuestring);
        } else if (strcmp(key, "region") == 0 && cJSON_IsString(current_item)) { // Extract region
            strcpy(response_region_val, current_item->valuestring);
        }
    }

    /* Print values of response for error checking
    printf("username: %s\n", response_username_val[0] != '\0' ? response_username_val : "Not available");
    printf("favoritegame: %s\n", response_favoritegame_val[0] != '\0' ? response_favoritegame_val : "Not available");
    printf("gamertag: %s\n", response_gamertag_val[0] != '\0' ? response_gamertag_val : "Not available");
    printf("platform: %s\n", response_platform_val[0] != '\0' ? response_platform_val : "Not available");
    printf("region: %s\n", response_region_val[0] != '\0' ? response_region_val : "Not available");
    */
    
    cJSON_Delete(root); // Clean up data
}


// End of API functions