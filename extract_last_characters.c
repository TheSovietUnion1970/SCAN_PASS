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
char pass1[] = "to dye his pale skin, and as the day Charles spent lying on a branch of the great oak tree in Boscobel Wood as the Parliamentary soldiers scoured the forest floor below. Spencer draws out both the humour - such as the preposterous refusal of Charles’s friend Henry Wilmot to adopt disguise on the grounds that it was beneath his dignity - and the emotional tension when the secret of the king’s presence was cautiously revealed to his supporters";        
char pass2[] = "asasasasto dye his  asle as skin, and as the day Charles asent lying on as a nch as of the great oak tree in Boscobel as ";
int main(){
    char* msg;
    msg = extract_last_characters(pass2, 2);
    printf("`%s`\n", msg);
}