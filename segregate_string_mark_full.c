#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void segregate_string_mark_full(char* pass2, char* mark){
    // set up
    //int len0 = strlen(pass)+1;
    //*pass2 = (char*)malloc(500); // pass2
    char** msg1 = (char**)malloc(200*sizeof(char*)); //[i] save substrings
    char *temp = (char*)malloc(strlen(pass2)+1); // temporary
    int *list = malloc(200*sizeof(int)); // minus
    int *list2 = malloc(200*sizeof(int)); // minus
    strcpy(temp, pass2); 
    int num=0, len1=0; 
    
    int i=0;
    // loop
    while(1){
        
        temp = strstr(temp, mark);
        //len1 = strlen(temp);
        
        if (temp == NULL) break;
        
        msg1[i] = (char*)malloc((strlen(temp)+1)*sizeof(char)); // +1 --> null terminator
        len1 = strlen(temp);
        list[i]=len1;
        printf("-->`%s` with len1 = %d, %d with len bew = %d, i = %d\n", temp,  len1,num,num-len1, i);
        
        printf("--\n");  
        strcpy(msg1[i], temp);
        temp[0] = 'n';
        printf("     msg[%d] = `%s`|\n",i , msg1[i]);  
        printf("-------------------------------------------------------------------------------------\n"); 
        num = len1; 
        //minus[i] = (int)malloc(10*4);
        //minus[i]=12;
        i++;   
    } 
    printf("i = %d\n", i);

    for (int j = 0; j < i; j++) {
        printf("list[%d] = %d\n",j , list[j]);
    }
    printf("--\n"); 

    list2[0] = 0;
    for (int j = 1; j < i; j++) {
        list2[j] = list[j-1] - list[j];
    }

    for (int j = 0; j < i; j++) {
        printf("list2[%d] = %d\n",j , list2[j]);
    }



    // Free allocated memory for substrings
    for (int j = 0; j < i; j++) {
        free(msg1[j]);
    }
    free(msg1);
    free(temp);
    free(list);
    free(list2);
}

char pass1[] = "asasasasto dye his asle as skin, and as the day Charles asent lying on as a branch as of the great    asoak tree in as Boscobel   as";    
char pass0[] = "to dye his pale skin, and as the day Charles spent lying on a branch of the great oak tree in Boscobel Wood as the Parliamentary soldiers scoured the forest floor below. Spencer draws out both the humour - such as the preposterous refusal of Charless friend Henry Wilmot to adopt disguise on the grounds that it was beneath his dignity - and the emotional tension when the secret of the kings presence was cautiously revealed to his supporters";        

char pass2[] = "as if as though I do whatever as you prefer ";
char pass3[] = "asasasasto dye his  asle as skin, and as the day Charles ";   
char pass4[] = "asasasasto dye his asle as skin,and as the day Charles asent lying on as a branch as of the great oak tree in Boscobel  as";     
int main(){
    segregate_string_mark_full(pass4, "as");
}