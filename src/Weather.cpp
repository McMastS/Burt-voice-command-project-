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

void Weather::getWeatherData(short type) {
    CURL *curl_handle;
    CURLcode res;
    
    struct MemoryStruct chunk;
    
    chunk.memory = (char *) malloc(1);  /* will be grown as needed by the realloc above */ 
    chunk.size = 0;    /* no data at this point */ 
    
    curl_global_init(CURL_GLOBAL_ALL);
    
    /* init the curl session */ 
    curl_handle = curl_easy_init();
    // current forecast
    if (type == 0) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, "https://api.openweathermap.org/data/2.5/weather?q=London,can&APPID=2efa2cf5aec88126598b2a34c11931bb");
    }
    // five day forecast
    if (type == 1) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, "https://api.openweathermap.org/data/2.5/forecast?q=London,can&APPID=2efa2cf5aec88126598b2a34c11931bb");
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
        std::string cpp_string = chunk.memory;
        cout << cpp_string << endl;
    }
    curl_easy_cleanup(curl_handle);
    free(chunk.memory);
     
    curl_global_cleanup();
}
