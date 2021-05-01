//Normal approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp,i,j;
        int n = nums.size();
        for(i=0;i<k;i++)
        {
            temp = nums[n-1];
            for(j=n-1;j!=0;j--)
            {
                nums[j] = nums[j-1];
            }
            nums[0] = temp;
        }
    }
};
//Optimized approach
class Solution {
public:
    int get_gcd(int a, int  b)
    {
        if(b == 0)
        return a;
        
        else
        return get_gcd(b,a%b);
    }
    void rotate(vector<int>& nums, int k) {
        int temp,i,j,d;
        int n = nums.size();
        k = k % n;
        k = n - k;
        int gcd = get_gcd(k,n);
        
        for(i=0;i<gcd;i++)
        {
            temp = nums[i];
            j = i;
            while(1)
            {
                d = j + k;
                if(d >= n)
                d = d -n;
                
                if(d == i)
                break;
                
                nums[j] = nums[d];
                j = d;
            }
            nums[j] = temp;
        }
        
    }
};
