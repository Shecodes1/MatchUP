#ifndef HASH_CONVERTER
#define HASH_CONVERTER

#include <stdio.h>
#include <openssl/evp.h>
#include <string.h>

void converter(const char *string, unsigned char *hash, unsigned int *length) {
    // Initialize the context for SHA-256
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new(); //Creates and stores a hashing algorithm  
    EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL); //Front: call "mdctx" to run the algorithm | Middle: Tells the type of hashing algorithm used | End: any additional configuration
    EVP_DigestUpdate(mdctx, string, strlen(string)); //First: calls the varible "mdctx" setted up for the algorithm, Middle: Calls the string [Password] to be hash by "mdctx", last asks for the length of the hash in which is the stringlength
    EVP_DigestFinal_ex(mdctx, hash, length); //Finalizes the hashing by creating a buffer which hash is the output of the hasher and which is the length 
    EVP_MD_CTX_free(mdctx); //frees the memory of mdctx
}


void printhash(unsigned char *input, unsigned int *length){
    // Print the hash in hexadecimal format
    for (unsigned int i = 0; i < length; i++) {
        printf("%02x", input[i]);
    }
    printf("\n");

    }

main(Input) {
    const char *password = Input;
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int length = 0;  // Initialize length as unsigned tells that the varible cannot be 0 

    // Call the converter function
    converter(password, hash, &length);

return 0;

}

#endif
