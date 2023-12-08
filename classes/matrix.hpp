/**
 * @brief The main Matrix class.
 * Builds a matrix given an array of vectors or an array of arrays of doubles.
 * @note Each vector or array of doubles is interpreted as a column vector.
*/
class Matrices::Matrix {
    public:

    int rows, cols;
    Vector mat[SIZEMAX];



    // SETUP AND FORMAT FUNCTIONS

    void Set(int rowsNumber, int colsNumber, Vector columns[]);
    void SetFromColumnsArray(int rowsNumber, int colsNumber, double columns[][SIZEMAX]);
    void Print(const char *format);

    std::string ToString();



    // BASIC METHODS

    Matrix Transposed();
    void Transpose();
    bool IsSymmetric();

    Matrix Merged(Matrix matrix);
    void Merge(Matrix matrix);

    bool IsColZero(int col);
    bool IsRowZero(int row);
    bool IsZero();

    void SwapCols(int col1, int col2);
    void SwapRows(int row1, int row2);



    // GAUSS ELIMINATION

    Matrix ColumnReduced();
    Matrix RowReduced();
    void ReduceToColEchelon();
    void ReduceToRowEchelon();



    // OPERATORS AND BASIC ARITHMETIC

    Vector operator[](int index);

    bool operator==(const Matrix &other);
    bool operator!=(const Matrix &other);

    Matrix operator-();

    Matrix operator+(const Matrix &other);
    Matrix operator-(Matrix &other);
    Matrix operator+=(Matrix &other);
    Matrix operator-=(Matrix &other);

    Matrix operator*(const double other);
    Matrix operator/(const double other);
    Matrix operator*=(const double other);
    Matrix operator/=(const double other);



    // INVERSE

    void RemoveColumn(int col);

    double Determinant();
    double DeterminantIJ(int i, int j);

    Matrix CofactorMatrix();
    Matrix Inverse();
    void Invert();
};








// INCLUDE FUNCTION DEFINITIONS

#include "matrix/setup.hpp"
#include "matrix/basic_methods.hpp"
#include "matrix/operators.hpp"
#include "matrix/gauss.hpp"
#include "matrix/inverse.hpp"








// ADVANCED ARITHMETIC

Matrices::Matrix operator*(Matrices::Vector &vect1, Matrices::Vector &vect2) {
    // interprets the first vector as the column matrix and the second as the row matrix
    // and performs the rows by columns product

    Matrices::Vector newMat[Matrices::SIZEMAX];
    Matrices::Matrix result;

    for (int i = 0; i < vect1.size; i++) {
        newMat[i] = vect1 * vect2.vec[i];
    }

    result.Set(vect1.size, vect2.size, newMat);

    return result;
}

Matrices::Matrix operator*(Matrices::Matrix &mat1, Matrices::Matrix &mat2) {
    // performs the rows by columns product and returns the resulting Matrix

    if (mat1.cols != mat2.rows) {
        error << "Row by column multiplication cannot be calculated between "
              << mat1.rows << "x" << mat1.cols << " and " << mat2.rows << "x" << mat2.cols << " matrices.";
        exit(0);
    }

    Matrices::Vector newMat[Matrices::SIZEMAX];
    Matrices::Matrix result;

    mat1 = mat1.Transposed();

    for (int i = 0; i < mat2.cols; i++) {
        double vec[Matrices::SIZEMAX];

        for (int j = 0; j < mat1.cols; j++) {
            double total = 0;

            for (int k = 0; k < mat1.rows; k++) {
                total += mat1.mat[j][k] * mat2.mat[i][k];
            }

            vec[j] = total;
        }

        newMat[i].Set(mat1.cols, vec);
    }

    result.Set(mat1.cols, mat2.cols, newMat);

    // transpose the first matrix back (as it changes since it's by reference)

    mat1 = mat1.Transposed();

    return result;
}

Matrices::Vector operator*(Matrices::Matrix &mat, Matrices::Vector &vect) {
    // performs the rows by columns product and returns the resulting Vector

    if (mat.cols != vect.size) {
        error << "Row by column multiplication cannot be calculated between "
              << mat.rows << "x" << mat.cols << " and " << vect.size << "x1 matrices.";
        exit(0);
    }

    Matrices::Matrix M;
    Matrices::Vector V[1] = {vect};
    M.Set(vect.size, 1, V);

    return (mat * M).mat[0];
}








// RANDOM MATRIX

/**
 * @brief Class inherited from `Matrices::Matrix`
 * that generates a matrix of random entries of the specified size in a given range (that defaults to 0-10).
*/
class Matrices::Random : public Matrices::Matrix {
    public:

    Random(int rowsNumber, int colsNumber, int rangeA = 0, int rangeB = 10) {
        rows = rowsNumber;
        cols = colsNumber;

        // error if size is too large or non positive

        if (rows <= 0 || rows > SIZEMAX || cols <= 0 || cols > SIZEMAX) {
            error << "The matrix rows and cols number have to be greater than 0 and less than " << SIZEMAX << ".";
            exit(0);
        }

        for (int i = 0; i < cols; i++) {
            double vec[SIZEMAX];

            for (int j = 0; j < rows; j++) {
                vec[j] = float(rangeA) + (float(rand()) / float(RAND_MAX)) * fabs(rangeB - rangeA);
            }

            mat[i].Set(rows, vec);
        }
    }
};

/**
 * @brief Class inherited from `Matrices::Matrix`
 * that generates a matrix of random integer entries of the specified size in a given range (that defaults to 0-10).
*/
class Matrices::RandomInt : public Matrices::Matrix {
    public:

    RandomInt(int rowsNumber, int colsNumber, int rangeA = 0, int rangeB = 10) {
        rows = rowsNumber;
        cols = colsNumber;

        // error if size is too large or non positive

        if (rows <= 0 || rows > SIZEMAX || cols <= 0 || cols > SIZEMAX) {
            error << "The matrix rows and cols number have to be greater than 0 and less than " << SIZEMAX << ".";
            exit(0);
        }

        for (int i = 0; i < cols; i++) {
            double vec[SIZEMAX];

            for (int j = 0; j < rows; j++) {
                vec[j] = rand() % (rangeB - rangeA) + rangeA;
            }

            mat[i].Set(rows, vec);
        }
    }
};








// IDENTITY MATRIX

/**
 * @brief Class inherited from `Matrices::Matrix` that generates a square identity matrix of the specified size.
*/
class Matrices::Identity : public Matrices::Matrix {
    public:

    Identity(int size) {
        rows = size;
        cols = size;

        // error if size is too large or non positive

        if (rows <= 0 || rows > SIZEMAX) {
            error << "The matrix size has to be greater than 0 and less than " << SIZEMAX << ".";
            exit(0);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == j) mat[i].vec[j] = 1;
                else mat[i].vec[j] = 0;
            }
        }
    }
};
