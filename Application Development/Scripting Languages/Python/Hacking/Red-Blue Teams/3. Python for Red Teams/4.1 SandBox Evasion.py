from ctypes import Structure, c_int32, c_uint64, sizeof, byref, windll
class MemoryStatusEx(Structure) :
    _fields_ = [
        ('length', c_int32),
        ('memoryLoad', c_int32),
        ('totalPhys', c_uint64),
        ('availPhys', c_uint64),
        ('totalPageFile', c_uint64),
        ('availPageFile', c_uint64),
        ('totalVirtual', c_uint64),
        ('availVirtual', c_uint64),
        ('availExtendedVirtual', c_uint64)
    ]
    def __init__ (self):
        self.length = sizeof(self)
        
memory = MemoryStatusEx()
windll.kernel32.GlobalMemoryStatusEx(byref(memory))

result = memory.totalPhys / (1024) ** 3
if result > 4.0 :
    print("Sandbox")
#print("%0.2f" % (memory.totalPhys / (1024) ** 3) + "GB RAM")
