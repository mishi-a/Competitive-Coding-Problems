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

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
map<pair<char,char>,int > mp;
int cost[30][30];

void floyd()
{
	for(int k=0;k<26;k++)
	{
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
			{
				if(cost[i][k]+cost[k][j]<cost[i][j])
				{
					cost[i][j] = cost[i][k]+cost[k][j];	
				}
			}
		}
	}
}

int main()
{
  sync;
  string s,t;
  cin >> s >> t;
  if(s.size()!=t.size())
  	cout << -1 << endl;
  else
  {
  	int n,w;
  	char A,B;
  	cin >> n;
  	for(int i=0;i<30;i++)
  		for(int j=0;j<30;j++)
  		{
  			if(i != j){
  				cost[i][j] = 1e9;
  			}
  			//cost[i][j] = 1e9;
  		}	
  	for(int i=0;i<n;i++)
  	{
  		cin >> A >> B >> w;
  		cost[A-'a'][B-'a'] = min(w,cost[A-'a'][B-'a']);
  	}

  	floyd();	
  	int ans = 0;
  	string res1 = "";
  	for(int i=0;i<s.size();i++)
  	{
  		int val = INT_MAX;
  		char res;
  		for(int j=0;j<26;j++)
  		{
  			if(cost[s[i]-'a'][j]+cost[t[i]-'a'][j] < val)
  			{
  				res = 'a'+j;
  				val = cost[s[i]-'a'][j]+cost[t[i]-'a'][j];
  			}
  		}
  		if(val == 1e9)
  		{
  			cout << -1 << endl;
  			return 0;
  		}
  		ans+=val;
  		res1 += res;
  	}
  	cout << ans << endl << res1 << endl;

  }  
}
