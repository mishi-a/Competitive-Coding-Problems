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

//D-S-U



using namespace std;

int par[100];
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y)
{ 
  if((x = root(x)) == (y = root(y)))
       return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}

void solve()
{
	int n;
	int arr[55];
	cin >> n;
	int odd = 0,even =0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		par[i] = -1;
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]&1)
			odd++;
		else
			even++;
	}
	for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(__gcd(arr[i],arr[j]) == 1)
					merge(i,j);
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		if(par[i]<0)
			cnt++;
	}
	//cerr << cnt << endl;
	if(cnt == 1)
	{
		cout << "0" << endl;
		for(int i=0;i<n;i++)
			cout << arr[i] << " ";
		cout << endl;	
		return;
	}
	if(odd > 0 && even > 0)
	{
		cout << "1 \n43 ";
		for(int i=1;i<n;i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else if(even > 0)
	{
		cout << "1 \n43 ";
		for(int i=1;i<n;i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		cout << "1 \n2 ";
		for(int i=1;i<n;i++)
			cout << arr[i] << " ";
		cout << endl;
	}
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  	solve();
}
