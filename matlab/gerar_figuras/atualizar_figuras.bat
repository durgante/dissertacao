@ECHO OFF

set UNIPAMPA=C:\Users\marcelodurgante\Desktop\Dropbox\Trabalho\Dissertacao
set CASA=D:\Dropbox\Trabalho\Dissertacao
set NOTEBOOK=C:\Users\Marcelo\Desktop\Dropbox\Trabalho\Dissertacao

IF exist %CASA% set PLACE=%CASA%
IF exist %UNIPAMPA% set PLACE=%UNIPAMPA%
IF exist %NOTEBOOK% set PLACE=%NOTEBOOK%

IF exist %PLACE% set gerar_figuras=%PLACE%\matlab\gerar_figuras&& set img=%PLACE%\img

xcopy "%gerar_figuras%\*.tex" "%img%\*.tex" /e /k /y /d