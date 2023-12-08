using namespace Matrices;





// INDEXING

double Vector::operator[](int index) {return vec[index];}





// EQUAL OR DIFFERENT

bool Vector::operator==(const Vector &other) {
    for (int i = 0; i < size; i++) {
        if (vec[i] != other.vec[i]) return false;
    }

    return true;
}

bool Vector::operator!=(const Vector &other) {return !(*this == other);}





// ADDITION AND SUBTRACTION

Vector Vector::operator+(const Vector &other) {
    if (size != other.size) {
        warning << "The second vector could not be added." << std::endl;
        return *this;
    }

    double newVec[SIZEMAX];
    Vector result;

    for (int i = 0; i < size; i++) {
        newVec[i] = vec[i] + other.vec[i];
    }

    result.Set(size, newVec);

    return result;
}

Vector Vector::operator-() {return *this * -1;}
Vector Vector::operator-(Vector &other) {return operator+(-other);}

Vector Vector::operator+=(Vector &other) {return *this = this->operator+(other);}
Vector Vector::operator-=(Vector &other) {return *this = this->operator+(-other);}





// MULTIPLICATION AND DIVISION

Vector Vector::operator*(const double other) {
    double newVec[SIZEMAX];
    Vector result;

    for (int i = 0; i < size; i++) {
        newVec[i] = vec[i] * other;
    }

    result.Set(size, newVec);

    return result;
}

Vector operator*(double value, Vector &vect) {return vect.operator*(value);}

Vector Vector::operator/(const double other) {
    double newVec[SIZEMAX];
    Vector result;

    for (int i = 0; i < size; i++) {
        newVec[i] = vec[i] / other;
    }

    result.Set(size, newVec);

    return result;
}

Vector Vector::operator*=(const double other) {return *this = this->operator*(other);}
Vector Vector::operator/=(const double other) {return *this = this->operator/(other);}
