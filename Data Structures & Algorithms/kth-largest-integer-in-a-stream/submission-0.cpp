class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > limit) pq.pop();
        return pq.top();
    }
};
