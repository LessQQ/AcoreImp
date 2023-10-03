# AcoreImp

The goal of AcoreImp is to provide a way of starting the AzerothCore servers (authserver, worldserver) in the background. 

## Install:
First, we need to build and install libimp:

    make libimp
    make install-libimp

Now build the rest:

<<<<<<< HEAD
    make all
    make install
=======
  make all
  make install
>>>>>>> main

## Setup
Imp needs a few things to be configured.

    impconfig set authpath "/path/to/authserver"
    impconfig set authargs "-c /path/to/authserver.conf"
    impconfig set worldpath "/path/to/worldserver"
    impconfig set worldargs "-c /path/to/worldserver.conf"

## Running
Imp can now be run via the commandline.

    impauth > /dev/null
    impworld > /dev/null

## Running at boot
Imp can be run from systemd 
    TODO 



