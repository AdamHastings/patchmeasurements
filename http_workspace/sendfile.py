import requests

url = 'https://www.cs.columbia.edu/~hastings/php-test/index.php'
data = {'submit':'Upload'}
files = {'file':(open('hello.txt', 'rb'))}
r = requests.post(url, data=data, files=files)

print(r.status_code)
print(r.content)
