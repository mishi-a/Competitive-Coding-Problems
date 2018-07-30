#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

vector <ll> v;
vector <ll> v1;
vector <ll> v2;
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
         int n;
          cin >> n;
          ll csum = 0;
          v.pb(-1);
          v1.pb(-1);
          v2.pb(-1);
          for(int i=0;i<n;i++)
          {
            ll x;
            cin >> x;
            csum+=x;
            v.pb(x);
          }
          v1.pb(1);
          ll max = 1;
          for(int i=2;i<=n;i++)
          {
             max++; 
            if(v[i]>=max)
            {
              v1.pb(max); 
            }
            else
            {
              v1.pb(v[i]);
              max = v[i];
            }
           
          }
          v2.pb(1);
          max = 1;
          for(int i=n-1;i>0;i--)
          {
            max++;
            if(v[i]>=max)
            {
              v2.pb(max); 
            }
            else
            {
              v2.pb(v[i]);
              max = v[i];
            }
            
          }
          reverse(v2.begin()+1,v2.end());
          for(int i=1;i<=n;i++)
          {
            ll x = min(v1[i],v2[i]);
            v2[i] = x;
          }
          ll mux = *max_element(v2.begin()+1,v2.end());
          cout << csum-mux*mux << endl;
          v.clear();
          v1.clear();
          v2.clear();
   }
}
