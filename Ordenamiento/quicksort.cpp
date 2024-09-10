#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
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

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        outFile << arr[i] << " ";
    }
    outFile << endl;

    inFile.close();
    outFile.close();

    return 0;
}
