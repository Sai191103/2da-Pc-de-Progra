#include <iostream>
using namespace std;

int main() {
    int matriz[3][3], x, y;

    // Entrada de datos
    for (x = 0; x <= 2; x++)
        for (y = 0; y <= 2; y++) {
            cout << "Introduzca elemento en fila " << x + 1 << ", columna " << y + 1 << ": ";
            cin >> matriz[x][y];
        }

    // Mostrar matriz original
    cout << "\nMatriz original:\n";
    for (x = 0; x <= 2; x++) {
        for (y = 0; y <= 2; y++)
            cout << "\t" << matriz[x][y];
        cout << "\n";
    }

    // Modificar matriz (ceros en diagonal)
    cout << "\nMatriz modificada (ceros en diagonal):\n";
    for (x = 0; x <= 2; x++)
        for (y = 0; y <= 2; y++)
            if (x == y)
                matriz[x][y] = 0;

    // Mostrar matriz modificada
    for (x = 0; x <= 2; x++) {
        for (y = 0; y <= 2; y++)
            cout << "\t" << matriz[x][y];
        cout << "\n";
    }

    return 0;
}
