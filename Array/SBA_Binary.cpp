#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){ //element stored in vector
        cin>>A[i];
    }
    int firstone = 1;
    auto it1 = lower_bound(A.begin(),A.end(),1);
    if(it1 == A.end()){
        firstone = n;

    }
    else{
        firstone = (it1-A.begin());
    }
    int lastzero;
    auto it0 = upper_bound(A.begin(),A.end(),0);
    if(it0 == A.begin()){
        lastzero = -1;
    }
    else{
        lastzero = (it0 - A.begin())-1;
    }
    cout << firstone << " " << lastzero << endl;
    return 0;
    

}