// Digit Dynamic Programming
// Given two numbers a and b ( 1<=a<=b<=10^12 ) . Calculate the sum of the digits of numbers a through b .

#include <bits/stdc++.h>
using namespace std;

vector <int> V ;
long long dp[20][3] , fp[20][3] ;

void init(long long number)
{
    V.clear();
    while(number!=0)
    {
        V.push_back(number%10);
        number/=10;
    }
}

pair<long long,long long> answer(int pos,bool flag)
{
    if(pos==-1) return make_pair(1,0) ;

    long long &ret = dp[pos][flag] , &f = fp[pos][flag] ;
    if(ret!=-1) return make_pair(ret,f) ;
    ret = 0 ; f = 0 ;

    int ending ;
    if(flag) ending = V[pos] ; else ending = 9 ;

    for(int i=0;i<=ending;i++)
    {
        pair<long long,long long> prv = answer(pos-1,flag&&i==ending) ;
        ret = ret+prv.first;
        f = f + i*prv.first + prv.second ;
    }

    return make_pair(ret,f) ;
}

long long solve(long long number)
{
    memset(dp,-1,sizeof(dp));
    init(number);
    return answer(V.size()-1,1).second ;
}

int main()
{
    long long a , b ;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",solve(b)-solve(a-1));

    return 0;
}
