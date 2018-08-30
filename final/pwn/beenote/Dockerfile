FROM ubuntu:xenial

RUN apt-get update
RUN apt-get install -y socat ucspi-tcp

COPY . /beenote
WORKDIR /beenote

RUN adduser beenote

RUN chown root:beenote * 

EXPOSE 31333

USER beenote

RUN LD_PRELOAD=./libc-2.23.so

CMD socat TCP4-LISTEN:31333,reuseaddr,fork EXEC:"./beenote"
