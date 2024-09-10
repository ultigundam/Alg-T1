#include <iostream>
#include <vector>
#include <fstream> // Para manejar archivos

using namespace std;

void TransponerMatriz(const vector<vector<int>>& B, vector<vector<int>>& B_T) {
    int n = B.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B_T[j][i] = B[i][j];
        }
    }
}

void Multiplicar(const vector<vector<int>>& A, const vector<vector<int>>& B_T, vector<vector<int>>& C) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }
}

int main() {
    ifstream inFile("matrices.in"); // Archivo de entrada
    ofstream outFile("resultado.out"); // Archivo de salida

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    int n;
    inFile >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> B_T(n, vector<int>(n));
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

    // Realizar la transposición y multiplicación de matrices
    TransponerMatriz(B, B_T);
    Multiplicar(A, B_T, C);

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
