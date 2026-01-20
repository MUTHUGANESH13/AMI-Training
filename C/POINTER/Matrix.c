/*
*  Program to perform Matrix calculation by Pointers
*  Author   : MUTHUGANESH S
*  Date     : 16/01/2026
*  Filename : Matrix.c
*  retval   : void
*/

#include <stdio.h>
#include <stdlib.h>

void AddMatix(int *Mat1,int *Mat2,int *SumMat,int Rows,int Cols);
void MultiplyMatrix(int *Mat1,int *Mat2,int *MulMat,int Rows1,int Cols1,int Rows2,int Cols2);
int main(void){
    int RowSize1, ColSize1, RowSize2, ColSize2;
    
    printf("Enter First Matrix Details:\n");
    printf("Enter the number of rows: ");
    scanf("%d", &RowSize1);
    printf("Enter the number of columns: ");
    scanf("%d", &ColSize1);

    int *Matrix1=(int *)malloc(RowSize1*ColSize1*sizeof(int));

    if (Matrix1 == NULL){
        printf("Memory allocation failed\n");
        return 0;
    }

    printf("\nEnter the elements of the 1st matrix:\n");
    for(int i = 0; i < RowSize1; i++){
        for(int j = 0; j < ColSize1; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &Matrix1[i*ColSize1 + j]);
        }
    }

    printf("\nEnter Second Matrix Details:\n");
    printf("Enter the number of rows: ");
    scanf("%d", &RowSize2);
    printf("Enter the number of columns: ");
    scanf("%d", &ColSize2);

    int *Matrix2=(int *)malloc(RowSize2*ColSize2*sizeof(int));

    if (Matrix2 == NULL){
        printf("Memory allocation failed\n");
        free(Matrix1);
        return 0;
    }

    printf("\nEnter the elements of the 2nd matrix:\n");
    for(int i = 0; i < RowSize2; i++){
        for(int j = 0; j < ColSize2; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &Matrix2[i*ColSize2 + j]);
        }
    }

    if(RowSize1 != RowSize2 || ColSize1 != ColSize2){
        printf("Matrix addition not possible due to dimension mismatch.\n");
        free(Matrix1);
        free(Matrix2);
        return 0;
    }
    
    int *SumMatrix=(int *)calloc(RowSize1*ColSize1, sizeof(int));
    if (SumMatrix == NULL){
        printf("Memory allocation failed\n");
        free(Matrix1);
        free(Matrix2);
        return 0;
    }

    AddMatix(Matrix1, Matrix2, SumMatrix, RowSize1, ColSize1);

    printf("\nSum of the two matrices:\n");
    for(int i = 0; i < RowSize1; i++){
        for(int j = 0; j < ColSize1; j++){
            printf("%d ", SumMatrix[i*ColSize1 + j]);
        }
        printf("\n");
    }

    if(ColSize1 != RowSize2){
        printf("Matrix multiplication not possible due to dimension mismatch.\n");
        free(Matrix1);
        free(Matrix2);
        free(SumMatrix);
        return 0;
    }

    int *MulMatrix=(int *)calloc(RowSize1*ColSize2, sizeof(int));
    if (MulMatrix == NULL){
        printf("Memory allocation failed\n");
        free(Matrix1);
        free(Matrix2);
        free(SumMatrix);
        return 0;
    }

    MultiplyMatrix(Matrix1, Matrix2, MulMatrix, RowSize1, ColSize1, RowSize2, ColSize2);
    printf("\nProduct of the two matrices:\n");
    for(int i = 0; i < RowSize1; i++){
        for(int j = 0; j < ColSize2; j++){
            printf("%d ", MulMatrix[i*ColSize2 + j]);
        }
        printf("\n");
    }

    free(Matrix1);
    free(Matrix2);
    free(SumMatrix);
    free(MulMatrix);

    return 0;
}

// Function to add two matrices
void AddMatix(int *Mat1, int *Mat2, int *SumMat, int Rows, int Cols){
    for(int i = 0; i < Rows; i++){
        for(int j = 0; j < Cols; j++){
            SumMat[i*Cols + j] = Mat1[i*Cols + j] + Mat2[i*Cols + j];
        }
    }
}

// Function to multiply two matrices
void MultiplyMatrix(int *Mat1, int *Mat2, int *MulMat, int Rows1, int Cols1, int Rows2, int Cols2){
    for(int i = 0; i < Rows1; i++){
        for(int j = 0; j < Cols2; j++){
            MulMat[i*Cols2 + j] = 0;
            for(int k = 0; k < Cols1; k++){
                MulMat[i*Cols2 + j] += Mat1[i*Cols1 + k] * Mat2[k*Cols2 + j];
            }
        }
    }
}