class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
        int targetArrival = times[targetFriend][0];
        sort(times.begin(), times.end());
        int nextChair = 0; 
        set<int> availableChairs;
        for (auto time : times) {
            int arrival = time[0];
            int leave = time[1];
            while (!pq.empty() &&
                   pq.top().first <= arrival) {
                availableChairs.insert(pq.top().second);
                pq.pop();
            }
            int currentChair;
            if (!availableChairs.empty()) {
                currentChair = *availableChairs.begin();
                availableChairs.erase(availableChairs.begin());
            }
            else {
                currentChair = nextChair++;
            }
            pq.push({leave, currentChair});
            if (arrival == targetArrival) return currentChair;
        }

        return 0;
    }
};