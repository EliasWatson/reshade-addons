@echo off

REM Create build directories if they don't exist
if not exist "build" (mkdir "build")
if not exist "build\x86" (mkdir "build\x86")
if not exist "build\x64" (mkdir "build\x64")

REM Generate build files
cmake . -A Win32 -B "build\x86"
cmake . -A x64 -B "build\x64"

REM Build the addon
cmake --build build\x86 --config Release
cmake --build build\x64 --config Release

REM Copy the addon to a convenient location and rename it to .addon
copy build\x86\Release\TextureTools.dll build\TextureTools_x86.addon
copy build\x64\Release\TextureTools.dll build\TextureTools_x64.addon
