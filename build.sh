#!/usr/bin/env bash
set -e

BUILD_DIR="build"
BUILD_TYPE="Release"

# Optional: ./build.sh clean  -> wipes build/ first
# Needed if the project was ever moved/renamed on this machine,
# since CMakeCache.txt hardcodes absolute paths.
if [[ "$1" == "clean" ]]; then
    echo "Cleaning $BUILD_DIR..."
    rm -rf "$BUILD_DIR"
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

echo "Configuring..."
cmake -DCMAKE_BUILD_TYPE="$BUILD_TYPE" ..

echo "Building..."
cmake --build . -- -j"$(nproc)"

echo ""
echo "Build complete. Run the executable from $BUILD_DIR/"