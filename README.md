# karman-avionics

This repository is for Project Karman's F.R.I.D.A.Y. avionics system's software. The project is for an STM32 F767 and is based on the mbed framework.

## Getting Started

We are using Eclipse with a GNU ARM compiler. The following should explain how to install and configure this IDE to work with our project.

First, install Eclipse 2018-12 from this [link](https://www.eclipse.org/downloads/packages/). Then install the correct [GNU toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm). If you are on Windows, you will also need to install the [GNU buildtools](https://gnu-mcu-eclipse.github.io/windows-build-tools/download/) - make sure you install these in a location that does not have spaces in its name. Also take note of the install location of your GNU toolchain and the buildtools. In addition, download the [SEGGER J-Link Software and Documentation Pack](https://www.segger.com/downloads/jlink/) and note the install location. But I would recommed installing the J-Link software after successfully installing Eclipse, because the J-Link installer sets some variables for you in Eclipse.

Once Eclipse has installed, create a workspace directory (it doesn't really matter what this directory is, becasuse you can just change it later) and open it. You will have to install the GNU ARM plugin. To do this navigate to Help->Eclipse Marketplace and search for GNU ARM and install the plugin.

Restart Eclipse after installing the plugin and click on the Packs icon (it looks like a couple of packages). You may have to refresh in order to see all of the options. Then navigate to ST Microelectronics and install the most recent version of the package for the F7 family of boards. You may get an error during this process, just have the installation continue the boards that are missing are not the ones we are using.

Finally, you will have to configure the compiler, built tools and J-Link debug files. Navigate to Window->Preferences->MCU. Under the MCU dropdown, first click on Global ARM Toolchain Paths. Once you have selected this there should be a dropdown menu and a few blank fields. Select 'GNU MCU Eclipse ARM Embedded GCC' as the default toolchain, then select the 'arm-none-eabi\bin' directory for the first compiler option, and the main 'bin' directory for the section compiler. Next, select 'Global Build Tools Path' from the MCU sublist and add the build tools installation location (the 'bin' directory more specifically) if you are on a Windows system. Finally, select 'Global SEGGER J-Link Path' from the MCU sublist. This field should already be populated, but if not, select the 'JLinkGDBServerCL' executable and the directory of that file. Then click 'Apply & Close' in the bottom right.

Now that the compiler and toolchain are configured, open Windows->Preferences->C/C++->Build->Environment and clear the variable PATH, if there is anything in it, and add the path to your built tools and your compiler (the same paths you used in the last step).

Then, clone this project into a good directory, and set that directory as your workspace. With the workspace open, go to File->Open Projects from File System and select the folder karman-avioincs. This should import the project into your workspace, so you can view all of the source files.

In order to use this project, you will have to install the Eigen library. Install Eigen 3.3.7 from [this site](http://eigen.tuxfamily.org/index.php?title=Main_Page) and extract it to a file location that is not in your project source. Next, within Eclipse, go to Project->Properties->C/C++ Build->Settings. Then in the main section of the window under cross ARM GNU Assembler->Includes, remove the include path for my version of Eigen, then add a new include path for you path to the Eigen folder within the extracted folder (mine is eigen-eigen-xxxxxx/Eigen) where xxxxxxx is a random string of numbers that probably mean something, but we don't care what. Yours will probably be similar. Then repeat this process for the cross ARM GNU C compiler and finally the cross ARM GNU C++ compiler. Finally, click 'Apply & Close'. At this point you should be all set to build the project, so try that by clicking the hammer icon on the toolbar. If your source compiles without error, continue to the next step.

Follow the instructions [here](https://gnu-mcu-eclipse.github.io/debug/jlink/) to get a debug configuration established. Our board is called an STM32F767ZI and it's clock runs at 216000000 Hz and the SWO should run at 6000000 Hz. That should be all of the information you will need to complete the basic walkthrough guide there. Once you complete the walkthrough, you should be able to launch your configuration with the devboard plugged into your computer and step through the code and debug normally. _Note:_ you have to use the devboard configured to work with the J-Link debug tools, currently only one of the devboards is configured to do so.

Once you're up and running, go to the drive task folder, or the issues in the repo to find something to work on.

## Best Practices

I'll add these later. But basically every device should have its own class, and both variables and functions are named using camelCase. Struts and global defines are in snake_case. _Note:_ the global defines should also be in all caps. 
