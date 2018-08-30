FROM ubuntu:xenial

RUN apt-get update
RUN apt-get install -y apache2 php7.0
RUN adduser image_uploader

COPY . /image_uploader
WORKDIR /image_uploader

RUN chown root:image_uploader *

EXPOSE 31336

USER image_uploader

CMD php -S 0.0.0.0:31336 -t /image_uploader > /dev/null 2>&1
