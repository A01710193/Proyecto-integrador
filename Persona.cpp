#include "Persona.hpp"

Persona::Persona() {
    nombre = "";
    edad = 0;
    telefono = "";
    correo = "";
    direccion = "";
}

Persona::Persona(string nNombre, int nEdad, string nTelefono, string nCorreo, string nDireccion) {
    nombre = nNombre;
    edad = nEdad;
    telefono = nTelefono;
    correo = nCorreo;
    direccion = nDireccion;
}

Persona::~Persona() {}

void Persona::setNombre(string nNombre) { nombre = nNombre; }
void Persona::setEdad(int nEdad) { edad = nEdad; }
void Persona::setTelefono(string nTelefono) { telefono = nTelefono; }
void Persona::setCorreo(string nCorreo) { correo = nCorreo; }
void Persona::setDireccion(string nDireccion) { direccion = nDireccion; }

string Persona::getNombre() { return nombre; }
int Persona::getEdad() { return edad; }
string Persona::getTelefono() { return telefono; }
string Persona::getCorreo() { return correo; }

Dueño::Dueño() : Persona() {}
Dueño::Dueño(vector<Mascota*> nMascotas) : Persona() { Mascotas = nMascotas; }
Dueño::~Dueño() {
    for (int i = 0; i < Mascotas.size(); i++) {
        delete Mascotas[i];
    }
    Mascotas.clear();
}

bool Dueño::agendarCita(vector<int> horas) { return true; }
void Dueño::pagar(int c) { cout << "El cliente " << nombre << " pagó $" << c << endl; }

void Dueño::mostrarMascotas() {
    if (Mascotas.empty()) {
        cout << "Este cliente no tiene mascotas registradas." << endl;
        return;
    }
    for (int i = 0; i < Mascotas.size(); i++) {
        Mascotas[i]->mostrarCuidados();
    }
}

void Dueño::agregarMascotas(Mascota* m) { Mascotas.push_back(m); }

bool Dueño::eliminarMascotas(string nMascota) {
    for (int i = 0; i < Mascotas.size(); i++) {
        if (Mascotas[i]->GetNombre() == nMascota) {
            delete Mascotas[i];
            Mascotas.erase(Mascotas.begin() + i);
            cout << "La mascota " << nMascota << " ha sido eliminada." << endl;
            return true;
        }
    }
    cout << "No se encontró la mascota " << nMascota << endl;
    return false;
}

void Dueño::vacunarMascota(string nMascota, string vacuna) {
    for (int i = 0; i < Mascotas.size(); i++) {
        if (Mascotas[i]->GetNombre() == nMascota) {
            Mascotas[i]->agregarVacuna(vacuna);
            cout << "Se aplicó la vacuna " << vacuna << " a " << nMascota << endl;
            return;
        }
    }
    cout << "Mascota no encontrada." << endl;
}

void Dueño::actualizarDatos(string T, string C) { telefono = T; correo = C; }
void Dueño::solicitarHistorial(Mascota* m) {
    if (m != nullptr) cout << "Historial: " << m->getCartillaVacunas() << endl;
}
void Dueño::mostrarDatosPersonales() {
    cout << "Cliente: " << nombre << " | Tel: " << telefono << " | Correo: " << correo << endl;
}

Veterinario::Veterinario() : Persona() { salario = 0.0; }
Veterinario::Veterinario(vector<int> h, vector<Dueño*> c, double s) : Persona() {
    Horarios = h;
    Clientes = c;
    salario = s;
}
Veterinario::~Veterinario() {}

void Veterinario::setSalario(double s) { salario = s; }
double Veterinario::getSalario() { return salario; }

void Veterinario::mostrarHorarios(vector<int> h) {
    cout << "Horarios disponibles para Dr/a " << nombre << ": ";
    for (int idx : Horarios) cout << idx << ":00 ";
    cout << endl;
}

void Veterinario::asignarCliente(Dueño* d) { Clientes.push_back(d); }
double Veterinario::clientesAtendidos() { return Clientes.size(); }

void Veterinario::recetarMedicina(Mascota* m, string medicina) {
    if (m != nullptr) cout << "Se receta " << medicina << " para " << m->GetNombre() << endl;
}
void Veterinario::registrarDiagnostico(Mascota* m, string diagnostico) {
    if (m != nullptr) cout << "Diagnóstico de " << nombre << " para " << m->GetNombre() << ": " << diagnostico << endl;
}

bool Veterinario::cancelarCita(int hora) {
    if (hora < 8 || hora > 20) {
        cout << "Error: la hora " << hora << ":00 no es un horario válido." << endl;
        return false;
    }
    for (int i = 0; i < Horarios.size(); i++) {
        if (Horarios[i] == hora) {
            cout << "La hora " << hora << ":00 ya estaba libre." << endl;
            return false;
        }
    }
    Horarios.push_back(hora);
    cout << "Cita de las " << hora << ":00 ha sido cancelada." << endl;
    return true;
}

void Veterinario::mostrarDatosPersonales() {
    cout << "Dr/a: " << nombre << " | Tel: " << telefono << " | Salario Base: $" << salario << endl;
}
