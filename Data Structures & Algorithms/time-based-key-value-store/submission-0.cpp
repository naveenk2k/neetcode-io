class TimeMap {
public:
    unordered_map<string, set<pair<int, string>>> mp;

    TimeMap() {
        // key mapped to a sorted array of <timestamp, value> pairs
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.contains(key)) return "";

        vector<pair<int, string>> vec = vector<pair<int, string>>(mp[key].begin(), mp[key].end());;
        int lo = 0;
        int hi = vec.size() - 1;

        // look for last F in [F, F, F, T, T] where predicate is p[mid] <= timestamp
        while (lo < hi) {
            int mid = lo + (hi-lo+1)/2;
            if (vec[mid].first > timestamp) hi = mid-1;
            else lo = mid;
        }

        if (vec[lo].first <= timestamp) return vec[lo].second;

        return "";
    }
};
