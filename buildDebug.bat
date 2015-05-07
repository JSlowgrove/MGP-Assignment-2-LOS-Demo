call C:\SDKs\android-ndk-r10d\ndk-build.cmd -j8
IF %ERRORLEVEL% NEQ 0 (
	pause
) else (
	call ant debug
)