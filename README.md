# Vefa Space Programme's Project
~~Vefa Space Programme is applying for Beamline for Schools (BL4S) using this demonstration on Geant4.~~

Vefa Space Programme has been [shortlisted](https://beamlineforschools.cern/wp-content/uploads/2026/05/BL4S_all-winners_2026.pdf) in Beamline for Schools (BL4S) 2026 edition with the use of this demonstration on Geant4.

## Contents
- [Geant4](#geant4)
- [Demonstration](#demonstration)
- [Setup and Running the Simulation](#setup-and-running-the-simulation)
- [Credits](#credits)

## Geant4
Geant4 is a toolkit for the simulation of the passage of particles through matter. It's a toolkit based on C++.
You can find more information about Geant4 [here](http://cern.ch/geant4).

## Demonstration
You can find some images from the simulation with 10000 beams of protons with increasing energy below.

<img src="/images/initial_state.png?raw=true" width="400" height="400" alt="Initial state">
<img src="/images/demo1.png?raw=true" width="400" height="400" alt="Demo 1">
<img src="/images/demo2.png?raw=true" width="400" height="400" alt="Demo 2">
<img src="/images/demo3.png?raw=true" width="400" height="400" alt="Demo 3">
<img src="/images/demo4.png?raw=true" width="400" height="400" alt="Demo 4">
<img src="/images/demo5.png?raw=true" width="400" height="400" alt="Demo 5">

These images can also be found inside [/images](/images)

## Setup and Running the Simulation
Before running the simulation, make sure to download all of the following:
- [CMake](https://cmake.org/download)
- [Visual Studio 2022](https://aka.ms/vs/17/release/vs_community.exe)
- [Geant4](https://geant4.web.cern.ch/download)

The download and the initial setup are the hardest steps (at least they were for me), so [here is a video](https://www.youtube.com/watch?v=w7k9PK1Ipv8) that explains how you can successfully complete them on Windows 11. After the initial setup:

1. Unzip the source code.
2. Open **CMake (cmake-gui)**.
3. From the source code, drag the `CMakeLists.txt` file inside the CMake GUI and release it.
4. At the end of the textbox `Where to build the binaries:`, add `/build`.
5. Click `Configure` at the bottom left.
6. In the `Build directory does not exist, should I create it?` popup, click `Yes`.
7. In the next popup, select `Visual Studio 2022` and `Use default native compilers` and click `Finish`.
8. After configuration, change the `CMAKE_CONFIGURATION_TYPES` to read just `Release`. Don't worry about the red boxes.
9. Click `Configure` once more.
10. After the second configuration (usually lasting less than a second) the red boxes should become white. Then, click `Generate`.
11. After generation, click `Open Project`.
12. In Visual Studio, right click the solution reading `alp` (should be on the right) and click on `Set as starting project`.
13. Click on `alp` again and click `Build`.
14. In Visual Studio, click `Alt + F5` and run the project. You can also do this by going to the folder `build -> Release` and running the `alp.exe` file inside.

After 14 steps, the simulation is now running!

You can use the [Geant4 guide](https://geant4-userdoc.web.cern.ch/UsersGuides/IntroductionToGeant4/html/index.html) to run some commands, but its very long and time consuming. So here are some commands you might want to use:
- `/run/beamOn 1`: Sends **1 beam(s)** of a particle.
- `/gun/energy 100 MeV`: Sets a new energy for all future particles to have at **100 MeV** (default: *100 MeV*).
- `/gun/particle proton`: Sets a new particle type for all future particles (default: *proton*).

## Credits
Geant4 was developed by the **Geant4 Collaboration** and its license was subsequently included in [/LICENSE](/LICENSE). This **README** and the project associated with it was made by [Alp (@alprys)](https://alprys.com).
