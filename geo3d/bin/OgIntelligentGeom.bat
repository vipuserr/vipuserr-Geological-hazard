@echo off
REM ***************************************************************************
REM    msvc-env.cmd
REM    ---------------------
REM    begin                : June 2018
REM    copyright            : (C) 2018 by Juergen E. Fischer
REM    email                : jef at norbit dot de
REM ***************************************************************************
REM *                                                                         *
REM *   This program is free software; you can redistribute it and/or modify  *
REM *   it under the terms of the GNU General Public License as published by  *
REM *   the Free Software Foundation; either version 2 of the License, or     *
REM *   (at your option) any later version.                                   *
REM *                                                                         *
REM ***************************************************************************

set ARCH=x86_64
set VCARCH=amd64
set OSGEO4W_ROOT=..\..\..\

rem Leo Add
set GDAL_FILENAME_IS_UTF8=YES
set VSI_CACHE=TRUE
set VSI_CACHE_SIZE=1000000
set JPEGMEM=1000000

set QGIS_PREFIX_PATH=%OSGEO4W_ROOT%\apps\qgis-ltr
set QT_PLUGIN_PATH=%OSGEO4W_ROOT%\apps\qgis-ltr\qtplugins;%OSGEO4W_ROOT%\apps\qt5\plugins
set GDAL_DATA=%OSGEO4W_ROOT%\share\gdal
set GDAL_DRIVER_PATH=%OSGEO4W_ROOT%\bin\gdalplugins
set GEOTIFF_CSV=%OSGEO4W_ROOT%\share\epsg_csv
set PROJ_LIB=%OSGEO4W_ROOT%\share\proj
set PYTHONHOME=%OSGEO4W_ROOT%\apps\Python37
set O4W_QT_PREFIX=%OSGEO4W_ROOT%\apps\Qt5
set O4W_QT_BINARIES=%OSGEO4W_ROOT%\apps\Qt5\bin
set O4W_QT_PLUGINS=%OSGEO4W_ROOT%\apps\Qt5\plugins
set O4W_QT_LIBRARIES=%OSGEO4W_ROOT%\apps\Qt5\lib
set O4W_QT_TRANSLATIONS=%OSGEO4W_ROOT%\apps\Qt5\translations
set O4W_QT_HEADERS=%OSGEO4W_ROOT%\apps\Qt5\include

rem Leo Add
path %Path%;%OSGEO4W_ROOT%\apps\geo3d\bin;%OSGEO4W_ROOT%\apps\qgis-ltr\bin;%OSGEO4W_ROOT%\apps\qt5\bin;%OSGEO4W_ROOT%\apps\Python37;%OSGEO4W_ROOT%\apps\Python37\Scripts;%OSGEO4W_ROOT%\bin;C:\Windows\system32;C:\Windows;C:\Windows\system32\WBem;%PF86%\Microsoft Visual Studio\2017\Enterprise\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64


if not "%ARCH%"=="x86" if not "%ARCH%"=="x86_64" (
	goto usage
)


if not exist "%OSGEO4W_ROOT%\bin\o4w_env.bat" (echo o4w_env.bat not found & goto error)
call "%OSGEO4W_ROOT%\bin\o4w_env.bat"
call "%OSGEO4W_ROOT%\bin\py3_env.bat"
call "%OSGEO4W_ROOT%\bin\qt5_env.bat"

if not "%PROGRAMFILES(X86)%"=="" set PF86=%PROGRAMFILES(X86)%
if "%PF86%"=="" set PF86=%PROGRAMFILES%
if "%PF86%"=="" (echo PROGRAMFILES not set & goto error)

set VS150COMNTOOLS=%PF86%\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\
call "%PF86%\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" %VCARCH%


set GRASS7=%OSGEO4W_ROOT%\apps\grass
if exist %OSGEO4W_ROOT%\bin\grass74.bat set GRASS7=%OSGEO4W_ROOT%\bin\grass74.bat
if exist %OSGEO4W_ROOT%\bin\grass76.bat set GRASS7=%OSGEO4W_ROOT%\bin\grass76.bat
if exist %OSGEO4W_ROOT%\bin\grass78.bat set GRASS7=%OSGEO4W_ROOT%\bin\grass78.bat
if "%GRASS7%"=="" (echo GRASS7 not found & goto error)
for /f "usebackq tokens=1" %%a in (`%GRASS7% --config path`) do set GRASS_PREFIX=%%a

set PYTHONPATH=%OSGEO4W_ROOT%\apps\Python37;%OSGEO4W_ROOT%\apps\Python37\Scripts
if exist "%PROGRAMFILES%\CMake\bin" path %PATH%;%PROGRAMFILES%\CMake\bin
if exist "%PF86%\CMake\bin" path %PATH%;%PF86%\CMake\bin
if exist c:\cygwin64\bin path %PATH%;c:\cygwin64\bin
if exist c:\cygwin\bin path %PATH%;c:\cygwin\bin


set LIB=%LIB%;%OSGEO4W_ROOT%\apps\Qt5\lib;%OSGEO4W_ROOT%\lib
set INCLUDE=%INCLUDE%;%OSGEO4W_ROOT%\apps\Qt5\include;%OSGEO4W_ROOT%\include



goto end

:usage
echo usage: %0 arch
echo sample: %0 x86_64
exit /b 1

:error
echo ENV ERROR %ERRORLEVEL%: %DATE% %TIME%
exit /b 1

:end
