FROM ubuntu:jammy
ENV TZ=Asia/Calcutta
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get -y upgrade
RUN apt-get install -y --no-install-recommends \
    ca-cacert \
    cmake \
    build-essential \
    libboost-all-dev \
    libssl-dev \
    wget \
    zlib1g-dev

RUN apt-get update && \
    apt-get -y upgrade && \
    apt-get -y install libboost-all-dev && \
    apt-get -y install libbson-dev && \
    apt-get -y install libzstd-dev && \
    apt-get -y install git

WORKDIR /tmp
RUN git clone https://github.com/google/googletest/ && \
    cd /tmp/googletest && \
    mkdir build && cd build && cmake .. && make install &&\
    cd .. &&\
    mkdir source && \
    cd source

#RUN git clone https://github.com/google/googletest/
#WORKDIR /tmp/googletest
#RUN mkdir build && cd build && cmake .. && make install
#RUN ldconfig

#RUN mkdir -p /tmp/source
#WORKDIR /tmp/source

COPY inc /tmp/source/app
COPY test /tmp/source/app
COPY CMakeLists.txt /tmp/source/app
COPY vectors_main.cpp /tmp/source/app
COPY vectors.cpp /tmp/source/app

RUN cd /tmp/source/app &&\
    mkdir build &&\
    cd build &&\
    cmake .. && make

#WORKDIR /tmp/source/app

#RUN mkdir -p /tmp/source/app/build
#WORKDIR /tmp/source/app/build
#RUN cmake .. && make

RUN mkdir -p /opt/app
RUN mkdir /opt/app/test
WORKDIR /opt/app/test
RUN cp /tmp/source/app/build/test/EE951_test .

WORKDIR /opt/app
RUN cp /tmp/source/app/build/EE951 .



CMD ["/opt/app/EE951"]