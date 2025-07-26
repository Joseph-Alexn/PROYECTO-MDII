#include <iostream>
using namespace std;

const int MAX_ZONAS = 11; // Máximo N es 10

void leerEntrada(int& N, int& M, int& T, int& P, int grados[], bool conexiones[][MAX_ZONAS]) {
    cin >> N >> M;
    cin >> T >> P;

    if (N < 2 || N > 10) {
        cout << "Error: N debe estar entre 2 y 10." << endl;
        return;
    }
    if (M < 1 || M > 20) {
        cout << "Error: M debe estar entre 1 y 20." << endl;
        return;
    }
    if (T < 1) {
        cout << "Error: T debe ser al menos 1." << endl;
        return;
    }
    if (P < 1) {
        cout << "Error: P debe ser al menos 1." << endl;
        return;
    }
    
    for (int i = 0; i < M; ++i) {
        int U, V;
        cin >> U >> V;

        if (U < 1 || V > N || U == V) {
            cout << "Error: Puentes deben conectar zonas válidas." << endl;
            return;
        }
        
        grados[U]++;
        grados[V]++;
        conexiones[U][V] = true;
        conexiones[V][U] = true;
    }
}


int contarVerticesImpares(int N, const int grados[]) {
    int impares = 0;
    for (int i = 1; i <= N; ++i) {
        if (grados[i] % 2 != 0) {  
            impares++;
        }
    }
    return impares;
}

void identificarZonasImpares(int N, const int grados[], int zonas_impares[], int& count) {
    count = 0;
    for (int i = 1; i <= N; ++i) {
        if (grados[i] % 2 != 0) {
            zonas_impares[count++] = i;
        }
    }
}

bool verificarConexiones(const bool conexiones[][MAX_ZONAS], const int zonas_impares[], int count) {
    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (conexiones[zonas_impares[i]][zonas_impares[j]]) {
                return true;
            }
        }
    }
    return false;
}

void resolverProblema(int N, int T, int P, const int grados[], const bool conexiones[][MAX_ZONAS]) {
    int impares = contarVerticesImpares(N, grados);
    
    // Caso 1: Ya es euleriano
    if (impares == 0) {
        cout << "No es necesario hacer cambios" << endl;
        return;
    }
    
    // Caso 2: Verificar si podemos modificarlo
    if (impares % 2 != 0) {
        cout << "Debo presentar mi renuncia" << endl;
        return;
    }
    
    int puentes_necesarios = impares / 2;
    int zonas_impares[MAX_ZONAS];
    int count;
    
    identificarZonasImpares(N, grados, zonas_impares, count);
    bool hay_conexion = verificarConexiones(conexiones, zonas_impares, count);
    bool es_posible = hay_conexion;
    
    // Verificar tiempo de construcción
    if (es_posible && (puentes_necesarios * P <= T)) {
        cout << "Es posible modificar la ciudad" << endl;
    } else {
        cout << "Debo presentar mi renuncia" << endl;
    }
}

int main() {
    int N, M, T, P;
    int grados[MAX_ZONAS] = {0};
    bool conexiones[MAX_ZONAS][MAX_ZONAS] = {false};
    
    leerEntrada(N, M, T, P, grados, conexiones);
    resolverProblema(N, T, P, grados, conexiones);
    
    return 0;
}