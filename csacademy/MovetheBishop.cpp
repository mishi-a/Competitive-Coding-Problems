/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
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

//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;
int chess[10][10];
int main()
{
  sync;
  int r,c,r1,c1;
  cin >> r >> c >> r1 >> c1;
  if((r%2 == 0 && c%2==0) || (r%2==1 && c%2 == 1))
  {
    if((r1%2==0&&c1%2==1) || (r1%2==1 && c1%2==0))
      cout << "-1" << endl;
    else if(fabs(r-r1) == fabs(c-c1))
      cout << "1" << endl;
    else
      cout << "2" << endl;
  }
  else
  {
    if((r1%2 == 0 && c1%2==0) || (r1%2==1 && c1%2 == 1))
       cout << "-1" << endl;
     else if(fabs(r-r1) == fabs(c-c1))
      cout << "1" << endl;
    else
      cout << "2" << endl;
  }
}

