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
int arr[105];
int main()
{
  sync;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sum = 0;
  for(int i=0;i<s.size();i++)
  {
  	arr[i] = s[i]-'0';
  	sum += s[i]-'0';
  }
  for(int i=2;i<=n;i++)
  {
  	if(sum%i == 0)
  	{
  		int req = sum/i;
  		int flag = 0;
  		int p = 0,cnt = 0;
  		for(int j=0;j<n;j++)
  		{
  			p+=arr[j];
  			//cout << p << endl;
  			if(p == sum/i)
  			{
  				p = 0;
  				cnt++;
  			}	
  			else if(p > sum/i)
  			{
  				flag = 1;
  				break;
  			}
  		}
  		//cout << i << " " << flag << " " << cnt << endl;
  		if(flag == 0 && cnt == i)
  		{
  			cout << "YES" << endl;
  			return 0;
  		}
  	}
  }
  cout <<"NO" << endl;  
}
