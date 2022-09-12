#include<stdio.h>
#include<stdlib.h>
int* insertCompBackward(int* ar,int size,int key){
    int* ptr=(int*)malloc((size+1)*sizeof(int));
    for(int i=0;i<size;i++){
        ptr[i]=ar[i];
    }
    int i=size-1;
    while(key<ptr[i] && i>=0){      //in backward traversal we need to be careful for i to be reasonable
        ptr[i+1]=ptr[i];
        i--;
    }
    ptr[i+1]=key;
    return ptr;
}
int* insertCompForward(int* ar,int size,int key){
    int* ptr=(int*)malloc((size+1)*sizeof(int));
    for(int i=0;i<size;i++){
        ptr[i]=ar[i];
    }
    int i=0;
    while(key>ptr[i]){
        i++;
    }
    for(int j=size;j>i;j--){
        ptr[j]=ptr[j-1];
    }
    ptr[i]=key;
    return ptr;
}
void printarr(int* ar,int size){
    for(int i=0;i<size;i++){
        printf("%d ",ar[i]);
    }
}
int main(){
    const int size=5;
    int ar[size]={1,2,3,7,8};
    //realloc does not behaves properly with static pointers
    //realloc also initializes with 0
    int* newAr=insertCompForward(ar,size,0);
    printarr(newAr,size+1);
    printf("\n");
    int* newArB=insertCompBackward(ar,size,0);
    printarr(newArB,size+1);
    return 0;
}