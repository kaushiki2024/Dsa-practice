#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
    //creation
    unordered_map<string,int> m;

    //insertion
    //1 way of insertion using pair 
    pair<string,int> p = make_pair("kaushiki",1);
    m.insert(p);

    //2 way of insertion
    pair<string,int> pair2("Mishra",4);
    m.insert(pair2);

    //3 way 
    m["Hello"] = 2;
    m["Hello"] = 4; // Hello's value is updated to 4 from 2
    
    //Search
    //cout<<m["Hello"]<<endl;// new entry created by this way 
    //cout<<m.at("Hello")<<endl;// this does not create a new entry it just search where is the key mapped to which value
    
  
    //cout<<m["unknown"]<<endl;
    //cout<<m.at("unknown")<<endl;
    //size
    cout<<m.size()<<endl;
    // to check presense
    cout<<m.count("kaushiki")<<endl;

    //erase
    m.erase("kaushiki");
    cout<<m.size()<<endl;
    cout<<m.count("kaushiki")<<endl;
    //traversal 
    // for(auto i:m){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    // traversal by creating iterator

    unordered_map<string,int> :: iterator it = m.begin();
    while(it!=m.end()){
        cout<< it->first<<" "<<it->second<<endl;
        it++;
    }
 return 0;
    
}
