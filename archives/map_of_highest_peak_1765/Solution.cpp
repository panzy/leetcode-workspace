/*
1765. Map of Highest Peak
https://leetcode.com/problems/map-of-highest-peak
--
Zhiyong, 2021-02-20
*/
#include <iostream>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(const vector<vector<int>>& isWater) {
        const int m = isWater.size();
        const int n = isWater[0].size();
        const int neibs[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

        auto A = isWater; // will be the answer
		queue<int> q; // cells that will be used to fix their surrounding cells' heights.

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (isWater[r][c] == 1) {
					A[r][c] = 0;
					q.push(r * 1000 + c);
				}
				else {
					A[r][c] = 9999; // init all land height to max
				}
            }
        }

		while (!q.empty()) {
			int r2 = q.front() / 1000;
			int c2 = q.front() % 1000;
			q.pop();

			for (auto&& d : neibs) {
				int r3 = r2 + d[0];
				int c3 = c2 + d[1];
				if (0 <= r3 && r3 < m &&
					0 <= c3 && c3 < n &&
					A[r3][c3] > A[r2][c2] + 1) {
					A[r3][c3] = A[r2][c2] + 1;
					q.push(r3 * 1000 + c3);
				}
			}
		}

        return A;
    }
};

int main() {
	{
		int m = 100, n = 100;
		vector<vector<int>> isWater;
		isWater.resize(m);
		for (vector<int>& row : isWater) {
			row.resize(n);
			fill(row.begin(), row.end(), 0);
		}
		isWater[0][0] = 1;
        vector<vector<int>> A = Solution().highestPeak(isWater);
	}

	{ // test case 21
		vector<vector<int>> isWater = {
			{1,1,0,1,0,0,0,0,0,1,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1},
			{1,1,1,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,0,0,1,1,0,0,1,0,0,1,1,1,0},
			{1,1,0,1,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,1,1,0,0},
			{1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,1,0,0,0,0,1,1,1},
			{1,0,1,1,0,0,1,0,1,1,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1},
			{1,1,0,0,1,0,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,0,0,1,1,1,0,0,0,1,1},
			{1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,1},
			{0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1},
			{1,1,0,0,1,1,0,0,1,1,1,1,1,0,1,0,1,1,0,0,0,1,0,0,1,1,1,1,0,0,1},
			{1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,1,1,1,0,1,1,0,0,1,0,1},
			{0,1,0,0,0,0,1,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,0,0,1,1,0},
			{1,0,1,1,1,1,1,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1},
			{1,1,1,0,1,1,1,0,1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,0,0,1,0},
			{1,1,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,1,0,1},
			{1,1,1,1,1,0,1,1,0,1,0,0,1,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,1,0,1},
			{1,1,1,1,0,1,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1},
			{1,0,1,1,0,1,1,0,1,0,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1,1,1,1,1,0},
			{1,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,1},
			{1,1,1,1,0,0,1,1,0,0,0,1,1,0,1,1,1,0,0,0,0,0,1,0,0,1,1,0,1,0,1},
			{1,0,0,0,1,1,1,1,0,1,1,1,0,1,0,0,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1},
			{1,1,1,0,1,1,1,0,1,1,1,1,0,0,0,0,1,0,1,0,1,1,0,1,1,1,1,0,0,1,1},
			{0,0,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,0,1,1,0,0,1,1},
			{1,1,0,0,1,0,1,1,0,1,1,0,1,1,0,1,1,1,0,0,1,0,1,0,1,1,0,1,0,1,0},
			{1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,1,1,1,0,1,0,1,1,1,0,0},
			{0,1,1,1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,1,0,0,0,0,1,0,0,1,0,1,0},
			{1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,1,1,1,1,1,0,0},
			{0,0,0,1,1,0,1,1,0,1,0,0,0,0,1,1,1,0,1,0,1,1,1,1,1,0,0,0,0,1,0},
			{1,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,0,0,0,1,1,0,0,1,1,1,1,1,0,0,0},
			{1,1,1,0,0,0,0,1,1,0,1,1,0,1,0,1,0,1,1,0,0,0,1,1,1,0,1,1,0,1,1},
			{1,0,1,0,1,1,0,1,0,1,1,1,0,0,0,0,1,0,1,0,0,0,1,0,1,1,0,0,1,1,0},
			{1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0},
			{0,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1}
		};
        vector<vector<int>> A = Solution().highestPeak(isWater);
	}
	{
		vector<vector<int>> isWater = {
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		};
        vector<vector<int>> A = Solution().highestPeak(isWater);
	}
    {
        vector<vector<int>> A = Solution().highestPeak({ {0, 1}, {0, 0} });
        //_ASSERT(Solution().canChoose(groups, nums));
    }
	{
		vector<vector<int>> isWater = {
			{1, 0, 1, 1, 0, 1, 1, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
			{1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
			{0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
			{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
			{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
			{0, 0, 0, 1, 1, 0, 1, 0, 1, 0},
			{1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
			{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
			{0, 1, 1, 1, 0, 1, 0, 0, 0, 0},
			{0, 0, 1, 0, 1, 1, 0, 0, 0, 1},
			{0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
			{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
			{1, 1, 1, 0, 0, 0, 0, 0, 0, 0}
		};
        vector<vector<int>> A = Solution().highestPeak(isWater);
	}

	{
		vector<vector<int>> isWater = {
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
		};
        vector<vector<int>> A = Solution().highestPeak(isWater);
	}
    return 0;
}