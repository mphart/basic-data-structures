/**
 * Matrix implementation in C
 * 
 * @author Mason Hart
*/


#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"


Matrix * newMatrix(unsigned int r, unsigned int c){
    Matrix *m = (Matrix*)malloc(sizeof(Matrix));
    // ensure memory allocation was successful
    if(m == NULL) {
        return NULL;
    }
    // ensure rows are unsigned ints & allocate memory
    m->rows = r < 0 ? 0 : r;
    m->cols = c < 0 ? 0 : c;
    m->numElements = r * c;
    m->data = (double*)malloc(m->numElements * sizeof(double));
    // ensure memory allocation was successful
    if(m->data == NULL){
        free(m);
        return NULL;
    }
    return m;
}

int freeMatrix(Matrix *m){
    if(m != NULL){ 
        free(m->data);
        free(m);
        return 1;
    }
    return 0;
}

double getAtIndexOfMatrix(Matrix *m, unsigned int r, unsigned int c){
    if(r < 0 || r >= m->rows || c < 0 || c >= m->cols){
        exit(1);   // index out of bounds
    } else {
        int linearIndex = r*m->cols + c;
        return(m->data[linearIndex]);
    }
}

double setAtIndexOfMatrix(Matrix *m, double e, unsigned int r, unsigned int c){
    if(r < 0 || r >= m->rows || c < 0 || c >= m->cols){
        exit(1);   // index out of bounds
    } else{
        double returnVal = getAtIndexOfMatrix(m, r, c);
        int linearIndex = r*m->cols + c;
        m->data[linearIndex] = e;
        return returnVal;
    }
}

Matrix * scaleMatrix(Matrix *m, double k){
    Matrix *n = newMatrix(m->rows, m->cols);
    for(int r = 0; r < n->rows; r++){
        for(int c = 0; c < n->cols; c++){
            setAtIndexOfMatrix(n, k*getAtIndexOfMatrix(m,r,c), r, c);
        }
    }
    return n;
}

Matrix * addMatrices(Matrix *m1, Matrix *m2){
    // ensure matrices have the same order
    if(m1->rows != m2->rows || m1->cols != m2->cols){
        return NULL;
    }
    // add the matrices
    Matrix *n = newMatrix(m1->rows, m1->cols);
    for(int r = 0; r < n->rows; r++){
        for(int c = 0; c < n->cols; c++){
            setAtIndexOfMatrix(n, getAtIndexOfMatrix(m1,r,c) + getAtIndexOfMatrix(m2,r,c), r, c);
        }
    }
    return n;
}

Matrix * multiplyMatrices(Matrix *m1, Matrix *m2){
    // ensure matrices can be multiplied
    if(m1->cols != m2->rows){
        return NULL;
    }
    // multiply the matrices
    Matrix *n = newMatrix(m1->rows, m2->cols);
    int termsPerElement = m1->cols; // = m2->rows
    for(int r = 0; r < n->rows; r++){
        for(int c = 0; c < n->cols; c++){
            double elementValue = 0;
            for(int k = 0; k < termsPerElement; k++){
                elementValue += getAtIndexOfMatrix(m1,r,k) * getAtIndexOfMatrix(m2,k,c);
            }
            setAtIndexOfMatrix(n,elementValue,r,c);
        }
    }
    return n;
}

double detOfMatrix(Matrix *m){
    // ensure the matrix is square of order >= 2
    if(m->rows != m->cols || m->rows < 2){
        exit(1);  // impossible to determine the determinant
    }
    double det = 0;
    // base case
    if(m->rows == 2 && m->cols == 2){
        det = getAtIndexOfMatrix(m,0,0) * getAtIndexOfMatrix(m,1,1);
        det -= getAtIndexOfMatrix(m,0,1) * getAtIndexOfMatrix(m,1,0);
        return det;
    }
    // recursive step
    for(int k = 0; k < m->cols; k++){
        // initialize the scalar and the submatrix
        int a = getAtIndexOfMatrix(m,0,k);
        Matrix *subMatrix = newMatrix(m->rows-1, m->cols-1);
        for(int r = 1; r < m->rows; r++){
            int c = 0;
            while(c < subMatrix->rows){
                double e = getAtIndexOfMatrix(m, r, (k+c+1)%m->cols);
                setAtIndexOfMatrix(subMatrix, e, r-1, c);
                c++;
            }
        }
        // make the recursive call to find the determinant of the submatrix
        det += a * detOfMatrix(subMatrix);
        freeMatrix(subMatrix);
    }
    return det;
}

Matrix * inverseMatrix(Matrix *m){
    if(detOfMatrix(m) == 0){
        return NULL; // impossible to find the inverse
    }
    // TODO
    return NULL;
}

Matrix * identityMatrix(unsigned int k){
    Matrix *m = newMatrix(k,k);
    if(m == NULL){
        free(m);
        return NULL;
    }
    for(int i = 0; i < k; i++){
        setAtIndexOfMatrix(m,1,i,i);
    }
    return m;
}

void printMatrix(Matrix *m){
    for(int r = 0; r < m->rows; r++){
        printf("| ");
        for(int c = 0; c < m->cols; c++){
            printf("%f ", getAtIndexOfMatrix(m,r,c));
        }
        printf("|\n");
    }
}