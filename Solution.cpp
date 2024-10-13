
#include <vector>
using namespace std;

class Solution {
    
    inline static const int FREE_SPACE = 0;
    inline static const int HOUSE = 1;

public:
    int minTotalDistance(vector<vector<int>>& matrix) const {
        vector<int> startRowsInAscendingOrder = findStartRowsInAscendingOrder(matrix);
        vector<int> startColumnsInAscendingOrder = findStartColumnsInAscendingOrder(matrix);
        return calculateDistance(startRowsInAscendingOrder) + calculateDistance(startColumnsInAscendingOrder);
    }

private:
    vector<int> findStartRowsInAscendingOrder(const vector<vector<int>>& matrix) const {
        vector<int> startRowsInAscendingOrder;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int column = 0; column < matrix[0].size(); ++column) {
                if (matrix[row][column] == HOUSE) {
                    startRowsInAscendingOrder.push_back(row);
                }
            }
        }
        return startRowsInAscendingOrder;
    }

    vector<int> findStartColumnsInAscendingOrder(const vector<vector<int>>& matrix) const {
        vector<int> startColumnsInAscendingOrder;
        for (int column = 0; column < matrix[0].size(); ++column) {
            for (int row = 0; row < matrix.size(); ++row) {
                if (matrix[row][column] == HOUSE) {
                    startColumnsInAscendingOrder.push_back(column);
                }
            }
        }
        return startColumnsInAscendingOrder;
    }

    int calculateDistance(const vector<int>& positions) const {
        int front = 0;
        int end = positions.size() - 1;
        int totalDistance = 0;
        while (front < end) {
            totalDistance += positions[end] - positions[front];
            ++front;
            --end;
        }
        return totalDistance;
    }
};
