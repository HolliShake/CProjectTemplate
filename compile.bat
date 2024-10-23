@echo off
echo [Console]::OutputEncoding = [Text.UTF8Encoding]::UTF8
gcc -g app.c ./core/*.c ./core/libgc/*.c ./core/utf/*.c ./core/utf/utf8proc/*.c -o app.exe