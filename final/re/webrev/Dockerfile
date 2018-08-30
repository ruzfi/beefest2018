FROM ubuntu:xenial

RUN apt-get update
RUN apt-get install -y apache2 php7.0
RUN adduser webrev

COPY . /webrev
WORKDIR /webrev

RUN chown root:webrev *

EXPOSE 31334

USER webrev

CMD php -S 0.0.0.0:31334 -t /webrev > /dev/null 2>&1
