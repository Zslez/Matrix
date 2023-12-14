using namespace Matrices;





/**
 * @brief Returns the Vector X solution of the linear system `Ax = b`
*/
void Matrix::LU_Decomposition(Matrix &L, Matrix &U) {
    if (rows != cols || Determinant() == 0) {
        error << "LU decomposition can only be found for square invertible matrices";
        exit(0);
    }
}





/**
 * @brief Returns the Vector X solution of the linear system `Ax = b`
*/
Vector Matrix::SolveAxb(Vector b) {
    if (rows != cols || Determinant() == 0) {
        error << "A linear system can give a single numerical solution only for invertible square matrices.";
        exit(0);
    }

    Matrix Ainverse = Inverse();
    Vector x = Ainverse * b;

    return x;
}
