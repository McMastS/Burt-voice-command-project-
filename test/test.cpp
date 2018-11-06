#include "../src/VoiceToText.cpp"
using namespace std;
class test{

};
int main(){
    cout << "VoiceToText Test" << endl;
    cout << VoiceToText::parseSpeech("./test/TurnOnLED1.wav") << endl;
    cout << VoiceToText::parseSpeech("./test/TurnOffLED1.wav") << endl;
} 