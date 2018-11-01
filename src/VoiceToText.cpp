#include "VoiceToText.h"
using namespace std;

struct WriteThis {
        const char *readptr;
        long sizeleft;
};
// callback function from http://curl.haxx.se/libcurl/c/post-callback.html
static size_t read_callback(void *ptr, size_t size, size_t nmemb, void *userp)
{
        struct WriteThis *pooh = (struct WriteThis *)userp;
 
        if (size*nmemb < 1)
                return 0;
 
        if (pooh->sizeleft) {
                *(char *)ptr = pooh->readptr[0]; /* copy one single byte */
                pooh->readptr++;                 /* advance pointer */
                pooh->sizeleft--;                /* less data left */
                return 1;                        /* we return 1 byte at a time! */
        }
 
        return 0;                          /* no more data left to deliver */
}
VoiceToText::VoiceToText(){
    
}
CURLcode VoiceToText::parseSpeech(string audioFile){
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    FILE *file;
    file = fopen(audioFile.c_str(), "r");
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    struct curl_slist *list = NULL;

    if (curl){
        char *audioData = (char*)malloc(fileSize);
        struct WriteThis pooh;
        fread(audioData, fileSize, 1, file);
        fclose(file);

        pooh.readptr = audioData;
        pooh.sizeleft = fileSize;

        std::string sizeHeader = "Content-Length: ";
        sizeHeader += std::to_string(fileSize);
        list = curl_slist_append(list, sizeHeader.c_str());
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.wit.ai/speech?v=20181031");
        list = curl_slist_append(list, "Authorization: Bearer KATQPBVVOXFYTGT2IT7X3WVFY3GKBBCZ");
        list = curl_slist_append(list, "Content-Type: audio/wav");
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);
        curl_easy_setopt(curl, CURLOPT_READDATA, &pooh);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, NULL);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);

        res = curl_easy_perform(curl);
        std::cout << res;
        curl_easy_cleanup(curl);
    }
    return res;
}
int main(){
    VoiceToText test = VoiceToText();
    test.parseSpeech("TurnOnLED.wav");
    test.parseSpeech("LED1.wav");
}