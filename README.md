##Requerimientos
1. CMake
2. Boost

## Instrucciones para la prueba Desarrollador C++
Para ejecutar la prueba, seguir los siguientes pasos:

1. Ir al directorio src
2. Correr Cmake
```sh
cmake .
```
3. Ejecutar el servidor
```sh
./server
```
4. Ejecutar el cliente
```sh
./client
```

##Hasta este punto:
1. los procesos no emparentados cliente y servidor medio de sockets
2. cada tarea se maneja entorno a un archivo JSON

##Falta:
1. Añadir funcionalidades varias para Windows y Unix
2. Implementar la base de datos usando SOCI + Sqlite

