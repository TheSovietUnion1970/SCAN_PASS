#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char* add_first_char(char* s, char mark){

    char* des = (char*)malloc(strlen(s) + 2);
    memmove(des+1, s,  strlen(s)+1);
    
    des[0] = mark;
    return des;
    free(des);
}

char* extract_last_characters(char* source, int n) {
    char* destination = malloc((strlen(source) - n + 1) * sizeof(char)); // Allocate memory for destination

    for (int i = n; i<strlen(source); i++){
        *(destination+i-n) = source[i];
    }

    *(destination + strlen(source) - n) = '\0';
    return destination; 
}

char* extract_first_characters(char* source, int n) {
    char* destination = malloc((n + 1) * sizeof(char)); // Allocate memory for destination
    strncpy(destination, source, n); // Copy at most n characters
    destination[n] = '\0';
    return destination;
}

char* segregate_string_mark_half(char* pass2, char* mark){
    // set up
    //int len0 = strlen(pass)+1;
    //*pass2 = (char*)malloc(500); // pass2
    char** msg = (char**)malloc(200*sizeof(char*)); //[i] save substrings
    char *temp = (char*)malloc(strlen(pass2)+1); // temporary
    int *list = malloc(200*sizeof(int)); // minus
    int *list2 = malloc(200*sizeof(int)); // minus
    strcpy(temp, pass2); 
    int num=0, len1=0; 
    
    int i=0, num_first, num_last;
    // loop
    while(1){
        
        temp = strstr(temp, mark);
        //len1 = strlen(temp);
        
        if (temp == NULL) break;
        
        msg[i] = (char*)malloc((strlen(temp)+1)*sizeof(char)); // +1 --> null terminator
        len1 = strlen(temp);
        list[i]=len1;
        printf("-->`%s` with len1 = %d, %d with len bew = %d, i = %d\n", temp,  len1,num,num-len1, i);
        
        printf("--\n");  
        strcpy(msg[i], temp);
        temp[0] = 'n';
        printf("     msg[%d] = `%s`|\n",i , msg[i]);  
        printf("-------------------------------------------------------------------------------------\n"); 
        num = len1; 

        i++;   
    } 
    num_first = strlen(pass2);
    num_last = strlen(msg[0]);
    // printf("i = %d, first_last = %d\n", i, num_first - num_last);
    char* first_last = (char*)malloc(num_first - num_last + 1);
    first_last = extract_first_characters(pass2, num_first - num_last);
    printf("i = %d, first_last = `%s`\n", i, first_last);

    for (int j = 0; j < i; j++) {
        printf("list[%d] = %d\n",j , list[j]);
    }
    printf("--\n"); 

    //list2[0] = 0;
    for (int j = 1; j < i; j++) {
        list2[j - 1] = list[j-1] - list[j];
    }
    list2[i - 1] = list[i - 1];

    for (int j = 0; j < i; j++) {
        printf("list2[%d] = %d\n",j , list2[j]);
    }

    printf("----- full ----\n"); 
    char* msg1;char* msg2;
    char* msg1_add;char* msg2_add;
    char** combine = (char**)malloc(200*sizeof(char*));
    for (int j = 0; j<i; j++){
        msg1 = extract_first_characters(msg[j], strlen(mark));
        msg2 = extract_last_characters(msg[j], strlen(mark));

        msg1_add = add_first_char(msg1, '|');
        msg2_add = add_first_char(msg2, '|');

        combine[j] = (char*)malloc(strlen(msg1_add) + strlen(msg2_add) + 1);
        sprintf(combine[j], "%s%s", msg1_add, msg2_add);
        printf("combine[%d] = `%s`\n", j, combine[j]);
    }

    printf("----- half ----\n"); 
    char* msg3;
    for (int j = 0; j<i; j++){
        msg3 = extract_first_characters(msg[j], list2[j]);

        msg1 = extract_first_characters(msg3, strlen(mark));
        msg2 = extract_last_characters(msg3, strlen(mark));

        msg1_add = add_first_char(msg1, '|');
        msg2_add = add_first_char(msg2, '|');

        combine[j] = (char*)malloc(strlen(msg1_add) + strlen(msg2_add) + 1);
        sprintf(combine[j], "%s%s", msg1_add, msg2_add);
        printf("combine[%d] = `%s`\n", j, combine[j]);
    }

    // add string
    int n;
    printf("----- add string ----\n"); 

    int length = strlen(pass2 + 2*i);
    char* temp1 = (char*)malloc(length + 1);
    sprintf(temp1, "%s%s", first_last, combine[0]);
    //strcpy(temp1, combine[0]);
    for (int j = 0; j<i; j++){
        if (j!=0){
            sprintf(temp1, "%s%s", temp1, combine[j]);

        }

        if (j == i - 1) printf("`%s`\n", temp1);
        n = length;
    }
    return temp1;

    // Free allocated memory for substrings
    for (int j = 0; j < i; j++) {
        free(msg[j]);
        free(combine[j]);
    }
    free(msg);
    free(msg1);
    free(msg2);
    free(msg3);
    free(msg1_add);
    free(msg2_add);
    free(temp);
    free(list);
    free(list2);
    free(combine);
    free(temp1);
}

char pass1[] = "asasasasto dye his asle as skin, and as the day Charles asent lying on as a branch as of the great asoak tree in as Boscobel   as";    
char pass0[] = "asasasasto dye his  asle as skin, and as the day Charles asent lying on as a nch as of the great oak tree in Boscobel as ";

char pass2[] = "as if as though I do whatever as you prefer ";
char pass3[] = "asasasasto dye his  asle as skin, and as the day Charles ";   
char pass4[] = "asasasasto dye his asle as skin,and as the day Charles asent lying on as a branch as of the great oak tree in Boscobel  as";     
char passage[] = "One of the joys of Spencers book, a result not least of its use of Charles IIs own narrative as well as those of his supporters, is just how close the reader gets to the action. The day-by-day retelling of the fugitives doings provides delicious details: the cutting of the king’s long hair with agricultural shears, the use of walnut leaves to dye his pale skin, and the day Charles spent lying on a branch of the great oak tree in Boscobel Wood as the Parliamentary soldiers scoured the forest floor below. Spencer draws out both the humour - such as the preposterous refusal of Charless friend Henry Wilmot to adopt disguise on the grounds that it was beneath his dignity - and the emotional tension when the secret of the kings presence was cautiously revealed to his supporters";

char pass5[] = "I am as if as though";
int main(){
    //char *ms = segregate_string_mark_half(passage, "Charles");
    
    char *ms = segregate_string_mark_half(passage, "Charles");
    printf("int main:\n");
    printf("`%s`\n", ms);
}