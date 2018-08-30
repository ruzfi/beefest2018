<?php 
    function db(){
        $username = 'root';
        $password = 'haruslegacy';
        $database = 'beefest';
        $db = mysqli_connect('172.18.0.2', $username, $password, $database);
        if(!$db){
            exit('Error while connecting to database: '.mysqli_connect_error());
        }

        return $db;
    }
?>
