#include <iostream>


void countSort(int* mas, int n) {
    int y[10];
    int c[10];
    int m = mas[0];
    int M = mas[1];

    for (int i = 0; i < n; i++) {
        if (mas[i] > M)
            M = mas[i];
    }
    for (int i = 0; i < n; i++) {
        if (mas[i] < m)
            m = mas[i];
    }

    for(int i = m; i < M; i++) c[i] = 0;

    for(int j = 0; j < n; j++){
        int k = mas[j];
        c[k] = c[k]+1;
    }
    for(int i = m+1; i<M; i++){
        c[i] += c[i-1];
    }
    for(int j = 0; j < n; j++){
        int k = mas[j];
        y[c[k-1]] = mas[j];
        c[k]--;
    }
    for(int j = 0; j < n; j++) mas[j] = y[j];
}


int main() {
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(array) / sizeof(array[0]);
    countSort(array, n);

    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}