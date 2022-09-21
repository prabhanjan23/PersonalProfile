<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Registration Form</title>
</head>
<body>
	<link rel="stylesheet" type="text/css" href="library.css">
<form method="POST">
	<fieldset>
	<legend>Login</legend>
	<table>
		<tr>
			<td>Username: </td>
			<td><input placeholder="Enter Username" type="text" name="username" required ></td>
		</tr>
		<tr>
			<td>Password: </td>
			<td><input placeholder="Enter Password" type="password" name="password" required> </td>
		</tr>
		
		<tr>
			<td><input type="submit" name="login" value="Login"></td>
			<td><input type="reset" name="clear" value="Clear"></td>
			<td><a class="registerbtn" href="register.php">Click here to register</a></td>
		</tr>
	</table>
	</fieldset>


</form>
</body>
</html>

<?php
if (isset($_POST['login'])) {
	$con = mysqli_connect('localhost', 'root', '', 'library');

	if ($con) {
		$uname = $_POST['username'];
		$pass = md5($_POST['password']); 
		

		$sql = "SELECT * FROM Student WHERE Username = '$uname'";
		$res = mysqli_query($con,$sql);
		if ($res == true) {
			$row = mysqli_fetch_assoc($res);
			$pass1 = $row['Password'];
			echo $pass . '<br>';
			echo $pass1;
			if ((strcmp($pass, $pass1)) == 0) {
				echo $pass1;
				header('Location: http://localhost/LibraryProject/homepage.html');

			}
		}


	}
}
?>
