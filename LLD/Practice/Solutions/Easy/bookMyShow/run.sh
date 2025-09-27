#!/bin/bash

echo "🔧 Compiling bookMyShow..."
g++ -std=c++17 -o bookMyShow main.cpp

if [ $? -eq 0 ]; then
    echo "✅ Compilation successful!"
    echo "🚀 Running bookMyShow..."
    ./bookMyShow
else
    echo "❌ Compilation failed!"
    exit 1
fi
