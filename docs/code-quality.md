# Code Quality

hmm.. interesting to see coverage analysis, cyclomatic complexity check, run using valgrind to check memory leak, and if possible add CodeQL from github locally (we run the test locally without github actions, etc).

ChatGPT said:
Memory updated

That's a great set of tools for improving code quality! Here's how you can integrate each of them into your local development workflow:

## 1. Coverage Analysis (gcov & lcov)

You can enable code coverage using `gcov`, `lcov`, and `genhtml` to generate reports.

### Modify `CMakeLists.txt` to Enable Coverage

```cmake
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    option(CODE_COVERAGE "Enable code coverage" ON)
    if(CODE_COVERAGE)
        add_compile_options(--coverage)
        add_link_options(--coverage)
    endif()
endif()
```

### Run Tests with Coverage

```sh
cd build
cmake -DCODE_COVERAGE=ON ..
make
ctest
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_report
```

Then open `coverage_report/index.html` in a browser.

### Example in tests

From top level/root folder:

```sh
cmake -DTARGET_PLATFORM=host -B build -DCMAKE_BUILD_TYPE=Debug -DCODE_COVERAGE=ON
cmake --build build
cd build/tests/integration/LedController
./LedControllerTests
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_report
```

Go to `coverage_report` folder, right click index.html and choose `Show Preview`.  
You might need Extension: `Live Preview` from Microsoft.

