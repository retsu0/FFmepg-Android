execue following commands in this directory:

export NDK=/home/retsu/android-ndk
export NDK_ARCH=linux-x86
cp -vR libogg/include/ogg/ libvorbis/include/

edit "build_android.sh":
replace "NDK_TOOLCHAIN" with correct value (ex: 4.6 for Android NDK 8c)
also unmark #build_x264 in "build_all"

./build_android
$NDK/ndk-build
