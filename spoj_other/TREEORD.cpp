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
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;

vector <int> pre;
vector <int> post;
vector <int> in;
vector <int> npost;
vector <pii >v(8005,pii(-1,-1));
int root,n;

void construct(int rstart , int start,int end)
{
  
  if(start == end)
    return;
  if(end >= n)
    return;
  int root2 = pre[rstart];
  int i;
  for(i=start;i<=end;i++)
  {
    if(in[i] == root2)
      break;
  }
  if(i>start && i<end)
  {
    v[root2].FI = pre[rstart+1];
    v[root2].SE = pre[rstart+i+1];
    construct(rstart+1,start,i-1);
    construct(rstart+i+1,i+1,end);
  }
  else if(i==start)
  {
    v[root2].SE = pre[rstart+1];
    construct(rstart+1,i+1,end);
  }
  else if(i == end)
  {
    v[root2].FI = pre[rstart+1];
    construct(rstart+1,start,i-1);
  }
  return;
}
void postorder(int root)
{
  if(root == -1)
    return;
  postorder(v[root].FI);
  postorder(v[root].SE);
  npost.pb(root);
}
int main()
{
  sync;
  int a;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> a;
    pre.pb(a);
  }
  for(int i=0;i<n;i++)
  {
    cin >> a;
    post.pb(a);
  }
  for(int i=0;i<n;i++)
  {
    cin >> a;
    in.pb(a);
  }
  root = pre[0];
  construct(0,0,n-1);
  postorder(root);
  int flag = 0;
  for(int i=0;i<n;i++)
  {
    if(npost[i]!=post[i])
    {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}

