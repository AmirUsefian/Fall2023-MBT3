#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    void inputMatrix() {
        cout << "Enter the elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void displayMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix m) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return result;
    }

    Matrix subtract(Matrix m) {
        Matrix result(rows, cols);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - m.data[i][j];
            }
        }
        return result;
    }

    

     Matrix multiply(Matrix m) {
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return result;
    }

     Matrix determine(Matrix) {
        if (rows == 2 && cols == 2) {
            Matrix result(1, 1);
            result.data[0][0] = data[0][0] * data[1][1] - data[0][1] * data[1][0];
            return result;
        } else if (rows == 3 && cols == 3) {
            Matrix result(1, 1);
            result.data[0][0] = data[0][0] * data[1][1] * data[2][2] +
                                data[0][1] * data[1][2] * data[2][0] +
                                data[0][2] * data[1][0] * data[2][1] -
                                data[0][2] * data[1][1] * data[2][0] -
                                data[0][1] * data[1][0] * data[2][2] -
                                data[0][0] * data[1][2] * data[2][1];
            return result;
        } else {
            cout << "Cannot determine for this matrix size" << endl;
            exit(1);
        }
    }

    Matrix inverse(Matrix) {
        if (rows == 2 && cols == 2) {
            Matrix result(rows, cols);
            int det = data[0][0] * data[1][1] - data[0][1] * data[1][0];
            if (det == 0) {
                cout << "Inverse does not exist" << endl;
                exit(1);
            } else {
                result.data[0][0] = data[1][1] / det;
                result.data[0][1] = -data[0][1] / det;
                result.data[1][0] = -data[1][0] / det;
                result.data[1][1] = data[0][0] / det;
                return result;
            }
        } else if (rows == 3 && cols == 3) {
            Matrix result(rows, cols);
            int det =
                data[0][0] * (data[1][1] * data[2][2] - data[1][2] * data[2][1]) -
                data[0][1] * (data[1][0] * data[2][2] - data[1][2] * data[2][0]) +
                data[0][2] * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
            if (det == 0) {
                cout << "Inverse does not exist" << endl;
                exit(1);
            } else

{
                result.data[0][0] = (data[1][1]*data[2][2]-data[1][2]*data[2][1]) / det;
                result.data[0][1] = (data[0][2]*data[2][1]-data[0][1]*data[2][2]) / det;
                result.data[0][2] = (data[0][1]*data[1][2]-data[0][2]*data[1][1]) / det;
                result.data[1][0] = (data[1][2]*data[2][0]-data[1][0]*data[2][2]) / det;
                result.data[1][1] = (data[0][0]*data[2][2]-data[0][2]*data[2][0]) / det;
                result.data[1][2] = (data[0][2]*data[1][0]-data[0][0]*data[1][2]) / det;
                result.data[2][0] = (data[1][0]*data[2][1]-data[1][1]*data[2][0]) / det;
                result.data[2][1] = (data[0][1]*data[2][0]-data[0][0]*data[2][1]) / det;
                result.data[2][2] = (data[0][0]*data[1][1]-data[0][1]*data[1][0]) / det;
                return result;
            }
        } else {
            cout << "Cannot find inverse for this matrix size" << endl;
            exit(1);
        }
    }


    
};

int main() {
    int choice, r, c;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> r >> c;

    Matrix matrix(r, c);
    matrix.inputMatrix();

    cout << "Choose an operation to perform on the matrix:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Determine" << endl;
    cout << "5. Inverse" << endl;
    cin >> choice;

    Matrix result(r, c);
    switch (choice) {
        case 1:
            result = matrix.add(matrix);
            break;
        case 2:
            result = matrix.subtract(matrix);
            break;
        case 3:
            result = matrix.multiply(matrix);
            break;
        case 4:
            result = matrix.determine(matrix);
            break;
        case 5:
             result = matrix.inverse(matrix);   
             break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    cout << "Result:" << endl;
    result.displayMatrix();

    return 0;
}