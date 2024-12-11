REM Set your MAKE tool here:
SET MAKETOOL=\z\borlandc\bin\make

REM REMEMBER! Make TLINK available through path
rem PATH %PATH%;\z\BORLANDC\BIN

%MAKETOOL% -f hw.mak %1
