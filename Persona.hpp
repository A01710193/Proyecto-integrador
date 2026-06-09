#ifndef Persona_hpp
#define Persona_hpp

#include <iostream>
#include <vector>
#include <string>
#include "Mascota.hpp"

using namespace std;

class Persona {
protected:
    string nombre;
    int edad;
    string telefono;
    string correo;
    string direccion;
    
public:
    Persona();
    Persona(string nombre, int edad, string telefono, string correo, string direccion);
    virtual ~Persona();
    
    void setNombre(string);
    void setEdad(int);
    void setTelefono(string);
    void setCorreo(string);
    void setDireccion(string);
    
    string getNombre();
    int getEdad();
    string getTelefono();
    string getCorreo();
    
    virtual void mostrarDatosPersonales() = 0;
};

class Dueño : public Persona {
private:
    vector<Mascota*> Mascotas;
    
public:
    Dueño();
    Dueño(vector<Mascota*>);
    ~Dueño();
    
    bool agendarCita(vector<int>);
    void pagar(int);
    void mostrarMascotas();
    void agregarMascotas(Mascota* m);
    bool eliminarMascotas(string nombre);
    void vacunarMascota(string nombre, string vacuna);
    void actualizarDatos(string Telefono, string Correo);
    void solicitarHistorial(Mascota*);
    void mostrarDatosPersonales();
};

class Veterinario : public Persona {
private:
    vector<int> Horarios;
    vector<Dueño*> Clientes;
    double salario;
    
public:
    Veterinario();
    Veterinario(vector<int>, vector<Dueño*>, double);
    ~Veterinario();
    
    void setSalario(double);
    double getSalario();
    
    void mostrarHorarios(vector<int>);
    void asignarCliente(Dueño*);
    double clientesAtendidos();
    void recetarMedicina(Mascota* m, string medicina);
    void registrarDiagnostico(Mascota* m, string diagnostico);
    bool cancelarCita(int hora);
    void mostrarDatosPersonales();
};

#endif
