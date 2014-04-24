@ECHO OFF

set gerar_figuras=C:\Users\marcelodurgante\Desktop\Dropbox\Trabalho\Dissertacao\matlab\gerar_figuras
set img=C:\Users\marcelodurgante\Desktop\Dropbox\Trabalho\Dissertacao\img

xcopy "%gerar_figuras%\*.tex" "%img%\*.tex" /e /k /y /d