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
int arr[26] = {0};
int main()
{
  sync;
  string s,p;
  cin >> s >> p;
  for(int i=0;i<s.length();i++)
     arr[s[i]-'a']++;
  int t;
  cin >> t;
  while(t--)
  {
    string q;
    cin >> q;
    int j =0;
    int flag = 0;
    int i;
    for(i=0;i<q.length() && j <p.length();)
    {
      if(p[j] == '?')
      {
        if(arr[q[i]-'a'] == 0)
        {
          flag = 1;
          break;
        }
        else
        {
          i++;
          j++;
        }
      }
      else if(p[j] == '*')
      {
        int x = 0;
        while(arr[q[i]-'a'] == 0 && i < q.length())
           i++;
        j++;
      }
      else if (p[j] == q[i])
      {
         i++;
         j++;
      }
      else
      {  
         flag = 1;
         break;
      }
    }
    //cout << flag << j << i << endl;
    if(flag == 1 || i < q.length())
      cout << "NO" << endl;
    else if(j < p.length()-1)
      cout << "NO" << endl;
    else if( j == p.length()-1 && p[j]!='*')
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}

