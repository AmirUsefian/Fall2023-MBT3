#include <iostream>
#include <Eigen/Dense>

using namespace std;

using namespace Eigen;

class MatrixOperations {
public:
    MatrixOperations() {}

    void run() {
        // گرفتن اندازه ماتریس از کاربر
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        // تعریف ماتریس با اندازه داده شده
        MatrixXd mat1(rows, cols);
        MatrixXd mat2(rows, cols);

        // گرفتن مقادیر ماتریس از کاربر
        cout << "Enter values for matrix 1:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat1(i, j);
            }
        }

        cout << "Enter values for matrix 2:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat2(i, j);
            }
        }

        // عملیات جمع و تفریق و ضرب بر روی ماتریس‌ها
        MatrixXd sum = mat1 + mat2;
        MatrixXd sub = mat1 - mat2;
        MatrixXd mul = mat1 * mat2;

        // نمایش نتایج
        cout << "Sum:" << endl << sum << endl;
        cout << "Subtraction:" << endl << sub << endl;
        cout << "Multiplication:" << endl << mul << endl;

        // تعیین اندازه ماتریس برای determinant
        if (rows == 2 && cols == 2) {
            double det1 = mat1(0, 0) * mat1(1, 1) - mat1(0, 1) * mat1(1, 0);
            double det2 = mat2(0, 0) * mat2(1, 1) - mat2(0, 1) * mat2(1, 0);
            cout << "Determinant 1: " << det1 << endl << "Determinant 2: " << det2 << endl;
        } else if (rows == 3 && cols == 3) {
            double det1 = mat1.determinant();
            double det2 = mat2.determinant();
            cout << "Determinant 1: " << det1 << endl << "Determinant 2: " << det2 << endl;
        } else {
            cout << "Cannot calculate determinant" << endl;
        }

        // عملیات inverse با استفاده از کتابخانه eigen
        if (rows == cols) {
            MatrixXd inv1 = mat1.inverse();
            MatrixXd inv2 = mat2.inverse();
            cout << "Inverse 1 : " << endl << inv1 << endl << "Inverse 2 : " << inv2 << endl; 
        } else {
            cout << "Cannot calculate inverse" << endl;
        }
    }
};

int main() {
    MatrixOperations matOps;
    matOps.run();
    return 0;
}