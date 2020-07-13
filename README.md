## Requerimientos
1. CMake
2. Boost

## Instrucciones para la prueba Desarrollador C++
Para ejecutar la prueba, seguir los siguientes pasos:

1. Ir al directorio src
2. Correr Cmake (aún no funcionan los anexos de boost)
```sh
cmake .
```
3. Ejecutar el servidor
```sh
g++ taskServerUnix.cpp -o server -lboost_system -std=c++17
./server
```
4. Ejecutar el cliente, en una terminal distinta
```sh
g++ taskClient.cpp -o client -lboost_system -std=c++17
./client
```

## Hasta este punto:
1. Los procesos no emparentados cliente y servidor medio de sockets.
2. Cada tarea se maneja entorno a un archivo JSON.

## Falta:
1. Añadir funcionalidades varias para Windows y Unix.
2. Configurar CMakeLists.txt de manera adecuada.
3. Implementar la base de datos usando SOCI + Sqlite.

