#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    priority_queue<int> left;                                    
    priority_queue<int, vector<int>, greater<int>> right;       
    unordered_map<int, int> leftDel, rightDel;                  
    int leftSize = 0, rightSize = 0;                      

    // Clean invalid elements from the top of a heap
    template<typename Heap>
    void clean(Heap& heap, unordered_map<int, int>& delMap) {
        while (!heap.empty() && delMap[heap.top()] > 0) {
            delMap[heap.top()]--;
            heap.pop();
        }
    }

    // Rebalance heaps to maintain size invariant
    void balance() {
        clean(left, leftDel);
        clean(right, rightDel);

        if (leftSize > rightSize + 1) {
            // Move from left to right
            clean(left, leftDel);
            int val = left.top();
            left.pop();
            leftSize--;
            right.push(val);
            rightSize++;
        } else if (leftSize < rightSize) {
            // Move from right to left
            clean(right, rightDel);
            int val = right.top();
            right.pop();
            rightSize--;
            left.push(val);
            leftSize++;
        }
    }

    // Add a new element to the appropriate heap
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
            leftSize++;
        } else {
            right.push(num);
            rightSize++;
        }
        balance();
    }

    // Mark an element for lazy deletion
    void removeNum(int num) {
        clean(left, leftDel);
        clean(right, rightDel);

        if (!left.empty() && num <= left.top()) {
            leftDel[num]++;
            leftSize--;
        } else {
            rightDel[num]++;
            rightSize--;
        }
        balance();
    }

    // Get the current median
    double getMedian(int k) {
        clean(left, leftDel);
        clean(right, rightDel);

        if (k % 2 == 1) {
            return left.top();
        } else {
            return ((double)left.top() + right.top()) / 2.0;
        }
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        int n = nums.size();

        // Initialize with first k elements
        for (int i = 0; i < k; i++) {
            addNum(nums[i]);
        }
        result.push_back(getMedian(k));

        // Slide the window
        for (int i = k; i < n; i++) {
            addNum(nums[i]);        
            removeNum(nums[i - k]); 
            result.push_back(getMedian(k));
        }

        return result;
    }
};