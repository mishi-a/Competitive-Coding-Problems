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

const int MAX = 2e5+7;
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
int RES[40005];
int arr[205][205],wr[205][205],wc[205][205],br[205][205],bc[205][205];
char arr1[205][205];
int check(int x,int y,int w,int z,int color)
{
	int ans = 0;
	if(color == 0)
	{
		ans+=bc[w][z]-(x == 0 ? 0 : bc[x-1][z]);
		ans+=br[w][z]-(y==0 ? 0 : br[w][y-1]);
		//cerr << ans << endl;
    	ans-=bc[w][z]-(w-1<0 ? 0 : bc[w-1][z]);
	}
	else
	{
		ans+=wc[w][z]-(x == 0 ? 0 : wc[x-1][z]);
		ans+=wr[w][z]-(y==0 ? 0 : wr[w][y-1]);
    	ans-=wc[w][z]-(w-1<0 ? 0 : wc[w-1][z]);
	}
	return ans;
}

int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  	for(int j=0;j<m;j++)
  	{
      cin >> arr1[i][j];
      if(arr1[i][j] == '0')arr[i][j]=0;
      else arr[i][j]=1;
    }	
  for(int i=0;i<n;i++)
  {
  	int cnt=0,bcnt=0;
  	for(int j=0;j<m;j++)
  	{
      if(i%2 == 0){
        if(j%2==0&&arr[i][j]!=0)bcnt++;
        if(j%2==1&&arr[i][j]!=1)bcnt++;
        if(j%2==0&&arr[i][j]!=1)cnt++;
        if(j%2==1&&arr[i][j]!=0)cnt++;
      }
      else{
        if(j%2==0&&arr[i][j]!=0)cnt++;
        if(j%2==1&&arr[i][j]!=1)cnt++;
        if(j%2==0&&arr[i][j]!=1)bcnt++;
        if(j%2==1&&arr[i][j]!=0)bcnt++;
      }
  		
  		wr[i][j]=cnt;
  		br[i][j]=bcnt;
  	}
  }
  //cout << br[0][0] << endl;
  //return 0;
  for(int i=0;i<m;i++)
  {
  	int cnt=0,bcnt=0;
  	for(int j=0;j<n;j++)
  	{
      if(i%2 == 0){
        if(j%2==0&&arr[j][i]!=0)bcnt++;
        if(j%2==1&&arr[j][i]!=1)bcnt++;
        if(j%2==0&&arr[j][i]!=1)cnt++;
        if(j%2==1&&arr[j][i]!=0)cnt++;
      }else{
        if(j%2==0&&arr[j][i]!=0)cnt++;
        if(j%2==1&&arr[j][i]!=1)cnt++;
        if(j%2==0&&arr[j][i]!=1)bcnt++;
        if(j%2==1&&arr[j][i]!=0)bcnt++;
      }
  		
  		wc[j][i] = cnt;
  		bc[j][i] = bcnt;
  	}
  }
  /*for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  		cout << bc[i][j] << " ";
  	cout << endl;
  }*/
  //cerr << check(0,0,2,2,0) << " " << bc[2][2] << " " << br[2][2] <<  endl;
  //cerr << check(0,1,0,1,1) << " " << wc[0][1] << " " << wr[0][1] << endl;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		int t=i,l=j;
  		int cBlack=0,cWhite=0;
  		while(t<n && l<m)
  		{
  			int tot = check(i,j,t,l,0);
  			int tot1 = check(i,j,t,l,1);
  			cBlack+=tot;
  			cWhite+=tot1;
            //cerr << cBlack << " " << cWhite <<endl;

  			RES[cBlack] = max(RES[cBlack],l-j+1);
            RES[cWhite] = max(RES[cWhite],l-j+1);
  			//cerr << i << " " << j << " " << t << " " << l << " " << RES[0] << endl;
  			t++,l++;
  		}
  	}
  }
  for(int i=1;i<40001;i++)
  	RES[i]=max(RES[i],RES[i-1]);
  int q;
  cin >> q;
  //cerr << q << endl;
  while(q--)
  {
  	int p;
  	cin >> p;
  	if(p>=40000)
  	{
  		cout << min(n,m) << endl;
  		continue;
  	}
  	cout << RES[p] << endl;
  }

}
