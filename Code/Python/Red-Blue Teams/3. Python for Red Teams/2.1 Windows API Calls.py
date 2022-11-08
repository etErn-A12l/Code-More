import ctypes
user_handle = ctypes.WinDLL("User32.dll")
kernel_handle = ctypes.WinDLL("Kernel32.dll")
def display() :
    user_input = input("Enter your Message : ")
    win_api_called = user_handle.MessageBoxW(None, user_input, "Python", 0x00000001)
    err = kernel_handle.GetLastError()
    
    if err != 0 :
        print(f"your error : {err}")
        
display()
