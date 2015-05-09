"# This is my README"  
  
Created by Jamie Slowgrove.  
You can do what you want with the code and in this project, however you must credit me and add a link back to the git repository.  
  
Created using SDL2, SDL2_image, SDL2_mixer, SDL2_ttf, Android NDK and the Android SDK:  
https://www.libsdl.org/  
https://www.libsdl.org/projects/SDL_image/  
https://www.libsdl.org/projects/SDL_mixer/   
https://www.libsdl.org/projects/SDL_ttf/  
https://developer.android.com/tools/sdk/ndk/index.html  
https://developer.android.com/sdk/index.html  
  
Required steps to build on your computer:  
  
Inside the jni folder you must add the following folders:  
-SDL2, Containing the source code for SDL2.  
-SDL2_image, Containing the source code for SDL2_image.  
-SDL2_ttf, Containing the source code for SDL2_ttf.  
-SDL2_mixer, Containing the source code for SDL2-Mixer.  
  
Inside local.properties modify to the following:  
sdk.dir="Computer's Android SDK path location"  
ndk.dir="Computer's Android NDK path location"  
  
Inside buildDebug.bat modify the following:  
"C:\SDKs\android-ndk-r10d\ndk-build.cmd" to "Computer's Android NDK path location\ndk-build.cmd"  
  
Inside deployDebug.bat modify the following:  
"C:/Users/Jamie/AppData/Local/Android/android-sdk/platform-tools/adb.exe"   
to "Computer's Android SDK path location/adb.exe"    
  
Asset References:  
  
Music:  
"Cut Trance" Kevin MacLeod (incompetech.com)   
Licensed under Creative Commons: By Attribution 3.0  
http://creativecommons.org/licenses/by/3.0/  
  
Underdog Font:  
http://www.dafont.com/underdog.font?l[]=10    
  
This is the code for my second MGP Assignment Line Of Sight Demo.  