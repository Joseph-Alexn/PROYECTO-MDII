#include <iostream>
using namespace std;

void leerEntrada(int &N, int &M, int &T, int &P, int grados[], bool conexiones[][11])
{
    cin >> N >> M;
    cin >> T >> P;

    if (N < 2 || N > 10)
    {
        cout << "Error: N debe estar entre 2 y 10." << endl;
        exit(1);
    }
    if (M < 1 || M > 20)
    {
        cout << "Error: M debe estar entre 1 y 20." << endl;
        exit(1);
    }
    if (T < 1)
    {
        cout << "Error: T debe ser al menos 1." << endl;
        exit(1);
    }
    if (P < 1)
    {
        cout << "Error: P debe ser al menos 1." << endl;
        exit(1);
    }

    for (int i = 0; i < M; ++i)
    {
        int U, V;
        cin >> U >> V;

        if (U < 1 || U > N || V < 1 || V > N || U == V)
        {
            cout << "Error: Puentes deben conectar zonas válidas." << endl;
            exit(1);
        }

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

void resolverProblema(int N, int T, int P, const int grados[])
{
    int impares = contarVerticesImpares(N, grados);

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

    if (puentes_necesarios * P <= T)
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
    int N, M, T, P;
    int grados[11] = {0};              // Tamaño fijo 11 (para índices 1-10)
    bool conexiones[11][11] = {false}; // Matriz 11x11

    leerEntrada(N, M, T, P, grados, conexiones);
    resolverProblema(N, T, P, grados);

    return 0;
}