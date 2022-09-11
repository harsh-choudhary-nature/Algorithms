#include<stdio.h>
int calcMaxDiffCons(int arr[],int size){
    int maxconsdiff=0;
    int diff;
    for(int i=0;i<size-1;i++){
        diff=arr[i+1]-arr[i];
        if(diff<0){
            diff=diff*(-1);
        }
        if(diff>maxconsdiff){
            maxconsdiff=diff;
        }
    }
    return maxconsdiff;
}
int main(){
    const int size=5;
    int arr[size]={7,8,3,1,2};
    int maxDiff=calcMaxDiffCons(arr,size);
    printf("Maximum difference between any two consequitive element in a list is %d",maxDiff);
    return 0;
}