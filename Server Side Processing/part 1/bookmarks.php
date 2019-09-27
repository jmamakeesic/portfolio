<?php
// connect to database
$servername="localhost";
$username="admin";
$password="admin";
$dbname="db";
$db=new mysqli($servername,$username,$password,$dbname);
if($db->connect_error)die("Connection failed: $db->connect_error");

$action=$_POST["action"];

// attempt login
if($action=="login"){
  $user=$_POST["user"];
  $pass=$_POST["pass"];
  $sql="SELECT * FROM users WHERE username='$user'";
  $result=$db->query($sql);
  if($result->num_rows==0)
    echo"err-user";
  else{
    $result=$db->query($sql." AND password='$pass'");
    if($result->num_rows==0)
      echo"err-pass";
    else
      loadBookmarks($user,$db);
  }
}
// attempt account creation
elseif($action=="newAcct"){
  $user=$_POST["user"];
  $pass=$_POST["pass"];
  $email=$_POST["email"];
  // validate email
  $email=filter_var($email, FILTER_SANITIZE_EMAIL);
  $email=filter_var($email, FILTER_VALIDATE_EMAIL);
  if($email=="FALSE")
    echo"inv-email"; // invalid email
  else {
    // check for existing account by email
    $sql="SELECT email FROM users WHERE email='$email'";
    $result=$db->query($sql);
    if($result->num_rows!=0){
      $account=$result->mysqli_fetch_field();
      $existingemail=$account->email;
      if($email==$existingemail)
        echo"err-email"; // existing email found
    }else{
      // check for existing account by username
      $sql="SELECT username FROM users WHERE username='$user'";
      $result=$db->query($sql);
      if($result->num_rows!=0){
        $account=$result->mysqli_fetch_field();
        $existinguser=$account->username;
        if($user==$existinguser)
          echo"err-user"; // existing username found
      }else{
        // add account into database
        $db->query("INSERT INTO users SET username='$user',password='$pass',email='$email')");
      }
    }
  }
}
// attempt account data retrieval by email address, send to user
elseif($action=="forgot"){
  $email=$_POST["email"];
  // validate email
  $email=filter_var($email, FILTER_SANITIZE_EMAIL);
  $email=filter_var($email, FILTER_VALIDATE_EMAIL);
  if($email=="FALSE")
    echo"Invalid email entered";
  else{
    // retrieve account data
    $sql="SELECT username,password,email FROM users WHERE email='$email'";
    $result=$db->query($sql);
    if($result->num_rows==0)
      echo"err-email"; //email not found
    else{
      // email account data to user
      $account=$result->mysqli_fetch_field();
      $user=$account->username;
      $pass=$account->password;
      $subject="Account details for Bookmarking Service";
      $msg="Username: $user<br/>Password: $pass";
      if (mail($email,$subject,$msg))
        echo"success";
      else
        echo"err-delivery";
    }
  }
}
// add bookmark to database
elseif($action=="add"){
  $site=$_POST['site'];
  $url=$_POST['url'];
  $user=$_POST['user'];
  $sql="INSERT INTO bookmarks SET site='$site',url='$url',user='$user'";
  $result=$db->query($sql);
  loadBookmarks($user,$db);
}
// edit a bookmark
elseif($action=="edit"){
  $id=$_POST['id'];
  $newsite=$_POST['newsite'];
  $newurl=$_POST['newurl'];
  $user=$_POST['user'];
  $sql="UPDATE bookmarks SET site='$newsite',url='$newurl' WHERE id='$id'";
  $db->query($sql);
  loadBookmarks($user,$db);
}
// delete a bookmark
elseif($action=="delete"){
  $id=$_POST['id'];
  $user=$_POST['user'];
  $sql="DELETE FROM bookmarks WHERE id='$id'";
  $db->query($sql);
  loadBookmarks($user,$db);
}
// retrieve bookmarks from database
function loadBookmarks($user,$db){
  $sql="SELECT id,site,url FROM bookmarks WHERE user='$user'";
  $result=$db->query($sql);
  if($result->num_rows!=0){
    $list="";
    //echo"$result->num_rows";
    for($i=0;$i<$result->num_rows;$i++){
      $get=$result->fetch_array(MYSQLI_ASSOC);
      $id=$get['id'];
      $site=$get['site'];
      $url=$get['url'];
      $list.="<li><a href='$url' target='_blank'>
        <img src='$url/favicon.ico' class='icon' alt=''/>$site</a>
        <form class='editMode' id='$site' onsubmit='return false;'>->
          <input type='text' size='6'  id='s$id' placeholder='Name' value='$site'/>
          <input type='text' size='12' id='u$id' placeholder='URL'  value='$url'/>
          <input type='submit' class='button' value='SAVE' onclick='edit(\"$id\")'/>
          <input type='button' class='button' value='DELETE' onclick='del(\"$id\")'/>
        </form></li>";
    }
    echo"$list";
  }
}

?>
