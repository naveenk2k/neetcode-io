class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        

        unordered_map<int, vector<int>> g;
        vector<int> inDegrees(numCourses, 0);

        set<int> preReqCourses;
        for (vector<int> preReq : prerequisites) {
            int u = preReq[0];
            int v = preReq[1];
            // v to u. v first, then u
            preReqCourses.insert(u);
            preReqCourses.insert(v);

            if (!g.contains(v)) {
                g[v] = vector<int>();
            }
            g[v].push_back(u);
            ++inDegrees[u];
        }

        // for (int s : preReqCourses) cout << s << ", ";
        // cout << '\n';

        // for (auto [k, v] : g) {
        //     cout << k << ": ";
        //     for (int u : v) cout << u << ", ";
        //     cout << '\n';
        // }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0) q.push(i);
        }

        vector<int> ordering;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ordering.push_back(u);

            for (int v : g[u]) {
                --inDegrees[v];
                if (inDegrees[v] == 0) {
                    q.push(v);
                }
            }
        }


        if (ordering.size() == numCourses) return ordering;
        else return {};
    }
};
