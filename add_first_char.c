#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* add_first_char(char* s, char mark){
    // input
    //char mark;
    //char* s = "Hello world!";
    // process
    char* des = (char*)malloc(strlen(s));
    memmove(des+1, s,  strlen(s)+1);
    
    des[0] = mark;
    return des;
    free(des);
}

char pass1[] = "33 to dye his pale skin, and as the day Charles spent lying on a branch of the great oak tree in Boscobel Wood as the Parliamentary soldiers scoured the forest floor below. Spencer draws out both the humour - such as the preposterous refusal of Charles’s friend Henry Wilmot to adopt disguise on the grounds that it was beneath his dignity - and the emotional tension when the secret of the king’s presence was cautiously revealed to his supporters";        
int main() {
    char *msg = add_first_char("asasasto dye his asle as skin, and as the day Charles asent lying on as a branch as of the great asoak tree in as Boscobel as", '|');
    printf("`%s`\n", msg);
    msg = add_first_char("hello", '|');
    printf("`%s`\n", msg);

    return 0;
}
