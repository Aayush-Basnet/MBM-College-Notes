<?php
$host = "localhost";
$username = "username";
$password = "";
$dbname = "WebTech";

$connect = mysqli_connect($host,$username,$password,$dbname);

if($connect){
    echo "Connection Successfull";
    else
    echo "Error in connection";
}
?>