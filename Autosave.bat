%~d0			
cd %~dp0
git add ./
git commit -m "%date:~0,10% %time:~0,-3%"
git push
