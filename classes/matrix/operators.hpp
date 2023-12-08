using namespace Matrices;





// INDEXING

Vector Matrix::operator[](int index) {return mat[index];}





// EQUAL OR DIFFERENT

bool Matrix::operator==(const Matrix &other) {
    for (int i = 0; i < cols; i++) {
        if (mat[i] != other.mat[i]) return false;
    }

    return true;
}

bool Matrix::operator!=(const Matrix &other) {return !(*this == other);}





// ADDITION AND SUBTRACTION

Matrix Matrix::operator+(const Matrix &other) {
    if (rows != other.rows || cols != other.cols) {
        warning << "The second Matrix could not be added because of different size." << std::endl;
        return *this;
    }

    Vector sums[SIZEMAX];
    Matrix result;

    for (int i = 0; i < cols; i++) {
        sums[i] = mat[i] + other.mat[i];
    }

    result.Set(rows, cols, sums);

    return result;
}

Matrix Matrix::operator-() {return *this * -1;}
Matrix Matrix::operator-(Matrix &other) {return operator+(-other);}

Matrix Matrix::operator+=(Matrix &other) {return *this = this->operator+(other);}
Matrix Matrix::operator-=(Matrix &other) {return *this = this->operator+(-other);}





// MULTIPLICATION AND DIVISION

Matrix Matrix::operator*(const double other) {
    Vector newVec[SIZEMAX];
    Matrix result;

    for (int i = 0; i < cols; i++) {
        newVec[i] = mat[i] * other;
    }

    result.Set(rows, cols, newVec);

    return result;
}

Matrix operator*(double value, Matrix &matrix) {return matrix.operator*(value);}

Matrix Matrix::operator/(const double other) {
    Vector newVec[SIZEMAX];
    Matrix result;

    for (int i = 0; i < cols; i++) {
        newVec[i] = mat[i] / other;
    }

    result.Set(rows, cols, newVec);

    return result;
}

Matrix Matrix::operator*=(const double other) {return *this = this->operator*(other);}
Matrix Matrix::operator/=(const double other) {return *this = this->operator/(other);}
