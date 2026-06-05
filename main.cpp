#include "Clinica.hpp"
#include <iostream>
using namespace std;

int main(){
    Clinica clinica1;
    int opcion = 0;
    
    do {
        cout << "\n¡Bienvenido al sistema de la clínica felicidad!" << endl << endl;
        cout << "¿Qué le gustaría hacer hoy?\n" << endl;
        cout << "1. Registrar un nuevo veterinario" << endl;
        cout << "2. Registrar un nuevo cliente" << endl;
        cout << "3. Mostrar los veterinarios" << endl;
        cout << "4. Buscar a un cliente y ver a sus mascotas" << endl;
        cout << "5. Eliminar un veterinario" << endl;
        cout << "6. Eliminar un cliente" << endl;
        cout << "7. Salir del sistema" << endl;
        cout << "\n Seleccione una opción: " << endl;
        cin >> opcion;
        
        if (opcion == 1){
            string nombre, tel, correo, dir;
            int edad;
            double salario;
            
            cout << "\n Registro de nuevo veterinario" << endl;
            cin.ignore();
            
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: " ; cin >> edad;
            cin.ignore();
            cout << "Telefono: "; getline(cin,tel);
            cout << "Correo: "; getline(cin, correo);
            cout << "Direccion: "; getline(cin, dir);
            cout << "Salario Base: $"; cin >> salario;
            
            clinica1.agregarVeterinario(nombre,edad, tel, correo, dir, salario);
        }
         
        else if (opcion == 2){
            string nombre, tel, correo, dir;
            int edad;
            
            cout << "\n Registro de nuevo cliente" << endl;
            cin.ignore();
            
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: " ; cin >> edad;
            cin.ignore();
            cout << "Telefono: "; getline(cin,tel);
            cout << "Correo: "; getline(cin, correo);
            cout << "Direccion: "; getline(cin, dir);
            
            clinica1.agregarCliente(nombre, edad, tel, correo, dir);
        }
        
        else if (opcion == 3){
            cout << "\n Veterinario registrados en el sistema" << endl;
            clinica1.mostrarVeterinarios();
        }
        
        else if (opcion == 4){
            string nombre, tel, correo;
            
            cout << "\nBuscar cliente en el sistema" << endl;
            cin.ignore();
            
            cout << "Ingrese el nombre: "; getline(cin, nombre);
            cout << "Ingrese el teléfono: "; getline(cin, tel);
            cout << "Ingrese el correo: "; getline(cin,correo);
            
            Dueño* cliente = clinica1.buscarDueño(nombre, tel, correo);
            
            if (cliente != nullptr){
                int subOpcion = 0;
                
                while (subOpcion != 6) {
                    cout << "\n Gestionando a " << nombre << endl;
                    cout << "1. Agregar una nueva mascota" << endl;
                    cout << "2. Ver las mascotas actuales" << endl;
                    cout << "3. Eliminar una mascota" << endl;
                    cout << "4. Agendar cita con un Veterinario" << endl;
                    cout << "5. Agregar vacuna" << endl;
                    cout << "6. Regresar al menú principal" << endl;
                    cout << "\n Elige una opción: " << endl;
                    
                    cin >> subOpcion;
                    
                    if (subOpcion == 1){
                        int tipoMascota;
                        cout << "\n ¿Qué tipo de mascota es?" << endl;
                        cout << "1. Perro" << endl;
                        cout << "2. Gato" << endl;
                        cout << "\n Elige una opción:" << endl;
                        cin.ignore();
                        cin >> tipoMascota;
                        
                        string nombre, motivo, raza;
                        int edad;
                        
                        cin.ignore();
                        cout << "Nombre de la mascota: "; getline(cin, nombre);
                        cout << "Edad de la mascota: "; cin >> edad;
                        cin.ignore();
                        cout << "Motivo de la consulta: "; getline(cin, motivo);
                        cout << "Raza: "; getline(cin, raza);
                        
                        if (tipoMascota == 1){
                            string tamaño;
                            cout << "Tamaño del perro (Chico/Mediano/Grande): "; getline(cin, tamaño);
                            
                            Perro* nPerro = new Perro();
                            nPerro -> setNombre(nombre);
                            nPerro -> setEdad(edad);
                            nPerro -> setMotivoConsulta(motivo);
                            nPerro -> setTipo("Perro");
                            nPerro -> setRaza(raza);
                            nPerro -> setTamaño(tamaño);
                            
                            cliente -> agregarMascotas(nPerro);
                        }
                        
                        else if (tipoMascota == 2){
                            string respuesta;
                            bool actext;
                            
                            cout << "¿El gato sale al exterior? (Si/No) "; getline(cin, respuesta);
                            if (respuesta == "Si" || respuesta == "SI" || respuesta == "si"){
                                actext = true;
                            }
                            
                            else {
                                actext = false;
                            }
                            
                            Gato* nGato = new Gato();
                            nGato -> setNombre(nombre);
                            nGato -> setEdad(edad);
                            nGato -> setMotivoConsulta(motivo);
                            nGato -> setTipo("Gato");
                            nGato -> setRaza(raza);
                            nGato -> setActividadExterior(actext);
                            
                            cliente -> agregarMascotas(nGato);
                        }
                        
                        else{
                            cout << "Error: el tipo de mascota que ingresó es inválido." << endl;
                        }
                    }
                    
                    else if (subOpcion == 2){
                        cliente -> mostrarMascotas();
                    }
                    
                    else if (subOpcion == 3){
                        string nombre;
                        
                        cin.ignore();
                        cout << "Ingrese el nombre de la mascota que quiere eliminar: "; getline(cin, nombre);
                        
                        cliente -> eliminarMascotas(nombre);
                    }
                    
                    else if (subOpcion == 4) {
                        cout << "\n--- Agendar cita ---" << endl;
                        vector<Veterinario*> lista = clinica1.mostrarVeterinarios();
                        
                        if (!lista.empty()){
                            string nombre;
                            cin.ignore();
                            cout << "Ingrese el nombre con quien gustaría la cita: "; getline(cin, nombre);
                            
                            Veterinario* nVeterinario = nullptr;
                            for (int i = 0; i < lista.size(); i++){
                                if (lista[i] -> getNombre() == nombre){
                                    nVeterinario = lista[i];
                                }
                            }
                            
                            if (nVeterinario != nullptr){
                                int hora;
                                cout << "Ingrese la hora deseada para su cita (en formato de 24hr; por ejemplo: 17 para indicar 5pm)" << endl; cin >> hora;
                                
                                nVeterinario -> asignarCliente(cliente);
                                
                                cout << "La cita ha sido agendada." << endl;
                                cout << "El cliente " << cliente -> getNombre() << " tiene la cita de las " << hora << ":00 con el Dr/a " << nVeterinario -> getNombre() << "." << endl;
                            }
                            
                            else {
                                cout << "No se logró encontrar a ningún veterinario con ese nombre." << endl;
                            }
                        }
                    }
                    
                    else if (subOpcion == 5){
                        string nombre, vacuna;
                        cin.ignore();
                        cout << "\n --- Aplicar la vacuna ---" << endl;
                        cout << "Ingrese el nombre de la mascota que vamos a vacunar: "; getline(cin, nombre);
                        cout << "Ingrese el nombre de la vacuna: "; getline(cin, vacuna);
                        
                        cliente -> vacunarMascota(nombre, vacuna);
                    }
                    else if (subOpcion != 6){
                        cout << "La opción que ingresó no es válida" << endl;
                    }
                }
            }
        }
        
        else if (opcion == 5){
            string nombre;
            cout << "\nBaja de veterinario del sistema" << endl;
            cin.ignore();
            cout << "Nombre del veterinario: "; getline(cin, nombre);
            clinica1.eliminarVeterinario(nombre);
        }
        
        else if (opcion == 6){
            string nombre, tel, correo;
            cout << "\n Baja de cliente del sistema" << endl;
            cin.ignore();
            cout << "Nombre del cliente: "; getline(cin, nombre);
            cout << "Telefono del cliente: "; getline(cin,tel);
            cout << "Correo del cliente: "; getline(cin,correo);
            clinica1.eliminarCliente(nombre, tel, correo);
        }
        
        else if (opcion == 7){
            cout << "\n Cerrando el sistema de la clinica felicidad." << endl << "\n Muchas gracias por utilizar el sistema de la clinica felicidad." << endl;
        }
        
        else {
            cout << "\nOpción inválida, intente de nuevo por favor." << endl;
        }
        
    } while (opcion != 7);
    
    return 0;
}
