class Solution {
public:
    bool solve(vector<int>& nums,int target,int i){
        if(target<0 || i==nums.size())return false;
        if(target==0)return true;

        int include=solve(nums,target-nums[i],i+1);
        int exclude=solve(nums,target,i+1);
        
        return include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        // int sum=accumulate(nums.begin(),nums.end());
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2!=0)return false;
        int target=sum/2;
        return solve(nums,target,0);
    }
};


