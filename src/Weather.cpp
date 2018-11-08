/**
 * This class currently handles getting the forecast using the Open Weather Map API.
 * Idea for future development: change this class into a "question handler" class that deals with
 * a bunch of commands that require a search on the internet. 
 **/
#include "Weather.h"

using namespace std;


// Memory callback function from: https://curl.haxx.se/libcurl/c/getinmemory.html
struct MemoryStruct {
  char *memory;
  size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if(ptr == NULL) {
        /* out of memory! */ 
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

string Weather::getWeatherData(short type) {
    CURL *curl_handle;
    CURLcode res;
    string json = "";
    struct MemoryStruct chunk;
    
    chunk.memory = (char *) malloc(1);  /* will be grown as needed by the realloc above */ 
    chunk.size = 0;    /* no data at this point */ 
    
    curl_global_init(CURL_GLOBAL_ALL);
    
    /* init the curl session */ 
    curl_handle = curl_easy_init();
    // current forecast
    if (type == 0) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, "https://api.openweathermap.org/data/2.5/weather?q=Toronto,can&APPID=2efa2cf5aec88126598b2a34c11931bb");
    }
    // five day forecast
    if (type == 1) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, "https://api.openweathermap.org/data/2.5/forecast?q=Toronto,can&APPID=2efa2cf5aec88126598b2a34c11931bb");
    }
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    res = curl_easy_perform(curl_handle);
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }
    else {
        json = chunk.memory;
    }
    curl_easy_cleanup(curl_handle);
    free(chunk.memory);
     
    curl_global_cleanup();
    return json;
}

/**
 * Parses json returned from weather api and returns a vector of the form:
 * ['current temp', 'min temp', 'max temp', 'sky conditions']
 * 
 * Will need to add option for 5 day forecast if we add it, as this is just current.
 **/
vector<string> Weather::parseWeatherData(std::string weatherJson) {
    vector<string> jsonVector;
    Json::Reader reader;
    Json::Value obj;
    reader.parse(weatherJson, obj);

    // Temperature is stored as Kelvin in JSON, so convert to celsius
    double temp = obj["main"]["temp"].asDouble() - 273.15;
    double min_temp = obj["main"]["temp_min"].asDouble() - 273.15;
    double max_temp = obj["main"]["temp_max"].asDouble() - 273.15;
    string skyCondition = obj["weather"][0]["main"].asString();
    int minTemp = (int) min_temp;
    int maxTemp = (int) max_temp;
    int curTemp = (int) temp;
    jsonVector.push_back(to_string(curTemp));
    jsonVector.push_back(to_string(minTemp));
    jsonVector.push_back(to_string(maxTemp));
    jsonVector.push_back(skyCondition);

    return jsonVector;
}

string Weather::currentForecast() {
    string weatherJson;
    vector<string> jsonVector;
    stringstream result;
    weatherJson = getWeatherData(0);
    jsonVector = parseWeatherData(weatherJson);
    result << "The current temperature is " << jsonVector[0] << "°C." << endl;
    result << "The max temp is " << jsonVector[1] << "°C." << " The min temp is " << jsonVector[2] << "°C." << endl;
    result << "The sky is currently " << jsonVector[3] <<  "." << endl;
    return result.str();
}
