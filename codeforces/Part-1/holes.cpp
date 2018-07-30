/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
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
	if(par[y] < par[x])	// balancing the height of the trees
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/
		

using namespace std;

int arr[100005],cnt[100005],next1[100005],last[100005];
int n,m,sz;

void query(int idx)
{
	int ans = 0,ans1;
    int sblock = idx/sz;
    while(idx!=-1)
    {
      ans+=cnt[idx];
      ans1 = last[idx];
      idx = next1[idx];
    } 
    cout << ans1+1<< " " << ans << endl;
}

void update(int idx,int val)
{
	int block = idx/sz;
	int end = sz*block;
	int len = end+sz-1;
	if(len>n-1)
		len=n-1;
	arr[idx]=val;
	for(int i=idx;i>=end;i--)
	{
       cnt[i] = i+arr[i]>len ? 1 : 1+cnt[i+arr[i]];
       next1[i] = i+arr[i] > len ?(i+arr[i]<n ? i+arr[i]:-1):next1[i+arr[i]];
       last[i] = i+arr[i]>len ? i : last[i+arr[i]]; 
	}

}

int main()
{
  sync;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  	cin >> arr[i];
  sz = ceil(sqrt(n));
  int cur = n/sz;
  int len = n-1;
  cnt[n-1]=1,next1[n-1]=-1,last[n-1]=n-1;
  for(int i=n-2;i>=0;i--)
  {
    if(i/sz < cur)
    {
      cur--;
      len = i;
    }
    cnt[i] = i+arr[i]>len ? 1 : 1+cnt[i+arr[i]];
    next1[i] = i+arr[i] > len ?(i+arr[i]<n ? i+arr[i]:-1):next1[i+arr[i]];
    last[i] = i+arr[i]>len ? i : last[i+arr[i]]; 
  }
  int type,a,b;
  for(int i=0;i<m;i++)
  {
    cin >> type;
    if(type == 0)
    { 
        cin >> a >> b;
        update(a-1,b);
    }
    else
    {
    	cin >> a;
    	query(a-1);
    }
  }
}
