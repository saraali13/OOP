/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <vector>

using namespace std;

// Base Matrix class template
template <typename T>
class Matrix 
{
protected:
    int rows;
    int cols;
    vector<vector<T> > matrix;

public:
    // Parameterized Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols), matrix(rows, vector<T>(cols)) 
	{}

    // Operator overloading for + operator
    Matrix<T> operator+(Matrix<T> other) 
	{
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) 
		{
            for (int j = 0; j < cols; ++j) 
			{
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    // Operator overloading for - operator
    Matrix<T> operator-(Matrix<T> other) 
	{
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) 
		{
            for (int j = 0; j < cols; ++j) 
			{
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    // Operator overloading for * operator
    template <typename U>
    Matrix<U> operator*(Matrix<U> other) 
    {
        Matrix<U> result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) 
            {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; ++k) 
                {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }

    // virtual Display function
    virtual void display() 
	{
        for (int i = 0; i < rows; ++i) 
		{
            for (int j = 0; j < cols; ++j) 
			{
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    T& operator()(int i, int j) 
    {
        return matrix[i][j];
    }
};

//Matrix class for integers matrix 
class IntMatrix : public Matrix<int> 
{
public:
    // Parameterized Constructor
    IntMatrix(int r, int c) : Matrix<int>(r, c) 
	{}

    // Conversion constructor
    IntMatrix(const Matrix<int>& other) : Matrix<int>(other) 
    {}

    // Overriding Display function for integers
    void display() 
	{
        Matrix<int>::display();
    }
};

//Matrix class for doubles matrix
class DoubleMatrix : public Matrix<double> 
{
public:
    // Parameterized Constructor
    DoubleMatrix(int r, int c) : Matrix<double>(r, c) 
    {}

    // Conversion constructor
    DoubleMatrix(const Matrix<double>& other) : Matrix<double>(other) 
    {}

    //Overriding Display function for doubles
    void display() 
    {
        Matrix<double>::display();
    }
};

int main() 
{
    cout<<"Name:S. Sara Ali\nID:23K-0070\n\n";

    //objects IntMatrix and DoubleMatrix
    IntMatrix intMat(2, 2);
    DoubleMatrix doubleMat(2, 2);

    // Initializing matrices
    intMat(0, 0) = 2; intMat(0, 1) = 3;
    intMat(1, 0) = 4; intMat(1, 1) = 5;
    doubleMat(0, 0) = 7.1; doubleMat(0, 1) = 6.2;
    doubleMat(1, 0) = 1.3; doubleMat(1, 1) = 8.4;

    // Displaying integer matrix
    cout << "IntMatrix:" << endl;
    intMat.display();
    cout << endl;

    // Displaying double matrix
    cout << "DoubleMatrix:" << endl;
    doubleMat.display();
    cout << endl;

    // Performing matrix operations for integers
    IntMatrix intResultAdd = intMat + intMat;
    IntMatrix intResultSub = intMat - intMat;
    IntMatrix intResultMul = intMat * intMat;

    // Performing matrix operations for doubles
    DoubleMatrix doubleResultAdd = doubleMat + doubleMat;
    DoubleMatrix doubleResultSub = doubleMat - doubleMat;
    DoubleMatrix doubleResultMul = doubleMat * doubleMat;

    // Display results for the operations applied to the matrices
    cout << "IntMatrix + IntMatrix:" << endl;
    intResultAdd.display();
    cout << endl;
    cout << "IntMatrix - IntMatrix:" << endl;
    intResultSub.display();
    cout << endl;
    cout << "IntMatrix * IntMatrix:" << endl;
    intResultMul.display();
    cout << endl;

    cout << "DoubleMatrix + DoubleMatrix:" << endl;
    doubleResultAdd.display();
    cout << endl;
    cout << "DoubleMatrix - DoubleMatrix:" << endl;
    doubleResultSub.display();
    cout << endl;
    cout << "DoubleMatrix * DoubleMatrix:" << endl;
    doubleResultMul.display();

    return 0;
}
