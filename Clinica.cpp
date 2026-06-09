#include "Clinica.hpp"

Clinica::Clinica() {}
Clinica::Clinica(vector<Veterinario*> nVeterinarios, vector<Dueño*> nDueños) {
    Veterinarios = nVeterinarios;
    Dueños = nDueños;
}

Clinica::~Clinica() {
    for (int i = 0; i < Veterinarios.size(); i++) delete Veterinarios[i];
    Veterinarios.clear();
    for (int i = 0; i < Dueños.size(); i++) delete Dueños[i];
    Dueños.clear();
}

double Clinica::calcularSalario(Veterinario* v) {
    if (v == nullptr) return 0.0;
    return v->getSalario();
}

double Clinica::calcularBono(Veterinario* v, double bonoPorCliente) {
    if (v == nullptr) return 0.0;
    int cantidadClientes = v->clientesAtendidos();
    double bonoTotal = cantidadClientes * bonoPorCliente;
    cout << "El Dr/a " << v->getNombre() << " tiene un bono total de $" << bonoTotal << endl;
    return bonoTotal;
}

vector<Veterinario*> Clinica::mostrarVeterinarios() {
    for (int i = 0; i < Veterinarios.size(); i++) Veterinarios[i]->mostrarDatosPersonales();
    return Veterinarios;
}

void Clinica::agregarCliente(string Nombre, int Edad, string Telefono, string Correo, string Direccion) {
    Dueño* nuevo = new Dueño();
    nuevo->setNombre(Nombre); nuevo->setEdad(Edad); nuevo->setTelefono(Telefono);
    nuevo->setCorreo(Correo); nuevo->setDireccion(Direccion);
    Dueños.push_back(nuevo);
    cout << "Cliente " << Nombre << " agregado con éxito." << endl;
}

void Clinica::agregarVeterinario(string Nombre, int Edad, string Telefono, string Correo, string Direccion, double Salario) {
    vector<int> h = {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    Veterinario* nuevo = new Veterinario(h, vector<Dueño*>(), Salario);
    nuevo->setNombre(Nombre); nuevo->setEdad(Edad); nuevo->setTelefono(Telefono);
    nuevo->setCorreo(Correo); nuevo->setDireccion(Direccion);
    Veterinarios.push_back(nuevo);
    cout << "Veterinario Dr/a " << Nombre << " agregado con éxito." << endl;
}

bool Clinica::eliminarCliente(string nTelefono) {
    for (int i = 0; i < Dueños.size(); i++) {
        if (Dueños[i]->getTelefono() == nTelefono) {
            delete Dueños[i];
            Dueños.erase(Dueños.begin() + i);
            cout << "Cliente eliminado del sistema." << endl;
            return true;
        }
    }
    return false;
}

bool Clinica::eliminarVeterinario(string nNombre) {
    for (int i = 0; i < Veterinarios.size(); i++) {
        if (Veterinarios[i]->getNombre() == nNombre) {
            delete Veterinarios[i];
            Veterinarios.erase(Veterinarios.begin() + i);
            cout << "Veterinario eliminado del sistema." << endl;
            return true;
        }
    }
    return false;
}

Dueño* Clinica::buscarDueño(string nTelefono) {
    for (int i = 0; i < Dueños.size(); i++) {
        if (Dueños[i]->getTelefono() == nTelefono) {
            return Dueños[i];
        }
    }
    return nullptr;
}

Veterinario* Clinica::buscarVeterinario(string nNombre) {
    for (int i = 0; i < Veterinarios.size(); i++) {
        if (Veterinarios[i]->getNombre() == nNombre) return Veterinarios[i];
    }
    return nullptr;
}
