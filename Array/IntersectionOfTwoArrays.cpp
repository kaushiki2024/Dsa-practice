#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long > Intersection(vector<long long >A,int N,vector<long long > B,int M){
       vector<long long > ans;
       int i=0,j=0;
       sort(A.begin(), A.end());
       sort(B.begin(), B.end());

       while(i<N && j<M){
          if(A[i]==B[j]){
            ans.push_back(A[i]);
            i++;
            j++;
          }
          else if(A[i]<B[j]){
            i++;
          }
          else if(A[i]>B[j]){
            j++;
          }
        }
          return ans;
       
}



int main(){
       int N;
       cout<<"Enter size of first array:";
       cin>>N;
       int M;
       cout<<"Enter size of second array:";
       cin>>M;
       vector<long long> A(N);
       vector<long long> B(M);
       cout<<"Enter elements in first array:";
       for(auto &i:A){
        cin>>i;
       }
       cout<<"Enter elements in second array:";
       for(auto &i:B){
        cin>>i;
       }
       vector<long long> result= Intersection(A,N,B,M);
       cout<<"Final array:";
       for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
       }

       
}