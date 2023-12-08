using namespace Matrices;





/**
 * @brief Returns the Column reduced matrix of the matrix, aka a lower triangular.
 * Used to compute the Row reduction, the inverse of the matrix and to solve systems of equations.
*/
Matrix Matrix::ColumnReduced() {
    if (IsZero()) return *this;

    Matrix result = *this;
    int oldBest = -1;

    for (int col = 0; col < cols; col++) {
        // put the columns with the first non-zero value in the first (remaining) column

        int best = cols;

        for (int i = col; i < cols; i++) {
            int nonZero = result.mat[i].FirstNonZero();

            if (nonZero > oldBest && nonZero < best) {
                result.SwapCols(col, i);
                best = nonZero;
            }
        }

        oldBest = best;

        // now for each of the other columns substract the first column scaled to make the first value 0

        for (int i = col + 1; i < cols; i++) {
            if (result.mat[i][best] == 0) continue;

            Vector V = result.mat[col] * result.mat[i][best] / result.mat[col][best];
            result.mat[i] -= V;
        }
    }

    return result;
}





/**
 * @brief Returns the Row reduced matrix of the matrix, aka an upper triangular.
*/
Matrix Matrix::RowReduced() {return (*this).Transposed().ColumnReduced().Transposed();}





/**
 * @brief Reduces the matrix to a lower triangular matrix.
 * @note This function modifies the matrix object.
*/
void Matrix::ReduceToColEchelon() {*this = this->ColumnReduced();}





/**
 * @brief Reduces the matrix to an upper triangular matrix.
 * @note This function modifies the matrix object.
*/
void Matrix::ReduceToRowEchelon() {*this = this->RowReduced();}
