#include<iostream>
using namespace std;

void countSort(int arr[], int n){
    
    int K =  arr[0];
    for(int i = 0; i<n; i++){
        K =  max(K, arr[i]);
    }
    
    int count[10] = {0};
    for(int i = 0; i< n; i++){
        count[arr[i]]++;
    }
    
    for(int i = 1; i<=K; i++){
        count[i]+=count[i-1];
    }
    
    int output[n];
    for(int i = n-1; i >=0; i--){
        output[--count[arr[i]]] = arr[i];
    }
    
    for(int i = 0; i< n; i++){
        arr[i] = output[i];
    }
    
}

int main(){
    int arr[] = {1,3,2,3,4,1,6,4,3};
    countSort(arr,9);
    for(int i = 0; i< 9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
