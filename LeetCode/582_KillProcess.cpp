#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> procs_to_kill;
        queue<int> temp_procs_queue;
        
        temp_procs_queue.push(kill);
		map<int, vector<int>> child_procs;
		for (int i = 0; i < ppid.size(); i++)
			if (child_procs.find(ppid[i]) == child_procs.end())
				child_procs[ppid[i]] = vector<int> {pid[i]};
			else
				child_procs[ppid[i]].push_back(pid[i]);

        while (!temp_procs_queue.empty()) {
            int killed_proc = temp_procs_queue.front();
			procs_to_kill.push_back(killed_proc);
			temp_procs_queue.pop();
			if (child_procs.find(killed_proc) != child_procs.end())
				for (int proc_id : child_procs[killed_proc])
					temp_procs_queue.push(proc_id);
        }
        
        return procs_to_kill;
    }
};

class Solution_DFS {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> procs_to_kill;
        
		map<int, vector<int>> child_procs;
		for (int i = 0; i < ppid.size(); i++) {
			if (child_procs.find(ppid[i]) == child_procs.end())
				child_procs[ppid[i]] = vector<int> {pid[i]};
			else
				child_procs[ppid[i]].push_back(pid[i]);

        procs_to_kill.push_back(kill);
		getAllChildren(child_procs, procs_to_kill, kill);
        
        return procs_to_kill;
    }

private:
	void getAllChildren(map<int, vector<int>>& proc_map, vector<int>& procs_to_be_killed, int kill) {
		if (proc_map.find(kill) != proc_map.end())
			for (int i = 0; i < proc_map[kill].size(); i++) {
				procs_to_be_killed.push_back(proc_map[kill][i]);
				getAllChildren(proc_map, procs_to_be_killed, proc_map[kill][i]);
			}
	}
};

int main()
{
	vector<int> pid {1, 3, 10, 5};
	vector<int> ppid {3, 0, 5, 3};

	vector<int> killed = Solution().killProcess(pid, ppid, 5);
	for (int i = 0; i < killed.size(); i++) {
		cout << killed[i] << " ";
	}
	cout << endl;

    return 0;
}
