#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int b[r-l+1];
    int idx=0;
    int s1=l;
    int s2=mid+1;
    while(s1<=mid && s2<=r){
        if(arr[s1]>arr[s2]){
            b[idx]=arr[s2];
            ++s2;
            ++idx;
        }else{
            b[idx]=arr[s1];
            ++s1;
            ++idx;
        }
    }
    if(s1>mid){
        while(s2<=r){
            b[idx]=arr[s2];
            ++idx;
            ++s2;
        }
    }else{
        while(s1<=mid){
            b[idx]=arr[s1];
            ++s1;
            ++idx;
        }
    }
    idx=0;
    for(int i=l;i<=r;i++){
        arr[i]=b[idx];
        ++idx;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[5]={5,4,3,2,1};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}