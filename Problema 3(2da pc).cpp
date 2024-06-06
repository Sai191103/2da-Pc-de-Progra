#include <iostream>
#include <vector>

using namespace std;

struct Empleado {
    string nombre;
    char tipo; // 'C' para contratado, 'N' para nombrado
    float sBasico;
    float dAFP;
    float dSeguro;
    float boni;
    float sNeto;
};

void calDeYBo(Empleado &emp) {
    emp.dAFP = emp.sBasico * 0.08;
    emp.dSeguro = emp.sBasico * 0.05;

    if (emp.tipo == 'C') {
        emp.boni = emp.sBasico * 0.08;
    } else if (emp.tipo == 'N') {
        emp.boni = emp.sBasico * 0.12;
    }

    emp.sNeto = emp.sBasico - emp.dAFP - emp.dSeguro + emp.boni;
}

int main() {
    int n;
    cout << "Ingrese el número de empleados: "<<endl;
    cin >> n;

    vector<Empleado> empleados(n);

    for (int i = 0; i < n; ++i) {
        cout << "Ingresar los datos del empleado " << i + 1 << endl;
        cout << "Nombre: "<<endl;
        cin.ignore();
        getline(cin, empleados[i].nombre);
        cout << "Tipo de empleado (C-contratado, N-nombrado): "<<endl;
        cin >> empleados[i].tipo;
        cout << "Sueldo básico: "<<endl;
        cin >> empleados[i].sBasico;

        calDeYBo(empleados[i]);
    }

    int tCon = 0, tNom = 0;
    float aCon = 0, aNom = 0;

    cout << "\nDetalles de los empleados: "<<endl;
    for (const auto &emp : empleados) {
        cout << "Nombre: " << emp.nombre << endl;
        cout << "Tipo de empleado: " << (emp.tipo == 'C' ? "Contratado" : "Nombrado") << endl;
        cout << "Sueldo básico: " << emp.sBasico << endl;
        cout << "Deducción AFP: " << emp.dAFP << endl;
        cout << "Deducción seguro: " << emp.dSeguro << endl;
        cout << "Bonificación: " << emp.boni << endl;
        cout << "Sueldo neto: " << emp.sNeto << endl;

        if (emp.tipo == 'C') {
            tCon++;
            aCon += emp.sNeto;
        } else if (emp.tipo == 'N') {
            tNom++;
            aNom+= emp.sNeto;
        }
    }

    cout << "Resumen consolidado: "<<endl;
    cout << "Total de empleados contratados: " << tCon << endl;
    cout << "Total acumulado de sueldos netos (contratados): " << aCon << endl;
    cout << "Total de empleados nombrados: " << tNom << endl;
    cout << "Total acumulado de sueldos netos (nombrados): " << aNom << endl;

    return 0;
}
