#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;
vector < int > arr(1008,0);
struct node{
  int  a;
  string b;
};
vector < vector <node> > v(26);
int main()
{
  sync;
  int n;
  node p;
  cin >> n;
  string x,y;
  vector <string> vec;
  for(int i=0;i<n;i++)
  {
    cin >> x;
    vec.pb(x);
    p.a = i;
    int k;
    cin >> k;
    for(int j=0;j<k;j++)
    {
      cin >> y;
      p.b = y;
      v[y[0]-'a'].pb(p);
    }
  }
  int t;
  cin >> t;
  int res = 0;
  while(t--)
  {
    int q;
    cin >> q;int cunt = 0;
    for(int i=0;i<q;i++)
    {
      cin >> x;
      int ind = x[0]-'a';
      for(int j=0;j<v[ind].size();j++)
      {
        if(v[ind][j].b == x)
        {
          arr[v[ind][j].a]+=1;
        }
        
      }
    }
      //cout << s1.size() << "+" << s2.size() << endl;
      res++;
      cout << "Diagnosis #" << res <<":" << endl;
      int mux = *max_element(arr.begin(),arr.end());
      for(int i=0;i<n;i++)
      {
        if(arr[i] == mux)
          cout << vec[i] << endl;
      }
      fill(arr.begin(),arr.end(),0);
      
       
  }
  
}
