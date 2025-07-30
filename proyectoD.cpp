#include <iostream>
using namespace std;

void leerEntrada(int &vertices, int &aristas, int &tiempoLimite, int &tiempoArista, int grados[], bool conexiones[][11])
{
    cin >> vertices >> aristas;
    cin >> tiempoLimite >> tiempoArista;

    for (int i = 0; i < aristas; ++i)
    {
        int U, V;
        cin >> U >> V;

        grados[U]++;
        grados[V]++;
        conexiones[U][V] = true;
        conexiones[V][U] = true;
    }
}

int contarVerticesImpares(int N, const int grados[])
{
    int impares = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (grados[i] % 2 != 0)
        {
            impares++;
        }
    }
    return impares;
}

void resolverProblema(int vertices, int tiempoLimite, int tiempoArista, const int grados[])
{
    int impares = contarVerticesImpares(vertices, grados);

    if (impares == 0)
    {
        cout << "No es necesario hacer cambios" << endl;
        return;
    }

    if (impares % 2 != 0)
    {
        cout << "Debo presentar mi renuncia" << endl;
        return;
    }

    int puentes_necesarios = impares / 2;

    if (puentes_necesarios * tiempoArista <= tiempoLimite)
    {
        cout << "Es posible modificar la ciudad" << endl;
    }
    else
    {
        cout << "Debo presentar mi renuncia" << endl;
    }
}

int main()
{
    int vertices, aristas, tiempoLimite, tiempoArista;
    int grados[11] = {0};
    bool conexiones[11][11] = {false};

    leerEntrada(vertices, aristas, tiempoLimite, tiempoArista, grados, conexiones);
    resolverProblema(vertices, tiempoLimite, tiempoArista, grados);

    return 0;
}