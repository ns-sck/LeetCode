class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),i=0;
        vector<int> dp;
        for(i=0;i<n;i++){
            int left=0,right=dp.size();
            while(left<right){
                int mid=left+(right-left)/2;
                if(dp[mid]<nums[i]) left=mid+1;
                else right=mid;
            }
            if(right>=dp.size())dp.push_back(nums[i]);
            else dp[right]=nums[i];
        }
        return dp.size();
    }
};