FROM ubuntu:xenial

RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get install -y libc6:i386 socat ucspi-tcp

COPY . /secret
WORKDIR /secret

RUN adduser secret

RUN chown root:secret secret flag

EXPOSE 31332

USER secret

CMD socat TCP4-LISTEN:31332,reuseaddr,fork EXEC:"./secret"
