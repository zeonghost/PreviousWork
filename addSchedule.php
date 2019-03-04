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

$id=0;
$dentistId=1;
$date=$_POST['date'];
$time=$_POST['time'];
$no=$_POST['no'];
$err=0;
$conn = new mysqli($servername,$username,$password,$dbname);

$sqla = "SELECT AppointmentNo, AppointmentDate,AppointmentTime FROM appointment";
$result = $conn -> query($sqla);
if($result -> num_rows > 0){
	while($row = $result -> fetch_assoc()){
		$no=$row["AppointmentNo"];
		if($date==$row['AppointmentDate'])
			$err=$err+1;
		if($time==$row['AppointmentTime'])
			$err=$err+1;
	}
}
else
{
	$no=0;
}	
$no=$no+1;
if($err=0){
$sql = "INSERT INTO appointment (AppointmentNo, AppointmentDate,AppointmentTime, PatientID, DentistID)
VALUES ('$no', '$date', '$time', '$id', '$dentistId')";
}
if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
	echo'<form action="schedule.php"><button type="submit">Return</button></form>';
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();

?>