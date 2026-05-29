#ifndef Clinica_hpp
#define Clinica_hpp

#include <iostream>
#include "Persona.hpp"

using namespace std;

class Clinica{
private:
    vector<Veterinario*> Veterinarios;
    
public:
    // Constructores y destructor
    Clinica();
    Clinica(vector<Veterinario*>);
    ~Clinica();
    
    // Métodos
    void calcularSalario(double);
    void calcularBono(double, double);
    void mostrarVeterinarios();
    void agregarCliente(string Nombre, int Edad, string Telefono, string Correo, string Direccion);
    void agregarVeterinario(string Nombre, int Edad, string Telefono, string Correo, string Direccion, double Salario);
    Dueño buscarDueño(string Nombre, string Telefono, string Correo);
    vector<Veterinario*> verVeterinariosDisp();
};

#endif /* Clinica_hpp */
