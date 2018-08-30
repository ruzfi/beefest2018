FROM ubuntu:xenial

RUN apt-get update
RUN apt-get install -y apache2 php7.0
RUN adduser tagsnlabels

COPY . /tagsnlabels
WORKDIR /tagsnlabels

RUN chown root:tagsnlabels *

EXPOSE 31335

USER tagsnlabels

CMD php -S 0.0.0.0:31335 -t /tagsnlabels > /dev/null 2>&1
