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
std::vector<int> v(10,-1);
int arr[10]={0};
int main()
{
  sync;
  int n;
  cin >> n;
  char a,p;
  int b;
  int cur = 0;
  for(int i=0;i<n;i++)
  {
  	cin >> a >> b;
  	if(a=='|')
  	{
      for(int i=0;i<=9;i++)
      {
      	if(b&(1<<i))
      	{
      		v[i]=1;
      	}
      }
  	}	
  	else if(a=='&')
  	{
       for(int i=0;i<=9;i++)
      {
      	if(!(b&(1<<i)))
      	{
      		v[i]=0;
      	}
      }
  	}
  	else
  	{
      for(int i=0;i<=9;i++)
      {
      	if(b&(1<<i))
      	{
      		if(v[i]==1)
      			v[i]=0;
      		else if(v[i]==0)
      			v[i]=1;
      		else 
      		{
      			arr[i]++;
      		}
      	}
      }
  	}
  }
  cout << "3" << endl;
  cout << "| ";
  int val = 0;
  for(int i=0;i<=9;i++)
  {
    if(v[i]==1)
    	val+=pow(2,i);
  }
  cout << val << endl;
  cout << "& ";
  val = 0;
  for(int i=0;i<=9;i++)
  {
  	if(v[i]!=0)
  		val+=pow(2,i);
  }
  cout << val << endl;
  cout << "^ ";
  val = 0;
  for(int i=0;i<=9;i++)
  {
    if(v[i]==-1&&(arr[i]%2==1))
    {
    	val+=pow(2,i);
    }
  }
  cout << val << endl;
}
