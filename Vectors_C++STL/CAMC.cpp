    // Chef and Minimum Colouring | Problem Code: CAMC
    

    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long int
    #define ld long double
    #define p 1000000007
    #define inf 1e18
    #define endl "\n"
    #define pb emplace_back
    #define vi vector<int>
    #define vll vector<ll>
    #define vs vector<string>
    #define pii pair<int, int>
    #define pll pair<ll, ll>
    #define ump unordered_map
    #define mp map
    #define pq_max priority_queue<ll>
    #define pq_min priority_queue<ll, vll, greater<ll>>
    #define ff first
    #define ss second
    #define mid(l, r) (l + (r - l) / 2)
    #define loop(i, a, b) for (int i = (a); i <= (b); i++)
    #define looprev(i, a, b) for (int i = (a); i >= (b); i--)

    int main()
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int t;
        cin >> t;

        while(t--){
            int n,m; cin>>n>>m; 
            vector<pair<ll, int>> v(n);
            for(int i=0; i<n; i++){
                cin>>v[i].first;
                v[i].second = i%m;
            }
            // for(int i=0; i<n; i++){
            //     cout<<v[i].first<<","<<v[i].second<<"\n";
            // }

            int count =m;
            int right =0;
            ll ans = INT_MAX;
            sort(v.begin(), v.end());

            vector<int> cnt(m,0);
            for(int left= 0; left<=n-1; left++){
                while (right < n && count > 0 )
                {
                    count -= cnt[v[right].second] == 0;
                    cnt[v[right].second]++;
                    right++;
                }
                if(count == 0){
                    ans  = min(ans, v[right-1].first-v[left].first);
                }
                if(cnt[v[left].second] > 0){
                    cnt[v[left].second]--;
                }
                count += cnt[v[left].second]==0;
            }
            cout<<ans<<endl;
        }

        return 0;
    }