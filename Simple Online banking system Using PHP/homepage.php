<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="stylesheet" type="text/css" href="style.css">
	<title>Homepage</title>
</head>
<body>
	<div class="container">
		<?php
		session_start();
		echo "
			<p class='login-text' style='font-size: 2rem; font-weight: 800;'>Welcome</p>
			<p class='login-register-text'>Name: ".$_SESSION['first_name']." ".$_SESSION['middle_name']." ".$_SESSION['last_name']."</p>
			<p class='login-register-text'>Email: ".$_SESSION['email']."</p>
			<p class='login-register-text'>Balance: ".$_SESSION['balance']."php</p><br />
			<form action='homepage.php' method='post' class='login-email'>
				<div class='input-group'>
					<input class='btn' type='submit' name='withdraw' value='Widthdraw'><br />
				</div>
				<div class='input-group'>
					<input class='btn' type='submit' name='add_funds' value='Add Funds'>
				</div>
				<div class='input-group'>
					<input class='btn' type='submit' name='logout' value='Logout'>
				</div>
			</form>
		";
		if(isset($_POST['withdraw'])){
			header('location: withdraw.php');
		}else if(isset($_POST['add_funds'])){
			header('location: add_funds.php');
		}else if(isset($_POST['logout'])){
			header('location: logout.php');
		}
		?>
	</div>
</body>
</html>