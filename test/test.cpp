#include "../src/VoiceToText.cpp"
#include "../src/JsonParser.cpp"
#include "../src/CommandParser.cpp"

using namespace std;
class test{

};
int main(){
    cout << "VoiceToText Test:" << endl;
    string test1 = VoiceToText::parseSpeech("./test/TurnOnTheLights.wav");
    string test2 = VoiceToText::parseSpeech("./test/TurnOffTheLights.wav");
    cout << test1 << endl;
    cout << test2 << endl;
    cout << "Json Parsing Test:" << endl;
    vector<string> vec1 = JsonParser::parseJSON(test1);
    vector<string> vec2 = JsonParser::parseJSON(test2);
    cout << "Subject:" << vec1[0] << endl;
    cout << "Intent:" << vec1[1] << endl;
    cout << "Subject:" << vec2[0] << endl;
    cout << "Intent:" << vec2[1] << endl;

    //Audio
    string weatherTest2 = VoiceToText::parseSpeech("./test/Weather.wav");
    vector<string> weather = JsonParser::parseJSON(weatherTest2);
    CommandParser::runCommand(weather);
} 
