<?php
    include 'connect.php';
    $sql = "CREATE TABLE Student
                fname varchar(20),
                lname varchar(20),
                email varchar(50)";
    $run = mysqli_query($connect, $sql);

    if($run)
        echo "Table Created Successfully";
    else
        echo "Error while creating table";
?>