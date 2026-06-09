#ifndef Clinica_hpp
#define Clinica_hpp

#include <iostream>
#include <vector>
#include <string>
#include "Persona.hpp"

using namespace std;

class Clinica {
private:
    vector<Veterinario*> Veterinarios;
    vector<Dueño*> Dueños;
    
public:
    Clinica();
    Clinica(vector<Veterinario*>, vector<Dueño*>);
    ~Clinica();
    
    double calcularSalario(Veterinario*);
    double calcularBono(Veterinario*, double);
    vector<Veterinario*> mostrarVeterinarios();
    void agregarCliente(string Nombre, int Edad, string Telefono, string Correo, string Direccion);
    void agregarVeterinario(string Nombre, int Edad, string Telefono, string Correo, string Direccion, double Salario);
    bool eliminarCliente(string Telefono);
    bool eliminarVeterinario(string Nombre);
    Dueño* buscarDueño(string Telefono);
    Veterinario* buscarVeterinario(string Nombre);
};

#endif
