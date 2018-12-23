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
  string s;
  cin >> s;
  int ans = 0;
  int done[305]={0};
  for(int i=0;i<s.size();i++)
  {
  	if(done[i])continue;
  	int j=i+1;
  	int cnt=1;
  	while(j<s.size() && s[j]==s[i])
  	{
  		//cout << i << endl;
  		cnt++;
  		i=j;
  		j++;
  	}
  	if(cnt!=1)
  	{
  		ans = ans + ceil(cnt/2.0);
  		//cout << ans << " gg" << endl;
  		if(cnt%2==0&&cnt>2)
  			ans++;

  		continue;
  	}
  	if(i+2<s.size() && s[i]==s[i+2])
  	{
  		done[i+2]=1;
  		ans++;
  	}

  }
  cout << ans << endl;
}
