/* INITIAL APPROACH
class Solution {
public:
    int find_newmax(queue<int> q)
    {
        int max = INT_MIN;
        while(q.empty() == false)
        {
            if(q.front() > max)
                max = q.front();
            
            q.pop();
        }
        return max;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int> q;
        int max = INT_MIN;
        
        for(int i=0;i<k;i++)
        {
            if(nums[i] > max)
                max = nums[i];
            
            q.push(nums[i]);
        }
        
        vector<int> max_arr;
        max_arr.push_back(max);
        
        for(int i=k;i<nums.size();i++)
        {
            q.push(nums[i]);
            if(nums[i] > max)
            {
                max = nums[i];
                q.pop();
            }
            else if(max == q.front())
            {
                q.pop();
                max = find_newmax(q);
            }
            else
            {
                q.pop();
            }
            
            max_arr.push_back(max);
        }
        
        return max_arr;
    }
};
*/

class Solution {
public: 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> v;
        deque<int> q;
        for(int i=0;i<k;i++)
        {
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            
            q.push_back(i);
        }
        
        for(int i=k;i<nums.size();i++)
        {
            v.push_back(nums[q.front()]);
            while(!q.empty() && q.front() <= i - k)
                q.pop_front();
            
            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            
            q.push_back(i);
        }
        v.push_back(nums[q.front()]);
        return v;
    }
};
