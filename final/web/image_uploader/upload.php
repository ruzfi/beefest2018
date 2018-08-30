<?php

$target_file = "uploads/" . basename($_FILES["fileupload"]["name"]);
$uploadOk = 1;
$imageFileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));
$type = $_FILES["fileupload"]["type"];
echo "Type Image: ".$type;
if(isset($_POST["submit"])) 
{
    if($type != "image/jpeg" && $type != "image/png") {
        $uploadOk = 0;
        header("location:index.php?error=fail");
        
    }
}

if ($uploadOk == 0) {
    echo "Sorry, your file was not uploaded.";
} else {
    $newfilename = round(microtime(true)) . '.' . $imageFileType;
    if (move_uploaded_file($_FILES["fileupload"]["tmp_name"], "uploads/" . $newfilename)) {
        echo '<div align="left">';
        echo '<img src="uploads/'.$newfilename.'"style="width:25%"> ';
        echo '</div><br/>';
        echo "The file ". basename( $_FILES["fileupload"]["name"]). " has been uploaded.";
    } else {
        header("location:index.php?error=failupload");
    }
}
?>