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

int arr[100005];
int pre[100005];
int freq[100005];
vector<int>v;
set<int> pf;
void solve(int n)
{
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		pf.insert(pre[arr[i]]);
		freq[arr[i]]=1;
	}

	set<int> ::iterator itr = pf.begin();
	while(itr!=pf.end())
	{
		v.pb(*itr);
		itr++;
	}
	for(int i=0;i<v.size();i++)
		cout << v[i] << endl;
	/*ll tot = 1LL << v.size();
	set<int> s1,s2;
	int ans = 0;
	for(int i=1;i<tot-1;i++)
	{
		int flag = 0;
		for(int j=0;j<v.size();j++)
		{
			if((i>>j)&1)
			{
				int start = v[j];
				while(start < 100001)
				{
					if(freq[start] == 1)
					{
						if(s2.find(start)!=s2.end())
					    {
					    	flag = 1;
					    	break;
					    }
					    else
					    {
					    	s1.insert(start);
					    }
					}
					   start+=v[j];
				}
			}
			else
			{
				int start = v[j];
				while(start < 100001)
				{
					if(freq[start] == 1)
					{
						if(s1.find(start)!=s1.end())
					    {
					    	flag = 1;
					    	break;
					    }
					    else
					    {
					    	s2.insert(start);
					    }
					}
					start +=v[j];
				}
			}
		}
		if(flag == 0)
		{
			ans++;
		}
		s1.clear();
		s2.clear();
	}*/
	//cout << ans << endl;

}

void precompute()
{
	for(int i=2;i<100005;i++)
	{
		for(int j=i;j<100005;j+=i)
		{
			if(pre[j] == 0)
			{
				pre[j] = i;
			}
		}
	}
}
int main()
{
  sync;
  precompute();
  int t;
  cin >> t;
  while(t--)
  {
  	int n;
  	cin >> n;
  	solve(n);
  }
}
