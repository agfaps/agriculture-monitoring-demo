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

## 2. Cyclomatic Complexity Analysis (cppcheck)

You can check cyclomatic complexity using cppcheck.

### Run cppcheck

```sh
cppcheck --enable=all --inconclusive --force --inline-suppr --check-level=exhaustive --suppress=missingIncludeSystem --max-configs=100 --template=gcc --verbose --xml --output-file=cppcheck_report.xml src/
```

### Check Complexity Only

```sh
cppcheck --enable=information --addon=cycletime src/
```

This will output complexity for each function.

## 3. Memory Leak Detection (Valgrind)

Run your tests using Valgrind to check for memory issues.

```sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./unit/StatusLed/StatusLedTests
```

## 4. CodeQL Static Analysis Locally

ou can run CodeQL locally without GitHub Actions.

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

Now you have automated quality checks for coverage, complexity, memory leaks, and static analysis 🚀! Let me know if you need refinements! 🔥
