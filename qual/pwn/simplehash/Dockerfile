FROM ubuntu:xenial

RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get install -y libc6:i386 socat ucspi-tcp

COPY . /simplehash
WORKDIR /simplehash

RUN adduser simplehash

RUN chown root:simplehash simplehash flag

EXPOSE 31332

USER simplehash

CMD socat TCP4-LISTEN:31332,reuseaddr,fork EXEC:"./simplehash"
