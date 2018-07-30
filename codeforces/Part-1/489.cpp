#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector<int> v;
int main()
{
  sync;
  int m,s;
  cin >> m >> s;
  if(m == 1 && s == 0)
  {
    cout << "0" << " 0" << endl;
    return 0;
  }
  int counter = 9;
  while(s>0)
  {
    if(s-counter >=1 && m-1>0 )
    {
      s -=counter;
      v.pb(counter);
      m-=1;
    }
    else if(m-1 == 0 && s-counter == 0)
    {
        v.pb(counter);
        s = 0;
        m-=1;
    }
    else
       --counter;
    if(counter < 0 && s == 1)
    {
      v.pb(1);
      s=0;
    }
    if(counter <0 && s > 1)
    { 
       cout << "-1" << " -1" ;
    return 0; 
      break;}
  }
  if(v.empty())
  {
    cout << "-1" << " -1" ;
    return 0; 
  }
  vector<int> :: iterator itr;
  if(v[0] == 0)
  {
     reverse(v.begin(),v.end());
     for(itr = v.begin();itr!=v.end();itr++)
     {
       cout << *itr ;
     }
      cout << " " ;
       for(itr = v.begin();itr!=v.end();itr++)
     {
       cout << *itr ;
     }
     return 0;
  }
  reverse(v.begin(),v.end());
  for(itr = v.begin();itr!=v.end();itr++)
  {
    cout << *itr ;
  }
  cout << " " ;
  sort(v.begin(),v.end(),greater<int>());
  int x = v.size();
  for(int i=0;i<x;i++)
  {
    for(int j=i+1;j<x;j++)
    {
      if(v[i]+v[j] <= 9)
      {
        v[i]+=v[j];
        v[j] = 0;
      }
      else
      {
        v[i] = 9;
        v[j] = v[j] - (9-v[i]);
      }
    }
  }
  for(itr = v.begin();itr!=v.end();itr++)
  {
    cout << *itr ;
  }
  return 0;
}
