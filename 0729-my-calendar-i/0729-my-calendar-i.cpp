class MyCalendar {
    vector<pair<int,int>> books;
public:
    bool book(int start, int end) {
        for (auto& [s, e] : books) {
            if (start < e && s < end) return false;  // conflict
        }
        books.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */