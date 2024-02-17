# reverse

Simple program that receives lines of strings via stdin and outputs the string reverted.

for example:

```
echo "Hello" | ./bin/reverse
```
returns:
```
olleH
```

## Options
Currently, the only option available is -v (verbose), this prints the output with the original word and an arrow to the reversed word (`{original string} -> {reversed string}`):

```
echo "Hello" | ./bin/reverse -v
Hello -> olleH
```

## Build requirements.

You need [zig](https://ziglang.org/) installed to build this using the `./build.sh` script.

```
./build.sh
```

This builds the [ELF](https://en.wikipedia.org/wiki/Executable_and_Linkable_Format) binary and the [wasm32-wasi](https://wasi.dev/) binary (in `./bin` and `./wasm`).

## Running the WASI module

This can be run with any capable runtime available (Rust, Go, Node, etc), but I personally recommend using [wasmtime](https://wasmtime.dev/), for example:

```
echo "Hello" | wasmtime ./wasm/reverse.wasm
```
also returns:
```
olleH
```

## Test

I provide a list of words to reverse (97565 words, one per line in `./test-data/common-words.txt`) so you can test it against a long list of words like this,

with the ELF binary:
```
cat ./test-data/common-words.txt | ./bin/reverse
```

and the wasm32-wasi binary:
```
cat ./test-data/common-words.txt | wasmtime ./wasm/reverse.wasm
```

## Motivation

This is just a experiment to see how `wasi` behaves when there's `backpressure` involved and also to have a reference implementation of a simple algorithm in `C` trying to follow some `POSIX` conventions.