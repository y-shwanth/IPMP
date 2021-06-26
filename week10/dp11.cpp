class Solution {
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> a(n,0);
	    int mx=0;
	    for(int i=0;i<n;++i)
	    {a[i]=arr[i];
	        mx=max(mx,a[i]);
	    }
	    
	    
	    for(int i=1;i<n;++i)
	    for(int j=0;j<i;++j)
	    {
	        if(arr[j]<arr[i])
	        {
	            a[i]=max(a[i],a[j]+arr[i]);
	        }
	        mx=max(mx,a[i]);
	    }
	    
	    return mx;
	    
	}  
};