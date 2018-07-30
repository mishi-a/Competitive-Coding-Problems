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
#define ull unsigned long long
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

ll f[100005];
string b = "What are you doing at the end of the world? Are you busy? Will you save us?";
string a = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
char solve(ll val,ull idx)
{
   if(idx>=f[val])
   	return '.';
   if(val == 0)
   {
   		return a[idx];
   }
   else 
   {
   	if(idx<34)
   		return b[idx];
   	idx-=34;
   	if(f[val-1]>idx )
   		return solve(val-1,idx);
   	idx-=f[val-1];
   	if(idx<32)
   		return b[idx+34];
   	idx-=32;
    if(f[val-1]>idx )
   		return solve(val-1,idx);
   	idx-=f[val-1];
   	return b[idx+66];

   }
}

int main()
{
  sync;
  ll q;
  cin >> q;
  f[0] = 75;
  for(ll i=1;i<=100000;i++)
  	f[i] = 2*f[i-1]+68;
  while(q--)
  {
  	ll n;
  	ull k;
  	cin >> n >> k;
  	cout << solve(n,k-1);
  }
}
