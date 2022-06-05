
import java.util.ArrayList;
import java.util.List;

public class Solution {

    private static final int FREE_SPACE = 0;
    private static final int HOUSE = 1;

    public int minTotalDistance(int[][] matrix) {
        List<Integer> startRowsInAscendingOrder = findStartRowsInAscendingOrder(matrix);
        List<Integer> startColumnsInAscendingOrder = findStartColumnsInAscendingOrder(matrix);
        return calculateDistance(startRowsInAscendingOrder) + calculateDistance(startColumnsInAscendingOrder);
    }

    private List<Integer> findStartRowsInAscendingOrder(int[][] matrix) {
        List<Integer> startRowsInAscendingOrder = new ArrayList<>();
        for (int row = 0; row < matrix.length; ++row) {
            for (int column = 0; column < matrix[0].length; ++column) {
                if (matrix[row][column] == HOUSE) {
                    startRowsInAscendingOrder.add(row);
                }
            }
        }
        return startRowsInAscendingOrder;
    }

    private List<Integer> findStartColumnsInAscendingOrder(int[][] matrix) {
        List<Integer> startColumnsInAscendingOrder = new ArrayList<>();
        for (int column = 0; column < matrix[0].length; ++column) {
            for (int row = 0; row < matrix.length; ++row) {
                if (matrix[row][column] == HOUSE) {
                    startColumnsInAscendingOrder.add(column);
                }
            }
        }
        return startColumnsInAscendingOrder;
    }

    private int calculateDistance(List<Integer> positions) {
        int front = 0;
        int end = positions.size() - 1;
        int totalDistance = 0;
        while (front < end) {
            totalDistance += positions.get(end) - positions.get(front);
            ++front;
            --end;
        }
        return totalDistance;
    }
}
