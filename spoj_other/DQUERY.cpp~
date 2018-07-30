#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

vector<int > v;
vector <pair<pii,int> > query;
int temp;
int ans[300000];
int arr[3000005] = {0};
int b_size ;
bool acompare(pair <pii,int> a,pair <pii,int > b)
{
  if(a.first.first/b_size < b.first.first/b_size)
    return true;
  else if(a.first.first/b_size == b.first.first/b_size &&a.first.second < b.first.second)
    return true;
  else
    return false;
}

void add(int r)
{
  int val = v[r];
  if(arr[val] == 0)
    temp++;
  arr[val]++;
}
void remove(int l)
{
  int val = v[l];
  arr[val]--;
  if(arr[val] <0)
    arr[val] = 0;
  arr[val] == 0 ? temp--  : temp = temp;
}
int main()
{
  sync;
  int n,l,r;
  cin >> n;
  v.pb(-1);
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    v.pb(a);
  }
  int q;
  cin >> q;
  for(int i=1;i<=q;i++)
  {
    cin >> l >> r;
    query.pb(make_pair(make_pair(l,r),i));
  }
  b_size = sqrt(n);
  sort(query.begin(),query.end(),acompare);
  l = 0;
  r = -1;
  for(int i=0;i<q;i++)
  {
    int cl = query[i].first.first;
    int cr = query[i].first.second;
    while(r < cr)
    {
      r++;
      add(r);
    }
    while(r>cr)
    {
      remove(r);
      r--;
    }
    while(l < cl)
    {
       remove(l);
       l++;
    }
    while (l>cl)
    {
      l--;
      add(l);
    }
    ans[query[i].second] = temp; 
  }
  for(int i=1;i<=q;i++)
  {
    cout << ans[i] << endl;
  }
}
