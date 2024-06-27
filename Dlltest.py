import ctypes
import os

# Construct the path to the DLL
current_dir = os.path.dirname(__file__)
dll_path = os.path.join(current_dir, 'x64', 'release', 'logitech-cve.dll')

# Load the DLL
my_dll = ctypes.CDLL(dll_path)

# Define argument and return types for the functions you'll call
# This is an example assuming mouse_move takes four integers and returns void
my_dll.mouse_move.argtypes = (ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int)
my_dll.mouse_move.restype = None

# Example call to mouse_move
# Replace these arguments with what your function expects
button = 1  # Example button code
x = 100  # Example x position
y = 100  # Example y position
wheel = 0  # Example wheel movement
my_dll.mouse_move(button, x, y, wheel)

print("Called mouse_move")
