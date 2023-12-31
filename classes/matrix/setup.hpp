using namespace Matrices;





/**
 * @brief Builds the matrix from an array of Column Vectors.
*/
void Matrix::Set(int rowsNumber, int colsNumber, Vector columns[]) {
    rows = rowsNumber;
    cols = colsNumber;

    // error if size is too large or non positive

    if (rows <= 0 || rows > NMAX || cols <= 0 || cols > NMAX) {
        error << "The matrix rows and cols number have to be greater than 0 and less than " << NMAX << ".";
        exit(0);
    }

    for (int i = 0; i < cols; i++) {
        mat[i].Set(columns[i].size, columns[i].vec);
    }
}





/**
 * @brief Builds the matrix from an array of arrays of doubles interpreted as Column Vectors.
*/
void Matrix::SetFromColumnsArray(int rowsNumber, int colsNumber, double columns[][NMAX]) {
    rows = rowsNumber;
    cols = colsNumber;

    // error if size is too large or non positive

    if (rows <= 0 || rows > NMAX || cols <= 0 || cols > NMAX) {
        error << "The matrix rows and cols number have to be greater than 0 and less than " << NMAX << ".";
        exit(0);
    }

    for (int i = 0; i < cols; i++) {
        Vector V;
        V.Set(rows, columns[i]);
        mat[i].Set(V.size, V.vec);
    }
}





/**
 * @brief Builds the matrix from an array of arrays of doubles interpreted as Row Vectors.
*/
void Matrix::SetFromRowsArray(int rowsNumber, int colsNumber, double rows[][NMAX]) {
    SetFromColumnsArray(rowsNumber, colsNumber, rows);
    Transpose();
}





/**
 * @brief Pretty prints the matrix.
*/
void Matrix::Print(const char *format = FORMAT) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf(format, mat[j][i]);
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}




/**
 * @brief Converts the Matrix to a string.
 * Useful if one need to copy the Matrix, formatted, to export it.
*/
std::string Matrix::ToColsString() {
    std::string result = "{" + mat[0].ToString();

    for (int i = 1; i < cols; i++) {result += "," + mat[i].ToString();}

    return result + "}";
}




/**
 * @brief Converts the Matrix to a string.
 * Useful if one need to copy the Matrix, formatted, to export it.
*/
std::string Matrix::ToRowsString() {
    Transpose();

    std::string result = "{" + mat[0].ToString();

    for (int i = 1; i < cols; i++) {result += "," + mat[i].ToString();}

    Transpose();

    return result + "}";
}
