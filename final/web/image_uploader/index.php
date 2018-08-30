<!DOCTYPE html>
<html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Image Uploader</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<div class="box">
	<form enctype="multipart/form-data" action="upload.php" method="POST">
		<h3 style="text-align:center">Image Uploader</h3>
		<input type="file" name="fileupload">
		<center><input type="submit" value="Upload!" name ="submit"class="tombol"></center>
	</form>
	<?php 
	if(isset($_GET['error'])){
		if($_GET['error'] == "fail")
		{
			echo "<br>";
			echo "Sorry, only JPG, JPEG & PNG files are allowed.";
		}
		else if($_GET['error'] == "failupload")
		{
			echo "<br>";
			echo "Sorry, there was an error uploading your file.";
		
		}
	}
	?> 
</div>
</body>
</html>