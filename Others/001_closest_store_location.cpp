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

// Google interview question
// Given the location (block number) of each house and store, find the closest stores for each house
vector<int> closest_stores(vector<int> houses, vector<int> stores)
{
    vector<int> nearest_stores;
    sort(stores.begin(), stores.end());

    for (int house : houses) {
        cout << "(" << house << ", ";
        // Binary search nearest store for the house
        int st = 0, end = stores.size() - 1;
        int mid;
        bool found = false;
        while (st < end) {
            mid = st + (end - st) / 2;
            if (house < stores[mid]) {
                if (house > stores[mid - 1]) {
                    // compare delta and return the lowest delta or lowest index
                    int house_left_dist = house - stores[mid - 1];
                    int house_right_dist = stores[mid] - house;
                    int min_dist = min(house_left_dist, house_right_dist);
                    if (min_dist == house_left_dist) {
                        nearest_stores.push_back(stores[mid - 1]);
                        cout << stores[mid - 1] << ") ";
                        found = true;
                    }
                    else {
                        nearest_stores.push_back(stores[mid]);
                        cout << stores[mid] << ") ";
                        found = true;
                    }
                    break;
                }
                else {
                    end = mid - 1;
                }
            }
            else if (house > stores[mid]) {
                if (house < stores[mid + 1]) {
                    // compare delta and return the lowest delta or lowest index
                    int house_left_dist = house - stores[mid];
                    int house_right_dist = stores[mid + 1] - house;
                    int min_dist = min(house_left_dist, house_right_dist);
                    if (min_dist == house_left_dist) {
                        nearest_stores.push_back(stores[mid]);
                        cout << stores[mid] << ") ";
                        found = true;
                    }
                    else {
                        nearest_stores.push_back(stores[mid + 1]);
                        cout << stores[mid + 1] << ") ";
                        found = true;
                    }
                    break;
                }
                else {
                    st = mid + 1;
                }
            }
            // If not found during binary search, push in the end
            if (st >= end) {
                mid = st + (end - st) / 2;
                nearest_stores.push_back(stores[mid]);
               
                cout << stores[mid] << ") ";
            }
        }
    }

    cout << endl;

    return nearest_stores;
}


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &stores, vector<int> &houses) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> closest_houses;
    
    sort(stores.begin(), stores.end());
    //cout << "Stores: ";
    //for (int store : stores)
    //    cout << store << " ";
    //cout << endl;
    for (int house : houses) {
        int lo = 0, hi = stores.size() - 1;
        int mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (house <= stores[lo]) {
                closest_houses.push_back(stores[lo]);
                break;
            }
            if (house >= stores[hi]) {
                closest_houses.push_back(stores[hi]);
                break;
            }
            if (house == stores[mid]) {
                closest_houses.push_back(stores[mid]);
                break;
            }
            else if (house < stores[mid]) {
                if (house > stores[mid - 1]) {
                    int left_store_dist = house - stores[mid - 1];
                    int right_store_dist = stores[mid] - house;
                    int min_dist = min(left_store_dist, right_store_dist);
                    if (left_store_dist == min_dist) {
                        closest_houses.push_back(stores[mid - 1]);
                        break;
                    }
                    else {
                        closest_houses.push_back(stores[mid]);
                        break;
                    }
                }
                else {
                    hi = mid - 1;
                    continue;
                }
            }
            else if (house > stores[mid]) {
                if (house < stores[mid + 1]) {
                    int left_store_dist = house - stores[mid];
                    int right_store_dist = stores[mid + 1] - house;
                    int min_dist = min(left_store_dist, right_store_dist);
                    if (left_store_dist == min_dist) {
                        closest_houses.push_back(stores[mid]);
                        break;
                    }
                    else {
                        closest_houses.push_back(stores[mid + 1]);
                        break;
                    }
                }  
                else {
                    lo = mid + 1;
                    continue;
                }
            }
        }
    }
    
    return closest_houses;
}

int main()
{
    vector<int> houses_loc {11, 5, 2, 14, 1, 3, 7, 16, 6, 13, 8};
    vector<int> stores_loc {4, 15, 10, 9, 0, 12};

    vector<int> near_stores = closest_stores(houses_loc, stores_loc);
    for (int near_store : near_stores)
        cout << near_store << " ";
    cout << endl;

    return 0;
}