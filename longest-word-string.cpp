#include<stdio.h>
#define maxSize 300
int maxlettercount=0;
int strLen(char* ar){
    int len=0;
    while(ar[len]!='\0'){
        len++;
    }
    return len;
}
char* longestWord(char* st){
    //we suppose string has only spaces and letters.
    int length=strLen(st);
    // printf("%d",length);
    int letterCount=0;
    char temp[maxSize];
    char* ptr=temp;
    int beg=-1;
    int permBeg=0;
    for(int i=0;i<length;i++){
        if(st[i]==' '){
            if(letterCount>maxlettercount){
                maxlettercount=letterCount;
                permBeg=beg;
            }
            beg=-1;
            letterCount=0;
            // printf("\n i=%d",i);
        }else{
            if(beg<0){
                beg=i;
            }
            // printf("\n i= %d and beg=%d",i,beg);
            letterCount++;
        }
    }
    // printf("%d",beg);
    if(letterCount>maxlettercount){
        maxlettercount=letterCount;
    }
    for(int m=0;m<maxlettercount;m++){
        // printf("%c",st[permBeg]);
        temp[m]=st[permBeg];
        permBeg++;
    }
    temp[maxlettercount]='\0';
    // printf("\n%d",maxlettercount);
    // printf("%s",temp);
    return ptr;
}
int main(){
    char str[maxSize];
    printf("Enter your sentence:");
    scanf("%[^\n]s",str);
    // printf("%s",str);
    char* large=longestWord(str);
    printf("The largest word in sentence is '%s' and its length is %d",large,maxlettercount);
}