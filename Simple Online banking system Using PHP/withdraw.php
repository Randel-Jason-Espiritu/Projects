<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="stylesheet" type="text/css" href="style.css">
	<title>Withdraw Balance</title>
    <?php
        session_start();
        $_SESSION['logged'] = true;
        $user = $_SESSION['username'];
        $bal = $_SESSION['balance'];
        require("dbinc.php");
    ?>
</head>
<body>
    <div class="container">
        <p class="login-register-text"><a href="homepage.php">Go back</a></p><br><br>
        <form action="withdraw.php" method="POST" class="login-email">
			<p class="login-text" style="font-size: 2rem; font-weight: 800;">Withdraw</p>
			<div class="input-group">
				<input type="text" placeholder="Enter amount minimum PHP 100.00" name="amount" required>
			</div>
			<div class="input-group">
				<button name="withdraw" class="btn">Withdraw</button>
			</div>
			<p class="login-register-text">Previous Balance:<?php echo " PHP ".$bal." ";?></p>
		</form>

        <?php
            if(isset($_POST['withdraw'])){
                $amount = $_POST['amount'];
                if($amount > $bal){
                    echo "<p class='withdraw-error-text'>Balance insufficient! Please add funds.</p>";
                } elseif($amount < 100){
                    echo "<p class='withdraw-error-text'>The amount entered is less than minimum withdrawal.</p>";
                } else{
                    $new_bal = $bal - $amount;
                    $_SESSION['balance'] = $new_bal;
                    $query = "UPDATE users SET balance='$new_bal' WHERE username='$user';";
                    $query_run = mysqli_query($conn, $query);
                    if($query_run){
                        echo "<p class='withdraw-success-text'>Withdrawal successful.</p>";
                        echo "<p class='login-register-text'>New Balance: PHP $new_bal </p>";
                    }
                }
            }
        ?>
    </div>
</body>
</html>