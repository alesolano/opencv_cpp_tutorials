#!/bin/bash

# We need to pass some arguments to allow GUI and debugging
# GUI: -e, -v
# Debugging: --cap-add, --security-opt

docker run -it \
    --name ocv_1 \
    -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix \
    --cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
    opencv_1 bash


