
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var minTotalDistance = function (matrix) {
    this.FREE_SPACE = 0;
    this.HOUSE = 1;
    const startRowsInAscendingOrder = findStartRowsInAscendingOrder(matrix);
    const startColumnsInAscendingOrder = findStartColumnsInAscendingOrder(matrix);
    return calculateDistance(startRowsInAscendingOrder) + calculateDistance(startColumnsInAscendingOrder);
};

/**
 * @param {number[][]} matrix
 * @return {void}
 */
function findStartRowsInAscendingOrder(matrix) {
    const startRowsInAscendingOrder = [];
    for (let row = 0; row < matrix.length; ++row) {
        for (let column = 0; column < matrix[0].length; ++column) {
            if (matrix[row][column] === this.HOUSE) {
                startRowsInAscendingOrder.push(row);
            }
        }
    }
    return startRowsInAscendingOrder;
}

/**
 * @param {number[][]} matrix
 * @return {void}
 */
function findStartColumnsInAscendingOrder(matrix) {
    const startColumnsInAscendingOrder = [];
    for (let column = 0; column < matrix[0].length; ++column) {
        for (let row = 0; row < matrix.length; ++row) {
            if (matrix[row][column] === this.HOUSE) {
                startColumnsInAscendingOrder.push(column);
            }
        }
    }
    return startColumnsInAscendingOrder;
}

/**
 * @param {number[]} positions
 * @return {number}
 */
function calculateDistance(positions) {
    let front = 0;
    let end = positions.length - 1;
    let totalDistance = 0;
    while (front < end) {
        totalDistance += positions[end] - positions[front];
        ++front;
        --end;
    }
    return totalDistance;
}
