#ifndef JsonParser_H
#define JsonParser_H
#include <nlohmann/json.hpp>
#include <string>
#include "VoiceToText.h"

class JsonParser{
    public:
        static std::string[] parse(CURLcode res);
    private:
        JsonParser() = delete;
};
#endif