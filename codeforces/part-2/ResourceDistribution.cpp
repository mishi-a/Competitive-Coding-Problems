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
vector<pii> v;
int main()
{
  sync;
  ll n,x1,x2,x;
  cin >> n >> x1 >> x2;
  for(int i=0;i<n;i++)
  {
  	cin >> x;
  	v.pb({x,i});
  }
  int idx = -1 ;
  sort(v.begin(),v.end());
  for(int i=n-1;i>=0;i--)
  {	
  	if(v[i].FI*(n-i)>=x2)
  	{
  		idx = i;
  		break;
  	}
  }
  int idx2 = -1;
  for(int i=n-1;i>=0;i--)
  {	
  	if(v[i].FI*(n-i)>=x1)
  	{
  		idx2 = i;
  		break;
  	}
  }
  //cout << idx << " " << idx2 << endl;
  int idx1 = -1;
  for(int i=idx-1;i>=0;i--)
  {
  	if(v[i].FI*(idx-i)>=x1)
  	{
  		idx1 = i;
  		break;
  	}
  }
  int idx3 = -1;
  for(int i=idx2-1;i>=0;i--)
  {
  	if(v[i].FI*(idx2-i)>=x2)
  	{
  		idx3 = i;
  		break;
  	}
  }
  if(idx !=-1&& idx1!=-1 )
  {
  	cout << "Yes" << endl;
	  cout << idx-idx1 << " " << n-idx << endl;
	  for(int i=idx1;i<idx;i++)
	  	cout << v[i].SE+1 << " ";
	  cout << endl;
	  for(int i=idx;i<n;i++)
	  	cout << v[i].SE+1 << " ";
	  cout << endl;
  }
  else if(idx2!=-1 && idx3!=-1)
  {
  	cout << "Yes" << endl;
  cout <<  n-idx2 << " " <<idx2-idx3  << endl;
  
  for(int i=idx2;i<n;i++)
  	cout << v[i].SE+1 << " ";
  cout << endl;
  for(int i=idx3;i<idx2;i++)
  	cout << v[i].SE+1 << " ";
  cout << endl;
  }
  else
  {
  	cout << "No" << endl;
  }
   
}
