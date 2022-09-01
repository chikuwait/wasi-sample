```
./wasi-sdk-mac/bin/clang --sysroot=./wasi-sdk-mac/share/wasi-sysroot/ github.com/chikuwait/wasi-sample/read.c -o read.wasm
./wasmtime-aarch64-mac/wasmtime --dir=. read.wasm
```