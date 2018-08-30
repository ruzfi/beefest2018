FROM ubuntu:xenial

RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get install -y libc6:i386 socat ucspi-tcp

COPY . /mistake
WORKDIR /mistake

RUN adduser mistake

RUN chown root:mistake mistake flag

EXPOSE 31331

USER mistake

CMD socat TCP4-LISTEN:31331,reuseaddr,fork EXEC:"./mistake"
