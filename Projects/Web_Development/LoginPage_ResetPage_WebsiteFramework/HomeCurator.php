
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title>Login Page</title>
</head>
<body>
	<link rel="stylesheet" type="text/css" href="homepage.css">

<form method="POST">	
<div class="header">
  	<a href="Homepage.php" class="logo">PetAdoption Assistant</a>
  	<div class="header-right">
    	<a class="active" href="HomeCurator.php">Home</a>
    	<a href="logout.php">Logout</a>
  </div>
</div>
</form>

<div class="row">
  <h2>Menu</h2>
  <input type="text" id="mySearch" onkeyup="myFunction()" placeholder="Search.." title="Type in a category">
  <ul id="myMenu">
    <li><a href="#">Dog</a></li>
    <li><a href="#">Cat</a></li>
    <li><a href="#">Rabbits</a></li>
    <li><a href="#">Small and Furry</a></li>
    <li><a href="#">Scales, Fins, & Other</a></li>
    <li><a href="#">Birds</a></li>
    <li><a href="#">Horses</a></li>
    <li><a href="#">Barnyard</a></li>
  </ul>
</div>

<div class="smol-flexbox-grid">
    <div class="card">  
      <img src="images/dog1.png" alt="Avatar" style="width: 50%">
      <div class="container">
      <h4><b>Spike</b></h4> 
      <p>Age: 2</p> 
      
      <button id="increment-btn" onclick ="increment()">More Infomation</button>
      </div>
    </div>

    <div class="card">
      <img src="images/dog2.jpg" alt="Avatar1" style="width: 50%">
    <div class="container">
      <p><b>Luke</p> 
      <p>Age: 3</p> 
    <button id="increment-btn" onclick ="increment()">More Infomation</button>
    </div>
    </div>

    <div class="card">
     <img src="images/dog3.jpg" alt="Avatar2" style="width: 50%">
   <div class="container">
     <p>Penny</p> 
     <p>Age: 5</p> 
    <button id="increment-btn" onclick ="increment()">More Infomation</button>
  </div>
    </div>
</div>

<div class="footer">
  <p>@2022 PetAdoption Assistant</p>
</div>


</body>
</html>

<script>
function myFunction() {
  var input, filter, ul, li, a, i;
  input = document.getElementById("mySearch");
  filter = input.value.toUpperCase();
  ul = document.getElementById("myMenu");
  li = ul.getElementsByTagName("li");
  for (i = 0; i < li.length; i++) {
    a = li[i].getElementsByTagName("a")[0];
    if (a.innerHTML.toUpperCase().indexOf(filter) > -1) {
      li[i].style.display = "";
    } else {
      li[i].style.display = "none";
    }
  }
}
</script>

<?php

if (isset($_POST['logout'])) {
	header("location:logout.php");
}

session_start();
if ($_SESSION['uname']) {
	//echo "Welcome " . $_SESSION['uname'];
}else{
	header("location:PetLogin.php");
}



?>