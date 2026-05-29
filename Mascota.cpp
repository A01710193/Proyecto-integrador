#include "Mascota.hpp"
// -------- Mascota --------

// Constructores y Destructor
Mascota::Mascota(){
    nombre = "";
    edad = 0;
    motivoConsulta = "";
    tipo = "";
    raza = "";
    cartillaVacunas = "";
    agresividad = false;
};

Mascota::Mascota(string nNombre, int nEdad, string nMotivoConsulta, string nTipo, string nRaza, string nCartillaVacunas, bool nAgresividad){
    nombre = nNombre;
    edad = nEdad;
    motivoConsulta = nMotivoConsulta;
    tipo = nTipo;
    raza = nRaza;
    cartillaVacunas = nCartillaVacunas;
    agresividad = nAgresividad;
}

Mascota::~Mascota(){};

// Setters
void Mascota::setNombre(string nNombre){
    nombre = nNombre;
};

void Mascota::setEdad(int nEdad){
    edad = nEdad;
};

void Mascota::setMotivoConsulta(string nMotivoConsulta){
    motivoConsulta = nMotivoConsulta;
};

void Mascota::setTipo(string nTipo){
    tipo = nTipo;
};

void Mascota::setRaza(string nRaza){
    raza = nRaza;
};

void Mascota::setCartillaVacunas(string nCartillaVacunas){
    cartillaVacunas = nCartillaVacunas;
};

void Mascota::setAgresividad(bool nAgresividad){
    agresividad = nAgresividad;
};

// Getters
string Mascota::GetNombre(){
    return nombre;
};

int Mascota::getEdad(){
    return edad;
};

string Mascota::getMotivoConsulta(){
    return motivoConsulta;
};

string Mascota::getTipo(){
    return tipo;
};

string Mascota::getRaza(){
    return raza;
};

string Mascota::getCartillaVacunas(){
    return cartillaVacunas;
};

bool Mascota::getAgresividad(){
    return agresividad;
};

// Métodos
int Mascota::tipoConsulta(){
    if (motivoConsulta == "Revisión") return 1;
    if (motivoConsulta == "Vacunación") return 2;
    if (motivoConsulta == "Grooming") return 3;
    if (motivoConsulta == "Emergencia") return 4;
    return 0;
};

string Mascota::registrarCartilla(){
    if (cartillaVacunas == ""){
        cout << "Registrando nueva cartilla de vacunas para " << nombre << endl;
        cartillaVacunas = "Cartilla de " + nombre + "\nNinguna vacuna registrada";
        cout << "\n" << cartillaVacunas << endl;
        return cartillaVacunas;
    }
    cout << "La cartilla a nombre de " << nombre << " ya está registrada :)" << endl;
    return cartillaVacunas;
};

void Mascota::agregarVacuna(string nuevaVacuna){
    if (cartillaVacunas == ""){
        cout << "Error: Primero debes de registrar la vacuna de: " << nombre << endl;
    }
    
    else{
        cartillaVacunas += "\n-" + nuevaVacuna;
        cout << "Vacuna " << nuevaVacuna << " ya fue agregada a la cartilla." << endl;
    }
};

// -------- Perro --------

// Constructores y destructor
Perro::Perro(){
    Mascota();
    tamaño = "";
};

Perro::Perro(string nTamaño){
    Mascota();
    tamaño = nTamaño;
};

Perro::~Perro(){};

// Setters
void Perro::setTamaño(string nTamaño){
    tamaño = nTamaño;
};

// Getters
string Perro::getTamaño(){
    return tamaño;
};

// Métodos
double Perro::dosisMedicamento(){
    if (tamaño == "Grande") return 19.7;
    if (tamaño == "Mediano") return 15.6;
    return 9.8;
};

void Perro::mostrarCuidados(){
    cout << "------ Cuidados para Perro -------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Raza: " << raza << endl;
    cout << "Tamaño: " << tamaño << endl;
    cout << "Requiere paseos diarios, una buena alimentación diaria y mucha agua." << endl;
    if (agresividad) cout << "Cuidado con el perro, es agresivo. Va a requerir usar un bozal para consultas" << endl;
};

// -------- Gato --------

// Constructores y destructor
Gato::Gato(){
    Mascota();
    actividadExterior = false;
};

Gato::Gato(bool nActividadExterior){
    Mascota();
    actividadExterior = nActividadExterior;
};

Gato::~Gato(){};

// Setters
void Gato::setActividadExterior(bool nActividadExterior){
    actividadExterior = nActividadExterior;
};

// Getters
bool Gato::getActividadExterior(){
    return actividadExterior;
};

// Métodos
string Gato::evaluarPrecauciones(){
    if (actividadExterior){
        return "Riesgo alto de infecciones y peleas, tendremos que revisar las heridas con precaución";
    }
    return "Riesgo bajo, sin tantas preocupaciones que revisar";
};

void Gato::mostrarCuidados(){
    cout << "------ Cuidados para Gato -------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Raza: " << raza << endl;
    cout << "¿Sale al exterior? " << (actividadExterior ? "Si" : "No") << endl;
    cout << "Requiere paseos diarios, una buena alimentación diaria y mucha agua." << endl;
    if (agresividad) cout << "Cuidado con el gato, es agresivo. Va a requerir utilizar una jaula para consultas" << endl;
}
