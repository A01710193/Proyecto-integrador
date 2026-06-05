#include "Persona.hpp"

// --------- PERSONA ---------

// Constructores y destructores
Persona::Persona(){
    nombre = "";
    edad = 0;
    telefono = "";
    correo = "";
    direccion = "";
};

Persona::Persona(string nNombre, int nEdad, string nTelefono, string nCorreo, string nDireccion){
    nombre = nNombre;
    edad = nEdad;
    telefono = nTelefono;
    correo = nCorreo;
    direccion = nDireccion;
};

Persona::~Persona(){};

// Setters
void Persona::setNombre(string nNombre){
    nombre = nNombre;
};

void Persona::setEdad(int nEdad){
    edad = nEdad;
};

void Persona::setTelefono(string nTelefono){
    telefono = nTelefono;
};

void Persona::setCorreo(string nCorreo){
    correo = nCorreo;
};

void Persona::setDireccion(string nDireccion){
    direccion = nDireccion;
};

// Getters
string Persona::getNombre(){
    return nombre;
};

int Persona::getEdad(){
    return edad;
};

string Persona::getTelefono(){
    return telefono;
};

string Persona::getCorreo(){
    return correo;
};

// --------- DUEÑO ---------

// Constructores y destructor
Dueño::Dueño() : Persona(){};

Dueño::Dueño(vector<Mascota*> nMascotas) : Persona(){
    Mascotas = nMascotas;
};

Dueño::~Dueño(){
    for(int i = 0; i < Mascotas.size(); i++){
        delete Mascotas[i];
    }
    Mascotas.clear();
};

// Métodos
bool Dueño::agendarCita(vector<int> horarios){
    if(!horarios.empty()){
        cout << "Su cita ha sido agendada a nombre de " << nombre << endl;
        return true;
    }
    return false;
};

void Dueño::pagar(int precio){
    cout << "Se ha realizado un pago de " << precio << " a nombre de: " << nombre << endl;
};

void Dueño::mostrarMascotas(){
    if (Mascotas.empty()){
        cout << "El cliente: " << nombre << " no tiene mascotas registradas." << endl;
    }
    
    for (int i = 0; i < Mascotas.size(); i++){
        Mascotas[i] -> mostrarCuidados();
        cout << endl;
    }
};

void Dueño::agregarMascotas(Mascota* m){
    if (m != nullptr){
        Mascotas.push_back(m);
        cout << "Nueva mascota " << m -> GetNombre() << " ha sido registrado al dueño " << nombre << "." << endl;
    }
};

bool Dueño::eliminarMascotas(string nNombre){
    for (int i = 0; i < Mascotas.size(); i++){
        if (Mascotas[i] -> GetNombre() == nNombre){
            delete Mascotas[i];
            
            Mascotas.erase(Mascotas.begin() + i);
            
            cout << "La mascota " << nNombre << " fue eliminada del sistema." << endl;
            return true;
        }
    }
    cout << "No se ha encontrado la mascota " << nNombre << " dentro del sistema." << endl;
    return false;
};

void Dueño::vacunarMascota(string nNombre, string nVacuna){
    for (int i = 0; i < Mascotas.size(); i++){
        if (Mascotas[i] -> GetNombre() == nNombre){
            Mascotas[i] -> agregarVacuna(nVacuna);
            cout << "La vacuna " << nVacuna << " ha sido registrada en la cartilla de " << nNombre << "." << endl;
            return;
        }
    }
    cout << "No se encontró a la mascota " << nNombre << "." << endl;
    
};

void Dueño::actualizarDatos(string nTelefono, string nCorreo){
    telefono = nTelefono;
    correo = nCorreo;
    cout << "Los datos de " << nombre << "han sido actualizados." << endl;
};

void Dueño::solicitarHistorial(Mascota* mascota){
    if (mascota != nullptr){
        cout << "Historial médico de: " << mascota -> GetNombre() << endl;
        cout << "Motivo de consulta actual: " << mascota -> getMotivoConsulta() << endl;
        cout << "Cartilla de vacunas: " << mascota -> getCartillaVacunas() << endl;
    }
};

void Dueño::mostrarDatosPersonales(){
    cout << "Cliente" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Teléfono: " << telefono << endl;
    cout << "Correo: " << correo << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Número de mascotas: " << Mascotas.size() << endl;
};

// --------- VETERINARIO ---------

// Constructores y destructor
Veterinario::Veterinario() : Persona(){
    salario = 0.0;
};

Veterinario::Veterinario(vector<int> nHorarios, vector<Dueño*> nClientes, double nSalario) : Persona(){
    Horarios = nHorarios;
    Clientes = nClientes;
    salario = nSalario;
};

Veterinario::~Veterinario(){};

// Setters
void Veterinario::setSalario(double nSalario){
    salario = nSalario;
};

// Getters
double Veterinario::getSalario(){
    return salario;
};

// Métodos
void Veterinario::mostrarHorarios(vector<int> nHorarios){
    cout << "Horarios disponibles del Dr/a: " << nombre << ": " << endl;
    for (int i = 0; i < nHorarios.size(); i++){
        cout << "[" << Horarios[i] << ":00 horas] " << endl;
    }
    cout << endl;
};

void Veterinario::asignarCliente(Dueño* d){
    if (d != nullptr){
        Clientes.push_back(d);
        cout << "Cliente " << d -> getNombre() << " asignado al Dr/a " << nombre << endl;
    }
};

double Veterinario::clientesAtendidos(){
    return Clientes.size();
};

vector<Dueño*> Veterinario::mostrarClientes(){
    if (Clientes.empty()){
        cout << "El Dr/a " << nombre << " no tiene clientes asignados actualmente." << endl;
    }
    
    else {
        cout << "Clientes del Dr/a " << nombre << ": " << endl;
        for (int i = 0; i < Clientes.size(); i++){
            cout << "- " << Clientes[i] -> getNombre() << endl;
        }
    }
    
    return Clientes;
};

void Veterinario::recetarMedicina(Mascota* m, string medicina){
    if (m != nullptr){
        cout << "Se receta " << medicina << " para la mascota " << m -> GetNombre() << endl;
    }
};

void Veterinario::registrarDiagnostico(Mascota* m, string diagnostico){
    if (m != nullptr){
        cout << "Diagnóstico del Dr/a " << nombre << " para " << m -> GetNombre() << ":" << endl;
        cout << "- " << diagnostico << endl;
    }
    
};

bool Veterinario::cancelarCita(int hora){
    if (hora < 8 || hora > 20){
        cout << "Error: la hora " << hora << ":00 no es un horario válido de la clínica." << endl;
        return false;
    }
    
    for (int i = 0; i < Horarios.size(); i++){
        if (Horarios[i] == hora){
            cout << "La hora " << hora << ":00 ya estaba libre. No había cita que cancelar." << endl;
            return false;
        }
    }
    
    Horarios.push_back(hora);
    
    cout << "Cita de las " << hora << ":00 ha sido cancelada con el Dr/a " << nombre << "." << endl;
    cout << "El horario de las " << hora << ":00 está disponbible ahora." << endl;
    
    return true;
};

void Veterinario::mostrarDatosPersonales(){
    cout << "Veterinario" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Teléfono: " << telefono << endl;
    cout << "Correo: " << correo << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Salario: " << salario << endl;
};
