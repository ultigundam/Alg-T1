#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inFile("entrada.in");
    ofstream outFile("salida.out");

    if (!inFile || !outFile) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    int n;
    inFile >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        inFile >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        outFile << arr[i] << " ";
    }
    outFile << endl;

    inFile.close();
    outFile.close();

    return 0;
}

