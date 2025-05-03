#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        int left = 0;
        int top = 0;
        while (top < bottom) {
            int mid = (bottom + top) / 2;
            if (matrix[mid][right] == target) {
                return true;
            }
            else if (matrix[mid][right] < target) {
                top = mid + 1;
            }
            else {
                bottom = mid;
            }
        }

        while (left <= right) {
            int mid = (right + left) / 2;
            if (matrix[top][mid] == target) {
                return true;
            }
            else if (matrix[top][mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};
