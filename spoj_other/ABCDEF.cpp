#include <iostream>
#include <vector>
#include <algorithm>


#define pb push_back
#define sync ios::sync_with_stdio
#define endl '\n'
#define ll long long
using namespace std;
vector <ll> lhs;
vector <ll> rhs;
vector <ll> v(105);
ll res = 0;


void cal (int flag,int n)
{
    for(int i=0;i<n;i++)
    {
     if(flag == 1)
     {
       if(v[i] == 0)
        continue;
     }
      for(int j=0;j<n;j++)
      {
        for(int k=0;k<n;k++)
        {
          if(flag == 1)
            rhs.pb(v[i]*(v[j]+v[k]));
          else
            lhs.pb(v[i]*v[j]+v[k]);
        }
      }
    }
}

ll bsearch(ll a)
{
 // cout << a << endl;
  int l = 0,r = rhs.size()-1;
  ll tot = 0;
  while(l<=r)
  {  
    int mid = (l+r)/2;
   // cout << l << " " << r << " " << mid <<endl;
    if(rhs[mid] == a)
    {  
      int x = mid+1;
      while(mid >=l && rhs[mid] == a)
      { //cout << "hi";
        tot++;
        mid--;
      }
      while(x<=r && rhs[x] == a)
      { //cout << "hi";
        tot++;
        x++;
      }
      return tot;
    }
    else if(rhs[mid] < a)
    {
      l = mid+1;
    }
    else
    {
      r = mid-1;
    }
  }
  return 0;
}

int main()
{ 
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> v[i];
  }
  cal(1,n);
  cal(0,n);
  sort(rhs.begin(),rhs.end());
  /*for(int i=0;i<lhs.size();i++)
  {
    cout << lhs[i] << " ";
  }
  cout << endl;
   for(int i=0;i<rhs.size();i++)
  {
    cout << rhs[i] << " ";
  }
  cout << endl;
  */
  for(int i=0;i<lhs.size();i++)
  {
    res = res + bsearch(lhs[i]);
  }
  cout << res << endl;
}