Check this [link](https://chatgpt.com/c/67b83126-7a0c-800b-b98a-7f063b411e92) for automating coverage tests and put minimum thresold.

## 2. Cyclomatic Complexity Analysis (~~cppcheck~~ -> lizard)

EDIT: use lizard.  
[HISTORY](https://chatgpt.com/c/67b83dc4-86e8-800b-8186-a4171c256d4e)

### Install lizard

```sh
pip install lizard
```

Execute script:

```sh
bash scripts/check_complexity.sh
```

output passed or not:

```sh
✅ Complexity check passed!
```

If you want raw output from top level:

```sh
$ lizard src/
================================================
  NLOC    CCN   token  PARAM  length  location  
------------------------------------------------
       1      1     24      1       1 ActivityLed::ActivityLed@3-3@src/ActivityLed/ActivityLed.cpp
       3      1     11      0       7 ActivityLed::pulseActivity@5-11@src/ActivityLed/ActivityLed.cpp
       3      1     11      0       4 ActivityLed::update@13-16@src/ActivityLed/ActivityLed.cpp
       5      1     24      1      15 AgricultureMonitoring::AgricultureMonitoring@5-19@src/app/AgricultureMonitoring.cpp
      10      2     43      0      41 AgricultureMonitoring::run@21-61@src/app/AgricultureMonitoring.cpp
       3      1     34      2       3 BaseLed::BaseLed@10-12@src/include/BaseLed.hpp
       4      1     16      0       4 BaseLed::turnOn@16-19@src/include/BaseLed.hpp
       4      1     16      0       4 BaseLed::turnOff@21-24@src/include/BaseLed.hpp
       4      1     18      0       4 BaseLed::toggle@26-29@src/include/BaseLed.hpp
       1      1      9      0       1 BaseLed::getState@32-32@src/include/BaseLed.hpp
       1      1      9      0       1 BaseLed::getName@34-34@src/include/BaseLed.hpp
       1      1     22      1       1 StatusLed::StatusLed@10-10@src/include/StatusLed.hpp
       1      1     22      1       1 Led::Led@9-9@src/include/Led.hpp
       4      1     16      0       4 Led::turnOn@13-16@src/include/Led.hpp
       4      1     16      0       4 Led::turnOff@18-21@src/include/Led.hpp
       4      1     18      0       4 Led::toggle@23-26@src/include/Led.hpp
       1      1      9      0       1 Led::isOn@28-28@src/include/Led.hpp
       9      2     44      0       9 StatusLed::init@5-13@src/StatusLed/StatusLed.cpp
       4      1     16      1       4 StatusLed::set@15-18@src/StatusLed/StatusLed.cpp
       1      1     24      1       1 ConnectivityLed::ConnectivityLed@3-3@src/ConnectivityLed/ConnectivityLed.cpp
       8      2     30      1       8 ConnectivityLed::setConnectionStatus@5-12@src/ConnectivityLed/ConnectivityLed.cpp
       3      1     11      0       3 ConnectivityLed::isConnected@14-16@src/ConnectivityLed/ConnectivityLed.cpp
       6      1     40      2       6 LedController::LedController@3-8@src/LedController/LedController.cpp
       3      1     16      1       3 LedController::setConnected@10-12@src/LedController/LedController.cpp
       3      1     13      0       3 LedController::pulseActivity@14-16@src/LedController/LedController.cpp
       3      1     15      0       3 LedController::getConnectionStatus@18-20@src/LedController/LedController.cpp
14 file analyzed.
==============================================================
NLOC    Avg.NLOC  AvgCCN  Avg.token  function_cnt    file
--------------------------------------------------------------
      8       2.3     1.0       15.3         3     src/ActivityLed/ActivityLed.cpp
     18       7.5     1.5       33.5         2     src/app/AgricultureMonitoring.cpp
     28       2.8     1.0       17.0         6     src/include/BaseLed.hpp
     12       1.0     1.0       22.0         1     src/include/StatusLed.hpp
     23       2.8     1.0       16.2         5     src/include/Led.hpp
      7       0.0     0.0        0.0         0     src/include/ActivityLed.hpp
      6       0.0     0.0        0.0         0     src/include/ILedHardware.hpp
     16       0.0     0.0        0.0         0     src/include/LedController.hpp
      9       0.0     0.0        0.0         0     src/include/ConnectivityLed.hpp
     11       0.0     0.0        0.0         0     src/include/AgricultureMonitoring.hpp
     16       6.5     1.5       30.0         2     src/StatusLed/StatusLed.cpp
     13       4.0     1.3       21.7         3     src/ConnectivityLed/ConnectivityLed.cpp
     10       0.0     0.0        0.0         0     src/hal/HAL_GPIO.hpp
     16       3.8     1.0       21.0         4     src/LedController/LedController.cpp

===============================================================================================================
No thresholds exceeded (cyclomatic_complexity > 15 or length > 1000 or nloc > 1000000 or parameter_count > 100)
==========================================================================================
Total nloc   Avg.NLOC  AvgCCN  Avg.token   Fun Cnt  Warning cnt   Fun Rt   nloc Rt
------------------------------------------------------------------------------------------
       193       3.6     1.1       20.3       26            0      0.00    0.00
```

## 3. Memory Leak Detection (Valgrind)

Run your tests using Valgrind to check for memory issues.

```sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./unit/StatusLed/StatusLedTests
```

## 4. CodeQL Static Analysis Locally

you can run CodeQL locally without GitHub Actions.

### Install CodeQL CLI

```sh
wget https://github.com/github/codeql-cli-binaries/releases/latest/download/codeql-linux64.zip
unzip codeql-linux64.zip
export PATH=$PATH:$(pwd)/codeql
```

### Create a CodeQL Database

```sh
codeql database create mydb --language=cpp --source-root=src
```

### Run Analysis

```sh
codeql database analyze mydb cpp-security-and-quality.qls --format=sarif-latest --output=codeql-results.sarif
```

### Automate with a Script

To streamline these checks, create a script `run_analysis.sh`:

```sh
#!/bin/bash
set -e

echo "Running Tests with Coverage..."
cmake -DCODE_COVERAGE=ON ..
make
ctest
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_report

echo "Running Cyclomatic Complexity Check..."
cppcheck --enable=information --addon=cycletime src/

echo "Running Memory Leak Check..."
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./unit/StatusLed/StatusLedTests

echo "Running CodeQL Analysis..."
codeql database create mydb --language=cpp --source-root=src
codeql database analyze mydb cpp-security-and-quality.qls --format=sarif-latest --output=codeql-results.sarif

echo "All analyses completed!"
```

Run it with:

```sh
chmod +x run_analysis.sh
./run_analysis.sh
```

## 5. Static Code Analysis using cppcheck

command:

```sh
cppcheck --enable=all --inconclusive --force -I src/include -I src/hal -I components/osal/include -I targets/host/hal_impl src/ components/ libs/ os/ targets/ tests/

OR to check only .h, .c, .hpp and .cpp, and ignore CMake* and ignore gmock+gtest files:
cppcheck --enable=all --suppress=missingIncludeSystem $(find src/ -type f -name '*.h' -o -name '*.hpp' -o -name '*.c' -o -name '*.cpp')
cppcheck --enable=all --suppress=missingIncludeSystem $(find src/ targets/ tests/ -type f \( -name '*.h' -o -name '*.hpp' -o -name '*.c' -o -name '*.cpp' \))
cppcheck --enable=all --suppress=missingIncludeSystem $(find src/ targets/ tests/ -type f \( -name '*.h' -o -name '*.hpp' -o -name '*.c' -o -name '*.cpp' \) ! -name 'CMake*' )
cppcheck --enable=all --suppress=missingIncludeSystem $(find src/ targets/ tests/ -type f \( -name '*.h' -o -name '*.hpp' -o -name '*.c' -o -name '*.cpp' \) ! -name 'CMake*' ! -name 'gmock*' ! -name 'gtest*')


```

Now you have automated quality checks for coverage, complexity, memory leaks, and static analysis 🚀! Let me know if you need refinements! 🔥

## Deep Seek Another Code Quality Check

Yes, there are several other common and best-practice code quality checks for C/C++ projects beyond gcov/lcov, Lizard (cyclomatic complexity), and Valgrind (memory leaks). Here’s a list of additional tools and techniques:

## 1. Static Code Analysis

Purpose: Detect potential bugs, vulnerabilities, and code smells without executing the code.

Tools:

Cppcheck: Lightweight static analysis tool for C/C++.

sh
Copy
cppcheck --enable=all --inconclusive --force src/
Clang Static Analyzer: Integrated with Clang/LLVM, provides detailed reports.

sh
Copy
clang --analyze src_file.c
PVS-Studio: Commercial tool for detecting bugs and security vulnerabilities.

SonarQube: A platform for continuous inspection of code quality (supports C/C++ with plugins).

## 2. Dynamic Analysis

Purpose: Detect runtime issues such as memory errors, race conditions, and undefined behavior.

Tools:

AddressSanitizer (ASan): Detects memory errors (e.g., buffer overflows, use-after-free).

sh
Copy
clang -fsanitize=address -o my_program my_program.c
./my_program
ThreadSanitizer (TSan): Detects data races in multithreaded programs.

sh
Copy
clang -fsanitize=thread -o my_program my_program.c
./my_program
UndefinedBehaviorSanitizer (UBSan): Detects undefined behavior (e.g., integer overflow, null pointer dereference).

sh
Copy
clang -fsanitize=undefined -o my_program my_program.c
./my_program

## 3. Code Formatting and Style Enforcement

Purpose: Ensure consistent code style and readability.

Tools:

Clang-Format: Automatically formats code according to a specified style (e.g., Google, LLVM).

sh
Copy
clang-format -i src_file.c
Artistic Style (AStyle): Another code formatter for C/C++.

EditorConfig: Ensures consistent coding styles across different editors/IDEs.

## 4. Code Duplication Detection

Purpose: Identify and eliminate duplicate code to improve maintainability.

Tools:

PMD/CPD: Part of the PMD project, detects copy-pasted code.

sh
Copy
cpd --minimum-tokens 50 --files src/
Simian: A commercial tool for detecting duplicate code.

## 5. Dependency Analysis

Purpose: Ensure proper management of dependencies and avoid issues like circular dependencies.

Tools:

Include What You Use (IWYU): Helps ensure that headers are included only when necessary.

sh
Copy
include-what-you-use src_file.c
CppDepend: Analyzes dependencies and provides insights into code structure.

## 6. Security Analysis

Purpose: Identify security vulnerabilities in the code.

Tools:

Flawfinder: Scans C/C++ code for security issues.

sh
Copy
flawfinder src_file.c
Infer: A static analysis tool developed by Facebook for detecting security and reliability issues.

Coverity: A commercial tool for static security analysis.

## 7. Performance Profiling

Purpose: Identify performance bottlenecks and optimize code.

Tools:

gprof: A performance analysis tool for C/C++.

sh
Copy
gcc -pg -o my_program my_program.c
./my_program
gprof my_program gmon.out > analysis.txt
Perf: A Linux profiling tool for performance analysis.

sh
Copy
perf record ./my_program
perf report
Valgrind (Callgrind): For profiling and analyzing performance.

sh
Copy
valgrind --tool=callgrind ./my_program

## 8. Documentation and Comments

Purpose: Ensure code is well-documented and maintainable.

Tools:

Doxygen: Generates documentation from annotated code.

sh
Copy
doxygen Doxyfile
Sphinx: A documentation generator that can work with Doxygen for C/C++.

## 9. Unit Testing and Test Coverage

Purpose: Ensure code correctness and high test coverage.

Tools:

Google Test: A popular C++ testing framework.

Catch2: A modern C++ testing framework.

gcov/lcov: For measuring test coverage (already mentioned).

## 10. Build and Dependency Management

Purpose: Ensure reproducible and efficient builds.

Tools:

CMake: For managing build processes.

Conan: A package manager for C/C++.

## 11. Code Review and Collaboration

Purpose: Improve code quality through peer review.

Tools:

GitHub/GitLab Code Review: For collaborative code reviews.

Phabricator: A code review and collaboration tool.

Summary
Combining these tools and practices ensures a comprehensive approach to code quality, covering:

Static and dynamic analysis

Code style and formatting

Security and performance

Documentation and testing

Collaboration and maintainability

Let me know if you need further details on any of these tools or practices!
