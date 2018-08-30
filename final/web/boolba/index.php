<?php 
    include('database.php');
    $db = db();
    $html = '';
    if(isset($_POST['submit'])){
        $id = $_POST['id'];
        $getid = "SELECT username, password FROM users WHERE id ='" . $id . "'";
        $result = mysqli_query($db, $getid);

        $num = mysqli_num_rows($result);
        if($num > 0){
            $html = '<pre>Benar :)</pre>';
        }else{
            header($_SERVER[ 'SERVER_PROTOCOL' ] . ' 404 Not Found');
            $html = '<pre>Salah :(</pre>';
        }
    }
?>

<html>
    <head>
    <meta charset="utf-8">
    <title>admin_Boolba</title>
    <link rel="stylesheet" type="text/css" href="index.css">
    <link href="https://fonts.googleapis.com/css?family=Lato:100,100i,300,300i,400,400i,700,700i,900,900i" rel="stylesheet">
    </head>
    <body>
        <div id="container">
            <div id="wrapper">
                <div class="title">BOO<span>LBA</span></div>
                <form method="post" action="#" class="login">
                    <input type="text" name="id" placeholder="User ID">
                    <br>
                    <input class="btn-submit" type="submit" name="submit" value="Submit">
                </form>    
            </div>
            <div id="response"><?php echo $html; ?></div>
        </div>
    </body>
</html>
