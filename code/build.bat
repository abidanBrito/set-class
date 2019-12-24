@echo off

REM create build directory
IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

echo.
echo - Build directory created.
echo.
echo - Initiating specified builds....
echo.

echo -----------------------
echo // COMPILER WARNINGS //
echo -----------------------

REM compile and link and generate executable file
REM g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasArray.exe ..\code\ConjuntoArray.cpp ..\code\mainPruebas.cpp
REM g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasEspecificasArray.exe ..\code\ConjuntoArray.cpp ..\code\mainPruebasEspecificas.cpp
g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasVector.exe ..\code\ConjuntoVector.cpp ..\code\mainPruebas.cpp
g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasEspecificasVector.exe ..\code\ConjuntoVector.cpp ..\code\mainPruebasEspecificas.cpp

echo.
echo.
echo -- All builds completed! --

REM jump back to original directory
popd
