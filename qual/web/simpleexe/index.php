<!DOCTYPE html>
<html lang="en">
<head>
  <title>SimpleExe</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<body style="height:1500px">

<nav class="navbar navbar-default navbar-fixed-top">
  <div class="container">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">SimpleExe</a>
    </div>
  </div>
</nav>
  
<div class="container" style="margin-top:50px">
  <h1 style="text-align: center">Check ping from our server!</h1>
  <br>
  <form action="index.php" method="POST">
    <div class="row">
    <div class="col-md-10">
      <input type="text" name="URL" placeholder="IP Address" class="form-control">
    </div>
    <div class="col-md-2"> 
      <input type="submit" value="PING TEST" class="btn btn-danger">
    </div>
  </div>
  </form>
  <div>
  <br>
  <?php
  $ip = htmlspecialchars($_POST['URL'], ENT_QUOTES);

   if(isset($_POST['URL'])) 
   {
    $result = shell_exec('ping -c 4 ' . $ip);
    echo '<div class="alert alert-success" style="text-align: center">' . nl2br($result). '</div>';
    ob_flush(); flush();
   }
  ?>
    
  </div>
</div>
</body>
</html>
