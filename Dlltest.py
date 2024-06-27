import ctypes
import time
import os

# Construct the path to the DLL
current_dir = os.path.dirname(__file__)
dll_path = os.path.join(current_dir, 'x64', 'release', 'logitech-cve.dll')

# Load the DLL
my_dll = ctypes.CDLL(dll_path)

# Set up press_key function
my_dll.press_key.argtypes = (ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int)
# press_key returns void, so no restype is needed
my_dll.release_key.argtypes = ()
# Check if the keyboard is found
found_result = my_dll.found_keyboard()
print(f"found_keyboard returned: {found_result}")

# Example call to press_key
# Replace these values with the actual key codes you want to send
my_dll.press_key(0x0B, 0,0,0,0,0) # Press the 'H' key
my_dll.press_key(0x08, 0,0,0,0,0) # Press the 'E' key
my_dll.release_key()

# Wait for a bit
time.sleep(5)

exit(0)
