#include "JsonParser.h"
using json = nlohmann::json;

std::vector<std::string> JsonParser::parse(std::string ret){
	auto json = R"(ret)"_json;
	
	std::string subject = json["entities"]["message_subject"]["value"];
	// won't always be "on_off"
	std::string intent = json["entites"]["on_off"]["value"];
	
	std::cout << subject << std::endl;
	std::cout << intent << std::endl;
	
	std::vector<std::string> command;
	command.push_back(subject);
	command.push_back(intent);
	
	return command;
}