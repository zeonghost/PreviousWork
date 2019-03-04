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
$conn = new mysqli($servername,$username,$password,$dbname);

$sql="DELETE FROM appointment WHERE appointmentNo = '$no'";

if ($conn->query($sql) === TRUE) {
    echo "<br>Record deleted successfully";
	echo'<form action="schedule.php"><button type="submit">Return</button></form>';
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();

?>