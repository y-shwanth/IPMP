#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

void _01_knapsack(int item[], int profit[], int W, int n)
{
	int dp[n + 1][W + 1];
	
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(i == 0 || w == 0)
			dp[i][w] = 0;
			
			else if(item[i-1]<=w)
			{
				dp[i][w] = max(dp[i-1][w], dp[i-1][w - item[i-1]] + item[i-1]);
			}
			else
			dp[i][w] = dp[i-1][w];
		}
	}
	
	cout<<dp[n][W];
}

int main()
{
	int item[] = {60, 100, 120};
	int profit[] = {10, 20, 30};
	int W = 50;
	int n = sizeof(item)/sizeof(item[0]);
	_01_knapsack(item, profit, W, n);
	
	return 1;
}
