#include<stdio.h>
#include<stdlib.h>
int numRepeat=0;
int* repeated(int arr[],int size){
    int* ptr=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        int present=0;        
        int key=arr[i];
        for(int j=i+1;j<size;j++){
            if(key==arr[j]){
                //check if that number already added once
                for(int k=0;k<numRepeat;k++){
                    if(ptr[k]==key){
                        present=1;
                        break;
                    }
                }
                if(present==0){    
                    ptr[numRepeat]=key;
                    numRepeat++;
                }
            }
        }
    }
    return ptr;
}
int main(){
    const int size=15;
    int arr[size]={1,2,3,1,2,4,5,6,7,2,1,2,3,5,8};
    int* repeatList=repeated(arr,size);
    for(int i=0;i<numRepeat;i++){
        printf("%d ",repeatList[i]);
    }
    return 0;
}