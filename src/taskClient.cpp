#include <iostream>
#include <stdio.h>
#include <chrono>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#define pt boost::property_tree

using namespace boost::asio;
namespace pt = boost::property_tree;
using ip::tcp;
using std::string;
using std::cout;
using std::cin;

void task1();
void task2();
void task3();
void send();
string read();
void menu();
void run();
void printData();


int main(){
	run();
	return 0;
}

void run(){
	io_service io_service;
	tcp::socket socket(io_service
	socket.connect(tcp::endpoint(ip::address::from_string("127.0.0.1"),1234))
	while(true) menu(socket);
}

void menu(tcp::socket & socket){
	short option;
	printf("\tPRUEBA DESARROLLADOR C++"
			"\nEscoja una tarea:\n"
			"\t1. Ver info de la CPU\n"
			"\t2. Buscar un archivo\n"
			"\t3. Consultar la base de datos\n"
			"\t4. Salir\n");
	scanf("%hd",&option);
	switch(option){
		case 1:
			task1(socket);
			break;
		case 2:
			task2(socket);
			break;
		case 3:
			task3(socket);
			break;
		case 4:
			exit(0);
		default:
		printf("Ingrese una opción válida\n\n");
	}
}

void task1(tcp::socket & socket){
	//	JSON query
	pt::ptree query, response;
	q.put("task",1);
	string hour = getHour();
	q.put("hour",hour);

	//Write JSON file
	pt::write_json("query.json",query);

	//Notify the server, that the json is ready
	const string done = "OK";
	send(socket, done);

	//Recieves server confirmation
	string answer = read(socket);
	if(answer == "OK"){
		read_json("response.json",response);
		cout<<response.get<string>("detail")<<"\n";
	}else{
		printf("Error en el servidor\n\n");
	}
}
void task2(tcp::socket & socket){
	//	JSON query
	pt::ptree query, response;
	q.put("task",2);
	string hour = getHour();
	q.put("hour",hour);

	//Ask for the query file
	string file;
	printf("Porfavor, ingrese el archivo a buscar: ");
	cin>>file;

	//Write JSON file
	pt::write_json("query.json",query);

	//Notify the server, that the json is ready
	const string done = "OK";
	send(socket, done);

	//Recieves server confirmation
	string answer = read(socket);
	if(answer == "OK"){
		read_json("response.json",response);
		cout<<response.get<string>("detail")<<"\n";
	}else{
		printf("Error en el servidor\n\n");
	}

}
void task3(tcp::socket & socket){
	//	JSON query
	pt::ptree query, response;
	q.put("task",3);
	string hour = getHour();
	q.put("hour",hour);	

	//Write JSON file
	pt::write_json("query.json",query);

	//Notify the server, that the json is ready
	const string done = "OK";
	send(socket, done);

	//Recieves server confirmation
	string answer = read(socket);
	if(answer == "OK"){
		read_json("response.json",response);
		cout<<response.get<string>("detail")<<"\n";
	}else{
		printf("Error en el servidor\n\n");
	}

}

string getHour(){
	string hour = "123456";
	return hour;
}

string read_(tcp::socket & socket){
	boost::asio::streambuf buf;
	boost::asio::read_until(socket,buf,"\n");
	string data = boost::asio::buffer_cast<const char*>(buf.data());
	return data;
}
void send_(tcp::socket & socket, const string &query){
	boost::asio::write(socket, boost::asio::buffer(query));
}
