#include<stdio.h>
int ternarySearch(int arr[],int size,int key){
    int beg=0,end=size-1;
    while(beg<end){
        printf("isinfinite or not\n");
        int div1=(beg+end)/3;       //2
        int div2=2*(beg+end)/3;     //4
        // printf(" %d and %f ",div,div2);
        if(key==arr[div1]){
            return div1+1;
        }
        if(key<arr[div1]){
            end=div1;               //0
            continue;
        }else if(arr[div1]<key && key<arr[div2]){
            beg=div1+1;
            end=div2;
            continue;
        }
        if(key==arr[div2]){
            return div2+1;
        }
        if(key>div2){
            beg=div2+1;
        }
    }
    return -1;    
    
}
int main(){
    const int size=8;
    int arr[size]={1,2,3,4,5,6,7,8};
    int key=9;
    int position=ternarySearch(arr,size,key);
    printf("%d",position);
}