#ifndef Mascota_hpp
#define Mascota_hpp

#include <iostream>
using namespace std;

class Mascota{
protected:
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
    virtual ~Mascota();
    
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
    bool getAgresividad();
    
    // Métodos
    int tipoConsulta();
    string registrarCartilla();
    void agregarVacuna(string);
    virtual void mostrarCuidados();
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
    void mostrarCuidados();
    
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
    void mostrarCuidados();
};


#endif /* Mascota_hpp */
