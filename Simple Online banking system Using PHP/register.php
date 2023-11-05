<?php
	//Checks if submit is set 
	if(isset($_POST['submit'])){
		$username = $_POST['username'];
		$email = $_POST['email'];
		$pass = $_POST['pass'];
		$cpassword = $_POST['cpassword'];
		//check if password and cpassword is equal
		if($pass == $cpassword){
			//sql
			$mysqli = new mysqli("localhost", "root", "", "bank") or die($mysqli->connection_error);
			$tname= 'users';
			// //query
			$mysqli->query("INSERT INTO $tname(username, email, user_password) VALUES ('$username', '$email', '$pass');") or die($mysqli->error);
			
			echo "<script>alert('Account Successfully created!!!')</script>";
		}else{
			echo "<script>alert('Password and Confrim-Password not the same!!!')</script>";
		}
	}
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="stylesheet" type="text/css" href="style.css">
	<title>Register</title>
</head>
<body>
	<div class="container">
		<form action='register.php' method="POST" class="login-email">
            <p class="login-text" style="font-size: 2rem; font-weight: 800;">Register</p>
			<div class="input-group">
                <input class="txt" placeholder='Username' type="text" name="username">
			</div>
			<div class="input-group">
                <input class="txt" placeholder='Email' type="email" name="email">
			</div>
			<div class="input-group">
                <input class="txt" placeholder='Password' type="password" name="pass">
			</div>
			<div class="input-group">
                <input class="txt" placeholder='Confirm Password'type="password" name="cpassword">
			</div>
			<div class="input-group">
				<button name="submit" class="btn">Register</button>
			</div>
			<p class="login-register-text">Have an account? <a href="login.php">Login Here</a>.</p>
		</form>
	</div>
</body>
</html>