import requests

# defining the api-endpoint  
API_ENDPOINT = "http://www.cs.columbia.edu/~hastings/experiments/asdfasdg"


files = {'upload_file': open('file.txt','rb')}



# sending post request and saving response as response object
r = requests.post(url = API_ENDPOINT, data = data)

print(r.status_code)
