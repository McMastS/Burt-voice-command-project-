#ifndef Weather_H
#define Weather_H
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <jsoncpp/json/json.h>
#include <curl/curl.h>
#include "VoiceToText.h"


class Weather{
    public:
        static std::vector<std::string> currentForecast(std::string ret);
        static std::vector<std::string> fiveDayForecast(std::string ret);
        static void getWeatherData(short type);
    private:
        Weather() = delete;
};
#endif