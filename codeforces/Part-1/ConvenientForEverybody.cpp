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

int arr[100005];

int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
  	cin >> arr[i];
  	arr[i]+=arr[i-1];
  	//cout << arr[i] << " ";
  }
  //cout << endl;
  int s,f;
  cin >> s >> f;
  int ans = 0;
  int res = -1;
  f--;
  for(int i=1;i<=n;i++)
  {
     if(i<=s)
     {
        int idx = s+1-i;
        if(arr[f+1-i]-arr[idx-1] > ans)
        {
        	ans = max(ans,arr[f+1-i]-arr[idx-1]);
        	res = i;
        } 	
        	
     }
     else
     {
       int idx = n-i+1;
       idx +=(s);
       if(f<i)
       { 
          if(arr[idx+(f-s)]-arr[idx-1]>ans)
          {
          	ans = max(ans,arr[idx+(f-s)]-arr[idx-1]);
        	res = i;
          }
       }
       else
       {
           int val = arr[n]-arr[idx-1];
           if(val+arr[f-i+1]>ans)
           {
           	ans = max(ans,val+arr[f-i+1]);
        	res = i;
           }
       }
     } 
     //cout << ans << " " << res << " " << i << endl; 
  }
  cout << res << endl;
}
