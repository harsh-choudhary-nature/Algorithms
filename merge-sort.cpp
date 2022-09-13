#include<stdio.h>
#include<stdlib.h>
int counter=0;
void printArray(int arr[],int size){
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
void merge(int ar[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int* left=(int*)malloc((n1)*sizeof(int));
    int* right=(int*)malloc((n2)*sizeof(int));
    for(int i=0;i<n1;i++){
        left[i]=ar[p+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=ar[q+i+1];
    }
    // printf("\nright[o]%d=",right[0]);

    int i=0,j=0;
    for(int k=p;k<=r;k++){
        if(i==n1){
            ar[k]=right[j];
            // printf("\n%d ",ar[k]);
            j++;
            continue;
        }
        if(j==n2){
            ar[k]=left[i];
            // printf("\n%d ",ar[k]);
            i++;
            continue;
        }
        if(left[i]<=right[j]){
            ar[k]=left[i];
            // printf("\n%d ",ar[k]);
            i++;
        }else{
            ar[k]=right[j];
            // printf("\n%d ",ar[k]);
            j++;
        }
    }
    free(left);
    free(right);
}
void mergeSort(int ar[],int beg,int end){
    counter++;
    if(beg>=end){
        // printf("\nBase case");
        return;
    }
    int p=beg,r=end;    
    int q=(r+p)/2;
    mergeSort(ar,p,q);
    mergeSort(ar,q+1,r);
    merge(ar,p,q,r);
    return;
}

int main(){
    const int size=5;
    int ar[size]={7,8,3,1,2};
    printArray(ar,size);
    mergeSort(ar,0,size-1);
    printArray(ar,size);
    printf("\nnumber of iterartions are %d",counter);       //nlogn
}