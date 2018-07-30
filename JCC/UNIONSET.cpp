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

vector<pair<pair<int,int> ,vector<int> > > v(2505);
set <int> se;
bool acompare(pair <pair<int,int> ,vector<int> > a,pair <pair<int,int> ,vector<int> >b)
{
  return a.first.first < b.first.first;
}
void solve()
{
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;i++)
  {
    int a,b,sum = 0;
    cin >> a;
    v[i].first.first = a;
    for(int j=0;j<a;j++)
    {
      cin >> b;
      sum+=b;
      v[i].second.pb(b);
    }
    v[i].first.second = sum;
    
  }
  int rsum = (k*(k+1))/2;
  sort(v.begin(),v.begin()+n,acompare);
  int tot = 0;
  //pair<vector<int>::iterator,vector<int>::iterator> bounds;
  for(int i=0;i<n;i++)
  {
    for(int k=0;k<v[i].second.size();k++)
    {
        se.insert(v[i].second[k]);
    }
    for(int j=i+1;j<n;j++)
    {
      //cout << "hi" << endl;
      if(v[i].first.second + v[j].first.second < rsum)
        continue;
      if(v[i].first.first + v[j].first.first < k)
        continue;
      int s = 0;
      for(int k=0;k<v[j].second.size();k++)
      {
        if(se.find(v[j].second[k]) == se.end())
          s++;
      }
      if(se.size() + s == k)
        tot++;
    }
    se.clear();
  }
  cout << tot << endl;
  for(int i=0;i<n;i++)
    v[i].second.clear();
  
}
 

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
}

