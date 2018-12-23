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
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;

int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  int start = -1;
  int start1 = -1;
  for(int i=0;i<s.size();i++)
  {
  	//cout << i << endl;
  	for(int j=i+1;j<s.size();j++)
  	{
  		int idx = i,idx1 = j;
  		while(s[idx] == s[idx1])
  		{
  			idx++;
  			idx1++;
  		}
  		if(idx1 == s.size())
  		{
  			//cout << i << endl;
  			start = j;
  			break;
  		}

  	}
  	//cout << start << endl;
  	break;
  }
  //cout << start << endl;
  string ans = s;
  if(start != -1)
  {
  	for(int i=0;i<k-1;i++)
  	{
  		ans += (s.substr(s.size()-start,s.size()-(s.size()-start)+1));
  	}
  }
  else
  {
  	for(int i=0;i<k-1;i++)
  	{
  		ans += (s);
  	}
  }
  cout << ans << endl;
}
