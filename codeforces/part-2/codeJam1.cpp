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

int main()
{
  sync;
  int t;
  cin >> t;
  int p=0;
  while(t--)
  {
  	ll d;
  	p++;
  	string s;
  	cin >> d;
  	cin >> s;
  	ll sCnt=0;
  	ll val = 1;
  	ll dam = 0;
  	for(int i=0;i<s.size();i++)
  	{
  		if(s[i]=='S')
  			sCnt++,dam+=val;
  		else
  			val*=2;
  	}
  	if(dam <= d)
  	{
  		cout << "case #"<<p << ": 0" << endl;
  		continue;
  	}
  	if(sCnt>d)
  	{
  		cout << "case #"<<p << ": IMPOSSIBLE" << endl;
  		continue; 
  	}
  	int ans = 0;
  	for(int i=s.size()-1;i>=0;i--)
  	{
  		int flag = 0;
  		if(s[i]=='C')
  		{
  			int k=0;
  			for(int j=i+1;j<s.size()&&s[j]!='C';j++)
  			{
  				k=1;
  				dam-=(val/2);
  				ans++;
  				if(dam <= d)
  				{
  					flag = 1;
  					break;
  				}
  				swap(s[j-1],s[j]);
  			}
  			val/=2;
  		}
  		if(flag == 1)
  			break;
  	}
  	cout << "case #"<<p << ": " << ans << endl;
  }
}
