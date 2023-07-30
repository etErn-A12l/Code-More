from urllib.request import urlopen
from itertools import product
from string import ascii_lowercase
 
# list of possible characters for brute-forcing
alphabet = ascii_lowercase + '0123456789'
 
# set to True if you want to include special characters
if False:
    alphabet += '~!@#$%^&*()-_+'
 
website = input("Enter the website URL: ")
 
for length in range(1, 10):
    for attempt_chars in product(alphabet, repeat=length):
        attempt = ''.join(attempt_chars)
        # create a URL by joining the website URL with each character and attempt
        attempt_url = '/'.join([website, attempt])
        try:
            response = urlopen(attempt_url)
        except IOError:
            pass
        else:
            print("Found directory at {}".format(attempt_url))
