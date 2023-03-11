#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char** argv){
    if (fopen("./test.txt","r") != NULL){
        printf("Warning file \"test.txt\" is going to be overwritten, press Ctrl + C to exit the program and prevent this from occuring.\n");
    }
    printf("Hello there please enter a message to be written to test.txt:\n");
    char* userinput = malloc(sizeof(char) * 1);
    int i = 0;
    char* msgchar;
    while((msgchar = getc(stdin)) && msgchar != '\n'){
        userinput[i] = msgchar;
        i++;
        realloc(userinput,i * sizeof(char));

    }
    userinput[i + 1] = '\n';
    userinput[i + 2] = '\0';
    FILE* testfile = fopen("./test.txt","wb");
    fprintf(testfile,userinput);
    fclose(testfile);
    free(userinput);
    return 0;
}