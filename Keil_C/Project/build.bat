@echo off
echo ==============================================
echo Building 31392 Project...
echo ==============================================
"D:\keil\core\UV4\UV4.exe" -b "%~dp031392.uvproj" -j0 -o "%~dp0build.log"
type "%~dp0build.log"
echo Converting OMF to Intel HEX...
"D:\keil\core\C51\BIN\OHX51.EXE" "%~dp0..\Output\31392"
if exist "%~dp0..\Output\31392.hex" (
    echo [SUCCESS] 31392.hex generated successfully!
) else (
    echo [ERROR] 31392.hex generation failed!
)
