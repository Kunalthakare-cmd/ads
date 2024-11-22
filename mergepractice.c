#include<stdio.h>
void merge(int arr, int l, int mid , int r){
    int n1= mid-l+1;
    int n2=r-mid;
    int array1[n1], array2[n2];
    for(int i=0; i<n1; i++){
        array1[n1]=arr[l+i];
        
    }
}
void mergesort(int arr[],int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,l);
        merge(arr,l,mid,r);
    }
}
void main(){
    int arr[]={3,5,7,3,2,9,6};
    int n= sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0, n-1);
    for(int i=0;i<n; i++){
        printf("%d ",arr[0]);
    }
}