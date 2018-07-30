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

unordered_map<ll, ll> mp;
inline ll lca(ll v, ll u, ll w = -1){
	ll ans = 0;
	while(v != u){
		if(v < u)	swap(v, u);
		if(mp.find(v) != mp.end())	ans += mp[v];
		if(~w)	mp[v] += w;
		v >>= 1;
	}
	return ans;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		int type;
		ll v, u;
		cin >> type >> v >> u;
		if(type == 1){
			ll w;
			cin >> w;
			lca(v, u, w);
		}
		else
			cout << lca(v, u) << '\n';
	}
	return 0;
}

