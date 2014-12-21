SRCPATH=.
prefix=/home/retsu/FFmpeg-Android/jni/x264/../ffmpeg-build/armeavi-v7a-neon
exec_prefix=${prefix}
bindir=${exec_prefix}/bin
libdir=${exec_prefix}/lib
includedir=${prefix}/include
ARCH=ARM
SYS=LINUX
CC=/home/retsu/android-ndk/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86/bin/arm-linux-androideabi-gcc --sysroot=/home/retsu/android-ndk/platforms/android-9/arch-arm/
CFLAGS=-Wshadow -O3 -fno-fast-math -mfloat-abi=softfp -mfpu=neon -marm -march=armv7-a -mtune=cortex-a8 -mthumb -D__thumb__  -Wall -I. -I$(SRCPATH) -std=gnu99  -I../ffmpeg-build/armeabi-v7a/include   -fomit-frame-pointer -fno-tree-vectorize
DEPMM=-MM -g0
DEPMT=-MT
LD=/home/retsu/android-ndk/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86/bin/arm-linux-androideabi-gcc --sysroot=/home/retsu/android-ndk/platforms/android-9/arch-arm/ -o 
LDFLAGS=-Wl,-rpath-link=/home/retsu/android-ndk/platforms/android-9/arch-arm//usr/lib -L/home/retsu/android-ndk/platforms/android-9/arch-arm//usr/lib  -lc -lm -ldl -llog -lm -ldl
LIBX264=libx264.a
AR=/home/retsu/android-ndk/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86/bin/arm-linux-androideabi-ar rc 
RANLIB=/home/retsu/android-ndk/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86/bin/arm-linux-androideabi-ranlib
STRIP=/home/retsu/android-ndk/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86/bin/arm-linux-androideabi-strip
INSTALL=install
AS=/home/retsu/android-ndk/toolchains/arm-linux-androideabi-4.6/prebuilt/linux-x86/bin/arm-linux-androideabi-gcc --sysroot=/home/retsu/android-ndk/platforms/android-9/arch-arm/
ASFLAGS= -DHAVE_ALIGNED_STACK=1 -mfloat-abi=softfp -mfpu=neon -marm -march=armv7-a -mtune=cortex-a8 -mthumb -D__thumb__  -Wall -I. -I$(SRCPATH) -std=gnu99 -c -DHIGH_BIT_DEPTH=0 -DBIT_DEPTH=8
RC=
RCFLAGS=
EXE=
HAVE_GETOPT_LONG=1
DEVNULL=/dev/null
PROF_GEN_CC=-fprofile-generate
PROF_GEN_LD=-fprofile-generate
PROF_USE_CC=-fprofile-use
PROF_USE_LD=-fprofile-use
HAVE_OPENCL=yes
default: cli
install: install-cli
default: lib-static
install: install-lib-static
LDFLAGSCLI = -ldl  -L../ffmpeg-build/armeabi-v7a/lib -lswscale -lavutil -lm   
CLI_LIBX264 = $(LIBX264)
