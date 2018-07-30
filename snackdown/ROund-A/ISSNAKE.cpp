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
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector <vector<char> > v(2,vector<char>(n));
    int cunt = 0;
    for(int i=0;i<2;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin >> v[i][j];
        if(v[i][j] == '#')
          cunt ++;
      }
    }
    int ltop = -1;
    int lb = -1;
    int cunt1 = cunt;
    for(int j=0;j<n;j++)
    {
      int flag = 0;
      if(v[0][j]=='#')
      {
        ltop = j;
        flag = 1;
      }
      if(v[1][j] == '#')
      {
        lb = j;
        flag = 1;
      }
      if(flag == 1)
        break;
    }
    if(ltop!=-1)
    {
      int side = 0;
      cunt--;
      char top,bottom;
      if(lb!=-1)
      {
        cunt = cunt-1;
        side = 1;
      }
      for(int j=ltop+1;j<n;j++)
      {
        if(cunt == 0)
        {
          break;
        }
        top = v[0][j];
        bottom = v[1][j];
        if(side == 1 && bottom == '#' && top == '#')
        {
          side = 0;
          cunt -=2;
        }
        else if(side == 0 && bottom == '#' && top == '#' )
        {
          side = 1;
          cunt-=2;
        }
        else if(side == 0 && bottom == '.' && top == '#')
        {
          side = 0;
          cunt-=1;
        }
        else if(side == 0  && bottom == '#' && top == '.')
        {
          cunt = cunt;
          break;
        }
        else if(side == 1 && bottom == '#' && top == '.')
        {
          side = 1;
          cunt-=1;
        }
        else
        {
          cunt = cunt;
          break;
        }
      } 
    }
    if(lb!=-1 && cunt!=0)
    {
      int side = 1;
      char top,bottom;
      cunt = cunt1;
      cunt--;
      if(ltop!=-1)
      {
        side= 0;
        cunt-=1;
      }
      for(int j=lb+1;j<n;j++)
      {
        if(cunt == 0)
        {
           break;
        }
        top = v[0][j];
        bottom = v[1][j];
        if(side == 1 && bottom == '#' && top == '#')
        {
          side = 0;
          cunt -=2;
        }
        else if(side == 0 && bottom == '#' && top == '#' )
        {
          side = 1;
          cunt-=2;
        }
        else if(side == 0 && bottom == '.' && top == '#')
        {
          side = 0;
          cunt-=1;
        }
        else if(side == 0  && bottom == '#' && top == '.')
        {
          cunt = cunt;
          break;
        }
        else if(side == 1 && bottom == '#' && top == '.')
        {
          side = 1;
          cunt-=1;
        }
        else
        {
          cunt = cunt;
          break;
        }
      }
    }
    if(cunt == 0)
       cout << "yes" << endl;
    else
       cout << "no" << endl;
  }
}
