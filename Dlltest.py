import ctypes
import time
import os

# Construct the path to the DLL
current_dir = os.path.dirname(__file__)
dll_path = os.path.join(current_dir, 'x64', 'release', 'logitech-cve.dll')

# Load the DLL
my_dll = ctypes.CDLL(dll_path)

# Assuming keyboard_open and keyboard_close take no arguments and return an int
my_dll.keyboard_open.argtypes = ()
my_dll.keyboard_open.restype = ctypes.c_int

my_dll.keyboard_close.argtypes = ()
my_dll.keyboard_close.restype = ctypes.c_int

# Call keyboard_open
open_result = my_dll.keyboard_open()
print(f"keyboard_open returned: {open_result}")

# Wait for a bit before closing the keyboard
time.sleep(5)

# Call keyboard_close
close_result = my_dll.keyboard_close()
print(f"keyboard_close returned: {close_result}")

exit(0)
