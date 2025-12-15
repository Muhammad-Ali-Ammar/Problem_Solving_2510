#include <bits/stdc++.h>
using namespace std;


/*

std::sort(attributes.begin(), attributes.end());
attributes.erase(std::unique(attributes.begin(), attributes.end()), attributes.end());

*/
int main() 
{

vector<int> v {2,1,3,1,2,3,4};
std::sort(v.begin(), v.end());
v.erase(std::unique(v.begin(), v.end()), v.end());



for(auto i : v){
    cout<<i<<endl;
}


  return 0;
}


