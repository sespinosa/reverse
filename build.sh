# Compile the binary to the bin directory.
mkdir -p bin
zig cc src/reverse.c -o bin/reverse

# Compile the wasm to the wasm directory.
mkdir -p wasm
zig cc -target wasm32-wasi src/reverse.c -o wasm/reverse.wasm