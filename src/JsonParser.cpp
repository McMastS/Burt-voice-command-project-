#include "JsonParser.h"

using namespace std;

vector<string> JsonParser::parseJSON(string rawJson){
	vector<string> command;
	Json::Reader reader;
	Json::Value obj;
	reader.parse(rawJson, obj);

	string subject = obj["entities"]["message_subject"][0]["value"].asString();
	string intent = obj["entities"]["on_off"][0]["value"].asString();

	// subject at position 0, intent at 1
	command.push_back(subject);
	command.push_back(intent);
	if (obj["entities"]["duration"] != "null"){
		string duration = obj["entities"]["duration"][0]["normalized"]["value"].asDouble();
		// At some point need to get unit, then deal with it 
		command.push_back(duration);
	}
	
	return command;
}
