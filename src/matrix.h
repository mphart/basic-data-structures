/**
 * @file matrix.h
 *
 * @brief Nonresizable matrix
 * 
 * @author Mason Hart
 *
 * A Matrix is a table of doubles with n rows and m columns,
 * where n and m are unsigned integers. Here, matrices will be
 * represented internally as a single array of doubles.
 */

#ifndef MATRIX_H
#define MATRIX_H


/**
 *  Internal definition of matrix
 */
typedef struct {
    double* data;
    unsigned int rows;
    unsigned int cols; 
    unsigned int numElements;
} Matrix;

/**
 *  Create a new matrix
 *  @param  row row order of the matrix
 *  @param  col column order of the matrix
 *  @return  a pointer to matrix of order (ROW, COL), or NULL if allocation failed
 */
Matrix * newMatrix(unsigned int row, unsigned int col);

/**
 *  Free the allocated memory of a matrix
 *  @param  m pointer to the matrix to be freed
 */
int freeMatrix(Matrix *m);

/**
 *  Get the value at some index of a matrix
 *  @param  m reference matrix
 *  @param  row row index
 *  @param  col column index
 *  @return  the double value of (ROW, COL) in matrix M
 */
double getAtIndexOfMatrix(Matrix *m, unsigned int row, unsigned int col);

/**
 *  Set the value at some index of a matrix
 *  @param  m reference matrix
 *  @param  row row index
 *  @param  col column index
 *  @param  element the double to be set
 *  @return  the replaced element of M at (ROW, COL)
 */
double setAtIndexOfMatrix(Matrix *m, double element, unsigned int row, unsigned int col);

/**
 *  Scale the matrix by a constant factor
 *  @param  m reference matrix
 *  @param  k scalar value
 *  @return  a pointer to a new matrix
 */
Matrix * scaleMatrix(Matrix *m, double k);

/**
 *  Add two matrices
 *  @param  m1 left hand matrix
 *  @param  m2 right hand matrix
 *  @return  a pointer to a new matrix
 */
Matrix * addMatrices(Matrix *m1, Matrix *m2);

/**
 *  Multiply two matrices
 *  @param  m1 left hand matrix
 *  @param  m2 right hand matrix
 *  @return  a pointer to a new matrix
 */
Matrix * multiplyMatrices(Matrix *m1, Matrix *m2);

/**
 *  Finds the determinant of the matrix
 *  @param  m reference matrix
 *  @return  the determinant of M
 */
double detOfMatrix(Matrix *m);

/**
 *  Invert a matrix
 *  @param  m matrix to invert
 *  @return  the inverse of m, or NULL if the inverse doesn't exist
 */
Matrix * inverseMatrix(Matrix *m);

/**
 *  Get the identity matrix of specified size
 *  @param  k the size of the square matrix
 *  @return  the identity matrix of order (K, K)
 */
Matrix * identityMatrix(unsigned int k);

/**
 *  Prints the matrix
 *  @param  m matrix to print
 */
void printMatrix(Matrix *m);



#endif 