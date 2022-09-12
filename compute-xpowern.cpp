#include<stdio.h>
float xPowerN(float x,int n){
    float res=1;
    int flag=0;
    if(n<0){
        n=-1*n;
        flag=-1;
    }
    for(int i=0;i<n;i++){
        res=res*x;
    }
    if(flag==-1){
        return (1/res);
    }
    return res;
}
int main(){
    float X;
    int N;
    printf("Enter the value of x:");
    scanf("%f",&X);
    printf("Enter the value of N:");
    scanf("%d",&N);
    float power=xPowerN(X,N);
    printf("The value of %0.2f raised to power %d is %0.2f",X,N,power);
    return 0;
}
