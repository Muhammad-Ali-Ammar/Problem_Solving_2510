#include <bits/stdc++.h>
using namespace std;



/*

 -- Set : small to largest ( small on the top)
         Piorirty queue al 3aks, large to small 

 -- set of pair, based on first 
 -- to use set from large to small --> use greater <  > syntax 

    set<int, std::greater<int>> s2; 
    set<pair<int,int>, std::greater<pair<int,int>>> s2; 
*/

int main() 
{
set<int> st;

st.insert(0);
st.insert(1);
st.insert(-1);

for(auto i : st){
    cout<<i<<endl;  // -1 0 1 
}

//////////////////////////////// exmaple of pair ////////////////////////////////////////////

set<pair<int,int>>s;
s.insert({-1,10});
s.insert({10,-1});
for(auto i : s){
    cout<<i.first<<" "<<i.second<<endl;;  // {-1 10 }  {10, -1} 
}

//////////////////////////////// exmaple of large to small  ////////////////////////////////////////////

set<pair<int,int>, std::greater<pair<int,int>>> s2; 
s2.insert({-1,10});
s2.insert({10,-1});
for(auto i : s2){
    cout<<i.first<<" "<<i.second<<endl;;  // {10 -1}  {-1, 10} 
}

  return 0;
}


