<table align = 'center' border= '1px'>
    <tr>
        <th>fname</th>
        <th>lname</th>
        <th>email</th>
    </tr>

    <?php
        include 'connect.php';
        $sql = "SELECT * from Student";
        $run = mysqli_query($connect, $sql);
        while($row = mysqli_fetch_assoc($run));
    ?>
    <tr>
        <td><?php echo $row['fname'];?></td>
        <td><?php echo $row['lname'];?></td>
        <td><?php echo $row['email'];?></td>
    </tr>

</table>