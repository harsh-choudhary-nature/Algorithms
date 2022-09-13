#include<stdio.h>
void printArray(int arr[],int size){
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
void swapArr(int arr[],int size,int a,int b){
    if(a>=size || b>=size){
        printf("\n Not allowed!");
        return;
    }
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void sortfirstThree(int arr[],int size){
    if(size<3){
        switch(size){
            case 1:
                return;
            case 2:
                if(arr[0]>arr[1]){
                    swapArr(arr,2,0,1);
                }
        }
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3-i-1;j++){
            if(arr[j]>arr[j+1]){
                swapArr(arr,size,j,j+1);
            }
        }
    }
}
int main(){
    const int size=5;
    int ar[size]={7,8,3,1,2};
    printArray(ar,size);
    sortfirstThree(ar,size);
    printArray(ar,size);
    return 0;
}