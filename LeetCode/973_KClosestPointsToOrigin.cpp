#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

void print_points(vector<vector<int>> points) {
	cout << "{";
	for(vector<int> point: points) {
		cout << "(" << point[0] << ", " << point[1] << ") ";
	}
	cout << "}" << endl;
}

class Solution {
public:
	// Returns k closest points from the origin in O(n) time
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		work(points, 0, points.size() - 1, K);

		vector<vector<int>> k_closest;
		for(int i = 0; i < K; i++)
			k_closest.push_back(points[i]);
		return k_closest;
	}

private:
	// Logic like quick sort: Divide and Conquer
	void work(vector<vector<int>>& points, int start, int end, int K) {
		if(start >= end)
			return;

		int pivot = rand() % (end - start + 1) + start;

		swap_points(points[start], points[pivot]);

		int mid = quick_select(points, start, end);

		int left_length = mid - start + 1;
		if (K < left_length)
			work(points, start, mid - 1, K);
		else if (K > left_length)
			work(points, mid + 1, end, K - left_length);
	}

	// Quick select with pivot in first index and rearrange array
	//  by storing smaller values to the left and bigger to the right
	int quick_select(vector<vector<int>>& points, int start, int end) {
		int i = start + 1, j = end;
		int pivot_dist = origin_distance(points[start]);

		while (true) {
			while(i < j && origin_distance(points[i]) < pivot_dist)
				i++;
			while(i <= j && origin_distance(points[j]) >= pivot_dist)
				j--;

			if(i >= j)
				break;
			swap_points(points[i], points[j]);
		}

		swap_points(points[start], points[j]);
		return j;
	}

	int origin_distance(vector<int> point) {
		return point[0] * point[0] + point[1] * point[1];
	}

	void swap_points(vector<int>& p_1, vector<int>& p_2) {
		int p1_x = p_1[0], p1_y = p_1[1];
		p_1[0] = p_2[0]; p_1[1] = p_2[1];
		p_2[0] = p1_x; p_2[1] = p1_y;
	}
};

int main() {
	vector<vector<int>> input1 {{1, 3}, {-2, 2}};
	print_points(Solution().kClosest(input1, 1));

	vector<vector<int>> input2 {{3, 3}, {5, -1}, {-2, 4}};
	print_points(Solution().kClosest(input2, 2));

	vector<vector<int>> input3 {{2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}, {1, 1}};;
	print_points(Solution().kClosest(input3, 1));

	return 0;
}
