from datetime import datetime
import json
import urllib
from urllib import request
import sys

RED = "\033[1;31m"
BLUE = "\033[1;34m"
CYAN = "\033[1;36m"
GREEN = "\033[0;32m"
RESET = "\033[0;0m"
BOLD = "\033[;1m"
REVERSE = "\033[;7m"


def report():
    print("name:", value["name"])
    print("description:", value["description"])
    print("id:", value["id"])
    dt_date = datetime.strptime(value["created_at"], "%Y-%m-%dT%H:%M:%SZ")
    print("created at:", dt_date.strftime("%d-%b-%Y"))
    print("visibility:", value["visibility"])
    print("language:", value["language"])
    if value["license"] != None:
        print("license:", value["license"]["name"])
    print("stars:", value["stargazers_count"])
    print("forks:", value["forks"])
    print("open issues:", value["open_issues"])
    if value["size"] >= 1048576:
        print("size:", round(value["size"] / 1048576, ndigits=4), "GB")
    elif value["size"] >= 1024:
        print("size:", round(value["size"] / 1024, ndigits=4), "MB")
    else:
        print("size:", value["size"], "KB")

print("Repo you want to search: ",end="")
sys.stdout.write(RED)
url_type = input()
sys.stdout.write(RESET)
try:
    reps = request.urlopen("https://api.github.com/repos/" + url_type)
except urllib.error.HTTPError:
    print("Can't fetch resource")
else:
    data = reps.read()
    js = data.decode("UTF-8")
    value = json.loads(js)
    report()
