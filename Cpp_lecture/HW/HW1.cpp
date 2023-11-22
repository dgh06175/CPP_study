#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
    vector<vector<int>> mat;
    int row;
    int col;

    Matrix()
    {
        this->row = 0;
        this->col = 0;
    }

    Matrix(int m, int n)
    {
        this->row = m;
        this->col = n;
        mat.resize(row);
        for (int i = 0; i < mat.size(); i++)
        {
            mat[i].resize(col);
        }
    }

    Matrix operator+(Matrix in)
    {
        if (row != in.row || col != in.col)
        {
            cout << "두 행렬의 크기가 같지 않아 덧셈 연산이 불가능합니다." << endl;
            cout << "(" << row << "," << in.row << " " << col << "," << in.col << ")" << endl;
            return Matrix();
        }
        Matrix tmp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                tmp.mat[i][j] = mat[i][j] + in.mat[i][j];
            }
        }
        return tmp;
    }

    Matrix operator-(Matrix in)
    {
        if (row != in.row || col != in.col)
        {
            cout << "두 행렬의 크기가 같지 않아 뺄셈 연산이 불가능합니다." << endl;
            cout << "(" << row << "," << in.row << " " << col << "," << in.col << ")" << endl;
            return Matrix();
        }
        Matrix tmp(row, col);
        for (int i = 0; i < tmp.row; i++)
        {
            for (int j = 0; j < tmp.col; j++)
            {
                tmp.mat[i][j] = mat[i][j] - in.mat[i][j];
            }
        }
        return tmp;
    }

    Matrix operator*(Matrix in)
    {
        if (col != in.row)
        {
            cout << "앞 행렬의 행과 뒤 행렬의 열이 같지 않아 곱셈 연산이 불가능합니다." << endl;
            cout << "(" << col << "," << in.row << ")" << endl;
            return Matrix();
        }
        Matrix tmp(row, in.col);
        for (int i = 0; i < tmp.row; i++)
        {
            for (int j = 0; j < tmp.col; j++)
            {
                tmp.mat[i][j] = 0;
                for (int k = 0; k < col; k++)
                {
                    tmp.mat[i][j] += mat[i][k] * in.mat[k][j];
                }
            }
        }
        return tmp;
    }

    void operator+=(Matrix in)
    {
        *this = *this + in;
    }

    void operator-=(Matrix in)
    {
        *this = *this - in;
    }

    Matrix operator*(int value)
    {
        Matrix tmp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                tmp.mat[i][j] = mat[i][j] * value;
            }
        }
        return tmp;
    }

    Matrix operator+(int value)
    {
        Matrix tmp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                tmp.mat[i][j] = mat[i][j] + value;
            }
        }
        return tmp;
    }

    Matrix operator-(int value)
    {
        Matrix tmp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                tmp.mat[i][j] = mat[i][j] - value;
            }
        }
        return tmp;
    }

    Matrix operator/(int value)
    {
        if (value == 0)
        {
            cout << "0으로 나눌수 없습니다." << endl;
            return Matrix();
        }
        Matrix tmp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                tmp.mat[i][j] = mat[i][j] / value;
            }
        }
        return tmp;
    }

    void show()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Matrix A(2, 3);
    Matrix A_t(3, 2);
    Matrix B(3, 2);

    // 행렬 A 초기화
    int value = 1;
    for (int i = 0; i < A.row; i++)
    {
        for (int j = 0; j < A.col; j++)
        {
            A.mat[i][j] = value++;
        }
    }

    // A의 전치행렬 A_t 초기화
    value = 1;
    for (int i = 0; i < A_t.col; i++)
    {
        for (int j = 0; j < A_t.row; j++)
        {
            A_t.mat[j][i] = value++;
        }
    }

    // 행렬 B 초기화
    value = 1;
    for (int i = 0; i < B.row; i++)
    {
        for (int j = 0; j < B.col; j++)
        {
            B.mat[i][j] = 10 + value++;
        }
    }

    cout << "A:" << endl;
    A.show();
    cout << "A_t:" << endl;
    A_t.show();
    cout << "B:" << endl;
    B.show();

    Matrix C;

    cout << "C = A * B:" << endl;
    C = A * B;
    C.show();

    cout << "C = A_t * B:" << endl;
    C = A_t * B;
    C.show();

    cout << "C = A + B:" << endl;
    C = A + B;
    C.show();

    cout << "C = A_t + B:" << endl;
    C = A_t + B;
    C.show();

    cout << "C = A - B:" << endl;
    C = A - B;
    C.show();

    cout << "C = A_t - B:" << endl;
    C = A_t - B;
    C.show();

    cout << "C += B:" << endl;
    C += B;
    C.show();

    cout << "C -= B:" << endl;
    C -= B;
    C.show();

    cout << "C = A * 2:" << endl;
    C = A * 2;
    C.show();

    cout << "C = C / 2:" << endl;
    C = C / 2;
    C.show();

    cout << "C = C / 0:" << endl;
    C = C / 0;
    C.show();

    cout << "C = A + 1:" << endl;
    C = A + 1;
    C.show();

    cout << "C = A - 1:" << endl;
    C = A - 1;
    C.show();

    return 0;
}
