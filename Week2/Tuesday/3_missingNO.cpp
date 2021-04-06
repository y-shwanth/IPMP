class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum=0,max;
        max = (n*(n+1))/2;
        for(int i=0;i<n;i++)
        {
            sum = sum + nums[i];
        }
        return max-sum;
    }
};