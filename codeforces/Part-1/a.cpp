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

bool check(int a,int b)
{
  if(a < 10 && b >=10)
  {
    if(b%10 == 0 && a == b/10)
      return true;
    else
      return false; 
  }
  else if(a>=10 && b < 10)
  {
    if(b == a/10 && a%10 == 0 )
      return true;
    else
      return false;
  }
  else if(a <10 && b < 10)
  {
    if(a == b)
      return true;
    else
      return false;
  }
  else
  {
  
    if(a%10 == b/10 && a/10 == b%10)
      return true;
    else
      return false;
  }
}

int main()
{
  sync;
  string s;
  cin >> s;
  int a = (s[0]-'0')*10 + (s[1]-'0');
  int b = (s[3]-'0')*10 + (s[4]-'0');
  int flag = 0;
  int x,y;
  int cnt = 0;
  for(int i = a;i<=24;)
  {
    if(i == 24)
      i = 0;
    for(int j = b;j<60;j++)
    {
     if(check(i,j))
     {
       flag = 1;
       x = i;
       y = j;
       break;
     }
     cnt++;
    }
    if(flag == 1)
      break;
    b = 0;
    i++;
  }
  cout << cnt << endl;
  
}

