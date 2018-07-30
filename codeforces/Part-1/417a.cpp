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

int arr[4][4];

int main()
{
  sync;
  vector <int> v;
  for(int i=0;i<4;i++)
  {
    int flag = 0;
    int sum = 0;
    for(int j=0;j<4;j++)
    {
      cin >> arr[i][j];
      sum = sum+arr[i][j];
      if(arr[i][3] == 1)
        v.pb(i);
    }
    if(sum >=2 && arr[i][3] == 1)
    { 
       cout << "YES" ;
       return 0;
    } 
  }
  //
  for(int i=0;i<v.size();i++)
  { //cout << "Hi" << endl;
    if(v[i] == 0 )
    {
      if(arr[3][2] == 1 || arr[1][0] == 1 || arr[2][1] == 1)
      {
        cout << "YES" ;
        return 0;
      }
  
    }
    else if(v[i] == 1)
    {
      if(arr[0][2] == 1 || arr[2][0] == 1|| arr[3][1] == 1)
      {
        cout << "YES" ;
        return 0;
      }
      
    }
    else if(v[i] == 2)
    {
      if(arr[1][2] == 1 || arr[3][0] == 1 ||  arr[0][1] == 1)
      {
        cout << "YES" ;
        return 0;
      }
    }
    else if(v[i] == 3)
    {
      if(arr[0][0] == 1 || arr[2][2] == 1 ||  arr[1][1] == 1)
      {
        cout << "YES" ;
        return 0;
      }
   
    }
   
  }
  cout << "NO" << endl;
}

