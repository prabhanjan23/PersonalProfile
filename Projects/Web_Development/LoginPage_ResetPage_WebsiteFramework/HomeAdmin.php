<?php
  session_start();
  if ($_SESSION['uname']) {
  //echo "Welcome " . $_SESSION['uname'];
}else{
  header("location:PetLogin.php");
}
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Login Page</title>

<style>

.btncontainer { 
  height: 100px;
  position: relative; 
}

.center {
  margin: 50;
  position: absolute;
  top: 50%;
  left: 50%;
  -ms-transform: translate(-50%, -50%);
  transform: translate(-50%, -50%);
}

input[type=text], input[type=password] {
  width: 100%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  box-sizing: border-box;
}

/* Set a style for all buttons */
button {
  background-color: #6504b5;
  color: white;
  padding: 14px 20px;
  margin-left: auto;
  margin-right: auto;
  border: none;
  cursor: pointer;
  width: 100%;
}

button:hover {
  opacity: 0.8;
}

/* Extra styles for the cancel button */
.cancelbtn {
  width: auto;
  padding: 10px 18px;
  background-color: #f44336;
}


.container {
  padding: 16px;
}


/* The Modal (background) */
.modal {
  display: none; /* Hidden by default */
  position: fixed; /* Stay in place */
  z-index: 1; /* Sit on top */
  left: 0;
  top: 0;
  width: 100%; /* Full width */
  height: 100%; /* Full height */
  overflow: auto; /* Enable scroll if needed */
  background-color: rgb(0,0,0); /* Fallback color */
  background-color: rgba(0,0,0,0.4); /* Black w/ opacity */
  padding-top: 60px;
}

/* Modal Content/Box */
.modal-content {
  background-color: #fefefe;
  margin: 5% auto 15% auto; /* 5% from the top, 15% from the bottom and centered */
  border: 1px solid #888;
  width: 50%; /* Could be more or less, depending on screen size */
}

/* The Close Button (x) */
.close {
  position: absolute;
  right: 25px;
  top: 0;
  color: #000;
  font-size: 35px;
  font-weight: bold;
}

.close:hover,
.close:focus {
  color: red;
  cursor: pointer;
}

/* Add Zoom Animation */
.animate {
  -webkit-animation: animatezoom 0.6s;
  animation: animatezoom 0.6s
}

@-webkit-keyframes animatezoom {
  from {-webkit-transform: scale(0)} 
  to {-webkit-transform: scale(1)}
}
  
@keyframes animatezoom {
  from {transform: scale(0)} 
  to {transform: scale(1)}
}
</style>

</head>
<body>
	<link rel="stylesheet" type="text/css" href="homepage.css">

<form method="POST">	
<div class="header">
  	<a href="Homepage.php" class="logo">PetAdoption Assistant</a>
  	<div class="header-right">
    	<a class="active" href="HomeAdmin.php">Home</a>
    	<a href="logout.php">Logout</a>
  </div>
</div>
</form>

<h1>List of Accounts:</h1>

<?php
$con = mysqli_connect('localhost', 'root', '', 'PetLoginData');
	if ($con) {
		$sql = "SELECT * FROM LoginCredentials";
		$res = mysqli_query($con, $sql);
		$count = mysqli_num_rows($res);

		if ($res == true) {
			$i = 1;

		echo "<table style='border:1px solid black;margin-left:auto;margin-right:auto;'>
		<tr>
		<th style='border: 2px solid black; border-collapse: collapse;'>ID</th>
		<th style='border: 2px solid black; border-collapse: collapse;'>Firstname</th>
		<th style='border: 2px solid black; border-collapse: collapse;'>Lastname</th>
		<th style='border: 2px solid black; border-collapse: collapse;'>Username</th>
		<th style='border: 2px solid black; border-collapse: collapse;'>Password</th>
    <th style='border: 2px solid black; border-collapse: collapse;'>Delete</th></tr>";
		while($row = mysqli_fetch_assoc($res)){
			echo "<tr>
			<td style='border: 2px solid black; text-align: center; border-collapse: collapse;'>".$row['ID']."</td>
			<td style='border: 1px solid black; border-collapse: collapse;'>".$row['FirstName']."</td>
			<td style='border: 1px solid black; border-collapse: collapse;'>".$row['LastName']."</td>
			<td style='border: 1px solid black; border-collapse: collapse;'>".$row['Username']."</td>
			<td style='border: 1px solid black; border-collapse: collapse;'>".$row['Password']."</td>
      <td style='border: 1px solid black; border-collapse: collapse;'><a style='color: #6504b5;' href=delete.php?id=".$row['ID']."\>Delete</a></td></tr>";
			$i++;
		}
		echo "</table>";

		}
	}

?>

<div class="btncontainer">
  <div class="center">
    <button onclick="document.getElementById('id01').style.display='block'" style="width:auto;">Edit</button>
  </div>
</div>

<div id="id01" class="modal">
  
  <form class="modal-content animate" method="POST">

    <div class="container">
      <label for="uname"><b>ID</b></label>
      <input type="text" placeholder="Enter id number" name="id" required>

      <label for="psw"><b>Column</b></label>
      <input type="text" placeholder="Enter name of column" name="column" required>

      <label for="psw"><b>New value</b></label>
      <input type="text" placeholder="Enter new value" name="newval" required>
        
      <button type="submit" name="Edit">Edit</button>
    </div>

    <div class="container" style="background-color:#f1f1f1">
      <button type="button" onclick="document.getElementById('id01').style.display='none'" class="cancelbtn">Cancel</button>
    </div>
  </form>
</div>

<div class="footer">
  <p>@2022 PetAdoption Assistant</p>
</div>


</body>
</html>

<?php

if (isset($_POST['Edit'])) {
  $servername = "localhost";
  $username = "root";
  $password = "";
  $dbname = "PetLoginData";

  // Create connection
  $conn = new mysqli($servername, $username, $password, $dbname);
  // Check connection
  if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }

  $id = $_POST['id'];
  $column = $_POST['column'];
  $newVal = $_POST['newval'];

  $sql = "UPDATE LoginCredentials SET ".$column." = '".$newVal."' WHERE ID=".$id."";

  if ($conn->query($sql) === TRUE) {
    echo "
    <script>
      window.onload = function() {
      if(!window.location.hash) {
        window.location = window.location + '#loaded';
        window.location.reload();
        }
      }
    </script>";

  } else {
    echo "Error updating record: " . $conn->error;
  }

  $conn->close();



}


?>


<script>
var modal = document.getElementById('id01');
window.onclick = function(event) {
    if (event.target == modal) {
        modal.style.display = "none";
    }
}
</script>

