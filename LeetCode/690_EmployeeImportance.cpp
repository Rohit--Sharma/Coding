#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Employee info
class Employee
{
  public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution
{
  public:
    int getImportance(vector<Employee *> employees, int id)
    {
        for (auto emp : employees)
            myMap[emp->id] = emp;
        
        int imp = 0;
        subOrdIds.push(id);
        
        do {
            int currId = subOrdIds.front();
            subOrdIds.pop();
            
            imp += myMap[currId]->importance;
            
            for (int subId : myMap[currId]->subordinates)
                subOrdIds.push(subId);
        } while (!subOrdIds.empty());

        return imp;
    }

  private:
    map<int, Employee *> myMap;
    queue<int> subOrdIds;
};
