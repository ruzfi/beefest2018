FROM ubuntu:xenial

RUN apt-get update
RUN apt-get install -y apache2 php7.0
RUN adduser wongjowo

COPY . /wongjowo
WORKDIR /wongjowo

RUN chown root:wongjowo *

EXPOSE 31336

USER wongjowo

CMD php -S 0.0.0.0:31336 -t /wongjowo > /dev/null 2>&1
