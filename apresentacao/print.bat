@ECHO OFF

:INIT
::Nome do arquivo
IF "%1"=="" SET NOME=slides
IF NOT "%1"=="" SET NOME=%1
::Leitor de pdf
::set DIR="C:\Program Files (x86)\SumatraPDF\SumatraPDF.exe"
set CUR_DIR="%CD%"
set CASA="D:\Dropbox\Trabalho\Dissertacao"
set UNIPAMPA="C:\Users\marcelodurgante\Desktop\Dropbox\Trabalho\Dissertacao"
set NOTEBOOK="C:\Users\Marcelo\Desktop\Dropbox\Trabalho\Dissertacao"
IF exist %CASA% set PLACE=%CASA%
IF exist %UNIPAMPA% set PLACE=%UNIPAMPA%
IF exist %NOTEBOOK% set PLACE=%NOTEBOOK%
::IF exist %CASA% ( CD %CASA% ) ELSE ( CD %UNIPAMPA% )
::Atualiza as figuras antes de compilar
::IF exist %CASA% (CALL %CASA%\matlab\gerar_figuras\atualizar_figuras.bat) ELSE (CALL %UNIPAMPA%\matlab\gerar_figuras\atualizar_figuras.bat)
IF exist %PLACE% CALL %PLACE%\matlab\gerar_figuras\atualizar_figuras.bat
::CD "C:\Users\marcelodurgante\Desktop\Dropbox\Trabalho\Dissertacao"
set DIR="SumatraPDF.exe"
set VERSAO="slides"

:TXF
::Monta tex
::texify %NOME%.tex
::texify %NOME%.tex
bibtex %NOME%
lualatex %NOME%.tex
::lualatex -jobname %VERSAO% %NOME%.tex
::pdflatex -job-name=%VERSAO% -shell-escape %NOME%.tex
::Gera bibliografia
bibtex %NOME%

::Prepara impressão de pdf
::dvips -Ppdf %NOME%
::set GS_OPTIONS=-dMaxSubsetPct=100
::set GS_OPTIONS=-dSubsetFonts=true
::set GS_OPTIONS=-dEmbedAllFonts=true
::set GS_OPTIONS=-dCompatibilityLevel=1.2
::set GS_OPTIONS=-sPAPERSIZE=a4

::Imprime pdf
::ps2pdf %NOME%.ps %VERSAO%.pdf

:OPEN
::Abre documento
start %DIR% %VERSAO%.pdf
CD "%CUR_DIR%"

:CLEANUP
::DEL *.aux *.bbl *.blg *.dvi *.log *.nav *.out *.ps *.snm *.bak *.toc *.lot *.lof
set CUR_DIR=
set CASA=
set UNIPAMPA=
set NOME=
set DIR=
set PROC=
set VAR=
set VERSAO=
