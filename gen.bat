set d=build
rd /s /q %d%
md %d% && cd %d% && cmake -G "Visual Studio 15 2017 Win64" ..
pause