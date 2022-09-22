#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void printpascal(int** ar, int size) {
    for(int I=0;I<size;I++) {
        for(int j=0;j<2*size+1;j++) {
            if(ar[I][j]!=0) {
                printf("%d ", ar[I][j]) ;
            }else{
                printf("  ") ;
            }
        }
        printf("\n") ;
    }
}
void print(int** ar, int n) {
    for(int I=0;I<n;I++) {
        for(int j=0;j<2*n+1;j++) {
            printf("%d ", ar[I][j]) ;
        }
        printf("\n") ;
    }
}

int main()
{
    
    cout << "Hello World!\n";
    int** arr;
    int n=6;
    arr=(int**) malloc((n)*sizeof(int*)) ;
    for(int I=0;I<n;I++) {
        arr[I]=(int*) calloc((2*n+1),sizeof(int)) ;
    }
    //print(arr, n) ;
    arr[0][n]=1;
    for(int I=1;I<n;I++) {
        for(int j=n-I;j<=n+I;j=j+2) {
            arr[I][j]=arr[I-1][j-1]+arr[I-1][j+1];
        }
    }
    printpascal(arr, n) ;
    free(arr) ;
    return 0;
}