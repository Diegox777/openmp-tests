#include <math.h>
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;
 
int main(int argc, char *argv[])
{
    clock_t t_ini, t_fin;
    double secs;


    int n;
    cout<<"introduce la precision del calculo (n > 0): ";
    cin>>n;
    t_ini = clock();
    double PI25DT = 3.141592653589793238462643;
    double h = 1.0 / (double) n;
    double sum = 0.0;
 
    for (int i = 1; i <= n; i++) {
        double x = h * ((double)i - 0.5);
        sum += (4.0 / (1.0 + x*x));
    }
 
    double pi = sum * h;
    cout << "El valor aproximado de PI es: " << pi << ", con un error de " << fabs(pi - PI25DT) << endl;

    t_fin = clock();

    secs = (double) (t_fin - t_ini) / CLOCKS_PER_SEC;
    printf("%.16g milisegundos\n", secs * 1000.0);

    return 0;
}