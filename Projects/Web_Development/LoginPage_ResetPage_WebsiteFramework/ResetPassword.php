<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Sign Up Page</title>

<style>
	h1{
		margin-bottom: 0px;
	}
</style>


</head>
<body>
	<link rel="stylesheet" type="text/css" href="PetLogin.css">

<form method="POST">
	<h1>Reset Password</h1>


	<div class="container">
		<label for="uname"><b>Username</b></label>
		<input type="text" placeholder="Enter Username..." name="uname" required>
		
		<label for="password"><b>New Password</b></label>
		<input type="password" placeholder="Enter Password..." name="pass" required>

		<label for="password"><b>Confirm Password</b></label>
		<input type="password" placeholder="Enter Password..." name="conpass" required>

		<button type="submit" name="resetpass" >Reset</button>
	</div>
</form>	
</body>
</html>

<?php
if (isset($_POST['resetpass'])) {
	$con = mysqli_connect('localhost', 'root', '', 'PetLoginData');

	if ($con) {
		$uname = $_POST['uname'];
		$pass = $_POST['pass'];
		$conpass = $_POST['conpass'];
  
		$select = mysqli_query($con, "SELECT * FROM LoginCredentials WHERE username = '".$uname."'");
		if(!mysqli_num_rows($select)) {
			function function_alert($message) { 
		    	echo "<script>alert('$message');</script>";
			}
			function_alert("This username does not exists");
			exit();
		}

		if(strcmp($pass, $conpass) !== 0){
			function function_alert($message) { 
		    	echo "<script>alert('$message');</script>";
			}
			function_alert("The passwords do not match");
			exit();
		}


		$sql = "UPDATE LoginCredentials SET Password = '".$pass."' WHERE Username='".$uname."'";
		$res = mysqli_query($con, $sql);

		if ($res == true) {
			header('Location: http://localhost/PetApp/PetLogin.php');
		}
	}
}
?>

