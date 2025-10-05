#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    // taskId -> (userId, priority)
    unordered_map<int, pair<int,int>> task_info;

    // Max heap: (priority, taskId, userId)
    priority_queue<tuple<int,int,int>> pq;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            task_info[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        task_info[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        if (task_info.find(taskId) == task_info.end()) return;
        int userId = task_info[taskId].first;
        task_info[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId}); // lazy update
    }

    void rmv(int taskId) {
        task_info.erase(taskId); // just mark as removed
    }

    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            // check if valid
            if (task_info.count(taskId) && task_info[taskId].second == priority) {
                pq.pop();
                task_info.erase(taskId); // remove after execution
                return userId;           // return userId (not taskId!)
            }
            pq.pop(); // discard stale entry
        }
        return -1; // no tasks
    }
};