# Verification of Capability-based-security
```
./wasi-sdk-mac/bin/clang --sysroot=./wasi-sdk-mac/share/wasi-sysroot/ github.com/chikuwait/wasi-sample/read.c -o read.wasm

./wasmtime-aarch64-mac/wasmtime read_and_write_sample.wasm sample_text output
Error Opening Input: Capabilities insufficient
Error Opening Output: Capabilities insufficient

./wasmtime-aarch64-mac/wasmtime --dir=. read_and_write_sample.wasm sample_text output
cat output
aaaaaaaaaaaaaaaaaaaaaaa
bbbbbbbbbb
aaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaa

./wasmtime-aarch64-mac/wasmtime --dir=. read_write.wasm sample_text /tmp/output
Error Opening Output: No such file or directory

./wasmtime-aarch64-mac/wasmtime --dir=. --dir=/tmp/ read_write.wasm sample_text /tmp/output

cat /tmp/output
aaaaaaaaaaaaaaaaaaaaaaa
bbbbbbbbbb
aaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaa

./wasmtime-aarch64-mac/wasmtime --dir=$PWD --dir=/tmp/ read_write.wasm sample_text /tmp/output
Error Opening Input: Capabilities insufficient

./wasmtime-aarch64-mac/wasmtime --dir=. --dir=/tmp/ read_write.wasm sample_text /tmp/../var/output
Error Opening Output: Operation not permitted

./wasmtime-aarch64-mac/wasmtime --dir=. --mapdir=/tmp::/var/tmp read_write.wasm sample_text /tmp/output
cat /var/tmp/output
aaaaaaaaaaaaaaaaaaaaaaa
bbbbbbbbbb
aaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaa
```
