from ctypes import *
import psutil

psapi = windll.psapi

array = c_ulong * 256

lpidProcess = array()

cb = sizeof (lpidProcess)

cbNeeded = c_ulong()

psapi.EnumProcesses(lpidProcess,cb,cbNeeded)

for i in lpidProcess :
    if i != 0 :
        process = psutil.Process(i)
        print(f"{i}\t{process.name()}\t{process.status()}")
