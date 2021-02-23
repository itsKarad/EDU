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
#define debug(x) do { std::cerr <<#x<<":"<< x<<"   "; } while (0)
//===================================================================================================================
// THE FIRST PRINCIPLE, IS THAT YOU MUST NOT FOOL YOURSELF, AND YOU ARE THE EASIEST PERSON TO FOOL- Richard Feynman.
// ******************************************************************************************************************

int m,n;
vector<int> t(1005),rest(1005),z(1005);
bool valid(int x){
    // for every assistant find number of balloons they can inflate in x minutes
    int curr=0;
    for(int i=0;i<n;i++){
        int work_time=t[i]*z[i];
        int rest_time=rest[i];
        int cycles=x/(work_time+rest_time);
        int rem_time=x-cycles*(work_time+rest_time);
        // Mistake : min() was not taken, max z[i] can be inflated without break
        int rem_inflate=min(z[i],rem_time/t[i]);
        curr+=cycles*z[i]+rem_inflate;
    }
    return (curr>=m);
}
void solve()
{
    cin>>m>>n;
    int max_time=0;
    for(int i=0;i<n;i++){
        cin>>t[i]>>z[i]>>rest[i];
    }
    int answer=INF;
    int lo=0,hi=1e10;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(valid(mid)){
            answer=min(answer,mid);
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<answer<<endl;
    // TODO : find distribution
    vector<int> cnt(n,0);
    int curr=0;
    for(int i=0;i<n;i++){

        int work_time=t[i]*z[i];
        int rest_time=rest[i];
        int cycles=answer/(work_time+rest_time);
        int rem_time=answer-cycles*(work_time+rest_time);
        int rem_inflate=min(z[i],rem_time/t[i]);
        int inflate=cycles*z[i]+rem_inflate;
        if(inflate>=m-curr){
            cnt[i]=m-curr;
            break;
        }
        else{
            cnt[i]=inflate;
        }          
        curr+=inflate;
    }
    for(int i=0;i<n;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;

}
signed main() 
{ 
    FAST;
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