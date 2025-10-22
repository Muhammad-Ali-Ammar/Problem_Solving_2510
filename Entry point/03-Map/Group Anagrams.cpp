class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        for(auto str : strs){
            auto orgStr = str;
            sort(str.begin(), str.end());
            mp[str].push_back(orgStr);
        }
    
        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};