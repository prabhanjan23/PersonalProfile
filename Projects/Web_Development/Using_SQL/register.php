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
	<legend>Registration Form</legend>
	<table>
		<tr>
			<td>Username:</td>
			<td><input placeholder="Enter Username" type="text" name="uname" required ></td>
		</tr>
		<tr>
			<td>Password:</td>
			<td><input placeholder="Enter Password" type="password" name="password" required ></td>
		</tr>
		<tr>
			<td>Students name:</td>
			<td><input placeholder="Enter Name" type="text" name="sname" required ></td>
		</tr>
		<tr>
			<td>Roll number:</td>
			<td><input placeholder="Enter Roll Number" type="text" name="roll" required> </td>
		</tr>
		<tr>
			<td>Age:</td>
			<td><input placeholder="Enter Age" type="text" name="age" required> </td>
		</tr>
		<tr>
			<td>Stream/Major: </td>
			<td><input placeholder="Enter Stream/Major" type="text" name="major" required> </td>
		</tr>
		<tr>
			<td><input type="submit" name="register" value="Register"></td>
			<td><input type="reset" name="clear" value="Clear"></td>
		</tr>
	</table>
	</fieldset>
</form>
</body>
</html>

<?php
if (isset($_POST['register'])) {
	$con = mysqli_connect('localhost', 'root', '', 'library');

	
	if ($con) {
		$uname = $_POST['uname'];
		$pass = md5($_POST['password']);

		$sname = $_POST['sname'];
		$roll = $_POST['roll'];
		$age = $_POST['age'];
		$major = $_POST['major'];
		$sql = "INSERT INTO Student VALUES ('$uname','$pass','$sname', $roll, $age,'$major')";
		$res = mysqli_query($con, $sql);

		if ($res == true) {
		echo 'details added successfully<br>'; 
		echo '<td><a href="Login.php">Click here to login.</a></td>';
		}
	}
}
?>