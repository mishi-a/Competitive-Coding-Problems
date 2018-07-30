/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second

/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/


using namespace std;

int arr[1005];
int mod = 1e9+7;
int check(int val)
{
	if(val == 1)
		return 0;
	else
	{
	   int cnt = 0;
	   for(int i=0;i<30;i++)
	   {
	   	 if(val &(1<<i))
	   	 	cnt++;
	   }
	   int ans = 1+check(cnt);
	   return ans;
	}
}

int C[1005][1005];

int binomialCoeff(int n, int k)
{
    int i, j;
    memset(C,0,sizeof(C));
    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;
 
            // Calculate value using previosly stored values
            else
                C[i][j] = (C[i-1][j-1]%mod + C[i-1][j]%mod)%mod;
        }
    }
 
    return C[n][k];
}

void pre()
{
	for(int i=1001;i>0;i--)
	{
	    arr[i] = check(i);
	}
}
void pre1()
{
	binomialCoeff(1000,1000);
	// for(int i=0;i<=1000;i++)
	// {
	// 	for(int j=0;j<=1000;j++)
	// 		cout << C[i][j] << " ";
	// 	cout << endl;
	// }
	//cout << C[999][5] << endl;
}
int main()
{
  sync;
  pre();
  pre1();
  string s;
  cin >> s;
  int k;
  cin >> k;
  int cnt = 0;
  for(int i=0;i<s.length();i++)
  	if(s[i]=='0')
  		cnt++;
  int ans = 0;
  if(k==0)
  {
  	cout << "1" << endl;
  	return 0;
  }
  // cout << C[8][2] << endl;
  for(int i=1;i<=s.length();i++)
  {
  	//cout << arr[i] << endl;
  	if(arr[i]+1==k)
  	{
  	   int cnt1 = 0;
       for(int j=0;j<s.length();j++)
       {
       	if(s[j]=='1')
       	{
       		 if(i-cnt1>=0)
       		   ans = (ans%mod+C[s.length()-(j+1)][i-cnt1]%mod)%mod;
       		 //cout << ans <<" " << s.length()-(j+1) << " " << (i-cnt1) << endl;
       		 cnt1++;
       	}
       	else
       	{
       		ans = (ans%mod+C[s.length()-(j+1)][i-cnt1]%mod)%mod;
       	}
     }
  		//cout << ans << endl;
  	}
  }
  cout << ans%mod << endl;
}
