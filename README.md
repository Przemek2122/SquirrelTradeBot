# Squirrel trade bot
# This is my personal bot for crypto trading (or more like learning this)

# Pakages list
# Used on fedora so other distributions are untested
gcc-c++ cmake git make ninja-build libcurl-devel websocketpp-devel
gtest-devel

# Download submodules
git submodule update --init --recursive

# Build
cmake -B build -G Ninja
cmake --build build 

