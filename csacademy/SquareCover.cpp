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

int arr[305][305];
set <int> s;
vector <vector<int> > hor(100005);
vector <vector<int> >ver(100005);
int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin >> arr[i][j];
      s.insert(arr[i][j]); 
      hor[arr[i][j]].pb(j);
      ver[arr[i][j]].pb(i);   
    }
  }
  set <int>:: iterator itr = s.begin();
  while(itr!=s.end())
  {
    int num = *itr;
    sort(hor[num].begin(),hor[num].end());
    //sort(ver.begin(),ver.end());
    int xstart = hor[num][0];
    int xend = hor[num][hor[num].size()-1];
    int ystart = ver[num][0];
    int yend = ver[num][ver[num].size()-1];
    if(xend-xstart == yend-ystart)
    {
       for(int i=ystart;i<=yend;i++)
       {
         for(int j=xstart;j<=xend;j++)
         {
           if(arr[i][j]!=num)
           {
             cout << "0" << endl;
             return 0;
           }
         }
       }
    }
    else
    {
      cout << "0" << endl;
      return 0;
    }
    itr++;      
  }
  cout << "1" << endl;
}

