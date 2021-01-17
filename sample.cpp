#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define fin ios_base::sync_with_stdio(false); cin.tie(NULL);
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

struct cmp {
    bool operator() (const pair<int,int>&a, const pair<int,int>&b) {
        return a.first>=b.first;
    }
};

int solve(int n, int k, vector<int>a, vector<int>b) {
    multiset<pair<int,int>, cmp>s;
    for(int i = 0; i<n; i++) {
        s.insert({a[i], b[i]});
    }
    int score = 0;
    while(k--) {
        auto val = *s.begin();
        score += val.first;
        s.erase(s.begin());
        s.insert({val.first/val.second, val.second});
    }
    return score;
}

int main() {
    fin;
    int n,k,i;
    vector<int>a(n), b(n);
    cin>>n>>k;
    for(i = 0; i<n; i++)
        cin>>a[i];
    for(i = 0; i<n; i++)
        cin>>b[i];
    cout<<solve(n,k,a,b);
}