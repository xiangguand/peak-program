FROM ubuntu:22.04

RUN apt-get update && apt-get install build-essential g++ git -y

RUN mkdir -p /home/demo
COPY . /home/demo

WORKDIR /home/demo

CMD tail -f /dev/null
