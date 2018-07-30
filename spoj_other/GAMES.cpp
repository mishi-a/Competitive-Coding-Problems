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

int main()
{
  sync;
  ll t;
  cin >> t;
  while(t--)
  {
    string a;
    cin >> a;
    int num = 0,num1 = 0;
    int d = 1;
    for(int i=0;i<a.length();i++)
    {
      if(a[i] == '.')
      {
        for(int j=i+1;j<a.length();j++)
        {
          num = num*10 + (a[j]-'0');
          d = d*10;
        }
        break;
      }
      else
      {
        num1 = num1*10 + (a[i]-'0');
      }
    }
    int  cunt = 1;
    while(1)
    {
      double ans = num1*cunt*1.0 + (num*cunt*1.0)/(d*1.0);
      int res = ans;
      if(ans == res)
      {
        cout << cunt << endl;
        break;
      }
      cunt++;
    }
  }
}

