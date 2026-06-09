# Proyecto integrador - 1era entrega
Este proyecto está hecho para ayudar a una clínica veterinaria que necesita ayuda con la organización y registro de sus clientes y sus empleados. Al realizar este proyecto se va a separar en varias clases. Habrá una clase principal que sera la clínica que podra tener registro de las personas que se incluyan dentro del sistema, habrá una clase madre de persona en donde tendrá los datos de las personas involucradas como su nombre, teléfono, correo,etc., y sus clases hijas serán el veterinario y el dueño de la mascota. Además habrá otra clase madre llamada mascota que es en donde se dividirá en varias clases hijas de las distintas mascotas que existen, en este caso la clínica solo ha atendido a perros y gatos por lo que no se han agregado más clases hijas.

## Funcionalidad
El programa solo nos permitirá agregar nuevos clientes, veterinarios y mascotas mas no nuevos empleados además de los veterinarios. También es importante recalcar que los veterinarios van a poder recibir un bono que incrementará su salario que ganan. Va a constar de un menú fácil de visualizar además de instrucciones claras para poder agregar a nuevas personas y darlas de alta o baja en el sistema.

## Consideraciones
El programa solo va a correr dentro de la consola y está hecho con el lenguaje de programación de c++, va a poder visualizarse aquí dentro de github e igual en todos los sistemas operativos

## Casos de error
1. Si se llega a colocar o dar algún dato de otro tipo el cuál es inválido como poner la edad como un dato de tipo string en vez de un integer llegaría a dar fallas dentro de nuestro programa, llegando a que colapse.

2. Si usamos el polimorfismo con nuestro vector de mascotas y se llega a dar de baja una mascota o termina el programa, se podría quedar dentro de nuestra memoria RAM del sistema gracias al comando 'new'. Esto se puede llegar a resolver simplemente usando delete siempre antes de correr nuestro código.

3. Si se llegan a utilizar las funciones mostrarMascotas() o mostrarVeterinarios() y estos están vacíos ya que no tienen ningún dato, el programa intentaría acceder a posiciones de memoria inexistentes y llegaría a romper la ejecución del código.

4. Al utilizar la función de buscarDueño() y agrega algún dato mal o busca a un cliente inexistente, el sistema puede llegar a darnos algún dato basura o nulo, dándonos un error en nuestro código.

## Cómo compilar
Para poder compilar todo el proyecto primero tienes que instalar todos los archivos y guardarlos dentro de una carpeta. Dentro de la terminal vas a tener que redirigir la dirección hacia esa carpeta y luego lo compilarás con la función g++ y con todos los archivos cpp como se muestra:

g++ main.cpp Clinica.cpp Persona.cpp Mascota.cpp -o sistema_clinica

Y ya con el archivo que compilaron escribiran de nuevo en la terminal:

### Para Linux / MacOS:                  Para Windows: 
./sistema_clinica                        sistema_clinica.exe

Con esto ya podrán utilizar el programa con total libertad.
