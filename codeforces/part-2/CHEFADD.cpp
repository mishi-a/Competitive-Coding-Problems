// C++ program find all the possible combinations of 
// k-bit numbers with n-bits set where 1 <= n <= k 
#include <bits/stdc++.h>
using namespace std; 
// maximum allowed value of K 
#define K 32 

// DP lookup table 
vector<int> DP[K][K]; 

// Function to find all combinations k-bit numbers with 
// n-bits set where 1 <= n <= k 
void findBitCombinations(int k) 
{ 
	string str = ""; 
	
	// DP[k][0] will store all k-bit numbers 
	// with 0 bits set (All bits are 0's) 
	for (int len = 0; len <= k; len++) 
	{ 
		DP[len][0].push_back(0); 
	} 
	
	// fill DP lookup table in bottom-up manner 
	// DP[k][n] will store all k-bit numbers 
	// with n-bits set 
	for (int len = 1; len <= k; len++) 
	{ 
		for (int n = 1; n <= len; n++) 
		{ 
			// prefix 0 to all combinations of length len-1 
			// with n ones 
			for (int str : DP[len - 1][n]) 
				DP[len][n].push_back(str<<1|0); 

			// prefix 1 to all combinations of length len-1 
			// with n-1 ones 
			for (int str : DP[len - 1][n - 1]) 
				DP[len][n].push_back(str<<1|1); 
		} 
	} 
	
	// print all k-bit binary strings with 
	// n-bit set 
	//for (int n = 1; n <= k; n++) 
	// { 
	// 	for (string str : DP[k][10]) 
	// 		cout << str << " "; 

	// 	cout << endl; 
	// } 
} 

// Driver code 
int num(string s)
{
	int ans = 0;
	for(int i=s.size()-1;i>=0;i--)
	{
		ans+=((s[i]-'0')*(pow(2,s.size()-1-i)));
	}
	return ans;
}
int main() 
{ 
	int k = 17; 
	findBitCombinations(k); 
	//cerr << DP[k][15].size() << endl;
	int t;
	cin >> t;
	while(t--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int cnt = 0;
		int l = __builtin_popcount(a);
		int m = __builtin_popcount(b);
		//cerr << l << " " << m << endl;a
		for(int i=0;i<DP[k][l].size();i++)
		{
			int aVal = DP[k][l][i];
			if(aVal > c) continue;
			int bVal = c-aVal;
			if(__builtin_popcount(bVal) ==m)
				cnt++;
		}
		cout << cnt << endl;
	}

	return 0; 
} 
