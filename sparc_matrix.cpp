#include <iostream>
#include <vector>

using namespace std;

// Definici�n de una estructura para elementos de matriz dispersa
struct SparseMatrixElement {
    int row;
    int col;
    int value;

    SparseMatrixElement(int r, int c, int v) : row(r), col(c), value(v) {}
};

// Definici�n de matriz dispersa como un vector de SparseMatrixElement
typedef vector<SparseMatrixElement> SparseMatrix;

// Funci�n para imprimir la matriz dispersa
void printSparseMatrix(const SparseMatrix& sparseMatrix) {
    for (size_t i = 0; i < sparseMatrix.size(); ++i) {
        const SparseMatrixElement& elem = sparseMatrix[i];
        cout << "(" << elem.row << ", " << elem.col << "): " << elem.value << endl;
    }
}

// Funci�n para insertar un elemento en la matriz dispersa
void insertElement(SparseMatrix& sparseMatrix, int row, int col, int value) {
    // Verificar si el elemento ya existe en la matriz dispersa
    for (size_t i = 0; i < sparseMatrix.size(); ++i) {
        if (sparseMatrix[i].row == row && sparseMatrix[i].col == col) {
            cout << "El elemento (" << row << ", " << col << ") ya existe en la matriz dispersa." << endl;
            return;
        }
    }

    // Insertar el nuevo elemento
    sparseMatrix.push_back(SparseMatrixElement(row, col, value));
}

// Funci�n para borrar un elemento de la matriz dispersa
void deleteElement(SparseMatrix& sparseMatrix, int row, int col) {
    // Buscar y eliminar el elemento
    for (size_t i = 0; i < sparseMatrix.size(); ++i) {
        if (sparseMatrix[i].row == row && sparseMatrix[i].col == col) {
            sparseMatrix.erase(sparseMatrix.begin() + i);
            cout << "Elemento (" << row << ", " << col << ") eliminado de la matriz dispersa." << endl;
            return;
        }
    }

    // Si el elemento no se encuentra
    cout << "El elemento (" << row << ", " << col << ") no existe en la matriz dispersa." << endl;
}

int main() {
    // Creaci�n de una matriz dispersa de ejemplo
    SparseMatrix sparseMatrix;

    // Inserci�n de elementos distintos de cero
    insertElement(sparseMatrix, 0, 1, 3);  // Elemento en la fila 0, columna 1 con valor 3
    insertElement(sparseMatrix, 1, 2, 7);  // Elemento en la fila 1, columna 2 con valor 7
    insertElement(sparseMatrix, 2, 0, 5);  // Elemento en la fila 2, columna 0 con valor 5

    // Impresi�n de la matriz dispersa despu�s de la inserci�n
    cout << "Matriz dispersa despu�s de la inserci�n:" << endl;
    printSparseMatrix(sparseMatrix);

    // Eliminar un elemento de la matriz dispersa
    deleteElement(sparseMatrix, 1, 2); // Eliminar el elemento en la fila 1, columna 2

    // Impresi�n de la matriz dispersa despu�s de la eliminaci�n
    cout << "Matriz dispersa despu�s de la eliminaci�n:" << endl;
    printSparseMatrix(sparseMatrix);

    return 0;
}
