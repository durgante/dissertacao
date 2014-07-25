@ECHO OFF

set UNIPAMPA=C:\Users\marcelodurgante\Desktop\Dropbox\Trabalho\Dissertacao
set CASA=D:\Dropbox\Trabalho\Dissertacao

IF exist %UNIPAMPA% ( set gerar_figuras=%UNIPAMPA%\matlab\gerar_figuras&& set img=%UNIPAMPA%\img) ELSE ( set gerar_figuras=%CASA%\matlab\gerar_figuras&& set img=%CASA%\img)

xcopy "%gerar_figuras%\*.tex" "%img%\*.tex" /e /k /y /d