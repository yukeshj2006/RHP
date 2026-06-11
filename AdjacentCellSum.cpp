#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    if (!(cin >> rows >> cols) || rows <= 0 || cols <= 0) {
        cout << "Invalid dimensions." << endl;
        return 1;
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int targetRow, targetCol;
    cout << "Enter the row and column index to calculate neighbor sum (0-indexed): ";
    cin >> targetRow >> targetCol;

    if (targetRow < 0 || targetRow >= rows || targetCol < 0 || targetCol >= cols) {
        cout << "Error: Index out of bounds." << endl;
        return 1;
    }

    int sum = 0;

    int rowOffsets[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int colOffsets[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) {
        int neighborRow = targetRow + rowOffsets[i];
        int neighborCol = targetCol + colOffsets[i];

        if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
            sum += matrix[neighborRow][neighborCol];
        }
    }

    cout << "Sum of elements surrounding (" << targetRow << ", " << targetCol << ") is: " << sum << endl;

    return 0;
}