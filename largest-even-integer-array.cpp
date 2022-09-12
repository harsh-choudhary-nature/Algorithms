#include<stdio.h>
int indexEvenLarge(int* ar, int size){
    int pos=0;
    for(int i=0;i<size;i++){
        if(ar[i]%2==0){
            pos=i+1;
        }
    }
    return pos;
}
int main(){
    const int size=6;
    int arr[size]={7,8,3,1,2,9};
    int position=indexEvenLarge(arr,size);
    printf("%d",position);
    return 0;
}