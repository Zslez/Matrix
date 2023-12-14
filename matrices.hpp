namespace Matrices {
    namespace {
        // randomize as soon as the file is included

        auto a = []() {
            for (int i = 0; i < 10; i++) srand(uint16_t(rand() * time(NULL) + 100 * rand()));
            return 0;
        };

        int b = a();
    }

    const int NMAX = 50;
    const char *FORMAT = "% 12.9lf ";

    typedef double VEC[NMAX];
    typedef double MAT[NMAX][NMAX];

    class Vector;
    class Matrix;
    class Random;
    class RandomInt;
    class Identity;
    class Hilbert;
}


#include "classes/vector.hpp"
#include "classes/matrix.hpp"
