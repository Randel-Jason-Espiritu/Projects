<?php
	if(isset($_POST['submit'])){
		//storing $post valus in variables
		$temp1 = $_POST['username'];
		$temp2 = $_POST['password'];
		//sql
		$mysqli = new mysqli("localhost", "root", "", "bank") or die($mysqli->connection_error);
		$tname = 'users';
		$result = $mysqli->query("SELECT * FROM $tname") or die($mysqli->error);
		while($data=$result->fetch_assoc()){
			if($temp1==$data['username']&&$temp2==$data['user_password']){
				session_start();
				$_SESSION['logged'] = true;
				$_SESSION['username'] = $data['username'];
				$_SESSION['email'] = $data['email'];
				$_SESSION['password'] = $data['user_password'];
				$_SESSION['first_name'] = $data['first_name'];
				$_SESSION['middle_name'] = $data['middle_name'];
				$_SESSION['last_name'] = $data['last_name'];
				$_SESSION['balance'] = $data['balance'];

				if($_SESSION['first_name'] == NULL){
					header("Location: initialize.php");
				}else{
					header("Location: homepage.php");
				}
			}else{
				echo "<script>alert('Incorrect Username or Password')</script>";
			}
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
	<title>Login</title>
</head>
<body>
	<div class="container">
		<form action=<?php echo $_SERVER['PHP_SELF'] ?> method="POST" class="login-email">
			<p class="login-text" style="font-size: 2rem; font-weight: 800;">Login</p>
			<div class="input-group">
				<input type="text" placeholder="Username" name="username" required>
			</div>
			<div class="input-group">
				<input type="password" placeholder="Password" name="password" required>
			</div>
			<div class="input-group">
				<button name="submit" class="btn">Login</button>
			</div>
			<p class="login-register-text">Don't have an account? <a href="register.php">Register Here</a>.</p>
		</form>
	</div>
</body>
</html>