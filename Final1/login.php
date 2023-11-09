<?php
// Start PHP Session

session_start();

// Check if the Submit Button was clicked
if(isset($_POST["login"])){
    // Collect all the submitted Data and Store temporarily
    $inputUsername = $_POST["username"];
    $inputPassword = $_POST["password"];
    
    // Check for User Existence
    if(file_exists('database/'. $inputUsername . ".json")){
        $userFile = file_get_contents('database/'. $inputUsername . ".json", "r");
        $userData = json_decode($userFile);
        
        // Save Password from Database File
        $dbPassword = $userData->password;
        
        // Check if the Password matches the submitted Password
        if($inputPassword !== $dbPassword){
            // Redirect to Login Page if the Password is Incorrect
            echo "<script>alert('Sorry, You have entered an Incorrect Password')</script>";
            echo "<script>location.href='login.html'</script>";
            return false;
        } else{
            // Accept the User after submitting Valid Information
            echo "<script>alert('Welcome to your Dashboard')</script>";
            echo "<script>location.href='dashboard.php'</script>";
            $_SESSION["username"] = $inputUsername;
        }
    } else {
        // Redirect to Login Page if the User is Not Found
        echo "<script>alert('Sorry, User: $inputUsername Not Found in our Database')</script>";
        echo "<script>location.href='login.html'</script>";
        return false;
    }
}
?>

