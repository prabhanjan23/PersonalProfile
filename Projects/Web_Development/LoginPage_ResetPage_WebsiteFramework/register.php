<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Sign Up Page</title>
</head>
<body>
	<link rel="stylesheet" type="text/css" href="PetLogin.css">

<form method="POST">
	<h1>Sign Up</h1>


	<div class="container">
		<label for="firstname"><b>First Name</b></label>
		<input type="text" placeholder="Enter First Name..." name="firstname" required>

		<label for="lastname"><b>Last Name</b></label>
		<input type="text" placeholder="Enter Last Name..." name="lastname" required>

		<label for="uname"><b>Username</b></label>
		<input type="text" placeholder="Enter Username..." name="uname" required>
		
		<label for="password"><b>Password</b></label>
		<input type="password" placeholder="Enter Password..." name="pass" required>

		<button type="submit" name="register" >Sign Up</button>
	</div>
</form>	
</body>
</html>

<?php
if (isset($_POST['register'])) {
	$con = mysqli_connect('localhost', 'root', '', 'PetLoginData');

	if ($con) {
		$uname = $_POST['uname'];
		$pass = $_POST['pass'];


		$firstname = $_POST['firstname'];
		$lastname = $_POST['lastname'];
		$sql = "INSERT INTO LoginCredentials (Firstname, Lastname, Username, Password) VALUES ('$firstname','$lastname','$uname', '$pass')";
		$res = mysqli_query($con, $sql);

		if ($res == true) {
			header('Location: http://localhost/PetApp/Homepage.php');
		}
	}
}
?>

