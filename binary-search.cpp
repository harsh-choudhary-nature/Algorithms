#include<stdio.h>
#define notFound -1
int BinarySearchRecursion(int* arr,int beg,int end,int size,int key){
    // printf("Recursion\n");
    if(beg>=end){
        return notFound;
    }
    int mid=beg+(end-beg)/2;    //same as beg+end/2    
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]>key){
        end=mid;
        return BinarySearchRecursion(arr,beg,end,size,key);
    }else{
        beg=mid+1;
        return BinarySearchRecursion(arr,beg,end,size,key);
    }
}
int BinarySearch(int* arr,int key,int size){
    //only for sorted arrays
    int beg=0,end=size-1;
    int mid;
    while(beg<end){
        // printf("Not found!\n");    
        mid=(end+beg)/2;
        if(arr[mid]==key){
            return mid+1; 
        }
        if(arr[mid]>key){
            end=mid;        //learn
        }else{
            beg=mid+1;      //learn
        }
    }
    return notFound;
}
int main(){
    const int size=7;
    int arr[size]={1,2,3,4,5,6,7};
    int search=7;
    int found=BinarySearchRecursion(arr,0,size-1,size,search);
    int found1=BinarySearchRecursion(arr,0,size-1,size,search);
    printf("Found at %dth position from left!\n",found1);
    if(found==notFound){
        printf("Not found!");
    }else{
        printf("Found at %dth position from left!",found);
    }
    return 0;   
}