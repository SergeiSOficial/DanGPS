<!-- markdownlint-disable MD032 MD033-->
<!-- Write your README.md file. Build something amazing! This README.md template can guide you to build your project documentation, but feel free to modify it as you wish 🥰 -->
# 🔥 **SergeiSavkin/DanGPS**

<div align="center">
  <!-- Change your logo -->
  <a href="https://github.com/SergeiSavkin/DanGPS">
    <img width="100%" src="https://i.imgur.com/SVvgxJF.png" alt="@SergeiSavkin/DanGPS's logo">
  </a>
  <br>
  <a href="https://github.com/SergeiSavkin/DanGPS/issues">
    <img src="https://img.shields.io/github/issues/SergeiSavkin/DanGPS?color=0088ff&style=for-the-badge&logo=github" alt="SergeiSavkin/DanGPS's issues"/>
  </a>
  <a href="https://github.com/SergeiSavkin/DanGPS/pulls">
    <img src="https://img.shields.io/github/issues-pr/SergeiSavkin/DanGPS?color=0088ff&style=for-the-badge&logo=github"  alt="SergeiSavkin/DanGPS's pull requests"/>
  </a>
</div>

---

## 🤔 **About the project**

* <!-- ... [WHY DID YOU CREATED THIS PROJECT?, MOTIVATION, PURPOSE, DESCRIPTION, OBJECTIVES, etc] -->

---

## ⚡ **Installation**

* <!-- ... [SHOW HOW YOUR PROJECT IS INSTALLED] -->

---

## 🚀 **Usage**

* <!-- ... [SHOW HOW YOUR PROJECT IS USED] -->

---

## 🌲 **Project tree**

<!-- ... [SHOW YOUR PROJECT TREE HERE IF USEFUL] -->

---

## 📝 **Additional notes**

* <!-- ... [ADD ADDITIONAL NOTES] -->

---

## 📸 **Screenshots**

<!-- ... [SOME DESCRIPTIVE IMAGES] -->

---

## 🍰 **Supporters and donators**

<!-- Change your small logo -->
<a href="https://github.com/SergeiSavkin/DanGPS">
  <img alt="@SergeiSavkin/DanGPS's brand logo without text" align="right" src="https://i.imgur.com/3qK1sie.png" width="18%" />
</a>


We are currently looking for new donators to help and maintain this project! ❤️

By donating, you will help the development of this project, and *you will be featured in this DanGPS's README.md*, so everyone can see your kindness and visit your content ⭐.

<a href="https://github.com/sponsors/SergeiSavkin"> <!-- MODIFY THIS LINK TO YOUR MAIN DONATING SITE IF YOU ARE NOT IN THE GITHUB SPONSORS PROGRAM -->
  <img src="https://img.shields.io/badge/Sponsor-SergeiSavkin/DanGPS-blue?logo=github-sponsors&style=for-the-badge&color=red">
</a>

<!-- LINK TO YOUR DONATING PAGES HERE -->

---

