#ifndef Mascota_hpp
#define Mascota_hpp

#include <iostream>
#include <string>
using namespace std;

class Mascota {
protected:
    string nombre;
    int edad;
    string motivoConsulta;
    string tipo;
    string raza;
    string cartillaVacunas;
    bool agresividad;
    
public:
    Mascota();
    Mascota(string nombre, int edad, string motivoConsulta, string tipo, string raza, string cartillaVacunas, bool agresividad);
    virtual ~Mascota();
    
    void setNombre(string);
    void setEdad(int);
    void setMotivoConsulta(string);
    void setTipo(string);
    void setRaza(string);
    void setCartillaVacunas(string);
    void setAgresividad(bool);
    
    string GetNombre();
    int getEdad();
    string getMotivoConsulta();
    string getTipo();
    string getRaza();
    string getCartillaVacunas();
    bool getAgresividad();
    
    int tipoConsulta();
    string registrarCartilla();
    void agregarVacuna(string);
    virtual void mostrarCuidados() = 0;
};

class Perro : public Mascota {
private:
    string tamaño;
    
public:
    Perro();
    Perro(string tamaño);
    ~Perro();
    
    void setTamaño(string);
    string getTamaño();
    
    void mostrarCuidados();
};

class Gato : public Mascota {
private:
    bool actividadExterior;
    
public:
    Gato();
    Gato(bool actividadExterior);
    ~Gato();
    
    void setActividadExterior(bool);
    bool getActividadExterior();
    
    void mostrarCuidados();
};

#endif
