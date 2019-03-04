    <head>
        <meta charset="utf-8">
        <title>login</title>
        <link rel="stylesheet" href="styleS.css">
    </head>
    <div class="head">
    </div>
<?php 

$servername = "localhost";
$username = "root";
$password ="";
$dbname = "dentalclinic";

$no=$_POST['no'];
$date=$_POST['date'];
$time=$_POST['time'];

$conn = new mysqli($servername,$username,$password,$dbname);



$sql = "UPDATE appointment SET AppointmentDate='$date',AppointmentTime='$time' WHERE AppointmentNo='$no'";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
	echo'<form action="schedule.php"><button type="submit">Return</button></form>';
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();

?>