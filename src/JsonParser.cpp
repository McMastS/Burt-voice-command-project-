#include <stdio.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include "VoiceToText.h"

// for convenience
using json = nlohmann::json;


std::string fillarr(CURLcode res){
	auto json = res_json;
	
	std::string subject = json["entities"]["message_subject"]["value"];
	// won't always be "on_off"
	std::string intent = json["entites"]["on_off"]["value"];
	
	cout << command1;
	cout << command2;
	
	std::string arr [2] = {command1, command2};
	
	return arr;
}