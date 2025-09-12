#include<iostream>
#include<vector>
using namespace std;
int remove(vector<int>&arr){
     int i=0;
     for(int j=1;j<arr.size();j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
     }
     return i+1;
}
int main(){
    int n;
    cout<<"Enter length of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int newlength = remove(arr);
    for(int i=0;i<newlength;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}