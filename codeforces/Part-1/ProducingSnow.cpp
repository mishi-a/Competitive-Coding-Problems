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

vector<ll> arr(100005),temp(100005);
ll csum[100005],bias[100005];
int main()
{
  sync;
  ll n;
  cin >> n;
  for(ll i=1;i<=n;i++)
  	cin >> arr[i];
  for(ll j=1;j<=n;j++)
  	cin >> temp[j];

  for(ll j=1;j<=n;j++)
  	temp[j]+=temp[j-1];
  // for(int j=1;j<=n;j++)
  // 	cout << temp[j] << " ";
  // cout << endl;
  ll val;
  ll ans = 0;
  for(ll i=1;i<=n;i++)
  {
     vector<ll>::iterator it = lower_bound(temp.begin()+i,temp.begin()+n+1,(arr[i]+temp[i-1]));
     if(it == temp.begin()+n+1)
     {
     	val = n;
     }
     else
     {
     	val = it-(temp.begin());
     }
     
     csum[i]++;
     csum[val]--;
     ll x = temp[val]-temp[i-1];
     ll used = temp[val-1]-temp[i-1];
     if(x>=arr[i])
     {
     	bias[val]+=(arr[i]-used);
     }
     else
        bias[val]+=(temp[val]-temp[val-1]);	
     //if(x>arr[i]temp[val]-temp[val-1])
    //cout << i <<" " << val << " " << temp[val] << " "<< bias[val] << endl;
  }
  // for(int i=1;i<=n;i++)
  // 	cout << csum[i] << " " << bias[i] << endl;
  for(ll i=1;i<=n;i++)
  	csum[i]+=csum[i-1];
  for(ll i=1;i<=n;i++)
  {
  	cout << (temp[i]-temp[i-1])*csum[i]+bias[i] << " ";
  }

}
