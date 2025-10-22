class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> numMap;
        for(int i = 0;i<n;++i)
        {
            if(numMap.count(target-nums[i])){
                return {i,numMap[target-nums[i]]};
            }
            else{
                numMap[nums[i]]=i;
            }
        }

        return {};
    }
};