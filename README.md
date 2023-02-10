# Template for SFML in C++

## Description

This repo include all files you'll need to start a SFML project for Windows and Linux

List of what the template include
 - Custom library
    - Windows creation
    - Element creation functions
    - Container for:
        - All textures in ``assets/image/``
        - All fonts in ``assets/font/``
        - All sounds in ``assets/sound/``
        - All shaders in ``assets/shader/``
    - List of Buttons
        - Simple Clickable button
        - Simple Clickable button with icon
        - On/Off button
        - Write button
        - Scroller button
    - Transitions
        - Fade
        - Circle
    - Random functions
    - Read file functions
 - Template for a part
    - all basics files
        - creation
        - destruction
        - events

## Linux

Use the Makefile to compile the project form a terminal.
You can change ``BINNAME`` var to change the name of the binary
You have to install the SFML before.

 - Ubuntu: ``sudo apt-get install -y libsfml-dev``
 - Fedora: ``sudo dnf install -y SFML SFML-devel``


## Windows

There is the .vcxproj file you can use with [Visual Studio](https://visualstudio.microsoft.com/vs/community/)

If you want to create a repo from scratch there is all the step to setup it:

First Drag and drop on the project folder the following folder and files:
 - bin
 - include
 - lib
 - src
 - assets (copy the folder in ``bin/Debug`` and ``bin/Release`` too)

Now go in the settings of the project and set the configuration for both Debug and Release

# All Configurations

### Common Properties / Général
Change in `Output Directory` :
```
$(ProjectDir)bin\$(Configuration)\
```
Change in `Intermediate Directory` :
```
$(ProjectDir)bin\intermediates\$(Configuration)\
```
Change in `C++ Language Standard` :
```
Norme ISO C++17 (/std:c++17)
```

### C/C++ / General
Change in `Additional Include Directories` :
```
$(SolutionDir)$(ProjectName)\include
```

### C/C++ / Output files :
Change in `Object File Name` :
```
$(IntDir)%(RelativeDir)
```

### Linker / General
Change in `Additional Library Directories` :
```
$(SolutionDir)$(ProjectName)\lib
```

# Release

### Linker / Input
add in `Additional Dependencies` :
```
sfml-main.lib;sfml-graphics.lib;sfml-window.lib;sfml-system.lib;sfml-audio.lib;sfml-network.lib;
```

### Linker / System
change in `SubSystem` :
```
Windows (/SUBSYSTEM:WINDOWS)
```

# Debug

### Linker / Input
add in `Additional Dependencies` :
```
sfml-main-d.lib;sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-audio-d.lib;sfml-network-d.lib;
```

### Linker / System
change in `SubSystem` :
```
Console (/SUBSYSTEM:CONSOLE)
```
