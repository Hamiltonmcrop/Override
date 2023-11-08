<?php

require_once('loginhandler.php');

date_default_timezone_set("Africa/Lagos");

//Checking to see if this Session is set
if(isset($_SESSION['username'])){
    
    $user = file_get_contents('database/'. $_SESSION['username'] . ".json", "r");
    
    $userData = json_decode($user);
    
    //Saving Data from Database File
    $surname = $userData->surname;
    $firstname = $userData->firstname;
    $phone = $userData->phone;
    $email = $userData->email;
    $username = $userData->username;
    $occupation = $userData->occupation;
    $dbpassword = $userData->password;


?>


<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<title>Zuri Login Page</title>
		<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/css/bootstrap.min.css" rel="stylesheet">
		<link rel="stylesheet" href="assets/css/styles.css">
	</head>
	<body>
		<div class="container">
		    <div class="row">
		        <div class="col-12">
		            <div class="homepage">
		                <h2><center><b><?php echo $surname;?></b> Welcome to your Home Page</center></h2>
		                <h2><center><a href="logout.php" class="btn btn-danger">Logout</a></center></h2>
		                <hr>
		                <h3 class="greetings">
		                    This is a Demo Page, The Information on this Page was provided by you, during your Registration.
		                </h3>
		                <h5><center>Find Your Details Below</center></h5>
		                <table class="table">
		                    <tr>
		                        <td>Surname</td>
		                        <td><b><?php echo $surname;?></b></td>
		                    </tr>
		                    <tr>
		                        <td>First Name</td>
		                        <td><b><?php echo $firstname;?></b></td>
		                    </tr>
		                    <tr>
		                        <td>Phone Number</td>
		                        <td><b><?php echo $phone; ?></b></td>
		                    </tr>
		                    <tr>
		                        <td>Email</td>
		                        <td><b><?php echo $email; ?></b></td>
		                    </tr>
		                    
		                    <tr>
		                        <td>Username</td>
		                        <td><b><?php echo $username; ?></b></td>
		                    </tr>
		                    <tr>
		                        <td>Occupation</td>
		                        <td><b><?php echo $occupation; ?></b></td>
		                    </tr>
		                </table>
		            </div>
		        </div>
		    </div>
		</div>
		
		<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta3/dist/js/bootstrap.bundle.min.js"></script>
	</body>
</html>


<?php
    
    
}

else{
    echo "<script>alert('Please, kindly Login')</script>";
    
    echo "<script>location.href='login.html'</script>";
    
    return false;
}

?>
