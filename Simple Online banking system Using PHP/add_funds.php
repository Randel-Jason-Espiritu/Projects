<?php
	include_once "dbinc.php";
	session_start();
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="stylesheet" type="text/css" href="style.css">
    <title>Add Funds</title>
</head>
<body>
	<div class="container">
		<form action="" method="POST" class="add_funds">
			<p class="add_funds_text" style="font-size: 2rem; font-weight: 800;">Add Funds</p>
            
			<div class="input-group">
				<input type="number" placeholder="Enter Amount (Max: 50000)" name="funds_added" min="0" max="50000" required>
			</div>
			<div class="transaction-status">
			<?php 
				if (isset($_SESSION["message"])){
					echo $_SESSION["message"];
					unset($_SESSION["message"]);
				}
			?>
			</div>
			<div class="input-group">
				<button name="addBtn" class="btn">Add</button>
			</div>
			<div class="input-group">
				<button name="backBtn" class="btn" onclick="location.href='homepage.php'">Back</button>
			</div>
		</form>
	</div>
    <?php
        if (isset($_POST["addBtn"]))
        {
			$user = $_SESSION["username"];
            $funds_added = $_SESSION['balance'] + $_POST["funds_added"];
			$_SESSION['balance'] = $funds_added;
			$sql = "UPDATE users SET balance ='$funds_added' WHERE username='$user';";
            mysqli_query($conn, $sql);
			$_SESSION["message"] = "SUCCESS!";
            header("Location:add_funds.php");
        }
    ?>
</body>
</html>