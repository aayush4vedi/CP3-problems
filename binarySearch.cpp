#include<bits/stdc++.h>
//#include <string.h>
using namespace std;

#define nl endl
#define ll long long
#define vb vector<bool>
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, bool> msb;
typedef map<string, string> mss;
typedef map<string, char> msc;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define FOR(i,a,b) for(int i=a; i<b;i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define IterV (j, v) for(vector<int>::iterator j = v.begin(); j!=v.end();j++)
#define pb push_back
#define mp make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))

#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define all(ar) ar.begin(), ar.end()
#define pq priority_queue
inline ll Power(int b, int p) { ll ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }

int binarySerach(int a[], int n, int key){
  int l=0,r=n-1;
  int flag=0;
  int mid= (l+r)/2;
  while(l<=r){
    if(a[mid]==key){
      flag++;
      return mid;
    }else if(a[mid] < key){
      l=mid+1;
    }else{
      r= mid -1;
    }
  }
  if(flag ==0 )return -1;
}

int main(){
  int n;cin>>n;
  int a[n];FOR(i,0,n)cin>>a[i];
  int key;
  cout<<"enter the key\n";cin>>key;
  int ans=binarySerach(a,n,key);
  if(ans == -1)cout<<"not found\n";
  else cout<<ans<<'\n';

  return 0;
}
