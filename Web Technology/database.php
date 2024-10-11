<?php
$sql = "CREATE DATABASE webTech"

if(mysqli_query($connect,$sql)){
    echo "Database Created Successfully";
    else
    echo  "Failed to creating database";
}

?>