SET VERSION=1.13.2
doxygen CppUnit-win.dox
xcopy FAQ html /Y

@echo Warnings:
@type CppUnit-dox.log
