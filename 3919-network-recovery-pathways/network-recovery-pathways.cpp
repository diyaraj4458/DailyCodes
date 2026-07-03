#define ll long long
class Solution {
public:
    int n;
    vector<vector<pair<ll,ll>>>graph;

    bool disjktra(int val,vector<bool>& online, long long k)
    {
        priority_queue<
            pair<ll,ll>,
            vector<pair<ll,ll>>,
            greater<pair<ll,ll>>
        >pq;
        vector<long long >dist(n,LLONG_MAX);
        pq.push({0,0});
        dist[0]=0;
        while(pq.size())
        {
            auto [dis,node]=pq.top();
            pq.pop();
            if (dis > dist[node])
                continue;
            if(node==n-1)
            {
                return true;
            }
            else
            {
                for(auto i:graph[node])
                {
                    if(i.second+dis<=k && dist[i.first]>i.second+dis && online[i.first] && i.second>=val)
                    {
                        dist[i.first]=i.second+dis;
                        pq.push({i.second+dis,i.first});
                    }
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) 
    {
        n=online.size();
        graph.assign(n,{});
        for(auto i:edges){
            graph[i[0]].push_back({i[1],i[2]});
        }
        ll s=0,e=1e9,ans=-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(disjktra(m,online,k))
            {
                ans=m;
                s=m+1;
            }
            else
                e=m-1;
        }
        return ans;
    }
};