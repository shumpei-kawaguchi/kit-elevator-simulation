# How to test this project?
## Advance preparation
- Mac OS
  1. Install [Homebrew](https://brew.sh/index_ja)
  ```shell
  $ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
  ```
  2. Install wget, cmake
  ```shell
  $ brew install wget
  $ brew install cmake
  ```

## [ 1 ] Setup Googletest on your PC
  1. Download build [Googletest](https://github.com/google/googletest)
  ```shell
  $ wget https://github.com/google/googletest/archive/release-1.10.0.tar.gz
  $ tar zxvf release-1.10.0.tar.gz
  $ cd googletest-release-1.10.0/
  $ mkdir build
  $ cd build/
  $ cmake ..
  $ make
  ```

  2. Copy file on your local directory
  ```shell
  $ sudo cp -r ~/googletest/googlemock/include/gmock /usr/local/include/gmock
  $ sudo cp -r ~/googletest/googletest/include/gtest /usr/local/include/gtest
  $ sudo cp ~/googletest/build/lib/*.a /usr/local/lib/
  ```
## [ 2 ] Run the test
  1. Move directory
  ```shell
  $ cd ~/kit-elevator-simulation
  ```
  2. Run
  ```shell
  $ make test
  ```
  If run the test.
  ```shell
  [==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from SampleTest
[ RUN      ] SampleTest.SampleTestOk
[       OK ] SampleTest.SampleTestOk (0 ms)
[ RUN      ] SampleTest.SampleTestNg
test/test.cpp:4: Failure
Expected equality of these values:
  1
  0
[  FAILED  ] SampleTest.SampleTestNg (0 ms)
[----------] 2 tests from SampleTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 1 test.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] SampleTest.SampleTestNg

 1 FAILED TEST
  ```
  `make test` is operation check for googletest. So if you want to run a test, use test cpp test file name instead of test.  
  Exsample:
  ```shell
  $ make testCombination
  ```
  That's it!
