using namespace Matrices;





/**
 * @brief Returns the Vector X solution of the linear system `Ax = b`
*/
Vector Matrix::SolveAxb(Vector b) {
    if (rows != cols || Determinant() == 0) {
        error << "A linear system can give numerical solutions only for invertible square matrices.";
        exit(0);
    }

    Matrix Ainverse = Inverse();

    return Ainverse * b;
}
