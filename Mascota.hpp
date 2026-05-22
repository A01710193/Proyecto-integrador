#ifndef Mascota_hpp
#define Mascota_hpp

#include <iostream>
using namespace std;

class Mascota{
private:
    string nombre;
    int edad;
    string motivoConsulta;
    string tipo;
    string raza;
    string cartillaVacunas;
    bool agresividad;
    
public:
    // Constructores y destructores
    Mascota();
    Mascota(string nombre, int edad, string motivoConsulta, string tipo, string raza, string cartillaVacunas, bool agresividad);
    ~Mascota();
    
    // Setters
    void setNombre(string);
    void setEdad(int);
    void setMotivoConsulta(string);
    void setTipo(string);
    void setRaza(string);
    void setCartillaVacunas(string);
    void setAgresividad(bool);
    
    // Getters
    string GetNombre();
    int getEdad();
    string getMotivoConsulta();
    string getTipo();
    string getRaza();
    string getCartillaVacunas();
    string getAgresividad();
    
    // Métodos
    int tipoConsulta();
    void registrarCartilla();
};

class Perro : public Mascota{
private:
    string tamaño;
    
public:
    // Constructores y destructores
    Perro();
    Perro(string tamaño);
    ~Perro();
    
    // Setters
    void setTamaño(string);
    
    // Getters
    string getTamaño();
    
    // Métodos
    double dosisMedicamento();
    
};

class Gato : public Mascota{
private:
    bool actividadExterior;
    
public:
    // Constructores y destructores
    Gato();
    Gato(bool actividadExterior);
    ~Gato();
    
    // Setters
    void setActividadExterior(bool);
    
    // Getters
    bool getActividadExterior();
    
    // Métodos
    string evaluarPrecauciones();
    
};


#endif /* Mascota_hpp */
