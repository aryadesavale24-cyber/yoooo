class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int, int>> ans[n];

        vector<int> cos(n, 1e9);

        for (auto it : flights) {
            ans[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int stop = it.first;
            int y = it.second.first;
            int cost = it.second.second;
            if(stop>k) continue;

            for (auto x : ans[y]) {

                int adj = x.first;
                int ec = x.second;

                if (cos[adj] > ec + cost) {
                    cos[adj] = ec + cost;

                    if (stop + 1 <= k + 1) {
                        q.push({stop+1, {adj, cos[adj]}});
                    }
                }
            }
        
     }

        if (cos[dst] != 1e9)
            return cos[dst];
        else
            return -1;
    }
};