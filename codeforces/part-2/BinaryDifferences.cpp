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

int arr[100005],csum[100005];

int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
  	cin >> arr[i];
  	if(arr[i]==0)
  		arr[i]=-1;
  }
  int ans = 0;
  int ans1 = 0;
  int csum=0,csum1=0;
  for(int i=1;i<=n;i++)
  {
     csum+=arr[i];
     csum1+=arr[i];
     if(csum<0)
       csum=0;
     if(csum1>0)
       csum1 = 0;

     ans = max(ans,csum);
     ans1 = min(ans1,csum1);
     //cout << csum << endl;   
  }
  //cout << ans << " " << ans1 << endl;
  cout << ans-ans1+1 << endl;

}
