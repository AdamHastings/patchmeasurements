#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char* argv[])
{
    CURL* curl;
    CURLcode res;

    /* In windows, this will init the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);

    /* get a curl handle */
    curl = curl_easy_init();
    if (curl) {

        printf("Running curl test.\n");

        struct curl_slist* headers = NULL; /* init to NULL is important */
        headers = curl_slist_append(headers, "Authorization: Bearer 1v4q0_X7ptQAAAAAAAAAAXLkDScfpTbZWVk9TXX8Uy3DRsxRttFB34tQ41IGbEjl");
        headers = curl_slist_append(headers, "Content-Type: application/octet-stream");
        headers = curl_slist_append(headers, "Dropbox-API-Arg: {\"path\":\"/Protocol1/Apps/isthisworking.txt\",\"mode\": \"add\",\"autorename\": true,\"mute\": false,\"strict_conflict\": false}");
        //headers = curl_slist_append(headers, "Dropbox-API-Arg: {\"path\":\"/test.txt\",\"mode\": \"add\",\"autorename\": true}");
        //headers = curl_slist_append(headers, "Dropbox-API-Arg: {\"C:\\Users\\Administrator\\patchmeasurements\\CurlTest\":\"\\test.txt\"}");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_URL, "https://content.dropboxapi.com/2/files/upload");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "test data for upload");

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);

        printf("\nFinished curl test.\n");

    }
    curl_global_cleanup();

    printf("Done!\n");
    return 0;

}