#include<bits/stdc++.h>

using namespace std;

#define nl endl
#define lli long long int
#define ld long double
#define vb vector<bool>
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef priority_queue<int> pq; //maxHeap
typedef priority_queue <int, vector<int>, greater<int> > pqn; //minHEAP
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, bool> msb;
typedef map<string, string> mss;
typedef map<string, char> msc;
typedef pair<int, int> pii;
typedef pair<lli, lli> pllilli;
typedef vector<pii> vii;
typedef vector<pllilli> vllilli;
//vector<int>::iterator j;
#define REPV (j, v) for(vector<int>::iterator j = v.begin(); j!=v.end();j++)
#define pb push_back
//#define pf push_front
#define mp make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPR(I, A, B) for (int I = (B); I > (A); I--)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRLLI(X) lli (X); scanf("%lld", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRLLILLI(X, Y) lli X, Y; scanf("%lld%lld", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRLLILLILLI(X, Y, Z) lli X, Y, Z; scanf("%lld%lld%lld", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define DRA(a,n) int a[n]; REP(i,n)cin>>a[i]
#define l_b lower_bound
#define u_b upper_bound
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define NL cout<<endl
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define all(ar) ar.begin(), ar.end()
#define zzz return 0
inline lli Power(int b, int p) { lli ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
const int MOD = 1e9+7;
const int SIZE = 4e6+10;
const int MAX = 1e9+1;

int minVal(int x, int y) { return (x < y)? x: y; }
int getMid(int s, int e) {  return s + (e -s)/2;  }
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) + constructSTUtil(arr, mid + 1, se, st, si*2+2);
    return st[si];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = getMid(ss, se);
    return min(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
int RMQ(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
void update_rangeUtil(int *st,int ss,int se,int i, int j,int val,int index){
  if(se < i || ss >j)return;
  if(se == ss){
    st[index] += val;
    return;
  }
  int mid = getMid(ss,se);
  update_rangeUtil(st,ss,mid,i,j,val,2*index +1);
  update_rangeUtil(st,ss,mid+1,i,j,val,2*index +2);
  //st[index]=max(st[index*2 +1],st[index*2+2]);//TODO:for RMQ type query
  //TODO:for sum type qurry: do This->
  st[index]=st[index*2 +1]+st[index*2+2];
}
void update_range(int *st,int n,int i,int j,int val){
  if(i>j || i<0 ||j>n-1){
    cout<<"invalid input";
    return;
  }
  return update_rangeUtil(st,0,n-1,i,j,val,0);
}

void updateValueAtIndexUtil(int *st, int ss, int se, int i, int diff, int index)
{
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueAtIndexUtil(st, ss, mid, i, diff, 2 * index + 1);
        updateValueAtIndexUtil(st, mid+1, se, i, diff, 2 * index + 2);
    }
}
void updateValueAtIndex(int arr[], int *st, int n, int i, int new_val)
{
    if (i < 0 || i > n-1)
    {
        cout<<"Invalid Input";
        return;
    }
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueAtIndexUtil(st, 0, n - 1, i, diff, 0);
}
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2 * index + 1) + getSumUtil(st, mid + 1, se, qs, qe, 2 * index + 2);
}

int getSum(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input"<<endl;
        return -1;
    }
    return getSumUtil(st, 0, n - 1, qs, qe, 0);
}
//to find kth smallest element TODO:incomplete
/*int binary_search(int * st,int k,index){
  if(st[index]<k)return INT_MAX;
  while(1){
    if(st[index*2 +1]>st[index*2 +2])return st[index*2 +1];
    if(st[index*2 +1] <){}
  }
}
*/
int main()
{
    DRI(t);
    REP(c,0,t){
      DRII(n,q);
      int arr[n];
      REP(i,0,n)cin>>arr[i];
      int *st = constructST(arr, n);
      cout<<"Case "<<c<<" :\n";
      while(q--){
        int x;cin>>x;
        switch (x) {
          case 1:
                int z;cin>>z;
                updateValueAtIndex(arr, st, n, z-1, 0);
                REP(i,0,n){
                  cout<<arr[i]<<" ";
                }
          case 2:
                DRII(v,w);
                updateValueAtIndex(arr, st, n, w-1, arr[w-1]+v);
                REP(i,0,n){
                  cout<<arr[i]<<" ";
                }
          case 3:
                DRII(t,y);
                cout<<"sum: "<<getSum(st, n, t-1, y-1)<<endl;
        }
      }
    }
    zzz;
}
