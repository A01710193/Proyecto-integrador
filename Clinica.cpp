#include "Clinica.hpp"

// Constructores y destructor
Clinica::Clinica(){};
Clinica::Clinica(vector<Veterinario*> nVeterinarios, vector<Dueño*> nDueños){
    Veterinarios = nVeterinarios;
    Dueños = nDueños;
};

Clinica::~Clinica(){
    for (int i = 0; i < Veterinarios.size(); i++){
        delete Veterinarios[i];
    }
    Veterinarios.clear();
    
    for (int i = 0; i < Dueños.size(); i++){
        delete Dueños[i];
    }
    Dueños.clear();
    
};

// Métodos
double Clinica::calcularSalario(Veterinario* v){
    if (v == nullptr){
        cout << "Error: el veterinario que ingresó no es válido" << endl;
        return 0.0;
    }
    
    return v -> getSalario();
};

double Clinica::calcularBono(Veterinario* v, double bonoPorCliente){
    if (v == nullptr){
        cout << "Error: el veterinario que ingresó no es válido" << endl;
        return 0.0;
    }
    
    int cantidadClientes = v -> clientesAtendidos();
    double bonoTotal = cantidadClientes * bonoPorCliente;
    
    cout << "El Dr/a " << v -> getNombre() << " ha atendido a " << cantidadClientes << " clientes, por lo que se le otorgó un bono de $" << bonoTotal << endl;
    return bonoTotal;
};

vector<Veterinario*> Clinica::mostrarVeterinarios(){
    if (Veterinarios.empty()){
        cout << "No hay veterinarios registrados en la clínica." << endl;
    }
    
    cout << "----- Lista de veterinarios -----\n" << endl;
    for (int i = 0; i < Veterinarios.size(); i++){
        Veterinarios[i] -> mostrarDatosPersonales();
        cout << "---- Fin de la lista ----\n" << endl;
    }
    return Veterinarios;
};

void Clinica::agregarCliente(string nNombre, int nEdad, string nTelefono, string nCorreo, string nDireccion){
    Dueño* d = new Dueño();
    d -> setNombre(nNombre);
    d -> setEdad(nEdad);
    d -> setTelefono(nTelefono);
    d -> setCorreo(nCorreo);
    d -> setDireccion(nDireccion);
    
    Dueños.push_back(d);
    cout << "El cliente " << nNombre << " ha sido registrado con éxito." << endl;
};


void Clinica::agregarVeterinario(string nNombre, int nEdad, string nTelefono, string nCorreo, string nDireccion, double nSalario){
    Veterinario* v = new Veterinario();
    v -> setNombre(nNombre);
    v -> setEdad(nEdad);
    v -> setTelefono(nTelefono);
    v -> setCorreo(nCorreo);
    v -> setDireccion(nDireccion);
    v -> setSalario(nSalario);
    
    Veterinarios.push_back(v);
    cout << "El Dr/a " << nNombre << " ha sido registrado con éxito." << endl;
};

bool Clinica::eliminarCliente(string nNombre, string nTelefono, string nCorreo){
    for (int i = 0; i < Dueños.size(); i++){
        if (Dueños[i] -> getNombre() == nNombre && Dueños[i] -> getTelefono() == nTelefono && Dueños[i] -> getCorreo() == nCorreo){
            delete Dueños[i];

            Dueños.erase(Dueños.begin() + i);
            cout << "El cliente " << nNombre << " ha sido eliminado del sistema." << endl;
            return true;
        }
    }
    
    cout << "No se ha podido encontrar el cliente " << nNombre << " en el sistema." << endl;
    return false;
};

bool Clinica::eliminarVeterinario(string nNombre){
    for (int i = 0; i < Veterinarios.size(); i++){
        if (Veterinarios[i] -> getNombre() == nNombre){
            delete Veterinarios[i];
            
            Veterinarios.erase(Veterinarios.begin() + i);
            cout << "El Dr/a " << nNombre << " ha sido eliminado del sistema." << endl;
            return true;
        }
    }
    
    cout << "No se ha podido encontrar el/la Dr/a " << nNombre << " en el sistema." << endl;
    return false;
};


Dueño* Clinica::buscarDueño(string nNombre, string nTelefono, string nCorreo){
    for (int i = 0; i < Dueños.size(); i++){
        if (Dueños[i] -> getNombre() == nNombre && Dueños[i] -> getTelefono() == nTelefono && Dueños[i] -> getCorreo() == nCorreo){
            cout << "Cliente " << Dueños[i] -> getNombre() << " encontrado en el sistema." << endl;
            return Dueños[i];
        }
    }
    cout << "El cliente no se ha podido encontrar en el sistema." << endl;
    return nullptr;
};

