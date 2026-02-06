# Squirrel crypto trade bot

# Pakages list (tested on fedora)
gcc-c++ cmake git make ninja-build libcurl-devel websocketpp-devel
gtest-devel

# Download submodules
git submodule update --init --recursive

# Build
cmake -B build -G Ninja
cmake --build build 

