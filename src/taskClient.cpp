#include <iostream>
#include <stdio.h>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::asio;
namespace pt = boost::property_tree;
namespace pti = boost::posix_time;
using ip::tcp;
using std::string;
using std::cout;
using std::cin;
const string finish = "4";

void task1(tcp::socket &socket);
void task2(tcp::socket &socket);
void task3(tcp::socket &socket);
void send_(tcp::socket &socket, const string &query);
string read_(tcp::socket &socket);
void menu(tcp::socket &socket);
void run();


int main(){
	run();
	return 0;
}

void run(){
	io_service io_service;
	tcp::socket socket_(io_service);
	socket_.connect(tcp::endpoint(ip::address::from_string("127.0.0.1"),1234));
	while(true) menu(socket_);
}

void menu(tcp::socket &socket){
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
			send_(socket, finish);
			exit(0);
			break;
		default:
			printf("Ingrese una opción válida\n\n");
	}
}

void task1(tcp::socket &socket){
	//	JSON query
	pt::ptree query, response;
	query.put("task",1);
	query.put("hour",pti::second_clock::local_time());

	//Write JSON file
	pt::write_json("query.json",query);

	//Notify the server, that the json is ready
	const string done = "1";
	send_(socket, done);

	//Recieves server confirmation
	string answer = read_(socket);
	if(answer[0] == 'O' && answer[1] == 'K'){
		read_json("response.json",response);
		write_json(cout,response);
	}else{
		printf("Error en el servidor\n\n");
	}
}
void task2(tcp::socket & socket){
	//	JSON query
	pt::ptree query, response;
	query.put("task",2);
	query.put("hour",pti::second_clock::local_time());

	//Ask for the query file
	string file;
	printf("Porfavor, ingrese el archivo a buscar: ");
	cin>>file;
	query.put("detail",file);

	//Write JSON file
	pt::write_json("query.json",query);

	//Notify the server, that the json is ready
	const string done = "2";
	send_(socket, done);

	//Recieves server confirmation
	string answer = read_(socket);
	if(answer[0] == 'O' && answer[1] == '1'){
		read_json("response.json",response);
		write_json(cout,response);
	}else{
		printf("Error en el servidor\n\n");
	}

}
void task3(tcp::socket & socket){
	//	JSON query
	pt::ptree query, response;
	query.put("task",3);
	query.put("hour",pti::second_clock::local_time());

	//Write JSON file
	pt::write_json("query.json",query);

	//Notify the server, that the json is ready
	const string done = "3";
	send_(socket, done);

	//Recieves server confirmation
	string answer = read_(socket);
	if(answer[0] == 'O' && answer[1] == 'K'){
		read_json("response.json",response);
		write_json(cout,response);
	}else{
		printf("Error en el servidor\n\n");
	}

}


string read_(tcp::socket & socket){
	boost::asio::streambuf buf;
	boost::asio::read_until(socket,buf,"\n");
	string data = boost::asio::buffer_cast<const char*>(buf.data());
	return data;
}
void send_(tcp::socket & socket, const string &query){
	const string msg = query +"\n";
	boost::asio::write(socket, boost::asio::buffer(msg));
}
