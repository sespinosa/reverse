# Compile the binary to the bin directory.
mkdir -p bin
zig cc -Os src/reverse.c -o bin/reverse

# Compile the wasm to the wasm directory.
mkdir -p wasm
zig cc -Os -target wasm32-wasi src/reverse.c -o wasm/reverse.wasm
