#include "matrix.h"
#include <stdio.h>
#include <assert.h>


int main(){

    /** BEGIN TEST */

    Matrix *mptr1 = newMatrix(2,2);
    setAtIndexOfMatrix(mptr1,1,0,0);
    setAtIndexOfMatrix(mptr1,2,0,1);
    setAtIndexOfMatrix(mptr1,3,1,0);
    setAtIndexOfMatrix(mptr1,4,1,1);

    Matrix *mptr2 = newMatrix(2,2);
    setAtIndexOfMatrix(mptr2,5,0,0);
    setAtIndexOfMatrix(mptr2,6,0,1);
    setAtIndexOfMatrix(mptr2,7,1,0);
    setAtIndexOfMatrix(mptr2,8,1,1);

    printf("Initial Matrices\n");
    printMatrix(mptr1);
    printf("\n");
    printMatrix(mptr2);
    printf("\n");

    printf("Add Matrices\n");
    Matrix *addptr = addMatrices(mptr1, mptr2);
    printMatrix(addptr);
    printf("\n");

    printf("Scale Matrix 1\n");
    Matrix *scaledptr = scaleMatrix(mptr1, 5.3);
    printMatrix(scaledptr);
    printf("\n");

    printf("Multiply Matrices\n");
    Matrix *multptr = multiplyMatrices(mptr1, mptr2);
    printMatrix(multptr);
    printf("\n");

    printf("Find the determinant\n");
    Matrix *detptr = newMatrix(3,3);
    double elements[9] = {1,2,-1,3,0,1,-5,4,2};
    for(int i = 0; i < 9; i++){
        setAtIndexOfMatrix(detptr, elements[i], i/3, i%3);
    }
    printMatrix(detptr);
    printf("Determinant: %f\n\n", detOfMatrix(detptr));

    printf("Identity Matrix of size 5\n");
    Matrix *idptr = identityMatrix(5);
    printMatrix(idptr);
    printf("\n");
    

    /** END OF TEST */

    freeMatrix(mptr1);
    freeMatrix(mptr2);
    freeMatrix(scaledptr);
    freeMatrix(addptr);
    freeMatrix(multptr);
    freeMatrix(detptr);
    freeMatrix(idptr);
    mptr1 = NULL;
    mptr2 = NULL;
    scaledptr = NULL;
    addptr = NULL;

    return 0;
}