#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    ifstream inputFile("input.in");
    ofstream outputFile("output.out");

    if (!inputFile || !outputFile) {
        cerr << "Error al abrir los archivos." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        inputFile >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        outputFile << arr[i] << " ";
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
