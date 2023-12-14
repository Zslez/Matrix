using namespace Matrices;





/**
 * @brief Computes the Norm of the Vector.
*/
double Vector::Norm() {
    double result = 0;

    for (int i = 0; i < size; i++) {
        result += vec[i] * vec[i];
    }

    return sqrt(result);
}




/**
 * @brief Returns whether the matrix is all zeros or not.
*/
bool Vector::IsZero() {
    for (int i = 0; i < size; i++) {
        if (vec[i] != 0) return false;
    }

    return true;
}





/**
 * @brief Returns the index of the first non-zero value of the vector, or -1 if all values are zero.
*/
int Vector::FirstNonZero() {
    for (int i = 0; i < size; i++) {
        if (vec[i] != 0) return i;
    }

    return -1;
}





/**
 * @brief Rounds every entry of the Vector to the specified decimal precision.
 * @note This function modifies the Matrix object.
*/
void Vector::Round(int prec) {
    for (int i = 0; i < size; i++) {
        vec[i] = std::round(vec[i] * pow(10., prec)) / pow(10., prec);
    }
}
