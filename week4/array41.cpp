class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int cur_max = nums[0];
        int max_sofar = nums[0];
        
        for(int i=1;i<n;i++)
        {
            cur_max = max(nums[i],cur_max + nums[i]);
            max_sofar = max(cur_max,max_sofar);
        }
        return max_sofar;
    }
};
