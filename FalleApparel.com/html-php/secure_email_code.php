<?php
if(isset($_POST["submit"])){
  // Checking For Blank Fields..
  if($_POST["name"]==""||$_POST["email"]==""||$_POST["msg"]==""){
    echo "Fill All Fields...";
  }else{
    // Check if the "Sender's Email" input field is filled out
    $email=$_POST['email'];
    // Remove invalid characters
    $email =filter_var($email, FILTER_SANITIZE_EMAIL);
    // Validate E-mail Address
    $email= filter_var($email, FILTER_VALIDATE_EMAIL);
    if (!$email){
      echo "Invalid Sender's Email";
    }else{
      $subject = 'Message via FalleApparel.com';
      $message = $_POST['msg'];
      $headers = 'From:'. $email . "\r\n"; // Sender's Email
      $headers .= 'Cc:'. $email . "\r\n"; // Carbon copy to Sender
      // Message lines should not exceed 70 characters (PHP rule), so wrap it
      $message = wordwrap($message, 70);
      // Send Mail By PHP Mail Function
      if(mail("account@domain.com", $subject, $message, $headers)){
        echo "Your message was successfully delivered!";
        echo "Check your email for a copy of your message.";
        echo "If you don't see it, check your junk mail.";
      }else{
        echo "Message delivery failed.";
} } } }
?>
