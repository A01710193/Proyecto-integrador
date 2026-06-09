#include "Clinica.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
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
        cout << "7. Calcular bono de un veterinario" << endl;
        cout << "8. Salir del sistema" << endl;
        cout << "\n Seleccione una opción: ";
        
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = 0;
            cout << "Por favor ingrese un dato numérico." << endl;
        }
        
        if (opcion == 1) {
            string nombre, tel, correo, dir;
            int edad;
            double salario;
            
            cout << "\n Registro de nuevo veterinario" << endl;
            cin.ignore();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: ";
            while (!(cin >> edad)) {
                cin.clear();
                cin.ignore(10000, '\n');
                edad = 0;
                cout << "Por favor ingrese un dato numérico." << endl;
            }
            cin.ignore();
            cout << "Telefono: "; getline(cin, tel);
            cout << "Correo: "; getline(cin, correo);
            cout << "Direccion: "; getline(cin, dir);
            cout << "Salario Base: $";
            while (!(cin >> salario)) {
                cin.clear();
                cin.ignore(10000, '\n');
                salario = 0;
                cout << "Por favor ingrese un dato numérico." << endl;
            }
            
            clinica1.agregarVeterinario(nombre, edad, tel, correo, dir, salario);
        }
        else if (opcion == 2) {
            string nombre, tel, correo, dir;
            int edad;
            
            cout << "\n Registro de nuevo cliente" << endl;
            cin.ignore();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Edad: ";
            while (!(cin >> edad)) {
                cin.clear();
                cin.ignore(10000, '\n');
                edad = 0;
                cout << "Por favor ingrese un dato numérico." << endl;
            }
            cin.ignore();
            cout << "Telefono: "; getline(cin, tel);
            cout << "Correo: "; getline(cin, correo);
            cout << "Direccion: "; getline(cin, dir);
            
            clinica1.agregarCliente(nombre, edad, tel, correo, dir);
        }
        else if (opcion == 3) {
            cout << endl;
            clinica1.mostrarVeterinarios();
        }
        else if (opcion == 4) {
            string tel;
            cout << "\nBuscar cliente en el sistema" << endl;
            cin.ignore();
            cout << "Telefono del cliente: "; getline(cin, tel);
            
            Dueño* cliente = clinica1.buscarDueño(tel);
            
            if (cliente == nullptr) {
                cout << "No se encontró el cliente en el sistema." << endl;
            } else {
                int subOpcion = 0;
                do {
                    cout << "\n--- Menú de Gestión de Mascotas para " << cliente->getNombre() << " ---" << endl;
                    cout << "1. Mostrar los cuidados de sus mascotas" << endl;
                    cout << "2. Agregar una nueva mascota" << endl;
                    cout << "3. Eliminar una mascota" << endl;
                    cout << "4. Agendar Cita con Veterinario" << endl;
                    cout << "5. Vacunar una mascota" << endl;
                    cout << "6. Cancelar una cita" << endl;
                    cout << "7. Volver al menú principal" << endl;
                    cout << "\nSeleccione una opción: ";
                    
                    while (!(cin >> subOpcion)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        subOpcion = 0;
                        cout << "Por favor ingrese un dato numérico." << endl;
                    }
                    
                    if (subOpcion == 1) {
                        cout << endl;
                        cliente->mostrarMascotas();
                    }
                    else if (subOpcion == 2) {
                        string mNombre, mMotivo, mTipo, mRaza, mCartilla;
                        int mEdad;
                        string ansAgresividad;
                        bool mAgresividad = false;
                        
                        cin.ignore();
                        cout << "Nombre de la mascota: "; getline(cin, mNombre);
                        cout << "Edad: ";
                        while (!(cin >> mEdad)) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            subOpcion = 0;
                            cout << "Por favor ingrese un dato numérico." << endl;
                        }
                        cin.ignore();
                        cout << "Motivo de la consulta: "; getline(cin, mMotivo);
                        cout << "Tipo de mascota (Perro/Gato): "; getline(cin, mTipo);
                        cout << "Raza: "; getline(cin, mRaza);
                        cout << "Cartilla de vacunas: "; getline(cin, mCartilla);
                        
                        cout << "¿La mascota es agresiva? (si/no): "; getline(cin, ansAgresividad);
                        if (ansAgresividad == "si" || ansAgresividad == "sí" || ansAgresividad == "Sí" || ansAgresividad == "SI") {
                            mAgresividad = true;
                        }
                        
                        Mascota* nuevaMascota = nullptr;
                        if (mTipo == "Perro" || mTipo == "perro" || mTipo == "PERRO") {
                            string mTamaño;
                            cout << "Tamaño del perro (Pequeño/Mediano/Grande): "; getline(cin, mTamaño);
                            Perro* p = new Perro(mTamaño);
                            nuevaMascota = p;
                        } else {
                            string ansExterior;
                            bool mExterior = false;
                            cout << "¿Tiene actividad en el exterior? (si/no): "; getline(cin, ansExterior);
                            if (ansExterior == "si" || ansExterior == "sí" || ansExterior == "Sí" || ansExterior == "SI") {
                                mExterior = true;
                            }
                            Gato* g = new Gato(mExterior);
                            nuevaMascota = g;
                        }
                        
                        nuevaMascota->setNombre(mNombre);
                        nuevaMascota->setEdad(mEdad);
                        nuevaMascota->setMotivoConsulta(mMotivo);
                        nuevaMascota->setTipo(mTipo);
                        nuevaMascota->setRaza(mRaza);
                        nuevaMascota->setCartillaVacunas(mCartilla);
                        nuevaMascota->setAgresividad(mAgresividad);
                        
                        cliente->agregarMascotas(nuevaMascota);
                        cout << "¡Mascota registrada con éxito!" << endl;
                    }
                    else if (subOpcion == 3) {
                        string mNombre;
                        cin.ignore();
                        cout << "Ingrese el nombre de la mascota que quiere eliminar: "; getline(cin, mNombre);
                        cliente->eliminarMascotas(mNombre);
                    }
                    else if (subOpcion == 4) {
                        cout << "\n--- AGENDAR CITA ---" << endl;
                        vector<Veterinario*> listaVets = clinica1.mostrarVeterinarios();
                        
                        if (!listaVets.empty()) {
                            string nombreVet;
                            cin.ignore();
                            cout << "\nIngrese el nombre del Veterinario con el que desea la cita: ";
                            getline(cin, nombreVet);
                            
                            Veterinario* vetElegido = clinica1.buscarVeterinario(nombreVet);
                            
                            if (vetElegido != nullptr) {
                                int horaCita;
                                cout << "Ingrese la hora deseada (formato 24h, ej. 14 para 2pm): ";
                                if (!(cin >> horaCita)) {
                                    cin.clear();
                                    cin.ignore(10000, '\n');
                                    horaCita = -1;
                                }
                                
                                vetElegido->asignarCliente(cliente);
                                cout << "✅ ¡Cita agendada exitosamente a las " << horaCita << ":00 con el Dr/a " << vetElegido->getNombre() << "!" << endl;
                            } else {
                                cout << "❌ No se encontró ningún veterinario con ese nombre." << endl;
                            }
                        } else {
                            cout << "No hay veterinarios registrados en el sistema." << endl;
                        }
                    }
                    else if (subOpcion == 5) {
                        string mNombre, vacuna;
                        cin.ignore();
                        cout << "Ingrese el nombre de la mascota: "; getline(cin, mNombre);
                        cout << "Ingrese el nombre de la vacuna: "; getline(cin, vacuna);
                        cliente->vacunarMascota(mNombre, vacuna);
                    }
                    else if (subOpcion == 6) {
                        string vNombre;
                        int hora;
                        cin.ignore();
                        cout << "Ingrese el nombre del veterinario con quien agendó la cita: "; getline(cin, vNombre);
                        Veterinario* v = clinica1.buscarVeterinario(vNombre);
                        if (v == nullptr) {
                            cout << "No se encontró un veterinario con ese nombre." << endl;
                        } else {
                            cout << "Ingrese la hora de la cita a cancelar (de 8 a 20): ";
                            while (!(cin >> hora)) {
                                cin.clear();
                                cin.ignore(10000, '\n');
                                hora = 0;
                                cout << "Por favor ingrese un dato numérico." << endl;
                            }
                            cin.ignore();
                            v->cancelarCita(hora);
                        }
                    }
                    else if (subOpcion != 7) {
                        cout << "La opción no es válida en el menú." << endl;
                    }
                } while (subOpcion != 7);
            }
        }
        else if (opcion == 5) {
            string nombre;
            cout << "\nBaja de veterinario del sistema" << endl;
            cin.ignore();
            cout << "Nombre del veterinario: "; getline(cin, nombre);
            clinica1.eliminarVeterinario(nombre);
        }
        else if (opcion == 6) {
            string tel;
            cout << "\n Baja de cliente del sistema" << endl;
            cin.ignore();
            cout << "Telefono del cliente: "; getline(cin, tel);
            clinica1.eliminarCliente(tel);
        }
        else if (opcion == 7){
                    string nombreVet;
                    double bonoPorCliente;
                    
                    cout << "\n--- Calcular Bono de Veterinario ---" << endl;
                    cin.ignore();
                    cout << "Nombre del veterinario: ";
                    getline(cin, nombreVet);
                    cout << "Monto del bono a otorgar por cada cliente atendido: $";
                    cin >> bonoPorCliente;
                    
                    vector<Veterinario*> listaVets = clinica1.mostrarVeterinarios();
                    Veterinario* vetEncontrado = nullptr;
                    
                    for (int i = 0; i < listaVets.size(); i++){
                        if (listaVets[i]->getNombre() == nombreVet){
                            vetEncontrado = listaVets[i];
                            break;
                        }
                    }
            
                    if (vetEncontrado != nullptr){
                        clinica1.calcularBono(vetEncontrado, bonoPorCliente);
                    } else {
                        cout << "No se encontró al Dr/a " << nombreVet << " en el sistema." << endl;
                    }
                }
        else if (opcion == 8) {
            cout << "\n Cerrando el sistema de la clínica felicidad." << endl << "\n Muchas gracias por utilizar el sistema." << endl;
        }
        else {
            cout << "\nOpción inválida, intente de nuevo por favor." << endl;
        }
    } while (opcion != 8);
    
    return 0;
}
