#include <CkAuthGoogle.h>
#include <CkRest.h>
#include <CkJsonObject.h>
#include <iostream>

void ChilkatSample(void)
{
    bool success = true;

    //  It requires the Chilkat API to have been previously unlocked.
    //  See Global Unlock Sample for sample code.

    //  This example uses a previously obtained access token having permission for the
    //  Google Drive scope.

    CkAuthGoogle gAuth;
    gAuth.put_AccessToken("GOOGLE-DRIVE-ACCESS-TOKEN");

    CkRest rest;

    //  Connect using TLS.
    bool bAutoReconnect = true;
    success = rest.Connect("www.googleapis.com", 443, true, bAutoReconnect);

    //  Provide the authentication credentials (i.e. the access token)
    rest.SetAuthGoogle(gAuth);

    //  A multipart upload to Google Drive needs a multipart/related Content-Type
    rest.AddHeader("Content-Type", "multipart/related");

    //  Specify each part of the request.

    //  The 1st part is JSON with information about the file.
    rest.put_PartSelector("1");
    rest.AddHeader("Content-Type", "application/json; charset=UTF-8");

    CkJsonObject json;
    json.AppendString("name", "helloWorld.txt");
    json.AppendString("description", "A simple text file that says Hello World.");
    json.AppendString("mimeType", "text/plain");
    rest.SetMultipartBodyString(json.emit());

    //  The 2nd part is the file content.
    //  In this case, we'll upload a simple text file containing "Hello World!"
    rest.put_PartSelector("2");
    rest.AddHeader("Content-Type", "text/plain");

    const char* fileContents = "Hello World!";
    rest.SetMultipartBodyString(fileContents);

    const char* jsonResponse = rest.fullRequestMultipart("POST", "/upload/drive/v3/files?uploadType=multipart");
    if (rest.get_LastMethodSuccess() != true) {
        std::cout << rest.lastErrorText() << "\r\n";
        return;
    }

    //  A successful response will have a status code equal to 200.
    if (rest.get_ResponseStatusCode() != 200) {
        std::cout << "response status code = " << rest.get_ResponseStatusCode() << "\r\n";
        std::cout << "response status text = " << rest.responseStatusText() << "\r\n";
        std::cout << "response header: " << rest.responseHeader() << "\r\n";
        std::cout << "response JSON: " << jsonResponse << "\r\n";
        return;
    }

    //  Show the JSON response.
    json.Load(jsonResponse);

    //  Show the full JSON response.
    json.put_EmitCompact(false);
    std::cout << json.emit() << "\r\n";

    //  A successful response looks like this:
    //  {
//   "kind": "drive#file",
    //    "id": "0B53Q6OSTWYoldmJ0Z3ZqT2x5MFk",
    //    "name": "Untitled",
    //    "mimeType": "text/plain"
    //  }

    //  Get the fileId:
    std::cout << "fileId: " << json.stringOf("id") << "\r\n";
}
