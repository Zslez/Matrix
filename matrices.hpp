namespace Matrices {
    namespace {
        // randomize as soon as the file is included

        auto a = []() {
            for (int i = 0; i < 10; i++) srand(uint16_t(rand() * time(NULL) + 100 * rand()));
            return 0;
        };

        int b = a();
    }

    const int SIZEMAX = 50;
    const char *FORMAT = "% 9.2lf ";

    class Vector;
    class Matrix;
    class Random;
    class RandomInt;
    class Identity;
    class Hilbert;
}


#include "classes/vector.hpp"
#include "classes/matrix.hpp"
