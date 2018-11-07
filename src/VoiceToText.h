#ifndef VoiceToText_H
#define VoiceToText_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <curl/curl.h>

class VoiceToText{
    public:
        static std::string parseSpeech(std::string audioFile);
    private:
        VoiceToText() = delete;
};
#endif