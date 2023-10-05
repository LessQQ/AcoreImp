# AcoreImp

The goal of AcoreImp is to provide a way of starting the AzerothCore servers (authserver, worldserver) in the background. 

## Install:
First, we need to build and install libimp:

    make libimp
    make install-libimp

Now build the rest:

    make all
    make install

## Setup
Imp needs a few things to be configured.

    impconfig set authpath "/path/to/authserver"
    impconfig set authargs "--config=/path/to/authserver.conf"
    impconfig set worldpath "/path/to/worldserver"
    impconfig set worldargs "--config=/path/to/worldserver.conf"

## Running
Imp can now be run via the commandline.

    impauth 2>&1 /dev/null
    impworld 2>&1 /dev/null

## Running at boot
Imp can be run from systemd 
    
    TODO 



