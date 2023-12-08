/**
 * @brief The Vector class.
 * Through the method `Set()`, it builds a vector given an array of doubles.
 * @note Vectors are all interpreted as column vectors in `Matrix * Vector` multiplication.
*/
class Matrices::Vector {
    public:

    int size;
    double vec[SIZEMAX];



    // SETUP AND FORMAT FUNCTIONS

    void Set(int sizeOfVector, double values[SIZEMAX]);
    void Print();
    std::string ToString();



    // BASIC METHODS

    double Norm();
    bool IsZero();
    int FirstNonZero();



    // OPERATORS AND BASIC ARITHMETIC

    double operator[](int index);

    bool operator==(const Vector &other);
    bool operator!=(const Vector &other);

    Vector operator-();

    Vector operator+(const Vector &other);
    Vector operator-(Vector &other);
    Vector operator+=(Vector &other);
    Vector operator-=(Vector &other);

    Vector operator*(const double other);
    Vector operator/(const double other);
    Vector operator*=(const double other);
    Vector operator/=(const double other);
};





// INCLUDE FUNCTION DEFINITIONS

#include "vector/setup.hpp"
#include "vector/basic_methods.hpp"
#include "vector/operators.hpp"
