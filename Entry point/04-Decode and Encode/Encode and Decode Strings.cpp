class Solution {
public:

    string encode(vector<string>& strs) {
        
        string ans = "";
        for(auto str : strs){
            ans+= to_string(str.size())+ "#" + str ; 
        }

        return ans;
    }

    vector<string> decode(string s) {

      vector<string> ans;
      int len = 0;
      int i = 0; 
      while(s[i]){

        if(s[i] != '#'){
          len = len *10 + s[i++]-'0';
          continue;
        }
        ans.push_back(s.substr(i+1, len));
        i+= len +1;
        len = 0;
      }
      return ans;
    }
};
