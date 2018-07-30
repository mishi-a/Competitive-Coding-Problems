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
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int i=1;i<n;i++)
  {
  	if(s[i]==s[i-1] && s[i]!='?')
  	{
  		cout << "No" << endl;
  		return 0;
  	}
  }
  if(s[0]=='?'||s[n-1]=='?')
  {
  	cout << "Yes" << endl;
  	return 0;
  }
  //cout << "i" << n  << endl;

  for(int i=0;i<n;i++)
  {

  	if(s[i]=='?')
  	{
  		//cout << i << endl;
  		if(i+1<n && s[i+1]=='?')
  		{
  			cout << "Yes" << endl;
  			return 0;
  		}
  	}
  }
  for(int i=1;i<n-1;i++)
  {
  	if(s[i]=='?')
  	{
  		if(s[i-1] == s[i+1])
  		{
  			cout << "Yes" << endl;
  			return 0;
  		}
  	}
  }
  cout << "No" << endl;

}
