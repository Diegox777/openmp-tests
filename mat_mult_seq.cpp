#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

const int MAX_SIZE = 2005;

int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
int a_fila, a_col, b_fila, b_col;

int main() {

  clock_t ini, fin;
  double diff;

  int i, j, k;

  // Leemos las dimensiones de las matrices
  while (true) {
    printf("Ingrese el número de filas y columnas para la matriz A: ");
    cin >> a_fila >> a_col;
    printf("Ingrese el número de filas y columnas para la matriz B: ");
    cin >> b_fila >> b_col;
    if (a_col != b_fila) {
      printf("Intente otra vez\n");
      continue;
    }
    else break;
  }

  ini = clock();
  // Iniciamos la matriz A
  for (i = 0; i < a_fila; i++) {
    for (j = 0; j < a_col; j++) {
      A[i][j] = i + j; // llenamos la matriz A con la suma de los valores i y j
    }
  }
  // Iniciamos la matriz B
  for (i = 0; i < b_fila; i++) {
    for (j = 0; j < b_col; j++) {
      B[i][j] = i * j; // llenamos la matriz A con la mult de los valores i y j
    }
  }
  // Iniciamos la matriz C
  for (i = 0; i < a_fila; i++) {
    for (j = 0; j < b_col; j++) {
      C[i][j] = 0; 
    }
  }
  // Multiplicamos la matriz A con la matriz B 
  for (i = 0; i < a_fila; i++) {
    for (j = 0; j < a_col; j++) {
      for (k = 0; k < b_col; k++) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j]; // calculamos el resultado para cada celda
      }
    }
  }
  // Fin del proceso
  fin = clock();
  diff = (double)(fin - ini) / CLOCKS_PER_SEC;
  printf("Tiempo = %f\n", diff);
  return 0;
}