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
cmake -DTARGET_PLATFORM=host-test -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

## Build host simulation only

```sh
cd agriculture-monitoring
cmake -DTARGET_PLATFORM=host -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

when you check root/build then there will be targets and tests created and inside you will find both binaries built.

## ESP32x

It seems we have to use common build process for building esp32x based projects

```sh
cd agriculture-monitoring/targets/esp32-s3
source /home/agfaps/esp/v5.2.3/esp-idf/export.sh
idf.py set-target esp32s3
idf.py build
```

build folder for esp32x based project will be in targets/esp32xxx/build
