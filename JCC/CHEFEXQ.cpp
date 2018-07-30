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
int sz ;
int v[320][1048600];
int arr[100005],arr1[100005];
int lindx;
void build(int n)
{
  int cur = 0;
  int cxor = 0;	
  for(int i=0;i<n;i++)
  {
    if((i/sz)>cur)
    {
    	cur++;
        cxor=0;
    }
    cxor = cxor^arr[i];
    arr1[i]=cxor;
    v[cur][cxor]++;
   }	
}

void update(int idx,int val)
{
	int block = idx/sz;
	int end = block*sz+sz-1;
	end = min(end,lindx);
	v[block][arr1[idx]]--;
	arr1[idx]=arr1[idx]^arr[idx]^val;
	v[block][arr1[idx]]++;
	arr[idx]=val;
	int cxor = arr1[idx];
	for(int i=idx+1;i<=end;i++)
	{
       cxor = cxor^arr[i];
       v[block][arr1[i]]--;
       arr1[i]=cxor;
       v[block][arr1[i]]++;
	}
}

int query(int idx,int k)
{
	int block = idx/sz;
    int ans = 0;
    int c = k;
    int p = 0;
	for(int i=0;i<block;i++)
	{
      ans += v[i][c];
      c = c^arr1[i*sz+sz-1];
      p = p^arr1[i*sz+sz-1];
	}
	//cout << ans <<" " << p << endl;
	for(int i=block*sz;i<=idx;i++)
	{
      if((p^arr[i])==k)
      	ans++;
      p=p^arr[i];
	}
	return ans;	
}
int main()
{
  sync;
  int n,q;
  cin >> n >> q;
  lindx = n-1;
  sz = ceil(sqrt(n));
  for(int i=0;i<n;i++)
  	cin >> arr[i];
  build(n);
  while(q--)
  {
  	int t;
  	cin >> t;
  	if(t==1)
  	{
  	  int idx,val;
  	  cin >> idx >> val;
  	  update(idx-1,val);
  	}
  	else
  	{
  		int idx,k;
  		cin >> idx >> k;
  		cout << query(idx-1,k) << endl;
  	}
  }
}
