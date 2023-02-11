import subprocess
import re

res = subprocess.run(["wmic", "process", "list"],stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

lines = res.stdout.splitlines()

for i in lines :
    if re.search("vm",i):
        print(re.sub(' +', ' ', i))
