/* MODEL NO 1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        deque<int> q;
        map<int,int> m;
        
        int i=0;
        while(i<nums2.size())
        {
            while(!q.empty() && q.back() < nums2[i])
            {
                m[q.back()] = nums2[i];
                q.pop_back();
            }
            q.push_back(nums2[i]);
            i++;
        }
        
        while(!q.empty())
        {
            m[q.back()] = -1;
            q.pop_back();
        }
        
        vector<int> v;
        for(int i=0;i<nums1.size();i++)
        {
            v.push_back(m[nums1[i]]);
        }
        
        return v;
    }
};
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> q;
        
        int n = nums.size();
        vector<int> v(n,0);
        
        int i=0;
        while(i < n)
        {
            while(!q.empty() && nums[q.top()] < nums[i])
            {
                v.at(q.top()) = nums[i];
                q.pop();
            }
            
            q.push(i);
            i++;
        }
        
        i = 0;
        while(i < n && q.empty() == false)
        {
            if(i >= q.top())
            {
                v[q.top()] = -1;
                q.pop();
                i++;
                continue;
            }
            while(!q.empty() && nums[q.top()] < nums[i])
            {
                v[q.top()] = nums[i];
                q.pop();
            }
            i++;
        }
        
        while(!q.empty())
        {
            v[q.top()] = -1;
            q.pop();
        }
        
        return v;
    }
};
