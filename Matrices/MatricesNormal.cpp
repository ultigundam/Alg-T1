#include <iostream>
#include <vector>
#include <chrono>
#include <fstream> // Para manejar archivos

using namespace std;
using namespace chrono;

void Multiplicar(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    ifstream inFile("matrices.in");  // Leer desde "matrices.in"
    ofstream outFile("resultado.out"); // Escribir en "resultado.out"

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    int n;
    inFile >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n));

    // Leer la matriz A desde el archivo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> A[i][j];
        }
    }

    // Leer la matriz B desde el archivo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> B[i][j];
        }
    }

    // Cerrar el archivo de entrada
    inFile.close();

    // Multiplicar matrices
    Multiplicar(A, B, C);

    // Escribir el resultado en el archivo de salida
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outFile << C[i][j] << " ";
        }
        outFile << endl;
    }

    // Cerrar el archivo de salida
    outFile.close();

    return 0;
}
