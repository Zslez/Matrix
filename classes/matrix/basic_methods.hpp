using namespace Matrices;





/**
 * @brief Returns the transposed of the given matrix.
*/
Matrix Matrix::Transposed() {
    Vector newMat[NMAX];

    for (int i = 0; i < rows; i++) {
        double newVec[NMAX];

        for (int j = 0; j < cols; j++) {
            newVec[j] = mat[j][i];
        }

        newMat[i].Set(cols, newVec);
    }

    Matrix result;
    result.Set(cols, rows, newMat);

    return result;
}





/**
 * @brief Transposes the matrix.
 * @note This function modifies the Matrix object.
*/
void Matrix::Transpose() {*this = this->Transposed();}





/**
 * @brief Returns whether the matrix is symmetric or not.
*/
bool Matrix::IsSymmetric() {return Transposed() == *this;}





/**
 * @brief Returns a new matrix that is the matrix merged with the given matrix.
*/
Matrix Matrix::Merged(Matrix matrix) {
    if (matrix.rows != rows) {
        warning << "Matrices have a different number of rows. Empty coordinates are being left as they are (probably 0).\n";
    }

    Matrix result = *this;

    for (int i = 0; i < matrix.cols; i++) {
        result.mat[i + result.cols] = matrix.mat[i];
    }

    result.cols += matrix.cols;

    return result;
}





/**
 * @brief Merges the matrix with the given matrix.
 * @note This function modifies the Matrix object.
*/
void Matrix::Merge(Matrix matrix) {*this = this->Merged(matrix);}





/**
 * @brief Returns whether the given column of the matrix is all zero or not.
*/
bool Matrix::IsColZero(int col) {return mat[col].IsZero();}





/**
 * @brief Returns whether the given row of the matrix is all zero or not.
*/
bool Matrix::IsRowZero(int row) {return this->Transposed()[row].IsZero();}





/**
 * @brief Returns whether the given column of the matrix is all zero or not.
*/
bool Matrix::IsZero() {
    for (int i = 0; i < cols; i++) {
        if (!mat[i].IsZero()) return false;
    }

    return true;
}





/**
 * @brief Swaps the given columns of the matrix.
 * @note This function modifies the Matrix object.
*/
void Matrix::SwapCols(int col1, int col2) {
    Vector temp = mat[col1];
    mat[col1] = mat[col2];
    mat[col2] = temp;
}





/**
 * @brief Swaps the given rows of the matrix.
 * @note This function modifies the Matrix object.
*/
void Matrix::SwapRows(int row1, int row2) {
    Transpose();
    SwapCols(row1, row2);
    Transpose();
}





/**
 * @brief Rounds every entry of the Matrix to the specified decimal precision.
 * @note This function modifies the Matrix object.
*/
void Matrix::Round(int prec) {
    for (int i = 0; i < cols; i++) {
        mat[i].Round(prec);
    }
}
