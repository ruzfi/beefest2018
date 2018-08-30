FROM ubuntu:xenial

RUN apt-get update
RUN apt-get install -y apache2 php7.0 iputils-ping
RUN adduser simpleexe

COPY . /simpleexe
WORKDIR /simpleexe

RUN chown root:simpleexe *

EXPOSE 31334

USER simpleexe

CMD php -S 0.0.0.0:31334 -t /simpleexe > /dev/null 2>&1
