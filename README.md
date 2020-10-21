# Kit Elevator Simulation

## About
- LICENSE  
  [MIT License](https://github.com/shumpei-kawaguchi/kit-elevator-simulation/blob/main/LICENSE)

- Directory tree
  ```
  kit-elevator-simulation
  .
  ├── LICENSE
  ├── Makefile
  ├── README.md
  ├── calculations // Exsample: Some directory named functions
  │   ├── combination.c // C file
  │   ├── combination.h // Header file
      └── ... functions
  ├── kit-elevator-simulation
  ├── main.c // main code
  └── test
      ├── test.cpp
      └── ... test files
  ```

### Platforms
Confirmed operating environment:
- Mac OS X

## Usage
### Build
### Test
#### Advance preparation
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

#### [ 1 ] Setup Googletest on your PC
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
#### [ 2 ] Run the test
  1. Move directory
  ```shell
  $ cd ~/kit-elevator-simulation
  ```
  2. Run
  ```shell
  $ make test
  ```
  `make test` is operation check for googletest. So if you want to run a test, use test cpp test file name instead of test.  
  Exsample:
  ```shell
  $ make testCombination
  ```
  That's it!
