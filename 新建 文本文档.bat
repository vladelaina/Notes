%~d0			
cd %~dp0
git add ./
git commit -m "Autosave: %date:~0,10% %time:~0,-3%"
git push

timeout /t 3