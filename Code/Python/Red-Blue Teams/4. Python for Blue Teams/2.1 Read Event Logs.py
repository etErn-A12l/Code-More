import win32evtlog

log_server = "localhost"
log_type = 'System' #Application or Security
read_log = win32evtlog.OpenEventLog(log_server, log_type)
flags = win32evtlog.EVENTLOG_BACKWARDS_READ|win32evtlog.EVENTLOG_SEQUENTIAL_READ
while True :
    event_logs = win32evtlog.ReadEventLog(read_log, flags, 0)
    if event_logs:
        for event in event_logs:
            print ('Event Category : ', event.EventCategory)
            print ('Time generated : ', event.TimeGenerated)
            print ('Source Name : ', event.SourceName)
            print ('Event ID : ', event.EventID)
            print ('Event Type : ', event.EventType)
            print('--------------------------------------------')
