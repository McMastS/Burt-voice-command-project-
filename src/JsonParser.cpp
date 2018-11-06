#include "JsonParser.h";
using json = nlohmann::json;

std::string JsonParser::parse(CURLcode res){
	auto json = res_json;
	
	std::string subject = json["entities"]["message_subject"]["value"];
	// won't always be "on_off"
	std::string intent = json["entites"]["on_off"]["value"];
	
	std::cout << subject << std::endl;
	std::cout << intent << std::endl;
	
	std::string command [2] = {subject, intent};
	
	return command;
}