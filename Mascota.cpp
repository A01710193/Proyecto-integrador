#include "Mascota.hpp"

Mascota::Mascota() {
    nombre = "";
    edad = 0;
    motivoConsulta = "";
    tipo = "";
    raza = "";
    cartillaVacunas = "";
    agresividad = false;
}

Mascota::Mascota(string nNombre, int nEdad, string nMotivoConsulta, string nTipo, string nRaza, string nCartillaVacunas, bool nAgresividad) {
    nombre = nNombre;
    edad = nEdad;
    motivoConsulta = nMotivoConsulta;
    tipo = nTipo;
    raza = nRaza;
    cartillaVacunas = nCartillaVacunas;
    agresividad = nAgresividad;
}

Mascota::~Mascota() {}

void Mascota::setNombre(string nNombre) { nombre = nNombre; }
void Mascota::setEdad(int nEdad) { edad = nEdad; }
void Mascota::setMotivoConsulta(string nMotivoConsulta) { motivoConsulta = nMotivoConsulta; }
void Mascota::setTipo(string nTipo) { tipo = nTipo; }
void Mascota::setRaza(string nRaza) { raza = nRaza; }
void Mascota::setCartillaVacunas(string nCartillaVacunas) { cartillaVacunas = nCartillaVacunas; }
void Mascota::setAgresividad(bool nAgresividad) { agresividad = nAgresividad; }

string Mascota::GetNombre() { return nombre; }
int Mascota::getEdad() { return edad; }
string Mascota::getMotivoConsulta() { return motivoConsulta; }
string Mascota::getTipo() { return tipo; }
string Mascota::getRaza() { return raza; }
string Mascota::getCartillaVacunas() { return cartillaVacunas; }
bool Mascota::getAgresividad() { return agresividad; }

int Mascota::tipoConsulta() { return 1; }
string Mascota::registrarCartilla() { return cartillaVacunas; }

void Mascota::agregarVacuna(string nVacuna) {
    if (cartillaVacunas == "") {
        cartillaVacunas = nVacuna;
    } else {
        cartillaVacunas += ", " + nVacuna;
    }
}

Perro::Perro() : Mascota() { tamaño = ""; }
Perro::Perro(string nTamaño) : Mascota() { tamaño = nTamaño; }
Perro::~Perro() {}

void Perro::setTamaño(string nTamaño) { tamaño = nTamaño; }
string Perro::getTamaño() { return tamaño; }

void Perro::mostrarCuidados() {
    cout << "------ Cuidados para Perro -------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Raza: " << raza << endl;
    cout << "Tamaño: " << tamaño << endl;
    cout << "Vacunas: " << (cartillaVacunas == "" ? "Ninguna" : cartillaVacunas) << endl;
    cout << "Requiere paseos diarios, una buena alimentación diaria y mucha agua." << endl;
    if (agresividad) {
        cout << "Cuidado con el perro, es agresivo. Va a requerir usar un bozal para consultas" << endl;
    }
}

Gato::Gato() : Mascota() { actividadExterior = false; }
Gato::Gato(bool nActividadExterior) : Mascota() { actividadExterior = nActividadExterior; }
Gato::~Gato() {}

void Gato::setActividadExterior(bool nActividadExterior) { actividadExterior = nActividadExterior; }
bool Gato::getActividadExterior() { return actividadExterior; }

void Gato::mostrarCuidados() {
    cout << "------ Cuidados para Gato -------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Raza: " << raza << endl;
    cout << "¿Sale al exterior? " << (actividadExterior ? "Sí" : "No") << endl;
    cout << "Vacunas: " << (cartillaVacunas == "" ? "Ninguna" : cartillaVacunas) << endl;
    cout << "Requiere rascadores, caja de arena limpia y estimulación en interiores." << endl;
    if (agresividad) {
        cout << "Cuidado con el gato, es agresivo. Manejar con precaución durante la consulta." << endl;
    }
}
