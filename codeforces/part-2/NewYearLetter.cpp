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

string arr[] = {"AC","CA","AA","CC","DD"};

void print(int idx,int cnt)
{
	cout << arr[idx][0];
	for(int i=0;i<cnt;i++)
		cout <<"AC";
	cout << arr[idx][1];
}

int solve(int c0,int c1,int k,int x,int n,int m)
{
	if(n-2*c0)
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			pair<int,string> s1 = {c0,arr[i]};
			pair<int,string> s2 = {c1,arr[j]};
			for(int i=3;i<=k;i++)
			{
				int tot = c0+c1;
				if(s1.SE[1] == 'A' && s2.SE[0] == 'C')
					tot++;
				string s = "";
				s+=s1.SE[0],s+=s2.SE[1];
				pair<int,string> s3 = {tot,s};
				s1 = s2;
				s2 = s3;
			}
			if(s2.FI == x)
			{
				//print string s1
				cerr << i << " " << j << " " << c0 << " " << c1 << endl;
				print(i,c0);
				cout << endl;
				print(j,c1);
				return 1;
			}

		}

	return 0;
}

int main()
{
  sync;
  ll k,x,n,m;
  cin >> k >> x >> n >> m;
  ll l = n/2,r=m/2;
  for(int i=0;i<=l;i++)
  {
  	for(int j=0;j<=r;j++)
  	{
  		if(solve(i,j,k,x,n,m)) return 0;
  	}
  }
  cout << "Happy new year!" << endl;
}
