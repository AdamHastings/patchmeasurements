#define CURL_STATICLIB
#include <stdio.h>
#include <curl/curl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
//#pragma warning(disable:4996)


int main(void)
{
    CURL* curl;
    CURLcode res;
    ////struct stat file_info;
    //curl_off_t speed_upload, total_time;
    //FILE* fd;

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
        curl_mime_filedata(field, "hello.txt");

        field = curl_mime_addpart(form);
        curl_mime_name(field, "uploadBtn");
        curl_mime_data(field, "Upload", CURL_ZERO_TERMINATED);



        /* upload to this place */
        curl_easy_setopt(curl, CURLOPT_URL,"https://www.cs.columbia.edu/~hastings/php-test/upload.php");

        curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);


        //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "uploadedFile=@C:\Users\Administrator\patchmeasurements\http_workspace\curl_windows\hello.txt&uploadBtn=Upload");

        // /* tell it to "upload" to the URL */
        //curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        // /* set where to read from (on Windows you need to use READFUNCTION too) */
        //curl_easy_setopt(curl, CURLOPT_READDATA, fd);


        ///* and give the size of the upload (optional) */
        //curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)file_info.st_size);

        /* enable verbose for easier tracing */
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        }
        //else {
        //    /* now extract transfer info */
        //    curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD_T, &speed_upload);
        //    curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME_T, &total_time);

        //    fprintf(stderr, "Speed: %" CURL_FORMAT_CURL_OFF_T " bytes/sec during %"
        //        CURL_FORMAT_CURL_OFF_T ".%06ld seconds\n",
        //        speed_upload,
        //        (total_time / 1000000), (long)(total_time % 1000000));

        //}
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    //fclose(fd);

    curl_global_cleanup();

    return 0;
}