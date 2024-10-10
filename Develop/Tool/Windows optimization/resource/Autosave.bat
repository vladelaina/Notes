@echo off
cd /d E:\MD\MD 
git add ./
for /f "delims=" %%i in ('git commit -m "%date:~0,10% %time:~0,-3%" 2^>^&1') do (
    echo %%i | findstr /C:"nothing to commit, working tree clean" >nul
    if not errorlevel 1 exit /b
)
git push

:: 添加提示窗
echo 操作完成，按任意键退出...
pause >nul
