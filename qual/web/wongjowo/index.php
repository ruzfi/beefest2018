<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Script Wong Jowo</title>
	<link rel="stylesheet" type="text/css" href="index.css">
    <link href="https://fonts.googleapis.com/css?family=Lato" rel="stylesheet">
</head>
<body>
    <h1 class="judul">Script Wong Jowo</h1>

    <form method="POST" name="soal" id="formulir">
        <h4>Username:</h4>
        <input type="text" name="username" id="username" placeholder="Username">
        <h4>Password:</h4>
        <input type="password" name="password" id="password" placeholder="Password" class="">
        <br>
        <br>
        <button name="submit" value="submit" class="submit-button" onclick="return validate()">Login</button>
    </form>

    <script>
        //Selesaikan teka-teki ini untuk mendapatkan flag
        function validate(){
            var username = document.forms["soal"]["username"].value;
            var password = document.forms["soal"]["password"].value;
            if(username == "" || password == ""){
                alert("Semua input harus diisi!");
                return false;
            }
            if(username === "admin" && password === String.fromCharCode(52, 107, 85, 95, 98, 51, 108, 52, 106, 97, 114, 95, 106, 52, 118, 52, 83, 99, 114, 49, 112, 116, 95, 49, 48, 49)) {
                alert("Kamu Benar!");
            } else {
                alert("Username atau Password salah!");
                return false;
            }
        };
    </script>
</body>
</html>
