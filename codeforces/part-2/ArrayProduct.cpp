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

const int MAX = 1e5;
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
long arr[2*MAX+7];
vector<int> v;
vector<int>v1;
int main()
{

  long  mun = LONG_MIN;
  sync;
  int n;
  cin>>  n;
  int ncnt=0,idx= -1;
  for(int i=1;i<=n;i++)
  {
  	cin >> arr[i];
  	if(arr[i]==0)
  		v.pb(i);
  	else
  		v1.pb(i);
  	if(arr[i]<0)
  	{
  		if(arr[i]>mun)
  		{
  			mun  =  arr[i];
  			idx= i;
  		}
  		ncnt++;
  	}
  }
  //cout << ncnt <<  " " << idx  << endl;
  for(int i=0;v.size()>0&&i<(v.size()-1);i++)
  {
  	cout  <<  1  << " " << v[i]<<" "<<  v[i+1]<<endl;
  }
  int sz  = v1.size();
  if(ncnt%2 && v.size()  >= 1)
  {
  	sz--;
  	cout  <<  1  <<  " " << idx  << " "  <<  v[v.size()-1]  <<  endl;
  }
  if(v.size()  >= 1  && sz >0)
  	cout  <<  2  << " "  <<v[v.size()-1]  << endl;
  if(v.size() == 0 &&  ncnt%2)
  {
  	cout <<  2  <<  " " << idx <<  endl;
  }
  if(ncnt%2 ==0)
  	idx =-1;
  vector<int>  v2;
  for(int i=0;i<v1.size();i++)
  {
  	if(v1[i]!=idx)
  		v2.pb(v1[i]);
  }
  for(int i=0;v2.size()>0&& i<v2.size()-1;i++)
  {
  		cout  <<  1  << " " << v2[i]<<" "<<  v2[i+1]<<endl;	
  }
}
