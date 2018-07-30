/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second

/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/


using namespace std;
int arr[25];
int main()
{
  sync;
  for(int i=1;i<=24;i++)
  	cin >> arr[i];
  for(int i=1;i<=24;i++)
  	cout << arr[i] << " ";
  cout << endl;
  if(1)
  {
  	int cnt = 0;
    if((arr[1]==arr[3]&&arr[3]==arr[21]&&arr[21]==arr[23]))
    {	cnt++;
    }
    if((arr[10]==arr[12]&&arr[12]==arr[22]&&arr[22]==arr[24]))
    {	cnt++;
    }
    if((arr[17]==arr[18]&&arr[18]==arr[19]&&arr[19]==arr[20]))
    {	cnt++;
    }
    if((arr[9]==arr[11]&&arr[11]==arr[6]&&arr[6]==arr[8]))
    {	cnt++;
    }
    if((arr[5]==arr[7]&&arr[7]==arr[2]&&arr[2]==arr[4]))
    {	cnt++;
    }
    if((arr[13]==arr[14]&&arr[14]==arr[15]&&arr[16]==arr[15]))
    {	cnt++;
    }
    if(cnt == 4){
    	cout << "YES" << endl;
        return 0;}
        cout << cnt << endl;

  }
  if(1)
  {int cnt = 0;
  	if((arr[5]==arr[6]&&arr[6]==arr[7]&&arr[7]==arr[8]))
    {	cnt++;
    }
    if((arr[21]==arr[22]&&arr[22]==arr[23]&&arr[23]==arr[24]))
    {	cnt++;
    }
    if((arr[14]==arr[16]&&arr[11]==arr[16]&&arr[11]==arr[12]))
    {	cnt++;
    }
    if((arr[9]==arr[10]&&arr[10]==arr[18]&&arr[18]==arr[20]))
    {	cnt++;
    }
    if((arr[3]==arr[4]&&arr[4]==arr[13]&&arr[13]==arr[15]))
    {	cnt++;
    }
    if((arr[17]==arr[19]&&arr[19]==arr[1]&&arr[1]==arr[2]))
    {	cnt++;
    }
    if(cnt == 4){
    	cout << "YES" << endl;
        return 0;}
  }
  if(1)
  {int cnt = 0;
  	if((arr[9]==arr[10]&&arr[10]==arr[11]&&arr[11]==arr[12]))
    {	cnt++;
    }
    if((arr[1]==arr[2]&&arr[2]==arr[3]&&arr[3]==arr[4]))
    {	cnt++;
    }
    if((arr[5]==arr[6]&&arr[6]==arr[19]&&arr[19]==arr[20]))
    {	cnt++;
    }
    if((arr[13]==arr[14]&&arr[14]==arr[7]&&arr[7]==arr[8]))
    {	cnt++;
    }
    if((arr[17]==arr[18]&&arr[18]==arr[23]&&arr[23]==arr[24]))
    {	cnt++;
    }
    if((arr[21]==arr[22]&&arr[15]==arr[22]&&arr[15]==arr[16]))
    {	cnt++;
    }
    if(cnt == 4){
    	cout << "YES" << endl;
        return 0;}
  }
  if(1)
  {//cout << arr[13] << " " << arr[14] << " " << arr[15] << " " << arr[16] << endl; 
  	int cnt = 0;
  	if((arr[13]==arr[14]&&arr[14]==arr[15]&&arr[15]==arr[16]))
    {	cnt++;
    }
    if((arr[2]==arr[4]&&arr[4]==arr[5]&&arr[5]==arr[7]))
    {	cnt++;
    }
    if((arr[21]==arr[23]&&arr[23]==arr[1]&&arr[1]==arr[3]))
    {	cnt++;
    }
    if((arr[6]==arr[8]&&arr[8]==arr[9]&&arr[9]==arr[11]))
    {	cnt++;
    }
    if((arr[17]==arr[18]&&arr[18]==arr[19]&&arr[19]==arr[20]))
    {	cnt++;
    }
    if((arr[10]==arr[12]&&arr[12]==arr[22]&&arr[22]==arr[24]))
    {	cnt++;
    }
    if(cnt == 4){
    	cout << "YES" << endl;
        return 0;}
  }
  if(1)
  {int cnt = 0;
  	if((arr[1]==arr[2]&&arr[2]==arr[3]&&arr[3]==arr[4]))
    {	cnt++;
    }
    if((arr[9]==arr[10]&&arr[10]==arr[11]&&arr[11]==arr[12]))
    {	cnt++;
    }
    if((arr[15]==arr[16]&&arr[16]==arr[21]&&arr[21]==arr[22]))
    {	cnt++;
    }
    if((arr[7]==arr[8]&&arr[8]==arr[13]&&arr[13]==arr[14]))
    {	cnt++;
    }
    if((arr[19]==arr[20]&&arr[20]==arr[5]&&arr[5]==arr[6]))
    {	cnt++;
    }
    if((arr[23]==arr[24]&&arr[17]==arr[24]&&arr[17]==arr[18]))
    {	cnt++;
    }
    if(cnt == 4){
    	cout << "YES" << endl;
        return 0;}
  }
  if(1)
  {int cnt = 0;
  	if((arr[5]==arr[6]&&arr[6]==arr[7]&&arr[7]==arr[8]))
    {	cnt++;
    }
    if((arr[21]==arr[22]&&arr[22]==arr[23]&&arr[23]==arr[24]))
    {	cnt++;
    }
    if((arr[18]==arr[20]&&arr[20]==arr[9]&&arr[9]==arr[10]))
    {	cnt++;
    }
    if((arr[1]==arr[2]&&arr[2]==arr[17]&&arr[17]==arr[19]))
    {	cnt++;
    }
    if((arr[13]==arr[15]&&arr[15]==arr[3]&&arr[3]==arr[4]))
    {	cnt++;
    }
    if((arr[11]==arr[12]&&arr[12]==arr[14]&&arr[14]==arr[16]))
    {	cnt++;
    }
    if(cnt == 4){
    	cout << "YES" << endl;
        return 0;}
  }
  cout << "NO" << endl;
}
