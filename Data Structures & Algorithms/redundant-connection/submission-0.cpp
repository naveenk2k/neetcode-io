class Solution {
public:
    vector<int> component, componentSize; 

    int find(int a) {
        while (a != component[a]) a = component[a];
        return component[a];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        // point larger component to smaller
        if (componentSize[a] < componentSize[b]) swap(a, b);
        component[b] = a;
        componentSize[a] += componentSize[b];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int mx = 0;
        for (vector<int> edge : edges) {
            mx = max({mx, edge[0], edge[1]});
        }

        int n = mx+1;
        component.resize(n);
        componentSize.resize(n);

        for (int i = 0; i < n; ++i) {
            component[i] = i;
            componentSize[i] = 1;
        }

        for (vector<int>& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (find(a) == find(b)) return edge;
            unite(a, b);
        }
    }
};
