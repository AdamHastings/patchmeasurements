#pragma once

#define CURL_STATICLIB
#include <stdio.h>
#include <curl/curl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

void sendfile(std::string filename) {
    CURL* curl;
    CURLcode res;

    curl_mime* form = NULL;
    curl_mimepart* field = NULL;
    //struct curl_slist* headerlist = NULL;
    //static const char buf[] = "Expect:";

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    if (curl) {

        form = curl_mime_init(curl);

        field = curl_mime_addpart(form);
        curl_mime_name(field, "uploadedFile");
        curl_mime_filedata(field, filename.c_str());

        field = curl_mime_addpart(form);
        curl_mime_name(field, "uploadBtn");
        curl_mime_data(field, "Upload", CURL_ZERO_TERMINATED);



        /* upload to this place */
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.cs.columbia.edu/~hastings/php-test/upload.php");

        curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

        /* enable verbose for easier tracing */
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

