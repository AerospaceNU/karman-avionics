# karman-avionics

This repository is for Project Karman's F.R.I.D.A.Y. avionics system's software. The project is for an STM32 F767 and is based on the mbed framework.

## Getting Started

We are using Eclipse with a GNU ARM compiler. The following should explain how to install and configure this IDE to work with our project.

First, install Eclipse 2018-12 from this [link](https://www.eclipse.org/downloads/packages/). Then install the correct [GNU toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm). If you are on Windows, you will also need to install the [GNU buildtools](https://gnu-mcu-eclipse.github.io/windows-build-tools/download/) - make sure you install these in a location that does not have spaces in its name. Also take note of the install location of your GNU toolchain and the buildtools.

Once Eclipse has installed, create a workspace directory (it doesn't really matter what this directory is, becasuse you can just change it later) and open it. You will have to install the GNU ARM plugin. To do this navigate to Help->Eclipse Marketplace and search for GNU ARM and install the plugin.

Restart Eclipse after installing the plugin and click on the Packs icon (it looks like a couple of packages). You may have to refresh in order to see all of the options. Then navigate to ST Microelectronics and install the most recent version of the package for the F7 family of boards. You may get an error during this process, just have the installation continue the boards that are missing are not the ones we are using.

Finally, you will have to configure the compiler. Instructions on how to do this are coming soon. That being said I'm pretty sure if you go to Windows->Preferences then C/C++->Build->Environment and make a variable named PATH with the location of your compiler and buildtools it should be able to find them. But do not quote me on this. Ask me if you have any question. My apologies, I will try to get this section completed as soon as possible

Then install the project and test compile it. Once you're up and running, go to the drive task folder, or the issues in the repo to find something to work on.

## Best Practices

I'll add these later. But basically every device should have its own class, and both variables and functions are named using camelCase. Struts and global defines are in snake_case. _Note:_ the global defines should also be in all caps. 
