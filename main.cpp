#include <iostream>
using namespace std;
template <typename T>
T sumar(T a, T b) {
    return a + b;
}


class Base {
public:
    virtual ~Base() {};
    void mostrar() const {
        cout << "Soy un objeto de la clase base" << endl;
    }
};

class Derivada : public Base {
public:
    void mostrar() const {
        cout << "Soy un objeto de la clase Derivada" << endl;
    }
};

int main() {
    cout << "Sumar enteros: " << sumar(3, 4) << endl;
    cout << "Sumar dobles: " << sumar(3.5, 4.51) << endl;

    Base* base = new Base();
    base->mostrar();

    Derivada* ptrder = (Derivada*)base;
    Base* basePtr = new Derivada();
    ptrder->mostrar();

    //if (Derivada* derivadaPtr = dynamic_cast<Derivada*>(basePtr)) {
    if (Derivada* derivadaPtr = (Derivada*)(basePtr)) {

        derivadaPtr->mostrar();  // Safe cast; calls method of Derived class
    } else {
        cout << "No se pudo hacer dynamic_cast" << endl;
    }

    cout << basePtr << endl;
    delete basePtr;
    cout << basePtr << endl;




    return 0;
}


/*
Polimorfismo Ad-hoc:
Este concepto se discute ampliamente en el contexto de lenguajes de programaci�n y teor�a de tipos,
 y se refiere a la capacidad de un mismo nombre de funci�n u operador para operar sobre diferentes tipos.
  Puedes encontrar este concepto en libros como "Programming Language Pragmatics" de Michael L. Scott.

Polimorfismo Param�trico:
Este tipo de polimorfismo est� bien cubierto en la teor�a de tipos y lenguajes de programaci�n,
 especialmente en relaci�n con plantillas (templates) en C++.
 Un libro que lo discute es "Types and Programming Languages" de Benjamin C. Pierce.

Polimorfismo de Subtipo:
Este concepto est� muy relacionado con la herencia en la programaci�n orientada a objetos y es discutido
 en "Object-Oriented Software Construction" de Bertrand Meyer, donde se aborda el uso de clases derivadas
  para implementar polimorfismo.
*/