DanGPS was generated from *[Josee9988/project-template](https://github.com/Josee9988/project-template)* 📚

---

## 🕵️ Extra recommendations

* <!-- If you recommend installing anything special, or if you recommend using X thing for the good use of your project...-->

---

## 🎉 Was the embedded/firmware helpful? Help us raise these numbers up

[![GitHub followers](https://img.shields.io/github/followers/SergeiSavkin.svg?style=social)](https://github.com/SergeiSavkin)
[![GitHub stars](https://img.shields.io/github/stars/SergeiSavkin/DanGPS.svg?style=social)](https://github.com/SergeiSavkin/DanGPS/stargazers)
[![GitHub watchers](https://img.shields.io/github/watchers/SergeiSavkin/DanGPS.svg?style=social)](https://github.com/SergeiSavkin/DanGPS/watchers)
[![GitHub forks](https://img.shields.io/github/forks/SergeiSavkin/DanGPS.svg?style=social)](https://github.com/SergeiSavkin/DanGPS/network/members)
<!-- MODIFY THIS LINK TO YOUR MAIN DONATING SITE IF YOU ARE NOT IN THE GITHUB SPONSORS PROGRAM -->
[![Sponsor](https://img.shields.io/static/v1?label=Sponsor&message=%E2%9D%A4&logo=github-sponsors&color=red&style=social)](https://github.com/sponsors/SergeiSavkin)

Enjoy! 😃

---

## ⚖️📝 **License and Changelog**

See the license in the '**[LICENSE](LICENSE)**' file.

Watch the changes in the '**[CHANGELOG.md](CHANGELOG.md)**' file.

---

_Made with a lot of ❤️❤️ by **[@SergeiSavkin](https://github.com/SergeiSavkin)**_














### STM32 Base/Template Project

|    Type    |   Tool used |
| ---------- | ----------- |
| Build framework | cmake |
| Toolchain | arm-none-eabi-gcc |
| RTOS | FreeRTOS |
| HAL  | STM32 CubeMX |
| Test framework | Unity |
| Mocking framework | FFF |
| Code coverage | lcov |
| GDB utilities | GDB dashboard |
| GDB server | openocd |
| Documentation | doxygen |

### Installation
#### Method 1
- Clone complete repo including submodules  
  `git clone --recurse-submodules --depth 1 --single-branch https://github.com/rgujju/STM32_Base_Project <your_project_name>`    
  But the problem with this is the CMSIS and FreeRTOS repos (submodules) are huge due to history and takes time to download.

#### Method 2
- Clone this repo only and change paths of CMSIS and FreeRTOS in the **CmakeLists.txt** to the ones you already have.  
  `git clone --depth 1 --single-branch https://github.com/rgujju/STM32_Base_Project <your_project_name>`

### Usage
- **components** folder includes external libraries like RTOS, HAL, CMSIS, unity, and FFF mostly as git submodules.
- **modules** folder contains sources for individual parts which can be unit tested.
- **test** folder contains the tests for the modules.
- Debug build is the default build if ``CMAKE_BUILD_TYPE`` is not specified during cross-compiling  
- ARM Semihosting is turned on by default. To turn off use ``-DSEMIHOSTING=0``. ``SEMIHOSTING`` is also a macro which is set if ARM semihosting is enabled.  
- Most of the values like HSE, linker script, RTOS path, HAL path, CMSIS path, etc can be set in the configurable section of CMakeLists.txt in project root.  
- To add new modules, copy **modules/simple_module** to **modules/<your_module_name>** and rename ``simple_module`` with ``<your_module_name>`` in the **modules/<your_module_name>/CMakeLists.txt** file, 
  and add ``add_subdirectory(<your_module_name>)`` to the **modules/CMakeLists.txt**.
  Finally add ``<your_module_name>`` to the *MODULES_USED* variable in **CMakeLists.txt**. 
- For adding test for the modules, create **test/test_<your_module_name>.c** and add two lines as follows in **test/CMakeLists.txt**  

   ```
   list(APPEND tests_names "test_<your_module_name>")
   list(APPEND tests_flags " ")
   ```
- For ``make flash`` to work openocd should be running.

#### Build Tests for host
``mkdir -p build/test``  
Generate Makefile  
``cmake ../.. -DTARGET_GROUP=test``  
Build the tests  
``make``  
To run the tests  
``ctest --verbose``  
or to test and generate coverage report all together.  
``make coverage``  
The coverage report will be in **build/test/coverage/index.html**  

#### Build Release for cross-compiling
``mkdir -p build/release``  
Generate Makefile  
``cmake ../.. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=../../cross.cmake -DTARGET_GROUP=production``  
Generate elf  
``make <your_project_name>.elf``  
Load the board with elf  
``make flash``  

Note: To make FreeRTOS link with ``-flto`` option during Release build ``-Wl,--undefined=vTaskSwitchContext`` is passed to the linker.  

#### Build Debug (default) for cross-compiling
``mkdir -p build/debug``  
Generate Makefile  
``cmake ../.. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=../../cross.cmake -DTARGET_GROUP=production``  
Generate elf  
``make <your_project_name>.elf``  
Start GDB and load the board with elf with GDB dashboard output to eg: /dev/pts/12  
``make flash GDB_TTY=/dev/pts/12``  
Note: ``flash`` target is not present when ``-DTARGET_GROUP=test`` is provided.  
Currently using terminator to split the terminal to two and output the GDB dashboard to the terminal on the right  

#### Generate documentation
In the above created folders **(build/release, build/debug)**, use command  
`make docs`  
Documentation files will be generated in html and latex format. For example if command is used in **build/release** dir then
documentation will be generated in **build/release/html/index.html**  
Note: ``docs`` target is not present when ``-DTARGET_GROUP=test`` is provided.  

### Porting
- This project uses the STM32F429 mcu but should be portable to any mcu.
- Replace **components/STM32F4xx_HAL_Driver** and **include/stm32f4xx_hal_conf.h** with the HAL of your mcu.
- Replace **include/STM32F4xx** with the vendor files for your mcu. These files are basically the system, startup and header files of your mcu.
- The above 2 folders are provided by the vendor. In case of STM32, it is possible to use STM32CubeMX to generate them.
- Change *MCU Setup*, *HAL Setup*, and optionally *RTOS Setup* and *CMSIS Setup* in the **CMakeLists.txt** file.
- Linker script **linker.ld** needs to be changes according to your mcu memory. **layout_base.ld** also may be requried to be changed.
