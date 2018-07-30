#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>
using namespace std;

vector <int> v;

void tackle_even()
{
  int mid = v.size()/2;
  int l = mid-1,r = mid;
  //cout << l << ":" << r << endl;
  int flag = 0;
  while(l>=0)
  { //cout << flag << endl;
    if(flag == 0)
    { 
      if(v[l] == v[r])
      {
        l--;
        r++;
      }
      else if(v[l] > v[r])
      {
        v[r] = v[l];
        flag = 1;
        l--;r++;
      }
      else
      {// cout << "hi" << endl;
        
        v[r] = v[l];
        l--;r++;
        flag = 2;
         if(flag == 2 && l<0)
       flag = 0;
      }
   }
   else
   { //cout << flag << endl;
     v[r] = v[l];
     l--;
     r++;
     if(flag == 2 && l<0)
       flag = 0;
   }
  }
  l = mid-1;
  r = mid;
  if(flag == 0)
  {
     while(flag!=1)
     {
       v[l]++;
       v[r]++;
       flag = 1;
       if(v[l] == 10)
       {
         v[l] = 0;
         v[r] = 0;
         l--;
         r++;
         flag = 0;
         if(l == -1)
         {
           cout << "1";
           break;
         }
       }
     }
  }
  for(int i=0;i<mid*2;i++)
  {
    if(flag == 0 && i== mid*2-1)
      continue;
    cout << v[i] ;
  }
  if(flag == 0)
    cout << "1";
  cout << endl;
}

void tackle_odd()
{
  int mid = v.size()/2;
  int l = mid-1;
  int r = mid+1;
  int flag = 0;
  while(l>=0)
  {
    if(flag == 0)
    {
      if(v[l] == v[r])
      {
        l--;
        r++;
      }
      else if(v[r] > v[l])
      {
        v[r] = v[l];
        l--;
        r++;
        flag = 2;
         if(flag == 2 && l<0)
       flag = 0;
      }
      else
      {
        v[r] = v[l];
        l--;
        r++;
        flag = 1;
      }
    }
    else 
    {
      v[r] = v[l];
      l--;
      r++;
      if(flag == 2 && l<0)
        flag = 0;
    }
  }
  int ind = mid;
  if(flag == 0)
  {
    v[ind] = v[ind]+1;
    flag = 1;
    if(v[ind] == 10){
    flag = 0;
    v[ind] = 0;
    int l = ind-1;
    int r = ind + 1;
     while(flag!=1)
     {
      v[l]++;
      v[r]++;
      flag = 1;
      if(v[l] == 10)
      {
        v[l] = 0;
        v[r] = 0;
        l--;
        r++;
        flag = 0;
        if(l<0)
        {
          cout << "1";
          break;
        }
      }
    }
  }
 }
   for(int i=0;i<mid*2+1;i++)
  {
     if(flag == 0 && i== mid*2)
      continue;
    cout << v[i] ;
  }
  if(flag == 0)
    cout << "1";
  cout << endl;
}
 
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--){
  v.clear();
  string n;
  cin >> n;
  if(n[0]-'0'==9 && n.length() == 1)
  {
    cout << "11\n";
    continue;
  }
  for(int i=0;i<n.length();i++)
  {
    v.pb(n[i]-'0');
  }
  // reverse(v.begin(),v.end());
  
  if(v.size()&1)
  {
    tackle_odd();
  } 
  else
  {
    tackle_even();
  }
  }
}
