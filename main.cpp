#include <iostream>
#include <cmath>
#include <array>

#include <cstdint> // for uint16_t type

#include "variables/constants.h"
#include "matrices.hpp"

#include <chrono>



void Test();



int main() {
    Test();
    return 0;

    double A[Matrices::NMAX][Matrices::NMAX] = {
        {-6, 5},
        {10, -2}
    };

    Matrices::Matrix M;
    M.SetFromColumnsArray(2, 2, A);
    //M.Print();
    Matrices::Matrix N = M.Inverse();
    //N.Print();

    Vector b;
    double b_arr[Matrices::NMAX] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    b.Set(7, b_arr);

    Matrices::Hilbert H(7);
    H.SolveAxb(b).Print();
    //(H * H_inv).Print("% 12.2lf ");
    //H_inv.CofactorMatrix().Print();

    //double c[Matrices::NMAX][Matrices::NMAX] = {{4323.53, -2425.39}, {-1124.82, 1986.01}};
    /*double c[Matrices::NMAX][Matrices::NMAX] = {{0.000339,0.000414},{0.000192,0.000738}};
    Matrices::Matrix C;
    C.SetFromRowsArray(2, 2, c);
    //C.Invert();

    Vector x = C.SolveAxb(b);
    std::cout << C.ToRowsString() << std::endl;
    std::cout << b.ToString() << std::endl;
    std::cout << x.ToString() << std::endl;*/

    return 0;
}



void Test() {
    int testCount = 1;
    int notPassed = 0;

    std::cout << "\n============= TESTS =============\n" << std::endl;


    // SPEED TEST

    auto s = std::chrono::system_clock::now();
    int num = 500;
    int size = 10;

    for (int i = 0; i < num; i++) {
        Matrices::Random R(size, size);
        R.Invert();
    }

    std::chrono::duration<double> elap = std::chrono::system_clock::now() - s;
    std::cout << "\rInverted " << num << " " << size << "x" << size << " Matrices in: " << elap.count() << "s\n" << std::endl;





    // VECTORS TESTS

    double vec1[5] = {0.5, 0.04, 0.003, 0.0002, 1};
    double vec2[5] = {1, 2, 4, 8, 16};
    double vec3[5] = {1, 2, 3, 4, 5};
    double vec4[5] = {2, 3, 5, 7, 11};

    Matrices::Vector U;
    Matrices::Vector V;
    Matrices::Vector W;
    Matrices::Vector X;

    U.Set(5, vec1);
    V.Set(5, vec2);
    W.Set(5, vec3);
    X.Set(5, vec4);

    // CHECKS

    if ((V + W).ToString() != "{2,4,7,12,21}") notPassed++;
    if ((-V + U - X).ToString() != "{-2.5,-4.96,-8.997,-14.9998,-26}") notPassed++;
    if (((V * W) * (U * X)).RowReduced().ToColsString() !=
        "{{11.1796,0,0,0,0},{16.7694,0,0,0,0},{27.949,0,0,0,0},{39.1286,0,0,0,0},{61.4878,0,0,0,0}}") notPassed++;
    if ((V * 2 - W - 2 * U).ToString() != "{0,1.92,4.994,11.9996,25}") notPassed++;

    // RESULT

    if (notPassed != 0) {
        notpassed << "Vectors" << std::endl;
    } else {
        passed << "Vectors" << std::endl;
    }

    notPassed = 0;





    // MATRICES TESTS

    Matrices::Vector mat1[2] = {V, W};
    Matrices::Vector mat2[2] = {V, W};

    Matrices::Matrix M1;
    Matrices::Matrix M2;

    M1.Set(5, 2, mat1);
    M2.Set(5, 2, mat2);

    // CHECKS

    if (M1.Transposed().ToColsString() != "{{1,1},{2,2},{4,3},{8,4},{16,5}}") notPassed++;

    if ((M2 * M1.Transposed()).ToColsString() !=
        "{{2,4,7,12,21},{4,8,14,24,42},{7,14,25,44,79},{12,24,44,80,148},{21,42,79,148,281}}") notPassed++;

    if (((M1 * 0.5) * (-M2).Transposed()).ToColsString() !=
        "{{-1,-2,-3.5,-6,-10.5},{-2,-4,-7,-12,-21},{-3.5,-7,-12.5,-22,-39.5},{-6,-12,-22,-40,-74},{-10.5,-21,-39.5,-74,-140.5}}")
        notPassed++;

    for (int i = 0; i < 100; i++) {
        size = 4;
        Matrices::Random R(size, size);

        Matrices::Matrix res = R * R.Inverse();
        res.Round(2);

        if (res != Matrices::Identity(size)) notPassed++;
    }

    // RESULT

    if (notPassed != 0) {
        notpassed << "Matrices" << std::endl;
    } else {
        passed << "Matrices" << std::endl;
    }

    notPassed = 0;





    // VECTOR AND MATRIX PRODUCT TESTS

    /*double vec3[5] = {1, 2, 3, 4, 5};

    Matrices::Vector U;
    U.Set(sizeof(vec3) / sizeof(vec3[0]), vec3);

    double vec4[2] = {1, 4};

    Matrices::Vector X;
    X.Set(sizeof(vec4) / sizeof(vec4[0]), vec4);
    X.Print();

    (M1 * X).Print();
    M1 = M1.Transposed();
    (M1 * M2).Print();*/
}
