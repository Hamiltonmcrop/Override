<?php
//Starting PHP Session

session_start();


//Checking to see if the Submit Button was clicked
if(isset($_POST["login"])){
    //if it was, then Collect all the submitted Data and Store temporarily
    $username = $_POST["username"];
    $password = $_POST["password"];
    
    //Check for User Exists
    if(file_exists('database/'. $username . ".json")){
        
        //$user = file_get_contents('database/'. $username . ".json", "r");
        $user = file_get_contents('database/'. $username . ".json", "r");
        
        $userData = json_decode($user);
        
        //Saving Password from Database File
        $dbpassword = $userData->password;
        
        //Checking if the Password matched the Password submitted
        if($password !== $dbpassword){
            
            //Redirecting to Login Page, if the Password is Wrong
            echo "<script>alert('Sorry, You have entered a Wrong Password')</script>";
            
            echo "<script>location.href='login.html'</script>";
            
            return false;
            
        } else{
            //Accepting the User, after submitting Valid Information
            
            echo "<script>alert('Welcome to your Dashobard')</script>";
            
            echo "<script>location.href='dashboard.php'</script>";
            
            $_SESSION["username"] = $username;
        }
    } else {
        //Redirecting to Login Page, if the Password is Wrong
        echo "<script>alert('Sorry, User: $username Not Found on our Database')</script>";
            
        echo "<script>location.href='login.html'</script>";
            
        return false;
    }
}

?>
