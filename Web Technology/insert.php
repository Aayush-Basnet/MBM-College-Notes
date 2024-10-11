<?php
    $host = "localhost";
    $username = "username";
    $password = "";
    $dbname = "WebTech";

    $connect = mysqli_connect($host,$username,$password,$dbname);

    if($connect)
    echo "Connection Successfull";
    else
    echo "Error in connection";


    $sql = "INSERT INTO Student(fname, lname,email) 
        VALUES ("John","Cena","john@gmail.com";)";

    $run = mysqli_query($connect, $sql);

    if($run)
        echo "Recorded Inserted Successfullly";
    else
        echo "Recored Insertion Failed";
?>