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

vector <int > prime;
map <int,pii > mp;
void doing()
{
  prime.pb(2);
  for(int i=3;i<=100;i++)
  {
    int flag = 0;
    for(int j=2;j*j<= i;j++)
    {
      if(i%j == 0)
      {
        flag = 1;
        break;
      }
    }
    
    if(flag == 0)
      prime.pb(i);
  }
}

void pre()
{
  for(int i=0;i<prime.size();i++)
  {
    for(int j=0;j<prime.size();j++)
    {
      mp[prime[i]+(prime[j]*prime[j])] = {i,j};
    }
  }
}


int main()
{
  sync;
  doing();
  pre();
  while(1)
  {
    int n;
    cin >> n;
    if(n==0)
      break;
    int flag = 0;
    for(int i=0;i<prime.size();i++)
    {
      if(mp.find(n-(prime[i]*prime[i]*prime[i]))!=mp.end())
      {
        cout << prime[i] << " " << prime[mp[n-(prime[i]*prime[i]*prime[i])].FI] << " " << prime[mp[n-(prime[i]*prime[i]*prime[i])].SE] << endl;
        flag = 1;
        break;
      }
    }
    if(flag == 0)
     cout << "0 0 0" << endl;    
  }
}

