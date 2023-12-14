using namespace Matrices;




/**
 * @brief Removes the specified column from the matrix and reduces its size by one.
 * @note This function modifies the Matrix object.
*/
void Matrix::RemoveColumn(int col) {
    for (int i = col + 1; i < cols; i++) {
        mat[i - 1].Set(rows, mat[i].vec);
    }

    cols--;
}





/**
 * @brief Computes the determinant of the matrix.
 * @note Returns an error exiting the program if the matrix is not square.
*/
double Matrix::Determinant() {
    if (rows != cols) {
        error << "The determinant can only be calculated for square matrices.";
        exit(0);
    }

    double result = 1;
    Matrix M = RowReduced();

    for (int i = 0; i < cols; i++) {result *= M[i][i];}

    return result;
}





/**
 * @brief Computes the determinant of the matrix without the given i row and j column.
 * Used to compute the Cofactor Matrix and the Inverse.
*/
double Matrix::DeterminantIJ(int i, int j) {
    Matrix M = *this;
    M.RemoveColumn(j);
    M.Transpose();
    M.RemoveColumn(i);
    return M.Transposed().Determinant();
}





/**
 * @brief Returns the Cofactor Matrix of the matrix.
 * @note Returns an error exiting the program if the matrix is not square.
*/
Matrix Matrix::CofactorMatrix() {
    if (rows != cols) {
        error << "The cofactor matrix can only be calculated for square matrices.";
        exit(0);
    }

    Vector newMat[NMAX];

    for (int i = 0; i < cols; i++) {
        double newVec[NMAX];

        for (int j = 0; j < rows; j++) {
            newVec[j] = (((i + j) % 2) ? -1 : 1) * DeterminantIJ(j, i);
        }

        newMat[i].Set(rows, newVec);
    }

    Matrix result;
    result.Set(rows, cols, newMat);

    return result;
}





/**
 * @brief Returns the inverse of the matrix.
 * @note Returns an error exiting the program if the matrix is not square or if it has zero Determinant.
*/
Matrix Matrix::Inverse() {
    if (rows != cols) {
        error << "The inverse can only be calculated for square matrices.";
        exit(0);
    }

    if (Determinant() == 0) {
        error << "The inverse can only be calculated for matrices with non-zero determinant.";
        exit(0);
    }

    return CofactorMatrix().Transposed() / Determinant();
}





/**
 * @brief Inverts the matrix.
 * @note This function modifies the Matrix object.
*/
void Matrix::Invert() {*this = this->Inverse();}
