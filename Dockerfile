FROM ubuntu

# My dependencies
RUN apt-get update
RUN apt-get install -y \
	git unzip wget nano

# Qt Creator
RUN apt-get update
RUN apt-get install -y qtcreator

# New user for display
RUN apt-get install -y sudo
RUN export uid=1000 gid=1000 && \
    mkdir -p /home/developer && \
    echo "developer:x:${uid}:${gid}:Developer,,,:/home/developer:/bin/bash" >> /etc/passwd && \
    echo "developer:x:${uid}:" >> /etc/group && \
    echo "developer ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/developer && \
    chmod 0440 /etc/sudoers.d/developer && \
    chown ${uid}:${gid} -R /home/developer

WORKDIR /home/developer


####################################################################

# OpenCV dependencies
RUN apt-get update
RUN apt-get install -y build-essential
RUN apt-get install -y cmake git libgtk2.0-dev pkg-config \
	libavcodec-dev libavformat-dev libswscale-dev
RUN apt-get install -y python3-dev python3-numpy libtbb2 libtbb-dev \
	libjpeg-dev libpng-dev libtiff-dev libdc1394-22-dev

# libjasper-dev. Not supported on Ubuntu 18
#RUN add-apt-repository “deb http://security.ubuntu.com/ubuntu xenial-security main”
#RUN apt-get update && apt-get install -y libjasper-dev

# Build OpenCV
COPY opencv-4.1.1.zip .
RUN unzip opencv-4.1.1.zip -d . && rm opencv-4.1.1.zip
RUN mv opencv-4.1.1 opencv
RUN cd opencv && mkdir build
RUN cd opencv/build && cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
RUN cd opencv/build && make -j7
RUN cd opencv/build && make install

####################################################################

COPY create_project.sh .
RUN chmod +x create_project.sh

USER developer
ENV HOME /home/developer
