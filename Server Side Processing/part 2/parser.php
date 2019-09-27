<?php
// connect to database
$servername="localhost";
$username="admin";
$password="admin";
$dbname="db";
$db=new mysqli($servername,$username,$password,$dbname);
if($db->connect_error)die("Connection failed: $db->connect_error");

$load=$_POST['load'];

// course selection page
if($load=='select'){
  echo"<nav><a href='../index.htm'>Back</a></nav>
       <h1>Online Learning Management System</h1>
       <div style='display:inline-block;margin:0 auto;'>
       <b>Select a course: </b><select id='selection'>";
  $courses=$db->query("SELECT * FROM courses");
  for($i=0;$i<$courses->num_rows;$i++){
    $get=$courses->fetch_array(MYSQLI_ASSOC);
    $code=$get['code'];
    $title=$get['title'];
    echo"<option value='$code'>$title</option>";}
  echo"</select></div><button type='button' onclick='load(selection.value)'>Load Course</button>";}

// course overview
elseif($load=='overview'){
  // find course
  $courses=$db->query("SELECT * FROM courses");
  for($i=0;$i<$courses->num_rows;$i++){
    $get=$courses->fetch_array(MYSQLI_ASSOC);
    if($get['code']==$_POST['code']){
      $code=$get['code'];
      $title=$get['title'];
      $desc=$get['description'];
      $units=$db->query("SELECT * FROM units WHERE course='$code'");
      break;}
    else echo"course loading error";}
  // populate page
  $n=$units->num_rows;
  echo"<h1>$title</h1><h2>Welcome to $code !</h2><p>$desc</p>";
  for($i=0;$i<$n;$i++){
    $get=$units->fetch_array(MYSQLI_ASSOC);
    $unit=$get['unit'];
    $subtitle=$get['title'];
    $summary=$get['summary'];
    $lesson=$get['lesson'];
    $quiz=$get['quiz'];
    echo"<h2>Unit $unit - $subtitle</h2>
         <p>$summary</p>
         <button onclick=\"load('u$unit')\">Start Unit $unit</button>";}}

// build nav panel
elseif($load=='nav'){
  $code=$_POST['code'];
  $n=$db->query("SELECT * FROM units WHERE course='$code'")->num_rows;
  $nav="<nav><a href='../index.htm'>Back</a>
        <a href=\"javascript:load('select')\">Course Selection</a><br/>
        <a href=\"javascript:load('$code')\">Home</a>";
        for($i=1;$i<=$n;$i++)$nav.="<a href=\"javascript:load('u$i')\">Unit $i</a>";
        $nav.="<div id='qmenu'>Quizzes<div id='qlinks'>";
        for($i=1;$i<=$n;$i++)$nav.="<a href=\"javascript:load('q$i')\">Quiz $i</a>";
        $nav.="</div></div></nav>";
  echo$nav;}

// load lesson
elseif($load=='lesson'){
  $code=$_POST['code'];
  $num=$_POST['unit'];
  $course=$db->query("SELECT title FROM courses WHERE code='$code'");
  $title=$course->fetch_array(MYSQLI_ASSOC)['title'];
  $unit=$db->query("SELECT title,lesson FROM units WHERE course='$code' AND unit=$num");
  $get=$unit->fetch_array(MYSQLI_ASSOC);
  $subtitle=$get['title'];
  $lesson=$get['lesson'];
  $n=$db->query("SELECT * FROM units WHERE course='$code'")->num_rows;
  echo"<h1>Unit $num - $subtitle</h1>$lesson<div class='center'>
       <button type='button' onclick='load(\"q$num\")'>Quiz $num</button>";
  if($num!=$n)echo"<button type='button' onclick='load(\"u".($num+1)."\")'>Unit ".($num+1)."</button>";
  echo"</div>";}

// load quiz
elseif($load=='quiz'){
  $code=$_POST['code'];
  $num=$_POST['unit'];
  $course=$db->query("SELECT title FROM courses WHERE code='$code'");
  $title=$course->fetch_array(MYSQLI_ASSOC)['title'];
  $unit=$db->query("SELECT title,quiz FROM units WHERE course='$code' AND unit=$num");
  $get=$unit->fetch_array(MYSQLI_ASSOC);
  $subtitle=$get['title'];
  $eml=$get['quiz'];
  $n=$db->query("SELECT * FROM units WHERE course='$code'")->num_rows;
  echo"<h1>Unit $num - $subtitle Quiz</h1><form name='quiz'>";
  // parse quiz from EML to HTML
  $quiz=new SimpleXMLElement("$eml");
  $question=$quiz->children();
  for($i=0;$i<$question->count();$i++){
    $q=$quiz->question[$i]->prompt[0];
    echo"<h2 class='question'>".($i+1).") $q</h2>";
    $ans=$question[$i]->children();
    for($j=1;$j<$ans->count();$j++)
      echo "<input type='radio' name='q".($i+1).($ans[$j]->getName()==='true'?
      "' class='mark'/><span class='ans'>".$ans[$j]."</span>":"'/>".$ans[$j])."</br>";}
  echo"<button type='button' onclick='gradeQuiz($num)'>Submit</button></form>";}
?>
