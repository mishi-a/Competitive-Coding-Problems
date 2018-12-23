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

const int MAX = 5e7+7;
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

int arr[MAX];
int main()
{
  sync;
  int t,tot=1;
  cin >> t;
  while(t--)
  {
  	cout << "Case #"<<tot<< ": ";
  	tot++;
  	int n;
  	cin >> n;
  	string s;
  	cin >> s;
  	for(int i=0;i<n;i++)
  		arr[i] = s[i]-'0';
  	for(int i=1;i<n;i++) arr[i]+=arr[i-1];

  	int ans = INT_MIN;
  	//ans = max(ans,arr[n-1]-(n/2-1>=0 ? arr[n/2-1]:0));
  	int destroyed = n/2;
  	for(int i=0;i<=n/2;i++)
  	{
  		int right = n/2-i;
  		ans = max(arr[n-right-1]-arr[i-1],ans);
  	} 	
  	cout << ans << endl;						
  }
}
