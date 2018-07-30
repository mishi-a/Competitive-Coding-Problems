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
int A[500005],B[500005];

ll func(int val)
{
	ll ans = 0;
	for(int i=1;i<=n;i++)
	{
      if(val>=A[i])
      	ans+=(val-A[i]);
      else
      {
         ans=ans+val+(B[i]-A[i]);
      }
	}
	return ans;
}

int ts(int start, int end)
{
    int l = start, r = end;

    while(r-l>2) {
      int l1 = (l*2+r)/3;
      int l2 = (l+2*r)/3;
      //cout<<l1<<" "<<l2<<endl;
      if(func(l1) > func(l2)) r = l2; else l = l1;
      }

     int x = l;
    return func(x);
}
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int n;
  	cin >> n;
  	for(int i=1;i<=n;i++)
  		cin >> A[i];
  	for(int i=1;i<=n;i++)
  		cin >> B[i];
  	for(int i=1;i<=n;i++)
  		A[i]%=B[i];

  }
}
