<!DOCTYPE html>

	<html>
    <head>
        <meta charset="utf-8">
        <title>Input From UI Design</title>
        <link rel="stylesheet" href="styleS.css">
    </head>

  
    <body>
	     

    	<div class="head">
   <nav>
<ul>
    <li>
             <a class ="active" href="staff.php">Maintenance</a>
        </li>
		<li id="drop"> 
		   <div class="dropdown">
            <a  href ="record.php">Records</a>
			 <div class="dropdown-content">
            <a href="precord.php">Patients</a>
            <a href="arecord.php">Appointments</a>
            </div>
          </div>
        </li>
		<li> 
            <a  href ="schedule.php">Schedule</a>
        </li>
       
        <li id="loginHead"> 
            
            <a  href ="#">LOGOUT</a>
           
    
        </li>
    </ul>
</nav>
    
    </div>

    <div class="centercontent">
	<nav>
    <ul>
    <li>
             <a href="schedule.php">Add Schedule</a>
        </li>
		<li> 
            <a class ="active" href ="editSchedule.php">Edit Schedule</a>
        </li>
		<li> 
            <a  href ="deleteschedule.php">Delete Schedule</a>
        </li>
	
        
       
    </ul>
    </nav>
	<div class="formbox">
<?php 

$servername = "localhost";
$username = "root";
$password ="";
$dbname = "dentalclinic";

$no=$_POST['no'];
$date;
$time;

$conn = new mysqli($servername,$username,$password,$dbname);

$sqla = "SELECT AppointmentDate, AppointmentTime FROM appointment WHERE AppointmentNo='$no'";
$result = $conn -> query($sqla);
if($result -> num_rows > 0){
	while($row = $result -> fetch_assoc()){
		$date=$row["AppointmentDate"];
		$time=$row["AppointmentTime"];
	}
}

?>	
      <h1 style="text-align:center">Edit Schedule</h1>
	  <form action="editSchedule2.php" method="post">
      <input type="text" value=<?php echo $date;?> name="date">
      <input type="text" value=<?php echo $time;?> name="time">       
	  <input type="text" value=<?php echo $no;?> name="no" style="display:none;">
      <button type="submit">Edit</button>
	  </form>
     </div>     
    

    </div>
  
<?php
$conn->close();
?>
 <?php
   include 'footer.php';
   ?>

    </body>
</html>