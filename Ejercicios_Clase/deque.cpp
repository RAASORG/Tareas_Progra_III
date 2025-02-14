#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<char>     datos;

    // push_front() me permite agregar elementos al inicio de la lista
    datos.push_front('A'); // Lista: A
    datos.push_front('B'); // Lista: B, A
    datos.push_front('C'); // Lista: C, B, A
    // push_back() me permite agregar elementos al final de la lista
    datos.push_back(65);   // Lista: C, B, A, A  (65 es el valor ASCII de 'A')
    datos.push_back('Z');  // Lista: C, B, A, A, Z



    cout << "Deque elements: ";
    for (int elem :     datos) {
        cout << elem << " ";
    }
    cout << endl;

    // Remove elements from the front and back
    datos.pop_front();
    datos.pop_back();

    // Display the deque after removal
    cout << "Deque elements after removal: ";
    for (int elem :     datos) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}