#!/usr/bin/env sh
set -e



if [ -z "$NDK_ROOT" ] && [ "$#" -eq 0 ]; then
     echo "Applying desktop version without NDK_ROOT"
     DESKTOP="1"
else
    NDK_ROOT="${1:-${NDK_ROOT}}"
    DESKTOP="0"
fi


ANDROID_ABI=${ANDROID_ABI:-"armeabi-v7a with NEON"}
MYPWD=`pwd`
N_JOBS=${N_JOBS:-4}

BUILD_DIR=${MYPWD}/build


rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"
if [ "$DESKTOP" = "0"  ]; then

cmake -DCMAKE_TOOLCHAIN_FILE="${MYPWD}/android.toolchain.cmake" \
      -DANDROID_NDK="${NDK_ROOT}" \
      -DCMAKE_BUILD_TYPE=Release \
      -DANDROID_ABI="${ANDROID_ABI}" \
      -DANDROID_NATIVE_API_LEVEL=21 \
      -DANDROID_USE_OPENMP=ON \
      ..
else 
 cmake ..
fi

make -j${N_JOBS}

cd "${PWD}"
