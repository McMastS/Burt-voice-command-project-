#ifndef VoiceToText_H
#define VoiceToText_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <curl/curl.h>

class VoiceToText{
    public:
        VoiceToText();
        //~VoiceToText();
        CURLcode parseSpeech(std::string audioFile);
    private:
        //findCommandFromText(std::string text);

};
#endif