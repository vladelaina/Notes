;Ctrl	  ->	^
;Alt	  ->	!
;Shift -> +
;Windows	->	#
;==================================================================

#w::
    SetTimer, wezterm, -1
return

wezterm:
    Run, "D:\Date\Software\Ifrequently used\WezTerm\wezterm-gui.exe"

return

;==================================================================

^!/::
    SetTimer, lexclip, -1
return

lexclip:
    Run, "E:\MD\MD\Code\LexClip\LexClip .exe"

return


;==================================================================

^!d::
    SetTimer, do, -1

return

do:
    Run, "E:\MD\MD\Develop\Language\C\README.md"
return

;==================================================================

+!c::
    SetTimer, Chrome, -1

return

Chrome:
    Run, "C:\Program Files\Google\Chrome\Application\chrome.exe"
return

;==================================================================

^+g::
    SetTimer, geek, -1
return

geek:
    Run, "D:\Date\Tool\geek.exe"
return

;==================================================================

^!b::
    SetTimer, bilibili, -1
return

bilibili:
    Run, chrome.exe "https://space.bilibili.com/1862395225/favlist?fid=3228957325&ftype=create"
return

;==================================================================


^!c::
    SetTimer, chatgpt, -1
return

chatgpt:
    Run, chrome.exe --app="https://chat1.oaichat.cc/"
    WinWaitActive, ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe
    ; 将窗口移动到屏幕右侧
    WinMove, ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe,, 0, 0, 960, 1080 ; 将窗口移动到 X=1120, Y=100，宽度800，高度600
return



 

;==================================================================



^!+c::
    SetTimer, Calendar, -1
return

Calendar:
    Run, chrome.exe --app="https://calendar.notion.so"
    WinWaitActive, ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe
    ; 将窗口移动到屏幕右侧
    WinMove, ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe,, 0, 0, 960, 1080 ; 将窗口移动到 X=1120, Y=100，宽度800，高度600
return

;==================================================================


;^!f::
 ;   SetTimer, feishu, -1
;return

;feishu:
 ;   Run, chrome.exe --app="https://k021q39fc0u.feishu.cn/minutes/home/"
;return

;==================================================================

^!g::
    SetTimer, github, -1
return

github:   
    Run, chrome.exe "https://github.com/vladelaina?tab=repositories"   
return

;==================================================================

^!k::
    SetTimer, kimi, -1
return

kimi:
    Run, chrome.exe --app="https://kimi.moonshot.cn/"
return

;==================================================================

^!r::
    SetTimer, read, -1
return

read:
    Run, chrome.exe --app="https://zh-cn.text-to-speech.online/"

 ;   WinWaitActive, ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe

     ; 其中, -1920 表示将窗口移动到左侧显示器的左上角，129 为窗口的 Y 坐标，1920 为宽度，1080 为高度
  ;  WinMove, ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe,, -1920, 129, 1600, 1080
return


;==================================================================

^!u::
    SetTimer, uutool, -1
return

uutool:
    Run, chrome.exe --app="https://uutool.cn/extract-word/"
return

;==================================================================

+^!y::
    SetTimer, ywyj, -1
return

ywyj:
    Run, chrome.exe "https://ywyj.cn/"   
return

;==================================================================

^!q::
    SetTimer, Startup, -1
return

Startup:
	Run, "C:\Users\vladelaina\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup"
return

;==================================================================

^!y::
    SetTimer, youtube, -1
return

youtube:
    Run, chrome.exe "https://www.youtube.com/"
return

;==================================================================
;catim
;==================================================================

^!l::
    SetTimer, livelyWallpaper, -1
return

livelyWallpaper:
	Run, "C:\Users\vladelaina\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\Lively.lnk"
    ; 等待 Lively Wallpaper 启动并出现窗口
    WinWait, Lively Wallpaper
    ; 将窗口移动并调整大小到指定的坐标
    WinMove, Lively Wallpaper, , 405, 85, 114, 914
return


;==================================================================

^!w::
    SetTimer, w, -1
return

w:
	Run, "E:\"
return


;==================================================================


^!t::
    SetTimer, OpenTyporaFullScreen, -10
return

OpenTyporaFullScreen:
    Run, "D:\Date\Software\Ifrequently used\Typora\Typora.exe"
    WinWaitActive, Typora
    WinMaximize, Typora
return



;==================================================================

^!s::
    SetTimer, s, -1
return

s:
	Run, "D:\Date"
return

;==================================================================

Delete::
    SetTimer, autosave, -1
return

autosave:
	Run, "C:\Users\vladelaina\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\Autosave.bat.lnk"
return

;==================================================================


^!1::
    SetTimer, md, -1
return

md:
	Run, "E:\MD\MD"
return

;==================================================================


^!j::
    SetTimer, jj, -1
return

jj:
	Run, "D:\Date\Software\Ifrequently used\bilidown\bilidown.exe"
return

;==================================================================


!^a::
    SetTimer,aly, -10
return


aly:
    Run, chrome.exe --app="https://www.aliyundrive.com/drive/file/all"
    WinWaitActive, ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe
    ; 将窗口移动到屏幕右侧
    WinMove, ahk_class Chrome_WidgetWin_1 ahk_exe chrome.exe,, 0, 0, 960, 1080 ; 将窗口移动到 X=1120, Y=100，宽度800，高度600
return


;==================================================================


^!m::
    SetTimer,mopenspotify, -10
return


mopenspotify:
    Run, chrome.exe --app="https://open.spotify.com/"
return
;==================================================================


^!f::
    SetTimer, feishu, -1
return

feishu:
    Run, chrome.exe --app="https://k021q39fc0u.feishu.cn/minutes/home/"
return

;==================================================================

