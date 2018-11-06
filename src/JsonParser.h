#ifndef JsonParser_H
#define JsonParser_H
#include <string>
#include <vector>
#include "VoiceToText.h"
#include "json.hpp"

class JsonParser{
    public:
        static std::vector<std::string> parse(std::string ret);
    private:
        JsonParser() = delete;
};
#endif