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
REM g++ -std=c++17 -Wall -Wextra -pedantic -o testsArray.exe ..\code\SetArray.cpp ..\code\mainTests.cpp
REM g++ -std=c++17 -Wall -Wextra -pedantic -o testsArrayEspecific.exe ..\code\SetArray.cpp ..\code\mainTestsEspecific.cpp
g++ -std=c++17 -Wall -Wextra -pedantic -o testsVector.exe ..\code\SetVector.cpp ..\code\mainTests.cpp
g++ -std=c++17 -Wall -Wextra -pedantic -o testsVectorEspecific.exe ..\code\SetVector.cpp ..\code\mainTestsEspecific.cpp

echo.
echo.
echo -- All builds completed! --

REM jump back to original directory
popd
