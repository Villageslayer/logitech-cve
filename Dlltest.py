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

# Set up press_key function
my_dll.press_key.argtypes = (ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int)
# press_key returns void, so no restype is needed

# Call keyboard_open
open_result = my_dll.keyboard_open()
print(f"keyboard_open returned: {open_result}")
found_result = my_dll.found_keyboard()
print(f"keyboard_open returned: {found_result}")
# Example call to press_key
# Replace these values with the actual key codes you want to send
my_dll.press_key(0x0B, 0x08, 0x0F, 0x0F, 0x12,0)


# Wait for a bit before closing the keyboard
time.sleep(5)

# Call keyboard_close
close_result = my_dll.keyboard_close()
print(f"keyboard_close returned: {close_result}")

time.sleep(5)
exit(0)
