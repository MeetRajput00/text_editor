@echo off
g++ ../text_editor.cpp ../src/CustomWindow.cpp -o ../bin/release/text_editor.exe -lsfml-system -lsfml-graphics -lsfml-window