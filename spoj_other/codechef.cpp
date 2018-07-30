#include<iostream>
#include<vector>        
#include <algorithm> 
#include <iterator>
#include <deque>
using namespace std;

#define sync ios::sync_with_stdio(false)
#define endl '\n'

int main()
{
  sync;
  int n;
  cin >> n;
  int a,b;
  vector <int > v,w;
  for(int i=0;i<n;i++)
  {
    cin >> a >> b;
    if(a!=b)
    {
      cout << "rated" << endl;
      return 0;
    }
    else
    {
      v.push_back(a);
      w.push_back(a);
    }
  }
  sort(v.begin(),v.end(),greater<int>());
  for(int i=0;i<n;i++)
  {
   // cout << v[i] << " " << w[i];
    if(v[i] != w[i])
    {
      cout << "unrated" << endl;
      return 0;
    }
  }
  cout << "maybe" << endl;
  return 0;
}
