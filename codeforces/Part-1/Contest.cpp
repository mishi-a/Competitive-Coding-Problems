/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

vector <int> v;
vector <int> csum;
int main()
{
  sync;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++)
  {
    i==0 ? csum.pb(v[i]) : csum.pb(csum[i-1]+v[i]);
  }
  int m;
  cin >> m;
  vector<int> :: iterator itr;
  int t = 0;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin >> a >> b;
    itr = lower_bound(csum.begin()+t,csum.end(),b);
    while(*itr > b && itr!=csum.begin()+t )
    {
      itr--;
    }
    if(*itr <= b)
    {
      t = itr - csum.begin()+1;
      if(itr == csum.end())
      {
        t--;
        itr--;
      }
      //cout << "hi" << t << endl;
    }
    if(t == n)
    {
         //    cout << *itr << "  " << "hi" << endl;
      *itr<a ? cout << a : cout << *itr;
      return 0;
    }
  }
  cout << "-1" << endl;
}

