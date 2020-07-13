#include <iostream>
#include <stdio.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/asio.hpp>

using namespace boost::asio;
namespace pt = boost::property_tree;
using ip::tcp;
using std::string;
using std::cout;

void task1();
void task2();
void task3();
void menu();
void run();
void printData();


int main(){
	boost:::asio::io_service io_service;
	tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(),1324));
	tcp::socket socket_(io_service);
	acceptor_.accept(socket_);
	run(socket_);
	return 0;
}

void run(tcp::socket & socket){
	while(true) menu(socket);
}

void menu(tcp::socket & socket){
	string query = read_(socket)
	short option = (short) query[0]-'0';
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

void task1(tcp::socket & socket){
	//Read the JSON query
	pt::ptree query, response, detailnode;
	printf("\nQuery recieved:\n\n");
	pt::read_json("query.json",query);
	pt::write_json(cout,query);
	
	//prepare JSON response for client
	response.put("task",1);
	string hour = getHour();
	response.put("hour",hour);
	detailnode = getCpuInfo();
	write_json("response.json",response);

	//send confirmation to client
	const string done = "OK";
	send_(socket, done);
	
	//add info at the the DB

	
}
void task2(tpc::socket & socket){
	//Read the JSON query
	pt::ptree query, response, detailnode;
	printf("\nQuery recieved:\n\n");
	pt::read_json("query.json",query);
	pt::write_json(cout,query);
	
	//prepare JSON response for client
	response.put("task",1);
	string hour = getHour();
	response.put("hour",hour);
	const string file = query.get<string>("detail");
	detailnode = getFileInfo();
	write_json("response.json",response);

	//send confirmation to client
	const string done = "OK";
	send_(socket, done);
}
void task3(tcp::socket & socket){
	//Read the JSON query
	pt::ptree query, response, detailnode;
	printf("\nQuery recieved:\n\n");
	pt::read_json("query.json",query);
	pt::write_json(cout,query);
	
	//prepare JSON response for client
	response.put("task",1);
	string hour = getHour();
	response.put("hour",hour);
	detailnode = getDbInfo();
	write_json("response.json",response);

	//send confirmation to client
	const string done = "OK";
	send_(socket, done);
}

pt::tree getCpuInfo(){
	pt::ptree detail;
	
	return detail;
}

pt::tree getFileInfo(const string & file){
	pt::ptree detail;
	
	return detail;
}
pt::tree getDbInfo(){
	pt::ptree detail;
	
	return detail;
}
string getHour(){
	hour = "1234"
	return hour;
}

string read_(tcp::socket & socket){
	boost::asio::streambuf buf;
	boost::asio::read_until(socket,buf,"\n");
	string data = boost::asio::buffer_cast<string>(buf.data());
	return data;
}

void send_(tcp::socket & socket, const string & response){
	const msg = response + "\n";
	boost::asio::write(socket,boost::asio::buffer(msg));
}
