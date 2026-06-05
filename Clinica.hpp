#ifndef Clinica_hpp
#define Clinica_hpp

#include <iostream>
#include <vector>
#include "Persona.hpp"

using namespace std;

class Clinica{
private:
    vector<Veterinario*> Veterinarios;
    vector<Dueño*> Dueños;
    
public:
    // Constructores y destructor
    Clinica();
    Clinica(vector<Veterinario*>, vector<Dueño*>);
    ~Clinica();
    
    // Métodos
    double calcularSalario(Veterinario*);
    double calcularBono(Veterinario*, double);
    vector<Veterinario*> mostrarVeterinarios();
    void agregarCliente(string Nombre, int Edad, string Telefono, string Correo, string Direccion);
    void agregarVeterinario(string Nombre, int Edad, string Telefono, string Correo, string Direccion, double Salario);
    bool eliminarCliente(string Nombre, string Telefono, string Correo);
    bool eliminarVeterinario(string Nombre);
    Dueño* buscarDueño(string Nombre, string Telefono, string Correo);
};

#endif /* Clinica_hpp */
