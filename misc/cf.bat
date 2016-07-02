@echo off
@echo 1>%1
@echo /*========================= > %1
@echo 	$File: $%1 >> %1
For /f "tokens=2-4 delims=/ " %%a in ('date /t') do (set mydate=%%c-%%a-%%b)
@echo 	$Date: $ %mydate% >> %1
@echo 	$Revision: $ >>%1
@echo 	$Creator: $Tomer Shaim >>%1
@echo 	================================*/>>%1