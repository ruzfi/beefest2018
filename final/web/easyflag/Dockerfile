FROM ubuntu:xenial

RUN apt-get update
RUN apt-get install -y apache2 php7.0 libapache2-mod-php

RUN a2enmod php7.0

COPY . /var/www/html/.
WORKDIR /var/www/html/

RUN chown root:www-data *

EXPOSE 80

RUN rm index.html
CMD /usr/sbin/apache2ctl -D FOREGROUND
