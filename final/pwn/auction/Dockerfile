FROM ubuntu:xenial

RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get install -y libc6:i386 socat ucspi-tcp

COPY . /auction
WORKDIR /auction

RUN adduser auction

RUN chown root:auction auction flag

EXPOSE 31331

USER auction

CMD socat TCP4-LISTEN:31331,reuseaddr,fork EXEC:"./auction"
