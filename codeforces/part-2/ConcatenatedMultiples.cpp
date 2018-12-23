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

int arr[MAX];
vector<map<int,int> > v(11); 
int getDigit(int num)
{
	int cnt=0;
	while(num)num=num/10,cnt++;
	return cnt;
}
int main()
{
  sync;
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;i++)
  	cin >> arr[i];
  for(int i=0;i<n;i++)
  {
  	v[getDigit(arr[i])][arr[i]%k]++;
  }
  ll ans = 0;
  for(int i=0;i<n;i++)
  {
  	unsigned ll num = arr[i];
  	int len = getDigit(arr[i]) ;
  	for(int j=1;j<=10;j++)
  	{
  		num = num*10;
  		int req = (k-(num%k))%k;
  		ans = ans + v[j][req];
  		if(len == j && req == (arr[i]%k))
  			ans--;
  	}
  }
  cout << ans << endl;
}
