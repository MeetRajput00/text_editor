@echo off
g++ ../text_editor.cpp ../src/CustomWindow.cpp ../src/Text.cpp ../src/Cursor.cpp -o ../bin/release/text_editor.exe -lsfml-system -lsfml-graphics -lsfml-window