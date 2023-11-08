<?php

//Checking if the Submit Button was Clicked
if(isset($_POST["submit"])){
    //if it was, then Collect all the submitted Data and Store temporarily
    $surname = $_POST["surname"];
    $firstname = $_POST["firstname"];
    $phone = $_POST["phone"];
    $email = $_POST["email"];
    $username = $_POST["username"];
    $occupation = $_POST["occupation"];
    $password = $_POST["password1"];
    $password2 = $_POST["password2"];
    $squestion = $_POST["squestion"];
    $sanswer = $_POST["sanswer"];
    
    //Checking if Confirm Password Matches the Original
    if($password !== $password2){
        echo "<script>alert('Sorry Confirm Password Does not Match Original')</script>";
        echo "<script>location.href='register.html'</script>";
        return false;
    }
    
    //Trying to uniquely identify the User Registration
   // $username = $firstname .$phone;
    
    //echo $surname ."<br>". $firstname ."<br>". $phone ."<br>". $email ."<br>". $occupation ."<br>". $password1 ."<br>". $password2;
    
    $array_info = [
        'surname' => $surname,
        'firstname' => $firstname,
        'phone' => $phone,
        'email' => $email,
        'username' => $username,
        'occupation' => $occupation,
        'password' => $password,
        'squestion' => $squestion,
        'sanswer' => $sanswer,
    ];
    
    //Check for Duplicate Registration
    if(file_exists('database/'. $username . ".json")){
        echo "<h2 style='color:red;'><center>Duplicate Registration Form</center></h2>";
        echo "<h3><center><a href='login.html' style='color:red;text-decoration:none;'>Back to Login</a></center></h3>";
    } else {
        
        //file_put_contents('database/' . $filename . ".txt", json_encode($filename));
        file_put_contents('database/'. $username . ".json", json_encode($array_info));
        //unlink('database/'. $filename . ".json");
        
        //Showing Success Message
        echo "<h2 style='color:green;'><center>Registration Successful</center></h2>";
        echo "<h3><center>Your Username is: $username</center></h3>";
        echo "<h3><center><a href='login.html' style='color:red;text-decoration:none;'>Back to Login</a></center></h3>";
    }
}

?>
