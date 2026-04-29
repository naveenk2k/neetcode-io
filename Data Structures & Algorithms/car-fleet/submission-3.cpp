class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = (int)position.size();
        vector<pair<int, int>> zip;
        for (int i = 0; i < n; ++i) {
            zip.push_back({position[i], speed[i]});
        }

        sort(zip.rbegin(), zip.rend());

        stack<double> fleetTimes;
        for (int i = 0; i < n; ++i) {
            double timeToTarget = (double)(target - zip[i].first) / zip[i].second; // time = distance/speed, distance = target-position
            // cout << timeToTarget << '\n';
            if (fleetTimes.empty() || fleetTimes.top() < timeToTarget) fleetTimes.push(timeToTarget);
        }

        return fleetTimes.size();
    }
};
