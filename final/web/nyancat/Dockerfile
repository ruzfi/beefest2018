FROM ubuntu:xenial

RUN apt-get update
RUN apt-get install -y apache2 php7.0
RUN adduser nyancat

COPY . /nyancat
WORKDIR /nyancat

RUN chown root:nyancat *

EXPOSE 31335

USER nyancat

CMD php -S 0.0.0.0:31335 -t /nyancat > /dev/null 2>&1
