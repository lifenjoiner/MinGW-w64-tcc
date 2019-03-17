This is a mod of the MinGW-w64 to produce header files for tcc (Tiny C Compiler)

Tcc aims tiny piece of code, including dependencies and foot prints. And here we aims to leave the runtime codes unused, keeping the tcc runtime tiny. Do not mention that tcc doesn't support C++ ...

MinGW based means targeting Windows :)

For easier upstream commits merge, it keeps the whole MinGW-w64 structure and makes the least changes. More details: https://github.com/lifenjoiner/MinGW-w64-tcc

That focuses on folder 'mingw-w64-headers'. Run 'sh configure', 'make build' and maybe 'make install' just in this folder. Also you may organize the headers manually. A bat script example:
```
@echo off
if "$~1"=="" goto :EOF
if not exist %1 goto :EOF
pushd %1
xcopy crt\*.h ..\include\ /s /y /EXCLUDE:crt\stdio.h
xcopy crt\*.inl ..\include\ /s /y
xcopy defaults\include\*.h ..\include\ /s /y
xcopy include\*.h ..\include\winapi\ /s /y
xcopy ddk\include\*.h ..\include\winapi\ /s /y
xcopy direct-x\include\*.h ..\include\winapi\ /s /y
xcopy _mingw_ddk.h ..\include\sdks\ /y
xcopy _mingw_directx.h ..\include\sdks\ /y
popd
```

## Dependencies
MinGW-w64: https://git.code.sf.net/p/mingw-w64/mingw-w64

tcc: https://repo.or.cz/w/tinycc.git
