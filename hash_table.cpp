#include <iostream>
#include <list>
#include <string>

using namespace std;

// Definición de la tabla hash como un arreglo de listas enlazadas
const int TABLE_SIZE = 10;
list<pair<string, int>> hashTable[TABLE_SIZE];

// Función hash muy básica que utiliza el tamaño de la tabla
int hashFunction(const string& key) {
    return key.length() % TABLE_SIZE;
}

// Función para insertar un par clave-valor en la tabla hash
void insert(const string& key, int value) {
    int index = hashFunction(key);
    hashTable[index].push_back(make_pair(key, value));
}

// Función para buscar un valor por clave en la tabla hash
int search(const string& key) {
    int index = hashFunction(key);
    for (auto& pair : hashTable[index]) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    return -1; // Valor no encontrado
}

// Función para eliminar un par clave-valor de la tabla hash
void remove(const string& key) {
    int index = hashFunction(key);
    auto& bucket = hashTable[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->first == key) {
            bucket.erase(it);
            return;
        }
    }
}

// Función para imprimir la tabla hash
void printHashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "[" << i << "]: ";
        for (auto& pair : hashTable[i]) {
            cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    // Insertar algunos elementos en la tabla hash
    insert("apple", 5);
    insert("banana", 10);
    insert("orange", 15);

    // Imprimir la tabla hash después de la inserción
    cout << "Tabla hash después de la inserción:" << endl;
    printHashTable();

    // Buscar y mostrar valores
    cout << "Valor de 'apple': " << search("apple") << endl;
    cout << "Valor de 'banana': " << search("banana") << endl;
    cout << "Valor de 'orange': " << search("orange") << endl;
    cout << "Valor de 'grape': " << search("grape") << endl; // No existe

    // Eliminar un elemento y mostrar la tabla hash actualizada
    remove("banana");
    cout << "Tabla hash después de eliminar 'banana':" << endl;
    printHashTable();

    return 0;
}