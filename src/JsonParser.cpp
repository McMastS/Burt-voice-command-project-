#include "JsonParser.h"

using namespace std;

vector<string> JsonParser::parseJSON(string result){
	vector<string> command;
	Json::Reader reader;
	Json::Value obj;
	reader.parse(result, obj);
	string subject = obj["entities"]["message_subject"][0]["value"].asString();
	string intent = obj["entities"]["on_off"][0]["value"].asString();
	command.push_back(subject);
	// won't always be "on_off"
	command.push_back(intent);
	if (obj["entities"]["duration"] != "null"){
		string duration = obj["entities"]["duration"][0]["normalized"]["value"].asString(); 
		string unit = obj["entities"]["duration"][0]["normalized"]["unit"].asString(); 
		command.push_back(duration);
		command.push_back(unit);
	}
	
	return command;
}
<<<<<<< HEAD

vector<string> JsonParser::parseWeatherData(string weatherJson) {

}
=======
>>>>>>> 80ea5d77bbccdf5a39aa17f42e7b01916e1bb431
