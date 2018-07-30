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

vector<pair<ll,ll> > v;
ll cunt = 0;
ll last;
void fund(ll start, ll end)
{
    if(start == last)
    {
      cunt++;
      if(cunt > 1000000007)
        cunt = cunt%100000000;
      return;
    }
    // If start time of activity is less than present activity end time so don't select it
    if(v[start].first < end)
       fund(start+1,end);
    else
    {
      //select present activity change end to end time of present activity
      fund(start+1,v[start].second);
       //don't select present activity so end will not change
      fund(start+1,end);
    }
    
}

int main()
{
  sync;
  while(1)
  {
    ll n;
    cin >> n;
    last = n;
    if(n == -1)
      break;
    for(int i=0;i<n;i++)
    {
      ll a,b;
      cin >> a >> b;
      v.pb({a,b});
    }
    sort(v.begin(),v.end());
    //This is recursive function to calculate result i.e total activies
    fund(0,-1);
    ll res = cunt - 1;
    int tot = 0;
    while(res!=0)
    {
      res=res/10;
      tot++;
    }
    for(int i=0;i<8-tot;i++)
      cout << "0";
    // subtracting -1 as there will be case when none of the activities is selected
    cout << cunt-1 << endl;
    v.clear();
    cunt = 0;
  }
}


