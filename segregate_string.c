#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char* extract_last_characters(char* source, int n) {
    char* destination = malloc((strlen(source) - n) * sizeof(char)); // Allocate memory for destination

    for (int i = n; i<strlen(source); i++){
        *(destination+i-n) = source[i];
    }

    *(destination + strlen(source) - n) = '\0';
    return destination; 
}

char* extract_first_characters(char* source, int n) {
    char* destination = malloc((n) * sizeof(char)); // Allocate memory for destination
    strncpy(destination, source, n); // Copy at most n characters
    destination[n] = '\0';
    return destination;
}

void segregate_string(char* pass2, char* mark){
    // set up
    char** msg1 = (char**)malloc(200*sizeof(char*)); //[i] save substrings
    char *temp = (char*)malloc(strlen(pass2)); // temporary
    strcpy(temp, pass2);  
    
    int i;
    // loop
    while(1){
        
        temp = strstr(temp, mark);
        
        if (temp == NULL) break;
        msg1[i] = (char*)malloc(strlen(temp)*sizeof(char));
        printf("-->`%s` with strlen = %d\n", temp, strlen(temp));
        printf("--\n");  
        strcpy(msg1[i], temp);
        temp[0] = 'n';
        printf("     `%s`|\n", msg1[i]);  
        printf("-------------------------------------------------------------------------------------\n");  
        i++;   
    } 
    printf("i = %d\n", i);
    free(msg1);
    free(temp);
}

char pass1[] = "to dye his pale skin, and as the day Charles spent lying on a branch of the great oak tree in Boscobel Wood as the Parliamentary soldiers scoured the forest floor below. Spencer draws out both the humour - such as the preposterous refusal of Charles’s friend Henry Wilmot to adopt disguise on the grounds that it was beneath his dignity - and the emotional tension when the secret of the king’s presence was cautiously revealed to his supporters";        
char pass2[] = "as if as though I do whatever as you prefer ";
char pass3[] = "asasasasto dye his  asle as skin, and as the day Charles asent lying on as a nch as of the great oak tree in Boscobel as ";  
int main(){
    segregate_string(pass3, "as");
    // char *msg1 = extract_first_characters(pass1, 20);
    // char *msg2 = extract_last_characters(pass1, 20);
    
    // // set up
    // char** msg1 = (char**)malloc(200*sizeof(char*));
    // char *temp = (char*)malloc(200);
    // strcpy(temp, pass2);

    // // loop
    // msg1[0] = (char*)malloc(strlen(temp)*sizeof(char));
    // temp = strstr(temp, "as");
    // printf("`%s` with strlen = %d", temp, strlen(temp));
    // strcpy(msg1[0], temp);
    // temp[0] = 'n';
    // printf("     `%s`|\n", msg1[0]);


    // msg1[1] = (char*)malloc(strlen(temp)*sizeof(char));
    // temp = strstr(temp, "as");
    // printf("`%s` with strlen = %d", temp, strlen(temp));
    // strcpy(msg1[1], temp);
    // temp[0] = 'n';  
    // printf("     `%s`|\n", msg1[1]);

    // msg1[2] = (char*)malloc(strlen(temp)*sizeof(char));
    // temp = strstr(temp, "as");
    // printf("`%s` with strlen = %d", temp, strlen(temp));
    // strcpy(msg1[2], temp);
    // temp[0] = 'n';  
    // printf("     `%s`|\n", msg1[2]);
}