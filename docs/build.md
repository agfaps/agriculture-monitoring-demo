# How To Build

## Host Build

```sh
cd agriculture-monitoring
cmake -DTARGET_PLATFORM=host -B targets/host/build -DCMAKE_BUILD_TYPE=Debug
cmake --build targets/host/build
./targets/host/build/targets/host/host_simulator  # Run the host simulation
```
