#include<stdio.h>
#define notFound -1;
int ternarySearch(int* arr,int size,int key){
    int div1,div2,beg,end;
    beg=0;
    end=size-1;
    if(arr[end]==key){
        return size-1;
    }
    while(beg<end){
        div1=beg+(end-beg)/3;
        div2=beg+2*(end-beg)/3;
        if(key<arr[div1]){
            end=div1;
            continue;
        }
        if(key==arr[div1]){
            return div1;
        }
        if(arr[div1]<key && key<arr[div2]){
            beg=div1+1;
            end=div2;
            continue;
        }
        if(key==arr[div2]){
            return div2;
        }
        if(key>arr[div2]){
            beg=div2+1;
            continue;
        }
    }
    return notFound;

    
}
int main(){
    const int size=8;
    int arr[size]={1,2,3,4,5,6,7,8};
    int key=10;
    while(key>-2){
        int position=ternarySearch(arr,size,key);
        printf("key=%d and position=%d\n",key,position);
        key--;
    }
    return 0;
}