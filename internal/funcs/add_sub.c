#include "../../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL) return FAILURE;
  if ((A->rows != B->rows) || (A->columns != B->columns)) return FAILURE;
  int flag = 1;
  for (int i = 0; i < A->rows && flag; i++)
    for (int j = 0; j < A->columns && flag; j++)
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EXP) flag = 0;
  return flag ? SUCCESS : FAILURE;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) return INCORRECT_MATRIX;
  if ((A->rows != B->rows) || (A->columns != B->columns)) return CALC_ERROR;
  int flag = s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows && !flag; i++)
    for (int j = 0; j < A->columns && !flag; j++)
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL) return INCORRECT_MATRIX;
  if ((A->rows != B->rows) || (A->columns != B->columns)) return CALC_ERROR;
  int flag = s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows && !flag; i++)
    for (int j = 0; j < A->columns && !flag; j++)
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  return flag;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL) return INCORRECT_MATRIX;
  int flag = s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows && !flag; i++)
    for (int j = 0; j < A->columns && !flag; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  return flag;
}