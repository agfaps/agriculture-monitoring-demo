# How To Build

## Host Build

```sh
cd agriculture-monitoring
cmake -DTARGET_PLATFORM=host -B targets/host/build -DCMAKE_BUILD_TYPE=Debug
cmake --build targets/host/build
./targets/host/build/targets/host/host_simulator  # Run the host simulation
```

## Unit Test

```sh
cd agriculture-monitoring
cmake -B tests/build
cmake --build tests/build
./tests/build/tests/unit/StatusLed/StatusLedTests  # Run the host simulation
```

## The cmake and command actually build all (targets and tests)

```sh
cd agriculture-monitoring
cmake -DTARGET_PLATFORM=host -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

when you check root/build then there will be targets and tests created and inside you will find both binaries build.
