# C++ Apache Log Analysis

This C++ application analyzes Apache log files to provide statistics regarding requests made on various pages. It generates the top 10 most requested pages and can also create a graphical summary of the data. Upon execution, the default functionality is to display the top 10 requested pages.

## Table of Contents
- [Description](#description)
- [Operation](#operation)
    - [Global Operation](#global-operation)
    - [List of Options](#list-of-options)
- [Setting Up on Linux Machine](#setting-up-on-linux-machine)
    - [Update](#update)
    - [Install C++ Compiler](#install-c-compiler)
    - [Cloning the GitHub Repository](#cloning-the-github-repository)
    - [Launching the Application](#launching-the-application)
        - [Running the Application](#running-the-application)

## Description

This C++ program serves the purpose of parsing Apache log files and deriving statistics. The primary function is to display the top 10 requested pages within the log. Additionally, it offers options to configure and filter the analysis.

## Operation

### Global Operation

To execute the program, use the following command:

```bash
./prog file.log
```
This command represents the default functionality. You can also include options as follows:

```bash
./prog [-options] file.log
```
## List of Options

- `-c file.config`: Specify the configuration file for reader settings, including host server and extensions to ignore with the `-e` option.
- `-e`: Ignore files with specified extensions in the configuration file (e.g., css, js).
- `-t hh`: Analyze requests made between `hh` and `hh+1`, where `hh` represents the hour.
- `-g file.dot`: Generate a `.dot` file to create a graph. Utilize the command `dot -Tpng -o file.png file.dot` for graph generation.
- `-i`: When the `-g file.dot` option is active, include `-i` to directly generate the graph in `.png` format with the name specified using `-g` (e.g., file.png).

## Setup the Linux Machine 

### Update
- `sudo apt-get update`
- `sudo apt-get upgrade`

### Install C++ | Version : Update
- `sudo apt-get install cmake`

## Clone the repository Github in your linux machine
### Install git
- `sudo apt-get install git git-core`
### Clone the repository
- Go to the directory where you want to clone the repository
- `sudo git clone https://github.com/Lasssssa/TP3_CPP_INSA_LYON`

### Update
- Go to the directory where you clone the repository
- `sudo git pull https://github.com/Lasssssa/TP3_CPP_INSA_LYON`

### Other way to get the repository
- Go to the directory where you want to clone the repository
- Get the repository and move it to the directory where you want to clone the repository

## Launch the application

### Run the application
- Move to the directory where you clone the repository
- `cd TP3_CPP_INSA_LYON`
- `make`
- `./prog ...`

## Repertory Github :
https://github.com/Lasssssa/TP3_CPP_INSA_LYON
