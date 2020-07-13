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

void task1(tcp::socket & socket);
void task2(tcp::socket & socket);
void task3(tcp::socket & socket);
void menu(tcp::socket & socket);
void run(tcp::socket & socket);
pt::ptree getCpuInfo();
pt::ptree getFileInfo(const string & file);
pt::ptree getDbInfo();
string read_(tcp::socket & socket);
void send_(tcp::socket & socket, const string & response);

int main(){
	boost::asio::io_service io_service;
	tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234 ));
	tcp::socket socket_(io_service);
	acceptor_.accept(socket_);
	run(socket_);
	return 0;
}

void run(tcp::socket & socket){
	while(true) menu(socket);
}

void menu(tcp::socket & socket){
	string query = read_(socket);
	short option = (short) query[0]-'0';
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
	response.put("hour",pti::second_clock::local_time());
	detailnode = getCpuInfo();
	response.add_child("detail",detailnode);
	write_json("response.json",response);

	//send confirmation to client
	const string done = "OK";
	send_(socket, done);
	
	//add info at the the DB

	
}
void task2(tcp::socket & socket){
	//Read the JSON query
	pt::ptree query, response, detailnode;
	printf("\nQuery recieved:\n\n");
	pt::read_json("query.json",query);
	pt::write_json(cout,query);
	
	//prepare JSON response for client
	response.put("task",1);
	response.put("hour",pti::second_clock::local_time());
	const string file = query.get<string>("detail");
	detailnode = getFileInfo(file);
	response.add_child("detail",detailnode);
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
	response.put("hour",pti::second_clock::local_time());
	detailnode = getDbInfo();
	response.add_child("detail",detailnode);
	write_json("response.json",response);

	//send confirmation to client
	const string done = "OK";
	send_(socket, done);
}

pt::ptree getCpuInfo(){
	pt::ptree detail;
	detail.put("finished","true");
	return detail;
}

pt::ptree getFileInfo(const string & file){
	pt::ptree detail;
	detail.put("finished","true");
	return detail;
}
pt::ptree getDbInfo(){
	pt::ptree detail;
	detail.put("finished","true");
	return detail;
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
