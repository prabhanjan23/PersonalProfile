<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Login Page</title>

<style>

	a.forgetpass{
		color: #6504b6;
	}

	a:hover{
		color: red;
	}

</style>

</head>
<body>
	<link rel="stylesheet" type="text/css" href="PetLogin.css">

<form method="POST">
	<h1>Log In</h1>

	<div class="container">
		<label for="uname"><b>Username</b></label>
		<input type="text" placeholder="Enter Username..." name="uname" required>
		
		<label for="password"><b>Password</b></label>
		<input type="password" placeholder="Enter Password..." name="pass" required>

		<a class="forgetpass" href="ResetPassword.php" style="float: right;">Forgot Password?</a>

		<button type="submit" name="login">Login</button>
		<div>
			<span class="registerbtn">Don't have an account yet? <a href="register.php">Click here to register.</a></span>
		</div>
		<div style="text-align: center;margin-top: 10px;">
			<a href="GuestHomepage.html">Continue as guest</a>
		</div>
	</div>
</form>	
</body>
</html>

<?php
session_start();
if (isset($_POST['login'])) {
	$con = mysqli_connect('localhost', 'root', '', 'PetLoginData');


	if ($con) {
		$uname = $_POST['uname'];
		$pass = $_POST['pass']; 
		
		$select = mysqli_query($con, "SELECT * FROM LoginCredentials WHERE username = '".$uname."'");
		if(!mysqli_num_rows($select)) {
			function function_alert($message) { 
		    	echo "<script>alert('$message');</script>";
			}
			function_alert("The Username you have entered does NOT exists in our Database");
			exit();
		}

		$sql = "SELECT * FROM LoginCredentials WHERE Username = '$uname'";
		$ad = "SELECT * FROM LoginCredentials WHERE ID = '1'";
		$cu = "SELECT * FROM LoginCredentials WHERE ID = '2'";

		$res = mysqli_query($con,$sql);
		$adres = mysqli_query($con, $ad);
		$cures = mysqli_query($con, $cu);

		if ($res == true) {
			$row = mysqli_fetch_assoc($res);
			$row1 = mysqli_fetch_assoc($adres);
			$row2 = mysqli_fetch_assoc($cures);

			$pass1 = $row['Password'];
			$adname = $row1['Username'];
			$cuname = $row2['Username'];

			if ((strcmp($pass, $pass1)) == 0) {
				$_SESSION['uname'] = $uname;
				if ((strcmp($uname, $adname)) == 0) {
					header('Location: http://localhost/PetApp/HomeAdmin.php');
				}else if ((strcmp($uname, $cuname)) == 0) {
					header('Location: http://localhost/PetApp/HomeCurator.php');
				}else{
					header('Location: http://localhost/PetApp/Homepage.php');
				}
			}else{
				function function_alert($message) { 
		    		echo "<script>alert('$message');</script>";
				}
				function_alert("The Password you have entered is Incorrect");
				exit();
			}
		}


	}
}
?>