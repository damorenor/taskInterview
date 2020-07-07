#include <iostream>
#include <stdio.h>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tpc;
using std::string;

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
	switch(option){
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			exit(0);
		default:
		printf("se ingresó una opción invalida\n");
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

