#ifndef Persona_hpp
#define Persona_hpp

#include <iostream>
#include "Mascota.hpp"
#include <vector>


using namespace std;

class Persona{
protected:
    string nombre;
    int edad;
    string telefono;
    string correo;
    string direccion;
    
public:
    // Constructores y destructores
    Persona();
    Persona(string nombre, int edad, string telefono, string correo, string direccion);
    virtual ~Persona();
    
    // Setters
    void setNombre(string);
    void setEdad(int);
    void setTelefono(string);
    void setCorreo(string);
    void setDireccion(string);
    
    // Getters
    string getNombre();
    int getEdad();
    string getTelefono();
    string getCorreo();
    
    // Métodos
    virtual void mostrarDatosPersonales() = 0;
    
};

class Dueño : public Persona{
private:
    vector<Mascota*> Mascotas;
    
public:
    // Constructores y destructor
    Dueño();
    Dueño(vector <Mascota*>);
    ~Dueño();
    
    // Métodos
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

class Veterinario : public Persona{
private:
    vector<int> Horarios;
    vector<Dueño*> Clientes;
    double salario;
    
public:
    // Constructores y destructor
    Veterinario();
    Veterinario(vector<int>, vector<Dueño*>, double);
    ~Veterinario();
    
    // Setters
    void setSalario(double);
    
    // Getters
    double getSalario();
    
    // Métodos
    void mostrarHorarios(vector<int>);
    void asignarCliente(Dueño*);
    double clientesAtendidos();
    vector<Dueño*> mostrarClientes();
    void recetarMedicina(Mascota*, string);
    void registrarDiagnostico(Mascota*, string);
    bool cancelarCita(int);
    void mostrarDatosPersonales();
};

#endif /* Persona_hpp */
