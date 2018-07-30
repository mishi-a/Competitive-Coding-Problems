#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

using namespace std;

int main()
{
  sync;
  string s,a;
  cin >> s;
  a.append(s,0,1);
  for(int i=1;i<s.length();i++)
  {
    if(s[i]!=s[i-1])
      a.append(s,i,1);
  }
  //cout << a << endl;
  if(a[a.length()-1] == '0')
    cout << a.length()-1 << endl;
  else
    cout << a.length() << endl;
}
