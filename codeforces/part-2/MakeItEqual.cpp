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

const int MAX = 2e5+7;
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
int arr[MAX],arr1[MAX];
int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  int req = INT_MAX;
  for(int i=0;i<n;i++)
  	cin >> arr[i],req=min(req,arr[i]),arr1[i]=arr[i];

  sort(arr,arr+n);
  sort(arr1,arr1+n);
  for(int i=1;i<n;i++)
  	arr[i]+=arr[i-1];
  int lastGood = n-1,ans=0,cGood=-1,tot=-1,last=-1;
  for(int i=arr1[n-1]-1;i>=req;i--)
  {
  	//cerr << i << endl;
  	int idx = upper_bound(arr1,arr1+lastGood+1,i)-arr1;
  	tot = arr[lastGood]-arr[idx-1<0 ? 0 : idx-1]-(i*(lastGood-idx+1))+(n-1-lastGood)*(arr1[lastGood]-i);
  	//cerr << idx <<"  " << tot << " " << arr[lastGood] << lastGood << endl;
    if(tot <= k)
  	{
  		last = idx;
  	}
  	if(tot > k)
  	{
  		ans++;
  		lastGood = last;
      //cerr << "hi" << lastGood << endl;
  		arr1[lastGood] = i+1;
  		arr[lastGood] = arr[lastGood-1]+(i+1);
  		i++;
  		tot=-1;
  	}
  }
  if(tot>=0 && tot <= k)
  	ans++;
  cout << ans << endl;
}
