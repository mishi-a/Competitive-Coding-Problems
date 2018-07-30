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
int arr[10005];
int main()
{
  sync;
  int n;
  cin >> n;
  int fib1 = 0, fib2 = 1, fib3 = 1;
    arr[fib1] = 1;
    arr[fib2] = 1;
    //cout << "The Fibonacci Series is follows : " << endl << fib1 << " " << fib2 << " ";
    while (fib1 + fib2 < 5000)
    {
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
        arr[fib3] = 1;
    }
    for(int i=1;i<=n;i++)
    {
    	if(arr[i])
    		cout << "O";
    	else
    		cout << "o";
    }
}
