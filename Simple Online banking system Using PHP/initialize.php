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
        <form action='initialize.php' method='post' class='login-email'>
            <p class='login-text' style='font-size: 2rem; font-weight: 800;'>Enter Details</p>
            <div class='input-group'>
                <input type='text' placeholder='First Name' name='first_name' required>
            </div>
            <div class='input-group'>
                <input type='text' placeholder='Middle Name' name='middle_name' required>
            </div>
            <div class='input-group'>
                <input type='text' placeholder='Last Name' name='last_name' required>
            </div>
            <div class='input-group'>
                <input type='text' placeholder='Current Balance' name='balance' required>
            </div>
            <div class='input-group'>
                <button name='submit' class='btn'>Login</button>
            </div>
        </form>
	</div>
    <?php
    if(isset($_POST['submit'])){
        include('dbinc.php');
        session_start();
        $user = $_SESSION['username'];
        $_SESSION['first_name'] = $_POST['first_name'];
        $_SESSION['middle_name'] = $_POST['middle_name'];
        $_SESSION['last_name'] = $_POST['last_name'];
        $_SESSION['balance'] = $_POST['balance'];
        $fname =  $_SESSION['first_name'];
        $mname = $_SESSION['middle_name'];
        $lname = $_SESSION['last_name'];
        $bal = $_SESSION['balance'];
        $sql = "update users set first_name='$fname', middle_name='$mname', last_name='$lname', balance='$bal' where username='$user';";
        mysqli_query($conn, $sql);
        header('location: homepage.php');
    }
    ?>
</body>
</html>