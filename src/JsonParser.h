#ifndef JsonParser_H
#define JsonParser_H
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include "VoiceToText.h"

class JsonParser{
    public:
        static std::vector parse(CURLcode res);
    private:
        JsonParser() = delete;
};
#endif