<?php
  $servername = "localhost";
  $username = "root";
  $password = "";
  $dbname = "PetLoginData";

$con = new mysqli($servername, $username, $password, $dbname);

if ($con->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$id = (int)$_GET['id'];

// sql to delete a record
$sql = "DELETE FROM LoginCredentials WHERE ID = '$id'";

if ($con->query($sql) === TRUE) {
  echo "Record deleted successfully";
  $sql = "ALTER TABLE LoginCredentials AUTO_INCREMENT = 1";
} else {
  echo "Error deleting record: " . $conn->error;
}
header("Location: HomeAdmin.php");
?>