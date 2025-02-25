@echo off
chcp 65001
setlocal enabledelayedexpansion

:: 获取当前目录的绝对路径
set "CURRENT_DIR=%CD%"
set "OUTPUT_DIR=%CURRENT_DIR%\ok"

:: 检查必要文件是否存在
if not exist "1.txt" (
    echo 错误：1.txt 文件不存在！
    pause
    exit /b
)

if not exist "sfnttool.jar" (
    echo 错误：sfnttool.jar 文件不存在！
    pause
    exit /b
)

:: 创建基础输出目录
if not exist "%OUTPUT_DIR%" md "%OUTPUT_DIR%"

:: 递归处理所有ttf文件
for /r %%i in (*.ttf) do (
    :: 获取完整路径
    set "filepath=%%i"
    
    :: 获取相对路径
    set "relpath=!filepath:%CURRENT_DIR%=!"
    
    :: 设置输出路径
    set "outpath=%OUTPUT_DIR%!relpath!"
    set "outdir=%%~dpi"
    set "outdir=!outdir:%CURRENT_DIR%=%OUTPUT_DIR%!"
    
    :: 创建输出目录（使用完整路径）
    echo 创建目录: "!outdir!"
    if not exist "!outdir!" (
        md "!outdir!" 2>nul
    )
    
    :: 确保目录已创建后再处理文件
    if exist "!outdir!" (
        echo 处理: "!filepath!"
        echo 输出到: "!outpath!"
        java -jar sfnttool.jar -s "1.txt" "!filepath!" "!outpath!"
    ) else (
        echo 错误：无法创建目录 "!outdir!"
    )
)

echo 处理完成！
pause