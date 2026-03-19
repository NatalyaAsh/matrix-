#include "../../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || result == NULL) return INCORRECT_MATRIX;
  int flag = s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows && !flag; i++)
    for (int j = 0; j < A->columns && !flag; j++)
      result->matrix[i][j] = A->matrix[i][j] * number;
  return flag;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALC_ERROR;
  int flag = s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows && !flag; i++)
    for (int j = 0; j < B->columns && !flag; j++) {
      double sum = 0;
      for (int k = 0; k < A->columns && !flag; k++)
        sum += A->matrix[i][k] * B->matrix[k][j];
      result->matrix[i][j] = sum;
    }
  return flag;
}
