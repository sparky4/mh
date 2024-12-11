REM Set your MAKE tool here:
SET MAKETOOL=c:\z\borlandc\bin\make

REM REMEMBER! Make TLINK available through path
rem PATH c:\z\BORLANDC\BIN;%PATH%

%MAKETOOL% -f mhlist.mak %1
