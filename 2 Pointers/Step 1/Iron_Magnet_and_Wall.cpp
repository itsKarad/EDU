#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
#define int long long 
#define MOD 1000000007
#define MOD2 1000000014000000049L
#define PI 3.1415926535
#define INF 1e18 
#define ve vector
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define bs binary_search
#define all(a) (a).begin(),(a).end()
#define lb lower_bound
#define ub upper_bound
#define mxe(a) *max_element(a.begin(),a.end())
#define mne(a) *min_element(a.begin(),a.end())
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(g, i, n) for (int g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
using namespace std;
#define DEBUG(x) do { std::cerr <<#x<<":"<< x<<"   "; } while (0)
//===================================================================================================================
// THE FIRST PRINCIPLE, IS THAT YOU MUST NOT FOOL YOURSELF, AND YOU ARE THE EASIEST PERSON TO FOOL- Richard Feynman.
// ******************************************************************************************************************


void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int n=s.length();
    vector<pair<int,int>> left(n,{0,0});
    vector<pair<int,int>> right(n,{0,0});
    vector<int> cnt(n,0);
    if(s[0]=='M')
    {   
        left[0]={K,1};
        
    }
        
    for(int i=1;i<n;i++){
        left[i].first=left[i-1].first-left[i-1].second;
        left[i].second=left[i].second;
        if(s[i]=='M'){
            left[i].first+=k;
            left[i].second++;
        }        
        else if(s[i]==':')
        {
            left[i].first-=
        }
    }



    
}
signed main() 
{ 
    FAST;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0; 
} 



// Paste for reading from input file
//#ifndef ONLINE_JUDGE
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
//#endif




int power(int base, int exp) {
   int res=1;
   while(exp>0) {
      if(exp%2==1) res=(res*base)%MOD;
      base=(base*base)%MOD;
      exp/=2;
   }
   return res%MOD;
}






// sometimes I believe compiler ignores all my comments