#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

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

    selectionSort(arr);

    for (int i = 0; i < n; i++) {
        outFile << arr[i] << " ";
    }
    outFile << endl;

    inFile.close();
    outFile.close();

    return 0;
}
