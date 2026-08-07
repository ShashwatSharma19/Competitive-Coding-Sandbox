class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < points.size(); i++) {
        int x = points[i][0];
        int y = points[i][1];
        int dist = x * x + y * y; 
        if (maxHeap.size() < k) {
            maxHeap.push({dist, i});
        } 
        else if (dist < maxHeap.top().first) {
            maxHeap.pop();              
            maxHeap.push({dist, i});     
        }
    }

    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        int idx = maxHeap.top().second;
        result.push_back(points[idx]);
        maxHeap.pop();
    }
    return result;
}
};



