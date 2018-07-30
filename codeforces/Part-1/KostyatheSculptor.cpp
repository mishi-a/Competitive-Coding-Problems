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

map <pii,pair<pii,pii > > mp;
int main()
{
  sync;
  int n;
  cin >> n;
  int r = 0;
  int index1,index2;
    int flag = 0;
  for(int i=0;i<n;i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    vector <int> v;
    v.pb(a);
    v.pb(b);
    v.pb(c);
    sort(v.begin(),v.end());
    
    if(v[0] >= r)
    {
      r = v[0];
      flag = 1;
      index1 = i;
    }
      
    if(mp.find({v[1],v[2]})!=mp.end())
    {
      if(mp[{v[1],v[2]}].FI.SE == 0)
      {
        mp[{v[1],v[2]}].FI.SE = v[0];
        mp[{v[1],v[2]}].SE.SE = i;
        if(min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI) > r)
        {
          r = min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI);
          flag = 0;
          index1 =  mp[{v[1],v[2]}].SE.FI;
          index2 =  mp[{v[1],v[2]}].SE.SE;
        }
      }
      else
      {
        int val = mp[{v[1],v[2]}].FI.FI + mp[{v[1],v[2]}].FI.SE;
        if(val < mp[{v[1],v[2]}].FI.FI + v[0] && val < mp[{v[1],v[2]}].FI.SE + v[0] )
        {
           if(mp[{v[1],v[2]}].FI.FI < mp[{v[1],v[2]}].FI.SE )
           {
             mp[{v[1],v[2]}].FI.FI = v[0];
             mp[{v[1],v[2]}].SE.FI = i;
            if(min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI) > r)
            {
                r = min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI);
                flag = 0;
                index1 =  mp[{v[1],v[2]}].SE.FI;
                index2 =  mp[{v[1],v[2]}].SE.SE;
            }       
           }
           else
           {  
             mp[{v[1],v[2]}].FI.SE = v[0];
             mp[{v[1],v[2]}].SE.SE = i; 
             if(min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI) > r)
            {
                r = min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI);
                flag = 0;
                index1 =  mp[{v[1],v[2]}].SE.FI;
                index2 =  mp[{v[1],v[2]}].SE.SE;
             }
            
           } 
        }
        else if(val < mp[{v[1],v[2]}].FI.FI + v[0])
        {
             mp[{v[1],v[2]}].FI.SE = v[0];
             mp[{v[1],v[2]}].SE.SE = i;
             if(min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI) > r)
            {
                r = min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI);
                flag = 0;
                index1 =  mp[{v[1],v[2]}].SE.FI;
                index2 =  mp[{v[1],v[2]}].SE.SE;
             }
            
        }
        else if(val < mp[{v[1],v[2]}].FI.SE + v[0])
        { 
             mp[{v[1],v[2]}].FI.FI = v[0];
             mp[{v[1],v[2]}].SE.FI = i;
             if(min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI) > r)
            {
                r = min(min(v[1],v[2]),mp[{v[1],v[2]}].FI.SE+mp[{v[1],v[2]}].FI.FI);
                flag = 0;
                index1 =  mp[{v[1],v[2]}].SE.FI;
                index2 =  mp[{v[1],v[2]}].SE.SE;
            }
        }
      
      }
    }
    else
    {
      mp[{v[1],v[2]}] = {{v[0],0},{i,0}};
    }
  }
  if(flag == 1)
  {
    cout << "1" << endl;
    cout << index1+1 << endl;
  }
  else
  {
    cout << "2" << endl;
    cout << index1+1 << " " << index2+1  << endl;
  }
  //cout << r << endl;
  
} 

