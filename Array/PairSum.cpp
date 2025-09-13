#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>A={1,2,3,4,5};
    int S=5;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            if(A[i]+A[j]==S){
               cout<<"(" << A[i] << ", " << A[j] << ")"<<",";
            }
            
        }
        
    }
}
