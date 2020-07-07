#include <bits/stdc++.h>

void task1();
void task2();
void task3();
void menu();
void run();
void printData();


int main(){
	run();
	return 0;
}

void run(){
	while(true) menu();
}

void menu(){
	short option;
	printf("\tPRUEBA DESARROLLADOR C++
			\nEscoja una tarea:\n
			\t1. Ver info de la CPU\n
			\t2. Buscar un archivo\n
			\t3. Consultar la base de datos\n
			\t4. Salir\n");
	scanf("%hd",&option);
	switch(option){
		case 1:
			task1();
			break();
		case 2:
			task2();
			break();
		case 3:
			task3();
			break();
		case 4:
			exit(0);
		default:
		printf("ingrese una opción valida\n\n");
	}

}

void task1(){
	printf("Task1 performed\n");
}
void task2(){
	printf("Task2 performed\n");
}
void task3(){
	printf("Task3 performed\n");
}
