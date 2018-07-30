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
vector <ll> neg;
vector <ll> negsum;

ll sum,tot;

bool acompare(ll a,ll b)
{
  return sum+(tot+1)*a > sum+(tot+1)*b;
}

void solve()
{
  int n;
  cin >> n;
  sum = 0,tot = 0;
  while(n--)
  {
    ll a;
    cin >> a;
    a >= 0 ? sum = sum+a : sum = sum; 
    if(a>=0) tot++;
    if(a<0)
      neg.pb(a);
  }
  ll res = sum;
  sort(neg.begin(),neg.end(),acompare);
  int j =neg.size();
  for(int i=0;i<neg.size();i++)
  {
    i==0 ? negsum.pb(neg[i]) : negsum.pb(neg[i]+negsum[i-1]);
  }
  ll csum = res*tot;
  //cout << csum << endl;
  for(int i=0;i<negsum.size();i++)
  {
    //cout << (sum+negsum[i])*(tot+1) << "  " <<  csum-neg[i] << endl;
    if((sum+negsum[i])*(tot+1) < csum+neg[i])
    { 
      //cout << "hi" << endl;
      j = i;
      break;
    }
    else
    {
      tot!=0 ? csum =  ((csum/tot)+neg[i])*(tot+1) : csum = (csum + neg[i])*(tot+1);
      tot++;
    }
  }
  res = csum;
  for(int i=j;i<neg.size();i++)
  {
    res = res+neg[i];
  }
  cout << res << endl;
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
    neg.clear();
    negsum.clear();
  }
}

