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

vector <ll> v;
ll csum[500005];

int main()
{
  sync;
  ll q;
  cin >> q;
  while(q--)
  {
  	int t;
  	cin >> t;
    if(t==1)
    {
    	ll x;
    	cin >> x;
    	v.pb(x);
    	(v.size()==1) ? (csum[0]=x) : (csum[v.size()-1]=x+csum[v.size()-2]);
    	//cout << csum[v.size()-1] << endl;
    }
    else
    {
    	ll l=0,r=v.size()-1;
        double cmean = v[v.size()-1];
        double mean = 1e18;  
    	while(l<=r)
    	{
    		ll mid = (l+r)/2;
    		cmean += csum[mid];
    		//cout << cmean << mid << endl;
    		if(mid == v.size()-1)
    			cmean -= v[v.size()-1],cmean/=(mid+1);
    		else
    			cmean = (cmean/(mid+2));
    		
    		if(v[mid]>=cmean)
    	    {
    	    	mean = min(cmean,mean);
    	    	r = mid-1;
    	    }
    	    else
    	    {	
    	    	l = mid+1;
    	    	mean = min(cmean,mean);
    	    }

    	    cmean = v[v.size()-1];
    	}
        cout << fixed << setprecision(10) ;
    	cout << v[v.size()-1] - mean << endl;
    }
  }

}
