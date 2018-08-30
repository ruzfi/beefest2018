FROM ubuntu:xenial

RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get install -y libc6:i386 socat ucspi-tcp

COPY . /strlen
WORKDIR /strlen

RUN adduser strlen

RUN chown root:strlen strlen flag

EXPOSE 31333

USER strlen

CMD socat TCP4-LISTEN:31333,reuseaddr,fork EXEC:"./strlen"
