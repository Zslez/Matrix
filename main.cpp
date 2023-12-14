#include <iostream>
#include <cmath>
#include <array>

#include <cstdint> // for uint16_t type

#include "variables/constants.h"
#include "matrices.hpp"

#include <chrono>



int main() {
    double A[Matrices::SIZEMAX][Matrices::SIZEMAX] = {
        {-6, 5},
        {10, -2}
    };

    Matrices::Matrix M;
    M.SetFromColumnsArray(2, 2, A);
    //M.Print();
    Matrices::Matrix N = M.Inverse();
    //N.Print();

    Vector b;
    double b_arr[Matrices::SIZEMAX] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    b.Set(7, b_arr);

    Matrices::Hilbert H(7);
    H.SolveAxb(b).Print();
    //(H * H_inv).Print("% 12.2lf ");
    //H_inv.CofactorMatrix().Print();

    //double c[Matrices::SIZEMAX][Matrices::SIZEMAX] = {{4323.53, -2425.39}, {-1124.82, 1986.01}};
    /*double c[Matrices::SIZEMAX][Matrices::SIZEMAX] = {{0.000339,0.000414},{0.000192,0.000738}};
    Matrices::Matrix C;
    C.SetFromRowsArray(2, 2, c);
    //C.Invert();

    Vector x = C.SolveAxb(b);
    std::cout << C.ToRowsString() << std::endl;
    std::cout << b.ToString() << std::endl;
    std::cout << x.ToString() << std::endl;*/










    // SPEED TEST

    /*auto s = std::chrono::system_clock::now();

    for (int i = 0; i < 10000; i++) {
        Matrices::Random R(2, 2);
        R.Invert();
        std::cout << "\r" << i;
    }

    std::chrono::duration<double> elapsed = std::chrono::system_clock::now() - s;

    std::cout << "\r" << elapsed.count() << "        " << std::endl;*/


    // VECTORS TESTS

    //double vec1[5] = {1, 2, 3, -4, 0.5};
    //double vec2[5] = {0.2, 4, -1./3, 2./100, 7};
    /*double vec1[5] = {1, 2, 3, 4, 5};
    double vec2[5] = {5, 4, 3, 2, 1};

    Matrices::Vector V;
    V.Set(sizeof(vec1) / sizeof(vec1[0]), vec1);

    Matrices::Vector W;
    W.Set(sizeof(vec2) / sizeof(vec2[0]), vec2);



    // MATRICES TESTS

    Matrices::Vector mat1[2] = {V, W};
    Matrices::Matrix M1;
    M1.Set(5, 2, mat1);
    M1.Transposed().Print();

    Matrices::Vector mat2[2] = {V, W};
    Matrices::Matrix M2;
    M2.Set(5, 2, mat2);
    //M2.Print();



    // VECTOR AND MATRIX PRODUCT TESTS

    double vec3[5] = {1, 2, 3, 4, 5};

    Matrices::Vector U;
    U.Set(sizeof(vec3) / sizeof(vec3[0]), vec3);

    double vec4[2] = {1, 4};

    Matrices::Vector X;
    X.Set(sizeof(vec4) / sizeof(vec4[0]), vec4);
    X.Print();

    (M1 * X).Print();
    M1 = M1.Transposed();
    (M1 * M2).Print();*/

    return 0;
}
