#include <iostream>
using namespace std;

const int MAX_ZONAS = 11; // Máximo N es 10

int main() {
    int N, M;
    cin >> N >> M;
    
    int T, P;
    cin >> T >> P;
    
    int degrees[MAX_ZONAS] = {0};
    bool adj[MAX_ZONAS][MAX_ZONAS] = {false};
    
    // Leer puentes y construir grafo
    for (int i = 0; i < M; ++i) {
        int U, V;
        cin >> U >> V;
        degrees[U]++;
        degrees[V]++;
        adj[U][V] = adj[V][U] = true;
    }
    
    // Contar vértices con grado impar
    int impares = 0;
    for (int i = 1; i <= N; ++i) {
        if (degrees[i] % 2 != 0) impares++;
    }
    
    // Caso 1: Ya es euleriano
    if (impares == 0) {
        cout << "No es necesario hacer cambios" << endl;
        return 0;
    }
    
    // Caso 2: Verificar si podemos modificarlo
    if (impares % 2 != 0) { // Nunca se puede con número impar de vértices impares
        cout << "Debo presentar mi renuncia" << endl;
        return 0;
    }
    
    int puentes_necesarios = impares / 2;
    
    // Verificar si hay suficientes conexiones existentes para los nuevos puentes
    bool es_posible = true;
    int zonas_impares[MAX_ZONAS];
    int count = 0;
    
    // Identificar zonas impares
    for (int i = 1; i <= N; ++i) {
        if (degrees[i] % 2 != 0) {
            zonas_impares[count++] = i;
        }
    }
    
    // Verificar que al menos un par de zonas impares esté conectado
    bool hay_conexion = false;
    for (int i = 0; i < count; ++i) {
        for (int j = i+1; j < count; ++j) {
            if (adj[zonas_impares[i]][zonas_impares[j]]) {
                hay_conexion = true;
                break;
            }
        }
        if (hay_conexion) break;
    }
    
    if (!hay_conexion) {
        es_posible = false;
    }
    
    // Verificar tiempo de construcción
    if (es_posible && puentes_necesarios * P <= T) {
        cout << "Es posible modificar la ciudad" << endl;
    } else {
        cout << "Debo presentar mi renuncia" << endl;
    }
    
    return 0;
}