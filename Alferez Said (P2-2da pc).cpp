#include <iostream>
#include <string>

using namespace std;

struct Emp{   
	int codigo;
    string nombre;
    float talla;
    float peso;
    float sueldo;
};

int main() {
    int n;
    cout <<"Ingrese el número de empleados:"<<endl;
	cin>>n;
	
	Emp emp[n];
	// Ingresar los detalles de los empleados

    for(int i = 0; i < n; ++i) {
        cout << "Ingresar los datos de cada uno de los empleados " << i + 1 << endl;
        cout << "Código: "<<endl;
        cin >>emp[i].codigo;
        cout << "Nombre: "<<endl;
        cin.ignore();
        getline(cin, emp[i].nombre);
        cout << "Talla: "<<endl;
        cin >> emp[i].talla;
        cout << "Peso: "<<endl;
        cin >> emp[i].peso;
        cout << "Sueldo: "<<endl;
        cin >> emp[i].sueldo;
    }

    // Contar el total de empleados y los empleados con sueldo mayor a 1000
    int tEmp = n;
    int empsM100 = 0;

    for(int i = 0; i < n; ++i) {
        if(emp[i].sueldo > 1000) {
            empsM100++;
        }
    }

    // Mostrar los datos almacenados
    cout << "\nDatos almacenados:\n";
    for(int i = 0; i < n; ++i) {
        cout<< "Código: " << emp[i].codigo<<endl;
        cout<< "Nombre: " << emp[i].nombre<<endl;
        cout<< "Talla: " << emp[i].talla<<endl;
        cout<< "Peso: " << emp[i].peso<<endl;
        cout<< "Sueldo: " << emp[i].sueldo<< endl;
    }

    cout << "Total de empleados: " << tEmp << endl;
    cout << "Total de empleados con sueldo mayor a S/1000: " <<empsM100<<endl;

    // Ordenar los empleados por código de mayor a menor usando el método de burbuja
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(emp[j].codigo < emp[j + 1].codigo) {
                Emp temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }

    // Mostrar los datos ordenados
    cout << "\nDatos ordenados por código de mayor a menor:\n";
    for(int i = 0; i < n; ++i) {
        cout << "Código: " <<emp[i].codigo<<endl;
        cout << "Nombre: " <<emp[i].nombre<<endl;
        cout << "Talla: " <<emp[i].talla<<endl;
        cout << "Peso: " <<emp[i].peso<<endl;
        cout << "Sueldo: " <<emp[i].sueldo << endl;
    }

    return 0;
}
