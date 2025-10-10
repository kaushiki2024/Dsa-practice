#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int start=0;
    for(int i=0;i<=s.size();i++){
        if(s[i]==' '||i==s.size()){ 
            int forward=start;
            int backward=i-1;
            while(forward<backward){
                swap(s[forward],s[backward]);
                forward++;
                backward--;               
            } 
            start=i+1;          
        }
              
    }
    cout<<s;
    return 0;
}