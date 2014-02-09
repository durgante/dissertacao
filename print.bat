@ECHO OFF

:INIT
::Nome do arquivo
IF "%1"=="" SET NOME=dissertacao
IF NOT "%1"=="" SET NOME=%1
::Leitor de pdf
::set DIR="C:\Program Files (x86)\SumatraPDF\SumatraPDF.exe"
set DIR="SumatraPDF.exe"
set VERSAO="Dissertacao_v5.01"

:MODO
::Texto cont�m apenas figuras .eps
set LBL=txfy
::Texto cont�m figuras .pdf
::set LBL=pdfltx

IF %LBL%==pdfltx GOTO LTX

:TXF
::Monta tex
texify %NOME%.tex
::Gera bibliografia
bibtex %NOME%
::Monta tex
texify %NOME%.tex
::Monta tex
texify %NOME%.tex

::Prepara impress�o de pdf
dvips -Ppdf -t a4 %NOME%
set GS_OPTIONS=-dMaxSubsetPct=100
set GS_OPTIONS=-dSubsetFonts=true
set GS_OPTIONS=-dEmbedAllFonts=true
set GS_OPTIONS=-dCompatibilityLevel=1.2
set GS_OPTIONS=-sPAPERSIZE=a4

::Imprime pdf
ps2pdf %NOME%.ps %VERSAO%.pdf
GOTO OPEN

:LTX
::Gera bibliografia
bibtex %NOME%
::Monta tex
pdflatex %NOME%.tex
::Gera bibliografia
bibtex %NOME%
::Monta tex
pdflatex %NOME%.tex

:OPEN
::Abre documento
start %DIR% %VERSAO%.pdf

:CLEANUP
::DEL *.aux *.bbl *.blg *.dvi *.log *.nav *.out *.ps *.snm *.bak *.toc *.lot *.lof
set NOME=
set DIR=
set PROC=
set VAR=
set VERSAO=
