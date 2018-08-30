<?php

/*********************
***   @abdilahrf    **
**********************/

DEFINE('GOOD_DAY', 'Hi boys, its good day right? ');
session_start();

if(empty($_SESSION['question_today'])) {
	$_SESSION['question_today'] = GOOD_DAY;
}

if(isset($_GET['source'])){
	highlight_file (__FILE__);
	if($_GET['source']==="phpinfo"){
		die(phpinfo());
	}
}

if(isset($_REQUEST['upload'])==="Upload"){
    $tmp = $_FILES['file'];
    $filename = $tmp['name'];
    //H4h4h4h4h4h4h ;)
    while(stristr($filename,".")){
            $filename = stristr($filename,".");
    }
    $filename = basename($tmp['name']);
    if(move_uploaded_file($tmp['tmp_name'],'/var/www/html/uploads/'.$filename)){
            echo "The file ".$filename." has been uploaded";
    }else{
            echo "Failed Upload!";
    }
}

if(eval("echo '".$_SESSION['question_today']."';") === GOOD_DAY){
	echo "Good day!<br>";
}else{
	echo "Bad day!<br>";
}

if(isset($_REQUEST['cmd'])){
	$blacklist = ["~","!","@","#","\^",'\$',"&","\*","\(","\)","\+","{","}","\|",":","\"","<",">","\?","`","-","=","\[","\]","\"",";","'",","];
	$code = $_REQUEST['cmd'];
	$secure = true;
	foreach ($blacklist as $blacklisted) {
	    if (preg_match ('/' . $blacklisted . '/im', $code)) {
	        $secure = false;
	        echo "Found: ".$blacklisted. "<br>";
	        break;
	    }
	}
	if(substr_count($code, ' ')>3){
		$secure = false;
	}elseif (stristr($code,'flag') || stristr($code,'cat') || stristr($code,'head') || stristr($code,'tail') || stristr($code,'base64') || stristr($code,'hd') || stristr($code,'xxd') || stristr($code,'bash') || stristr($code,'od') || stristr($code,'grep') || stristr($code,'find') || stristr($code,'strings')) {
		$secure = false;
	}

	if (!$secure) {
	    die('Insecure command detected!');
	} else {
	    system ($code." ;#");
	}

}
