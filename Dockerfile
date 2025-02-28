FROM ubuntu:latest

WORKDIR /usr/src/snake

COPY main.cpp CMakeLists.txt /usr/src/snake/
COPY src/* /usr/src/snake/src/

RUN apt-get -y update && \
    apt-get -y install gcc && \
    apt-get -y install cmake && \
    apt-get -y install build-essential && \
    apt-get -y install libncurses5-dev && \
    cmake -S . -B ./build && \
    cmake --build build
    # apt-get -y install make && \
    
CMD [ "./build/terminal_snake" ]
