#ifndef Weather_H
#define Weather_H
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <json/json.h>
#include <curl/curl.h>
#include "VoiceToText.h"


class Weather{
    public:
        static std::string currentForecast();
    private:
        static std::string getWeatherData(short type);
        static std::vector<string> parseWeatherData(std::string weatherJson);
        Weather() = delete;
};
#endif