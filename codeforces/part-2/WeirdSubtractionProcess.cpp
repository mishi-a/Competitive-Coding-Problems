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
ll a,b;
void fun()
{
  	a = a%(2*b);
  	if(a==0)
  		cout << a << " " << b << endl;
  	else
  	{
  		if(b>=2*a)
  		{
           b = b%(2*a);
           if(a>=2*b&&b!=0)
           	fun();
           else
           	cout << a << " " << b << endl;
  		}
  		else
  		{
  			cout << a << " " << b << endl;
  		}
  	}
}
void fun1()
{
           b=b%(2*a);
           if(a>=2*b&&b!=0)
           	fun();
           else
           	cout << a << " " << b << endl;
}
int main()
{
  sync;
  cin >> a >> b;
  if(a==0||b==0)
  	cout << a << " " << b << endl;
  else if(a>=2*b)  
  {
  	fun();
  }
  else if(b>=2*a)
  {
  	 fun1();
  }
  else
  {
  	cout << a << " " << b << endl;
  }
}