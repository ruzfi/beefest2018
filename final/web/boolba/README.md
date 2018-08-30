# Boolba

Normalnya, soal-soal yang sudah diberikan tidak perlu diberikan file ***README*** seperti ini, namun karena pengaturan soal ini cukup sulit...

Pada proses pembuatan soal, PHP soal ini beserta DB tidak bisa disatukan dikarenakan cara Docker bekerja (mungkin juga dikarenakan kurangnya pengalaman problem-setters dalam Docker). Cara lain untuk deployment soal ini adalah dengan membuat network docker dengan IP static agar webservice challenge bisa connect ke MySQL yang terletak dalam satu jaringan.

```Bash
$ docker network create boolbanet --subnet=172.18.0.0/16
$ docker pull mysql/mysql-server:5.7
$ docker run -d --name boolbasql --net boolbanet --ip 172.18.0.2 mysql/mysql-server:5.7
```

Kemudian container MySQL yang telah dijalankan ini, harus diatur manual.

```Bash
docker logs [MySQL container id] | grep PASSWORD # untuk mendapatkan password MySQL
docker exec -ti [MySQL container id] bash
```

Sebelum melakukan pengaturan pada database, perlu dilakukan hal berikut:

```SQL
alter user 'root'@'localhost' identified by 'password';
grant all privileges on *.* to 'root'@'172.18.0.3' identified by 'password';
flush privileges;
```

Masih pada shell container MySQL, lakukan `mysql --user=root --password=password < users.sql` untuk langkah terakhir.

```Bash
docker build -t boolba .
docker run -d -p [port]:80 --net boolbanet --ip 172.18.0.3 boolba
```

Service dapat berjalan sebagaimana mestinya :)