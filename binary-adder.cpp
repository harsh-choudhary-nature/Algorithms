#include<stdio.h>
#include<stdlib.h>
int* bitAdder(int* arr1,int* arr2,int size){
    int* ptr=(int*)malloc((size+1)*sizeof(int));
    int co=0;
    for(int i=size-1;i>=0;i--){
        int sum=co+arr1[i]+arr2[i];
        switch(sum){
            case 0:
                ptr[i+1]=0;co=0;
                break;
            case 1:
                ptr[i+1]=1;co=0;
                break;
            case 2:
                ptr[i+1]=0;co=1;
                break;
            case 3:
                ptr[i+1]=1;co=1;
                break;
        }
    }
    ptr[0]=co;
    return ptr;
}
int main(){
    const int size=4;
    int num1[]={1,1,0,1};
    int num2[]={1,1,1,1};
    int* sum=bitAdder(num1,num2,size);
    for(int i=0;i<size+1;i++){
        if(sum[i]==0 && i==0){
            continue;
        }
        printf("%d ",sum[i]);
    }
    return 0;
}