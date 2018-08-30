FROM ubuntu:xenial

RUN apt-get update
RUN apt-get install -y apache2 php7.0 php7.0-mysqli libapache2-mod-php

RUN a2enmod php7.0

COPY . /var/www/html/.
WORKDIR /var/www/html/

RUN rm index.html && chown root:www-data *

EXPOSE 80

CMD /usr/sbin/apache2ctl -D FOREGROUND
