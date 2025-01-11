#include <algorithm>
#include <iostream>
#include <cstdio>
#define ll long long

using namespace std ;

int pri[15] = {0,2,3,5,7,11,13,17,19,23,29,31};
ll best = -1 , num = -1 ;
int n ;
int p[500]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,554400,665280,720720,1081080,1441440,2162160,2882880,3603600,4324320,6486480,7207200,8648640,10810800,14414400,17297280,21621600,32432400,36756720,43243200,61261200,73513440,110270160,122522400,147026880,183783600,245044800,294053760,367567200,551350800,698377680,735134400,1102701600,1396755360,2001000000};
void dfs(ll x  , int rest , int m, int up)
{
    if(m > best || (m == best && x < num))
        num = x , best = m ;
    ll ans = x ;
    int i = 0 ;
    while(i < up)
    {
        ++ i ;
        if(n / ans < pri[rest]) 
            return ;
        int kkk = m * (i + 1 ) ;
        ans *= pri[rest] ;
        if(ans <= n)
            dfs(ans , rest + 1 , kkk , i) ;
    }
}

int main() {
    scanf("%d" , &n) ;
    dfs(1 , 1 , 1 , 30);
    printf("%lld\n" , num);
    // int cnt = 0;
    // string s = ".in";
    // for (int i = 0; i < 68; ++i) {
    //     string t = to_string(i) + s;
    //     freopen(t.c_str(), "w", stdout);
    //     if (i > 20) p[i] += 101;
    //     cout << p[i] << '\n';
    //     fclose(stdout);
    // }
    return 0;
}
