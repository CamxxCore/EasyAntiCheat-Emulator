# EasyAntiCheat-Emulator
Simple DLL that spoofs EasyAntiCheat on most games

** For Debugging Purposes Only **
- Simply provides a fake EAC interface to the game to make it believe EAC is loaded. Does nothing to spoof client- server communication

# Usage
Replace the EasyAntiCheat_(platform).dll that is inside the game files (typically inside a folder called EasyAntiCheat) with this one. Then replace the launcher with the actual game executable. Not tested on all games, depending on the game you may need to implement more interface functions.
