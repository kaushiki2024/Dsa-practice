#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool divide(vector<int>&arr){
    int TotalSum=0;
    int n = arr.size();
    for(int i=0;i<n;i++)
        TotalSum+=arr[i];
    int prefix=0;
    int ans=0;
    for(int i=0;i<n-1;i++){
       prefix+=arr[i];
       ans = TotalSum - prefix;
       if(ans == prefix){   // TotalSum-prefix == prefix then TotalSum= 2*prefix
        return 1;
       }
    }
    return 0;
                       
}
int main(){
    int n;
    cout<<"Enter size of the array ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements in array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<divide(arr);
}