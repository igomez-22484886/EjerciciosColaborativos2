//
// Created by Israel on 07/10/2025.
//
#include <iostream>
#include "../include/Exercise3_AdvancedCalculator.h"
using namespace std;

// ========
//  Matrix
// ========
template <typename T>
class Matrix {
private:
    T matrix[10][10];
    int rows, cols;
public:
    //Constructor
    Matrix() {
        rows = 0;
        cols = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    //Inicializa la matriz
    void ini_matrix() {
        T dat;
        cout << "Enter the number of rows of the matrix:" << endl;
        cin >> rows;
        cout << "Enter the number of columns of the matrix:" << endl;
        cin >> cols;
        cout << "Enter elements for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> dat;
                matrix[i][j] = dat;
            }
        }
    }
    // --- Función auxiliar para calcular el adjunto (para la inversa) ---
    void adjoint(T mat[10][10], T adj[10][10], int n) {
        if (n == 1) {
            adj[0][0] = 1;
            return;
        }

        T temp[10][10];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Crear la submatriz para el cofactor
                int subi = 0;
                for (int row = 0; row < n; row++) {
                    if (row == i) {
                    } else {
                        int subj = 0;
                        for (int col = 0; col < n; col++) {
                            if (col == j) {
                            } else {
                                temp[subi][subj] = mat[row][col];
                                subj++;
                            }
                        }
                        subi++;
                    }
                }

                int sign;
                if ((i + j) % 2 == 0) {
                    sign = 1;
                } else {
                    sign = -1;
                }

                adj[j][i] = sign * determinantRecursive(temp, n - 1);
            }
        }
    }

    // --- Función auxiliar para invertir una matriz cuadrada (para división de matrices)---
    bool inverse(T mat[10][10], T inv[10][10], int n) {
        T det = determinantRecursive(mat, n);
        if (det == 0) {
            cout << "Error: The matrix is singular and cannot be inverted." << endl;
            return false;
        }

        T adj[10][10];
        adjoint(mat, adj, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                inv[i][j] = adj[i][j] / det;
            }
        }

        return true;
    }
    // --- NUEVO: División entre matrices (A / B = A * inv(B)) ---
    Matrix<T> div_matrix(Matrix<T> otra) {
        Matrix<T> res;
        if (otra.rows != otra.cols) {
            cout << "Error: only square matrices can be inverted for division." << endl;
            return res;
        }
        T inv[10][10];
        if (inverse(otra.matrix, inv, otra.rows) == false) {
            return res; // No invertible
        }

        res.rows = rows;
        res.cols = otra.cols;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < otra.cols; j++) {
                res.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    res.matrix[i][j] += matrix[i][k] * inv[k][j];
            }
        return res;
    }
    //Imprime la matriz
    void pri_matrix() {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    //Sumar matrices
    Matrix<T> add_matrix(Matrix<T> otra) {
        Matrix<T> res;
        if (rows != otra.rows || cols != otra.cols) {
            cout << "They must be the same dimension in order to be added." << endl;
            return res;
        }
        res.rows = rows;
        res.cols = cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.matrix[i][j] = matrix[i][j] + otra.matrix[i][j];
            }
        }
        return res;
    }
    //Restar matrices
    Matrix<T> sub_matrix(Matrix<T> otra) {
        Matrix<T> res;
        if (rows != otra.rows || cols != otra.cols) {
            cout << "They must be the same dimension in order to be added." << endl;
            return res;
        }
        res.rows = rows;
        res.cols = cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.matrix[i][j] = matrix[i][j] - otra.matrix[i][j];
            }
        }
        return res;
    }
    //multiplicacion matrices
    Matrix<T> mul_matrix(Matrix<T> otra) {
        Matrix<T> res;
        if (cols != otra.rows) {
            cout << "Error: multiplication cannot be performed. Columns of first matrix must equal rows of second." << endl;
            return res;
        }
        res.rows = rows;
        res.cols = cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < otra.cols; j++) {
                res.matrix[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    res.matrix[i][j] += matrix[i][k] * otra.matrix[k][j];
                }
            }
        }
        return res;
    }
    //division entre escalar
    Matrix<T> div_scalar(T scalar) {
        Matrix<T> res;
        if (scalar == 0) {
            cout << "Error: division by zero is not allowed." << endl;
            return res;
        }
        res.rows = rows;
        res.cols = cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.matrix[i][j] = matrix[i][j] / scalar;
            }
        }
        return res;
    }
    //matriz transpuesta
    Matrix<T> transpose() {
        Matrix<T> res;
        res.rows = cols;
        res.cols = rows;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.matrix[j][i] = matrix[i][j];
            }
        }
        return res;
    }
    //determinante matriz
    T determinant() {
        if (cols != rows) {
            cout << "Error: determinant is defined only for square matrices." << endl;
            return 0;
        }
        if (rows == 1) {
            return matrix[0][0];
        }
        if (rows == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
        if (rows == 3) {
            return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
            - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
            + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
        }

        cout << "Determinant calculation for matrices larger than 3x3 is not supported in this version." << endl;
        return 0;
    }
    //menu matrices
    void matrixMenu() {
        bool exit = false;
        while (!exit) {
            int option;
            cout << "----- Matrix Operations Menu -----" << endl;
            cout << "1. Add two matrices" << endl;
            cout << "2. Subtract two matrices" << endl;
            cout << "3. Multiplication two matrices" << endl;
            cout << "4. Matrix division by a scalar" << endl;
            cout << "5. Divide two matrices (A * inv(B))" << endl;
            cout << "6. Transpose matrix" << endl;
            cout << "7. Determinant of matrix (square only)" << endl;
            cout << "8. Back to main menu" << endl;
            cout << "\nSelect an option: " << endl;
            cin >> option;

            switch (option) {
                case 1: {
                    Matrix<T> m1, m2, result;
                    cout << "------------" << endl;
                    cout << "  Matrix A  " << endl;
                    cout << "------------" << endl;
                    m1.ini_matrix();
                    cout << "------------" << endl;
                    cout << "  Matrix B  " << endl;
                    cout << "------------" << endl;
                    m2.ini_matrix();
                    result = m1.add_matrix(m2);
                    cout << "Result of addition:" << endl;
                    result.pri_matrix();
                    break;
                }
                case 2: {
                    Matrix<T> m1, m2, result;
                    cout << "------------" << endl;
                    cout << "  Matrix A  " << endl;
                    cout << "------------" << endl;
                    m1.ini_matrix();
                    cout << "------------" << endl;
                    cout << "  Matrix B  " << endl;
                    cout << "------------" << endl;
                    m2.ini_matrix();
                    result = m1.sub_matrix(m2);
                    cout << "Result of subtraction:" << endl;
                    result.pri_matrix();
                    break;
                }
                case 3: {
                    Matrix<T> m1, m2, result;
                    cout << "------------" << endl;
                    cout << "  Matrix A  " << endl;
                    cout << "------------" << endl;
                    m1.ini_matrix();
                    cout << "------------" << endl;
                    cout << "  Matrix B  " << endl;
                    cout << "------------" << endl;
                    m2.ini_matrix();
                    result = m1.mul_matrix(m2);
                    cout << "Result of multiplication:" << endl;
                    result.pri_matrix();
                    break;
                }
                case 4: {
                    cout << "Enter scalar to divide the matrix: " << endl;
                    T scalar;
                    cin >> scalar;
                    Matrix<T> result = div_scalar(scalar);
                    cout << "Result after division by " << scalar << ":" << endl;
                    result.pri_matrix();
                    break;
                }
                case 5: {
                    Matrix<T> m1, m2, result;
                    cout << "------------" << endl;
                    cout << "  Matrix A  " << endl;
                    cout << "------------" << endl;
                    m1.ini_matrix();
                    cout << "------------" << endl;
                    cout << "  Matrix B  " << endl;
                    cout << "------------" << endl;
                    m2.ini_matrix();
                    result = m1.div_matrix(m2);
                    cout << "Result of A / B:" << endl;
                    result.pri_matrix();
                    break;
                }
                case 6: {
                    Matrix<T> m;
                    cout << "-------------------" << endl;
                    cout << "  Original Matrix  " << endl;
                    cout << "-------------------" << endl;
                    m.ini_matrix();
                    Matrix<T> result = m.transpose();
                    cout << "Transposed matrix:" << endl;
                    result.pri_matrix();
                    break;
                }
                case 7: {
                    Matrix<T> m;
                    cout << "Enter square matrix:" << endl;
                    m.ini_matrix();
                    T det = m.determinant();
                    cout << "Determinant:" << det << endl;
                    break;
                }
                case 8:
                    exit = true;
                    break;
                default:
                    cout << "Invalid option!" << endl;
            }
        }
    }
};
// ============
//  Calculator
// ============
template <typename T>
class Calculator {
    public:
        void add() {
            T a,b;
            cout << "Enter two values: " << endl;
            cin >> a;
            cin >> b;
            cout << "The sum of " << a << " and " << b << " is: " << a+b << endl;
        }
        void subtract() {
            T a,b;
            cout << "Enter two values: " << endl;
            cin >> a;
            cin >> b;
            cout << "The subtraction of " << a << " and " << b << " is: " << a-b << endl;
        }
        void multiply() {
            T a,b;
            cout << "Enter two values: " << endl;
            cin >> a;
            cin >> b;
            cout << "The multiplication of " << a << " and " << b << " is: " << a*b << endl;
        }
        void divide() {
            T a,b;
            cout << "Enter two values: " << endl;
            cin >> a;
            cin >> b;
            if (b == 0) {
                cout << "Error: division by zero is not allowed." << endl;
                return;
            }
            cout << "The result of the division is: " << a/b << endl;
            cout << "The remainder of the division is: " << a % b << endl;
        }
        void menu() {
            bool exit=false;
            while (!exit) {
                int opt;
                cout << "-----Menu-----" << endl;
                cout << "1. Add" << endl;
                cout << "2. Subtract" << endl;
                cout << "3. Multiply" << endl;
                cout << "4. Divide" << endl;
                cout << "5. Matrix operations" << endl;
                cout << "6. Exit" << endl;
                cout << "\nSelect an option: " << endl;
                cin >> opt;
                switch (opt) {
                    case 1:
                        add();
                        break;
                    case 2:
                        subtract();
                        break;
                    case 3:
                        multiply();
                        break;
                    case 4:
                        divide();
                        break;
                    case 5:
                        Matrix<T> m;
                        m.matrixMenu();
                        break;
                    case 6:
                        exit=true;
                        break;
                    default:
                        cout << "Invalid option!" << endl;
                }
            }
        }
};


void Exercise3_AdvancedCalculator::run() {
    cout << "Ejecutando Exercise 1 - Student Management..." << endl;
    // Aquí pondrás todo el menú y lógica del ejercicio 1
}