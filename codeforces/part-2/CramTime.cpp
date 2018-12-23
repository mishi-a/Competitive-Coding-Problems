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

ll fi[MAX],se[MAX];
map<ll,ll> mp; 
int main()
{
  sync;
  ll a,b;
  cin >> a >> b;
  ll sum = 0,rem = 0,idx = 0;
  
  for(ll i=1;i<=1e5;i++)
  {
  	sum+=i;
  	if(sum > a)
  	{
  		rem = a - (sum-i);
  		break;
  	}
  	fi[idx] = i;
  	idx++;
  }
  ll len = idx;
  idx--;
  while(rem > 0 && idx>=0)
  {
  	fi[idx]++;
  	rem--;
  	idx--;
  }
  for(int i=0;i<len;i++)
  	mp[fi[i]]++;
  sum = 0,idx=0;
  for(ll i = 1;i<=1e6;i++)
  {
  	if(mp[i] == 0)
  	{
  		sum += i;
  		if(sum > b)
  			break;
  		se[idx] = i;
  		idx++;

  	}
  }
  cout << len << endl;
  for(int i=0;i<len;i++)
  	cout << fi[i] << " ";
  cout << endl;
  cout << idx << endl;
  for(int i=0;i<idx;i++)
  	cout << se[i] << " ";
  cout << endl;

}
