import time
import os
import win32api
import win32evtlog
log_type = "Application"

log_name = time.strftime("%Y%M%d",time.localtime(time.time())) + log_type + ".evt"

header_log = win32evtlog.OpenEventLog(None,log_type)

if win32evtlog.GetNumberOfEventLogRecords(header_log) ==0 :
    print("No records")
    
else :
    win32evtlog.ClearEventLog(header_log, log_name)
    win32evtlog.CloseEventLog(header_log)
    print("OK")
