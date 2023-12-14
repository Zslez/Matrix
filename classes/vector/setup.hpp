using namespace Matrices;





/**
 * @brief Builds the Vector from an array of double.
*/
void Vector::Set(int sizeOfVector, double values[NMAX]) {
    size = sizeOfVector;

    // error if size is too large or non positive

    if (size <= 0 || size > NMAX) {
        error << "The vector size has to be greater than 0 and less than " << NMAX << ".";
        exit(0);
    }

    for (int i = 0; i < size; i++) {
        vec[i] = values[i];
    }
}





/**
 * @brief Pretty prints the Vector.
*/
void Vector::Print() {
    for (int i = 0; i < size; i++) {
        printf(FORMAT, vec[i]);
        std::cout << std::endl;
    }

    std::cout << std::endl;
}





/**
 * @brief Converts the Vector to a string.
 * Useful if one need to copy the Vector, formatted, to export it.
*/
std::string Vector::ToString() {
    std::string result = "{" + std::to_string(vec[0]);

    // remove trailing 0s and the . if the number is floating point and it ends in them

    if (result.find('.') != std::string::npos) {
        while (result[result.size() - 1] == '0') result.pop_back();
        if (result[result.size() - 1] == '.') result.pop_back();
    }

    for (int i = 1; i < size; i++) {
        result +=  "," + std::to_string(vec[i]);

        // remove trailing 0s and the . if the number is floating point and it ends in them

        if (result.find('.') != std::string::npos) {
            while (result[result.size() - 1] == '0') result.pop_back();
            if (result[result.size() - 1] == '.') result.pop_back();
        }
    }

    return result + "}";
}
