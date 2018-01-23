#include <iostream>
#include <cstdio>

using namespace std;

long comp_fib_numbers(int n) {

  long fnm1, fnm2, fn;
  if ( n == 0 || n == 1 )
    return(1);
  fnm1 = comp_fib_numbers(n-1);
  fnm2 = comp_fib_numbers(n-2);

  fn = fnm1 + fnm2;
  return(fn);
}

int main() {
  double start, stop;

  int nthreads = 4;
  int n = 45;

  start = omp_get_wtime();
  long result = comp_fib_numbers(n);
  cout << result << endl;
  stop = omp_get_wtime();
  printf("\nTime: %g\n",stop-start);

  return 0;
}