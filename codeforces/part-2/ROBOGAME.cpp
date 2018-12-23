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

int arr[55];

bool check(int idx,int idx1,int n)
{
	//cerr << idx << " " << idx1 << endl; 
	if(arr[idx]+arr[idx1] < idx1-idx)
		return true;
	else
		return false;
}


int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	vector<int> v;
  	string s;
  	cin >> s;
  	for(int i=0;i<s.size();i++)
  	{
  		if(s[i] == '.')
  			arr[i]=0;
  		else
  			arr[i] = s[i]-'0',v.pb(i);
  	}
  	if(v.size() <= 1)
  	{
  		cout << "safe" << endl;
  		continue;
  	}
  	else
  	{
  		int flag = 0;
  		for(int i=0;i<v.size()-1;i++)
  		{
  			flag = 0;
  			if(!check(v[i],v[i+1],s.size()))
  			{
  				cout << "unsafe" << endl;
  				flag = 1;
  				break;
  			}
  		}
  		if(flag == 0)
  		{
  			cout << "safe" << endl;
  		}
  	}
  }
}
