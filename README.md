# Matrix CPP

## English

Created to put together all the stuff from the Programming and Linear Algebra Courses of my first semester of University as a Math student, using also my knowledge of OOP and previous programming experience, this program has the following features and capabilities so far:

- Vectors
    1) create Column Vectors
        - starting from an array of doubles

    2) perform operations on a Vector
        - check if it is 0
        - compute its norm
        - conversion of the Vector to String

    3) perform operations between Vectors
        - sum and difference of two Vectors
        - product of a Vector by a scalar and vice versa
        - division of a Vector by a scalar
        - row by columns product between two Vectors (the first is the Column Vector and the second the Row Vector)
        - check whether two Vectors are equal

- Matrices
    1) create Matrices
        - starting from an array of Column Vectors
        - starting from an array of array of doubles interpreted as Column Vectors
        - starting from an array of array of doubles interpreted as Row Vectors
        - with random double entries
        - with random integer entries
        - square identity
        - Hilbert Matrix

    2) perform operations on a Matrix
        - check whether a row or a column is 0
        - check whether it is all 0
        - check whether it is symmetrical
        - conversion of the Matrix to String (by rows or columns)
        - swap two rows or two columns
        - remove a row or a column
        - reduce to Row or Column Echelon
        - compute the Transposed Matrix
        - compute the Determinant
        - compute the Determinant without a row or a column
        - compute the Cofactor Matrix
        - compute the Inverse

    3) perform operations between Matrices
        - check whether two Matrices are equal
        - sum and difference of two Matrices
        - product of a Matrix by a scalar and vice versa
        - division of a Matrix by a scalar
        - row by columns product between two Matrices and between a Matrix and a Column Vector
        - merge two Matrices, even of different sizes

- Linear Systems
    1) solve a linear system
        - `Ax = b`, where `A` is a square invertible Matrix and `b` any given Vector (solution gets a bit inaccurate for very small entries of the Matrix)

## Italian

Creato per mettere insieme tutta la roba fatta nei corsi di LPC e Algebra Lineare del primo semestre di Università a Matematica, insieme alle mie conoscenze di OOP e precedente esperienza con la programmazione, questo programma è capace finora di:

- Vettori
    1) creare Vettori Colonna
        - a partire da un array di double

    2) svolgere operazioni su un Vettore
        - controllare se è nullo
        - calcolarne la norma

    3) svolgere operazioni tra Vettori
        - somma e differenza di due Vettori
        - prodotto di un Vettore per uno scalare e viceversa
        - divisione di un Vettore per uno scalare
        - prodotto righe per colonne tra due Vettori (il primo è il Vettore Colonna e il secondo il Vettore Riga)
        - conversione del Vettore in Stringa
        - controlla se due Vettori sono uguali

- Matrici
    1) creare Matrici
        - a partire da un array di Vettori Colonna
        - a partire da un array di array di double interpretati come Vettori Colonna
        - a partire da un array di array di double interpretati come Vettori Riga
        - con entrate double casuali
        - con entrate intere casuali
        - quadrate identità
        - Matrice di Hilbert

    2) svolgere operazioni su una Matrice
        - controllare se una colonna o una riga è nulla
        - controllare se è tutta nulla
        - controllare se è simmetrica
        - conversione della Matrice in Stringa (per righe o per colonne)
        - scambiarne due righe o due colonne tra loro
        - rimuoverne una riga o una colonna
        - ridurla a scala per righe o a scala per colonne
        - calcolarne la Trasposta
        - calcolarne il Determinante
        - calcolarne il Determinante tolta una riga o una colonna
        - calcolarne la Matrice dei Cofattori
        - calcolarne l'Inversa

    3) svolgere operazioni tra Matrici
        - controllare se due Matrici sono uguali
        - somma e differenza di due Matrici
        - prodotto di una Matrice per uno scalare e viceversa
        - divisione di una Matrice per uno scalare
        - prodotto righe per colonne tra due Matrici e tra una Matrice e un Vettore Colonna
        - unione di due Matrici, anche di dimensioni diverse

- Sistemi Lineari
    1) risolvere sistemi lineari
        - `Ax = b`, dove `A` è una Matrice quadrata invertibile e `b` un Vettore dato (la soluzione è leggermente imprecisa per entrate molto piccole della Matrice)
