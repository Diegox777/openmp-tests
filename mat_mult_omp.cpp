#include <iostream>
#include <cstdio>
#include <omp.h>

using namespace std;

const int MAX_SIZE = 2000;

int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
int a_fila, a_col, b_fila, b_col;

int main() {


  double diff;

  int n_hilos, hilo_id, pedazos = 10;
  int i, j, k;
  while (true) {
    printf("Ingrese el número de filas y columnas para la matriz A: ");
    cin >> a_fila >> a_col;
    printf("Ingrese el número de filas y columnas para la matriz B: ");
    cin >> b_fila >> b_col;
    if (a_col != b_col) {
      printf("Intente otra vez\n");
      continue;
    }
    else break;
  }
  double ini = omp_get_wtime();

  #pragma omp parallel shared(A, B, C, n_hilos, pedazos) private (hilo_id, i, j, k)
  {
    hilo_id = omp_get_thread_num();
    if (hilo_id == 0) {
      n_hilos = omp_get_num_threads();
      printf("Empezando la multiplicación de matrices con %d procesadores\n", n_hilos);
    }
    #pragma omp for schedule (static, pedazos)
    for (i = 0; i < a_fila; i++) {
      for (j = 0; j < a_col; j++) {
        A[i][j] = i + j;
      }
    }
    #pragma omp for schedule (static, pedazos)
    for (i = 0; i < b_fila; i++) {
      for (j = 0; j < b_col; j++) {
        B[i][j] = i * j;
      }
    }
    #pragma omp for schedule (static, pedazos)
    for (i = 0; i < a_fila; i++) {
      for (j = 0; j < b_col; j++) {
        C[i][j] = 0;
      }
    }
    #pragma omp for schedule (static, pedazos)
    for (i = 0; i < a_fila; i++) {
      for (j = 0; j < a_col; j++) {
        for (k = 0; k < b_col; k++) {
          C[i][j] = C[i][j] + A[i][k] * B[k][j];
        }
      }
    }
  } // end pragma

  double fin = omp_get_wtime();
  diff = ((double) (fin - ini));
  printf("Tiempo = %f\n", diff);
  return 0;
}