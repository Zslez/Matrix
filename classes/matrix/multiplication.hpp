using namespace Matrices;





// ADVANCED ARITHMETIC

Matrix operator*(Vector &vect1, Vector &vect2) {
    // interprets the first vector as the column matrix and the second as the row matrix
    // and performs the rows by columns product

    Vector newMat[SIZEMAX];
    Matrix result;

    for (int i = 0; i < vect1.size; i++) {
        newMat[i] = vect1 * vect2.vec[i];
    }

    result.Set(vect1.size, vect2.size, newMat);

    return result;
}





Matrix operator*(Matrix &mat1, Matrix &mat2) {
    // performs the rows by columns product and returns the resulting Matrix

    if (mat1.cols != mat2.rows) {
        error << "Row by column multiplication cannot be calculated between "
              << mat1.rows << "x" << mat1.cols << " and " << mat2.rows << "x" << mat2.cols << " matrices.";
        exit(0);
    }

    Vector newMat[SIZEMAX];
    Matrix result;

    mat1 = mat1.Transposed();

    for (int i = 0; i < mat2.cols; i++) {
        double vec[SIZEMAX];

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





Vector operator*(Matrix &mat, Vector &vect) {
    // performs the rows by columns product and returns the resulting Vector

    if (mat.cols != vect.size) {
        error << "Row by column multiplication cannot be calculated between "
              << mat.rows << "x" << mat.cols << " and " << vect.size << "x1 matrices.";
        exit(0);
    }

    Matrix M;
    Vector V[1] = {vect};
    M.Set(vect.size, 1, V);

    return (mat * M).mat[0];
}
