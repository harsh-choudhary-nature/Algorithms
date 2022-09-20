#include<stdio.h>
#include<stdlib.h>
void insertionSort(int* ar,int size){
    for(int i=0;i<size;i++){
        int key=ar[i];
        int j=i-1;
        while(key<ar[j] && j>=0){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=key;
    }
}
int calcMode(int* ptr, int size){
    int ele=ptr[0];
    int maxEle=ele;
    int freq=0;
    int maxFreq=0;
    for(int i=0;i<size;i++){
        if(ptr[i]!=ele){
            if(freq>maxFreq){
                maxFreq=freq;
                maxEle=ele;
            }
            ele=ptr[i];
            freq=1;
        }else{
            freq++;
        }
    }
    if(freq>maxFreq){
        maxFreq=freq;
        maxEle=ele;
    }
    return maxEle;
}
void print(int* ar, int size){
    for(int i=0;i<size;i++){
        printf("%d ",ar[i]);
    }
    printf("\n");
}
void get(int* ar, int size){
    for(int i=0;i<size;i++){
        printf("Enter the %dth element",i+1);
        scanf("%d",&ar[i]);
    }
}
int main(){
    int size;
    printf("Enter the size of the list of numbers: ");
    scanf("%d",&size);
    int* arr=(int*)malloc(size*sizeof(int));
    get(arr,size);
    printf("The array you entered is :- \n");
    print(arr,size);
    printf("The sorted array is:\n");
    insertionSort(arr,size);
    print(arr,size);
    printf("The mode of given array is %d\n",calcMode(arr,size));
    free(arr);
    return 0;
}