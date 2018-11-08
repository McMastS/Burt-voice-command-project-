#ifndef JsonParser_H
#define JsonParser_H
#include <string>
#include <vector>
#include <jsoncpp/json/json.h>
#include "VoiceToText.h"


class JsonParser{
    public:
        static std::vector<std::string> parseJSON(std::string ret);
    private:
        JsonParser() = delete;
};
#endif
